#include "driver.hpp"
#include "parser.hpp"

//Cose un modulo, un file con dichiarazioni external e include


// Generazione di un'istanza per ciascuna della classi LLVMContext,
// Module e IRBuilder. Nel caso di singolo modulo è sufficiente
LLVMContext *context = new LLVMContext;
//LLVMContext classe "opaca" che tiene tutte le strutture, cose piu importanti per generare codice.
Module *module = new Module("Kaleidoscope", *context);
IRBuilder<> *builder = new IRBuilder(*context);
//i metodi della classe builder, generano internamente rapressentazioni di tutte le rappresentazione



Value *LogErrorV(const std::string Str) {
  std::cerr << Str << std::endl;
  return nullptr;v
}

/* Il codice seguente sulle prime non è semplice da comprendere.
   Esso definisce una utility (funzione C++) con due parametri:
   1) la rappresentazione di una funzione llvm IR, e
   2) il nome per un registro SSA
   La chiamata di questa utility restituisce un'istruzione IR che alloca un double
   in memoria e ne memorizza il puntatore in un registro SSA cui viene attribuito
   il nome passato come secondo parametro. L'istruzione verrà scritta all'inizio
   dell'entry block della funzione passata come primo parametro.
   Si ricordi che le istruzioni sono generate da un builder. Per non
   interferire con il builder globale, la generazione viene dunque effettuata
   con un builder temporaneo TmpB
*/
static AllocaInst *CreateEntryBlockAlloca(Function *fun, StringRef VarName) {
  IRBuilder<> TmpB(&fun->getEntryBlock(), fun->getEntryBlock().begin()); //getEntryBlock: crea un blocco di allocazione
  return TmpB.CreateAlloca(Type::getDoubleTy(*context), nullptr, VarName); //prende una rappresentazione LLVM, in input nome(es: x) e una funzione(funzione interna, un oggetto con all interno tutte el istruzioni: il tipo di ritorno, i parametri, il body etc..) 
}// (fun-> getEntryBlock()) definisce il builder temporaneo scrive nel entry block della funzione, che ha un metodo intermedio per allocare memoria
// CreateAlloca resituisce un istruzione di allocazione, alloca 8 bit di double, VarName cose? se il paramentro si chiama x, il puntatore viene messo con lo stesso nome con il % davanti

//nel processo di generaizone di codice usiamo una tabella associativa(nomi(variabili) e valori)
// qui non ce il nome della variabile perche sara determinato in run time.
// ad ogni varabile associa un istruzione, cosa fa?: che alloca uno spazio per tenere il nome della variabile, alloca un double e restituscie in un registro ssa il puntatore al valore.


// Implementazione del costruttore della classe driver
driver::driver(): trace_parsing(false), trace_scanning(false) {};

// Implementazione del metodo parse, chiamata a bison, poi ci pensa bison a farlo, il parse viene chiamato con l'input file,
//l'oggetto driver viene passato al parse
int driver::parse (const std::string &f) {
  file = f;                    // File con il programma
  location.initialize(&file);  // Inizializzazione dell'oggetto location
  scan_begin();                // Inizio scanning (ovvero apertura del file programma)
  yy::parser parser(*this);    // Istanziazione del parser
  parser.set_debug_level(trace_parsing); // Livello di debug del parsed
  int res = parser.parse();    // Chiamata dell'entry point del parser
  scan_end();                  // Fine scanning (ovvero chiusura del file programma), chiuso il file
  return res;                  // viene restituito il parse
}

// Implementazione del metodo codegen, che è una "semplice" chiamata del 
// metodo omonimo presente nel nodo root (il puntatore root è stato scritto dal parser)
//GENERAZIONE DEL CODICE
//si parte dalla root
void driver::codegen() {
  root->codegen(*this);
};

// si partono dai costrutti
/************************* Sequence tree **************************/
SeqAST::SeqAST(RootAST* first, RootAST* continuation):
  first(first), continuation(continuation) {};

// La generazione del codice per una sequenza è banale:
// mediante chiamate ricorsive viene generato il codice di first e 
// poi quello di continuation (con gli opportuni controlli di "esistenza")
Value *SeqAST::codegen(driver& drv) {
  if (first != nullptr) { //la grammatica ci consente di fare ;;
    Value *f = first->codegen(drv); //tutte le codegen restituisco un tipo Value, infatti la generazione di codgen termina SSA
  } else {
    if (continuation == nullptr) return nullptr;
  }
  Value *c = continuation->codegen(drv);
  return nullptr;
};

/********************* Number Expression Tree *********************/
// codgen cosa deve fare per il number? un numero e' una costanza infatti verra chiamata ricorsivamente
NumberExprAST::NumberExprAST(double Val): Val(Val) {};

lexval NumberExprAST::getLexVal() const {
  // Non utilizzata, Inserita per continuità con versione precedente
  lexval lval = Val;
  return lval;
};

// Non viene generata un'struzione; soltanto una costante LLVM IR
// corrispondente al valore float memorizzato nel nodo
// La costante verrà utilizzata in altra parte del processo di generazione
// Si noti che l'uso del contesto garantisce l'unicità della costanti 
Value *NumberExprAST::codegen(driver& drv) {  
  return ConstantFP::get(*context, APFloat(Val)); //perche non return il valroe del nodo? perche le costanti devono essere uniche e sono mantenute tutte da questo contesto. 
                    //get vuol dire prendi, si usa val per una normalizzazione come vuole lui
};

/******************** Variable Expression Tree ********************/
VariableExprAST::VariableExprAST(const std::string &Name): Name(Name) {};

lexval VariableExprAST::getLexVal() const {
  lexval lval = Name;
  return lval;
};

// NamedValues è una tabella che ad ogni variabile (che, in Kaleidoscope1.0, 
// può essere solo un parametro di funzione) associa non un valore bensì
// la rappresentazione di una funzione che alloca memoria e restituisce in un
// registro SSA il puntatore alla memoria allocata. Generare il codice corrispondente
// ad una varibile equivale dunque a recuperare il tipo della variabile 
// allocata e il nome del registro e generare una corrispondente istruzione di load
// Negli argomenti della CreateLoad ritroviamo quindi: (1) il tipo allocato, (2) il registro
// SSA in cui è stato messo il puntatore alla memoria allocata (si ricordi che A è
// l'istruzione ma è anche il registro, vista la corrispodenza 1-1 fra le due nozioni), (3)
// il nome del registro in cui verrà trasferito il valore dalla memoria
Value *VariableExprAST::codegen(driver& drv) {
  AllocaInst *A = drv.NamedValues[Name]; //rappresentazione di un istruzione di allocazione.
  if (!A) //test di un rerroe semantico
     return LogErrorV("Variabile non definita");
  return builder->CreateLoad(A->getAllocatedType(), A, Name.c_str());
  //il codice per usare una variabile si traduce nel caricare un valore della bariabile nel registro
}

/******************** Binary Expression Tree **********************/
// se mi imbatto in un nodo che operatore binario , questo e' il suo construttore, operatore binario ha due figli  e quindi due alberi variabili.
BinaryExprAST::BinaryExprAST(char Op, ExprAST* LHS, ExprAST* RHS):
  Op(Op), LHS(LHS), RHS(RHS) {};

// La generazione del codice in questo caso è di facile comprensione.
// Vengono ricorsivamente generati il codice per il primo e quello per il secondo
// operando. Con i valori memorizzati in altrettanti registri SSA si
// costruisce l'istruzione utilizzando l'opportuno operatore
Value *BinaryExprAST::codegen(driver& drv) {
  Value *L = LHS->codegen(drv); //genero il codice che lascio il risultato in un registro che io chiamo L
  Value *R = RHS->codegen(drv); //registro R
  if (!L || !R) // se tutte e due sono diversi da null.
     return nullptr;
  switch (Op) { // 4 operatori per capire cosa e' visualizzato nel nodo
  case '+':
    return builder->CreateFAdd(L,R,"addres"); //meotodo che costruisce l'istruzione attraverso due registri e opzionalmente il nome di un registro dove mettere il risultato
  case '-':
    return builder->CreateFSub(L,R,"subres");
  case '*':
    return builder->CreateFMul(L,R,"mulres");
  case '/':
    return builder->CreateFDiv(L,R,"addres");
  default:  
    std::cout << Op << std::endl;
    return LogErrorV("Operatore binario non supportato");
  }
};

/********************* Call Expression Tree ***********************/
/* Call Expression Tree */
CallExprAST::CallExprAST(std::string Callee, std::vector<ExprAST*> Args):
  Callee(Callee),  Args(std::move(Args)) {};

lexval CallExprAST::getLexVal() const {
  lexval lval = Callee;
  return lval;
};

Value* CallExprAST::codegen(driver& drv) {
  // La generazione del codice corrispondente ad una chiamata di funzione
  // inizia cercando nel modulo corrente (l'unico, nel nostro caso) una funzione
  // il cui nome coincide con il nome memorizzato nel nodo dell'AST
  // Se la funzione non viene trovata (e dunque non è stata precedentemente definita)
  // viene generato un errore

  Function *CalleeF = module->getFunction(Callee); //nel module se esiste funzione e metto la sua rappresentazione nella variaible Callee
  if (!CalleeF)
     return LogErrorV("Funzione non definita");
  // Il secondo controllo è che la funzione recuperata abbia tanti parametri
  // quanti sono gi argomenti previsti nel nodo AST
  if (CalleeF->arg_size() != Args.size()) // quanti sono gli argomenti, se non concide con gli argomenti con la funzione passata
     return LogErrorV("Numero di argomenti non corretto");
  // Passato con successo anche il secondo controllo, viene predisposta
  // ricorsivamente la valutazione degli argomenti presenti nella chiamata 
  // (si ricordi che gli argomenti possono essere espressioni arbitarie)
  // I risultati delle valutazioni degli argomenti (registri SSA, come sempre)
  // vengono inseriti in un vettore, dove "se li aspetta" il metodo CreateCall
  // del builder, che viene chiamato subito dopo per la generazione dell'istruzione
  // IR di chiamata
  //costruiamo un vettore degli oggetti di tipo value, 
  std::vector<Value *> ArgsV;
  for (auto arg : Args) {
     ArgsV.push_back(arg->codegen(drv));
     if (!ArgsV.back())
        return nullptr;
  }
  return builder->CreateCall(CalleeF, ArgsV, "calltmp");
}
/************************* Prototype Tree *************************/
PrototypeAST::PrototypeAST(std::string Name, std::vector<std::string> Args):
  Name(Name), Args(std::move(Args)), emitcode(true) {};  //Di regola il codice viene emesso

lexval PrototypeAST::getLexVal() const {
   lexval lval = Name;
   return lval;	
};

const std::vector<std::string>& PrototypeAST::getArgs() const { 
   return Args;
};

// Previene la doppia emissione del codice. Si veda il commento più avanti.
void PrototypeAST::noemit() { 
   emitcode = false; 
};

Function *PrototypeAST::codegen(driver& drv) {
  // Costruisce una struttura, qui chiamata FT, che rappresenta il "tipo" di una
  // funzione. Con ciò si intende a sua volta una coppia composta dal tipo
  // del risultato (valore di ritorno) e da un vettore che contiene il tipo di tutti
  // i parametri. Si ricordi, tuttavia, che nel nostro caso l'unico tipo è double.
  
  // Prima definiamo il vettore (qui chiamato Doubles) con il tipo degli argomenti
  //tutte el funzioni resistuiscono un double


  std::vector<Type*> Doubles(Args.size(), Type::getDoubleTy(*context));
  // Quindi definiamo il tipo (FT) della funzione
  FunctionType *FT = FunctionType::get(Type::getDoubleTy(*context), Doubles, false);
  //guarda se ce gia una funzoine con tipo ritorno double e tipo dei parametri double, e difnisco il function type
  // Infine definiamo una funzione (al momento senza body) del tipo creato e con il nome
  // presente nel nodo AST. ExternalLinkage vuol dire che la funzione può avere
  // visibilità anche al di fuori del modulo
  Function *F = Function::Create(FT, Function::ExternalLinkage, Name, *module);//creiamo una funzione con il nome Name e la inseriamo nel modulo puntato.

  // Ad ogni parametro della funzione F (che, è bene ricordare, è la rappresentazione 
  // llvm di una funzione, non è una funzione C++) attribuiamo ora il nome specificato dal
  // programmatore e presente nel nodo AST relativo al prototipo
  unsigned Idx = 0;
  for (auto &Arg : F->args())
    Arg.setName(Args[Idx++]); //Args sono quelli nel nodo, nome dei parametri specificato dai programmatori

  /* Abbiamo completato la creazione del codice del prototipo.
     Il codice può quindi essere emesso, ma solo se esso corrisponde
     ad una dichiarazione extern. Se invece il prototipo fa parte
     della definizione "completa" di una funzione (prototipo+body) allora
     l'emissione viene fatta al momendo dell'emissione della funzione.
     In caso contrario nel codice si avrebbe sia una dichiarazione
     (come nel caso di funzione esterna) sia una definizione della stessa
     funzione.
  */
  if (emitcode) { //chi chiama la emit? dentro il parser
    F->print(errs()); 
    fprintf(stderr, "\n");
  };
  
  return F; //restituisce la funzione F
}
//qui il suo body e' gia stato definitivo
/************************* Function Tree **************************/
FunctionAST::FunctionAST(PrototypeAST* Proto, ExprAST* Body): Proto(Proto), Body(Body) {};

Function *FunctionAST::codegen(driver& drv) {
  // Verifica che la funzione non sia già presente nel modulo, cioò che non
  // si tenti una "doppia definizion"
  Function *function = 
      module->getFunction(std::get<std::string>(Proto->getLexVal()));//getlexval da il nome della funzione //lex e' un tipo variant //get va specializzata con qualcosa tipo string //tutta la riga restituisce il nome della funzione
  // Se la funzione non è già presente, si prova a definirla, innanzitutto
  // generando (ma non emettendo) il codice del prototipo
  if (!function)
    function = Proto->codegen(drv); //generiamo il codice per il prototipo 
  // Se, per qualche ragione, la definizione "fallisce" si restituisce nullptr
  if (!function)
    return nullptr;
else
  return nullptr; //falliamo se la funzione non e' stata definita
  // Altrimenti si crea un blocco di base in cui iniziare a inserire il codice
  //il body deve avere almeno un basic block
  // il builder punti al basic block
  BasicBlock *BB = BasicBlock::Create(*context, "entry", function);
  builder->SetInsertPoint(BB); // e' un puntatore AL BASIC BLOCK creato nel contesto. 
  //Cosa vuol dire classe opaca?

 // esempio ha x y e z come paramentro
  // Ora viene la parte "più delicata". Per ogni parametro formale della
  // funzione, nella symbol table si registra una coppia in cui la chiave
  // è il nome del parametro mentre il valore è un'istruzione alloca, generata
  // invocando l'utility CreateEntryBlockAlloca già commentata.
  // Vale comunque la pena ricordare: l'istruzione di allocazione riserva 
  // spazio in memoria (nel nostro caso per un double) e scrive l'indirizzo
  // in un registro SSA
  // Il builder crea poi un'istruzione che memorizza il valore del parametro x
  // (al momento contenuto nel registro SSA %x) nell'area di memoria allocata.
  // Si noti che il builder conosce il registro che contiene il puntatore all'area
  // perché esso è parte della rappresentazione C++ dell'istruzione di allocazione
  // (variabile Alloca) 
  
  for (auto &Arg : function->args()) {  //per ogni argomente della funzione 
    // Genera l'istruzione di allocazione(di spazio 8 byte) per il parametro corrente, per ogni chiave di variale contiene una istruzione che alloca 8 byte che mettera in un registro SSA.
    AllocaInst *Alloca = CreateEntryBlockAlloca(function, Arg.getName());
    // Genera un'istruzione per la memorizzazione del parametro nell'area
    // di memoria allocata
    builder->CreateStore(&Arg, Alloca); //per ogni variabile crea delle store: cosa fa? memorizza 
    // Registra gli argomenti nella symbol table per eventuale riferimento futuro
    drv.NamedValues[std::string(Arg.getName())] = Alloca;
  } 
  
  // Ora può essere generato il codice corssipondente al body (che potrà
  // fare riferimento alla symbol table)
  if (Value *RetVal = Body->codegen(drv)) { //viene generato il body ricorsivamente
    // Se la generazione termina senza errori, ciò che rimane da fare è
    // di generare l'istruzione return, che ("a tempo di esecuzione") prenderà
    // il valore lasciato nel registro RetVal 
    builder->CreateRet(RetVal);

    // Effettua la validazione del codice e un controllo di consistenza
    verifyFunction(*function);
 
    // Emissione del codice su su stderr) 
    function->print(errs());
    fprintf(stderr, "\n");
    return function;
  }

  // Errore nella definizione. La funzione viene rimossa
  function->eraseFromParent();
  return nullptr;
};

**************  Block expression tree***********************
//implementazione del costruttore
BlockExprAS::BlockExprAST(std::vector<VariableExprAST*> Def, ExprAST* Val):
  Def(std::move(Def)), Val(Val) {};
Value* BlockExprAST::codegen(driver& drv){
    std::vector<AllocaInst*> tmp;
    for(int i=0,e=Def.size();  i < e; i++)// var a=
    {
      AllocaInst *boundVal = Def[i]-> codegen(drv);
      if (!boundVal) return nullptr;
      tmp.push_back(NamedValue[Def[i]->getName()])
      drv.NamedValue[Def[i]->getName()] = boundVal;
    };
    Value *blockvalue = Val->codegen(drv);  //chiamata ricorsiva che si riferisce al body
    for(int i=0,e=Def.size();  i < e; i++)// 
    {
      drv.NamedValue[Def[i]->getName()] = tmp[i];
    };
    
    
    return blockvalue; 
}
VarBindingAST::VarBindingAST(std::string Name, ExprAST* Val):
Name(Name), Bal(Val) {};
std::string& VarBindingAST::getName(){return Name; };
AllocaInst *bound

