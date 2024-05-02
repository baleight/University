# Python

###### Complementi di programmazione UNIMORE

## Introduzione

#### Linguaggi statici VS Linguaggi Dinamici

Riguarda il momento in cui vengono verificate e assegnati i tipi di variabili e assegnati i tipi alle variabili e alle espressioni nel codice 

Ling. Statici (Java, C++, C#)

* Tipizzazione statica: dichiarati esplicitamente prima di eseguire il programma e vengono verificati a compile-time
* Forte tipizzazione: i cast devono essere espliciti
- Gli errori sono rilevati prima che il programma viene eseguito
* Linguaggi compilati

Linguaggi Dinamici (Python, JavaScript e Ruby)-> si sa analizzare e modificare durante run-time

* Tipizzazione dinamica: risolti a run-time, il tipo varia durante il run-time

* linguaggi interpretati

* Castare tra una variabile e l'altra posso venire in modo implicito(comportam. imprevisti).

* dato che la verifica dei tipi e' in run time possono portare il programma a dare errore. 

* non e’ necessario dichiarare il tipo di variabile può cambiare durante l’esecuzione di un programma

* i controlli sono fatti a run time

* più flessibile ma prestazioni più lente a causa della allocazione di memoria, difficoltà a mantenere il codice

* il debug più facile e la sintassi anche

#### Linguaggi Compilati VS Interpretati

Riguarda il modo in cui vengono eseguiti, il processo di conversione sorgente in istruzioni eseguibili.

##### Compilato (C, C++, Rust):

Il codice scritto in un file sorgente e passato al compilatore che traduce il codice in un linguaggio macchina o linguaggio intermedio(codice oggetto o file eseguibile)

Il codice oggetto puo essere subito eseguito.

![](https://lh7-us.googleusercontent.com/6uwDeIIR6K1iyjKTo9XlSOEwwyd_DY3TLD6D0j043eWrxGvwdatt5ERkaHnUmxVtlS7AkR_CYxjNKuefx8Oe_ezmVlJI8xa0M1aUaQJC6uKnpep8q4bZJTPHvqkS_q5ecGkucwZepRHMKgEAh4xyaCg)

##### Interpretato (Python, Javascripot e Php)

Il codice sorgente viene eseguito direttamenre da un interprete senza una fase di pre compilazione .
Legge il codice sorgente riga per riga ed esegue ogni istruzione in tempo reale.

Java cose? e' ibrido! Viene compilato in linguaggio intermedio(bytecode) e poi viene eseguito riga per riga utilizzando un interprete ovvero la Java virtual Machine (JVM)

![](https://lh7-us.googleusercontent.com/UXkrNMcfzDeQ01Fc24JQG5mNGmaaT1F0Ad7rakAHEO5mJuldMUvLa37toRU4HXRb9gslZ9BWyBjb6Ciqzj-DwcHIhG-bVv_0cOZqd47SwGJJDZKZtmgF7x7LnG751ZA8Jm070Ixoz1AtfBUmRfnrAas)

Compilatore = più efficiente ma meno flessibile
Interprete = meno efficiente ma più flessibile

#### Linguaggio ALTO / BASSO livello

Riguarda il livello di astrazione e alla vicinanza all'hardware

Alto(Python, Java, C#...):

- Livello d'astrazione molto alto ovvero piu vicini al linguaggio naturale.(istruzioni piu leggibili)

- Molto portabili ovvero eseguiti da diverse piattaforme

- Facili da imparare e da usare

- Pragrammazione piu efficente, poche righe maggiore produttivita

Basso(Assembly e linguaggio macchina):

- Piu vicini all'hardware e infati richiedono una profonda compressione dell'archittetura

- Molto piu efficenti in termini di prestazioni, usati per scrivere driver che chiedono prestazioni ottimizzate

- Non sono portabili, dipendenti dall'architettura hardware specifica

- Molto complessi e suscettibili ad errore

### Tipizzazione

Indica cosa rappres. il dato per determinare il risultato di un istruzione.

Tipi:

- Debole: Consente conversione implicite

- Forte: linguaggio ha delle regole rigide infatti si usano le conversione esplicite

- Safe: se il casting e' implicito viene impedito per adottare una tipizzazione di default

- Unsafe: se il casting e' implicito non viene impedito e causando dei possbili crash

# PYTHON

Linguaggio orientato ad oggetti ovvero ogni variabile e' un oggetto (tipi primitivi, classi, i metodi... TUTTO)

Python non controlla la classe di appartenza esempio:

```python
function calcola(a,b,c) => return (a+b)*c    | e1 = calcola(1,2,3)        e1 → 9
e2 = calcola([1,2,3],[4,5,6],2)                       | e2 → [1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6]
e3 = calcola(‘mele ’, ‘e arance’, 3                   | e3 → “mele e arance mele e arance mele e arance”
```

Creato nel 1991 , linguaggio ad alto livello , dinamico e interpretato -> macchina virtuale python (PVM)
Si usa la versione 3 -> python3 co l'IDE: PyCharm

I tipi di dati Built-In o tipi primitivi soto tipi fondamentali forniti dapython per rappresebntare dati di base.
Tipi di dati incorporati direttamente nella lingua e sono utilizzati per rappres. informazioni di base esempio:

1. **Interi (Integers):** Il tipo di dato `int` in Python rappresenta numeri interi senza parte frazionaria. Ad esempio:
   
   ```python
   x = 10
   ```

2. **Numeri in virgola mobile (Floating-Point):** Python offre il tipo di dato `float` per rappresentare numeri in virgola mobile. Ad esempio:
   
   ```python
   y = 3.14
   ```

3. **Stringhe (Strings):** Il tipo di dato `str` in Python rappresenta sequenze di caratteri. Le stringhe possono essere definite utilizzando apici singoli o doppi. Ad esempio:
   
   ```python
   stringa = "Ciao, mondo!"
   #Concatenazione di stringhe: [1,2]+[3,4] = [1,2,3,4]
   s.lower(), s.upper(): ritornano una copia della stringa s con lettere minuscole, maiuscole
   s.count(substr): ritorna il numero di occorrenze della sottostringa substr in s
   s.find(substr): ritorna l'indice della prima occorrenza della sottostringa substr in s
   s.replace(sub1,sub2): rimpiazza le occorrenze della sottostringa sub1 con sub2 
   ‘;’.join([1,2,3]) = “1;2;3”
   '1+2+3+4+5'.split('+') = ['1', '2', '3', '4', '5'] in 
   Esempio:
   a = [1,2,3]; b = a; b[0] = 2; -> b è [2,2,3] a è [2,2,3] è stata modifica A
   a = [1,2,3]; b = a[:]; b[0] =2; -> b è [2,2,3] a è [1,2,3]
   B ORA E’ UNA LISTA DIVERSA E OPERARE SU DI ESSA NON MODIFICA A!
   ```

4. **Booleani (Booleans):** Python ha il tipo di dato `bool` che rappresenta i valori di verità: `True` o `False`. Ad esempio:

```python
valore_verità = True
```

5. **Lista (Lists):** Le liste sono raccolte ordinate di elementi che possono essere di diversi tipi di dati. Si definiscono con parentesi quadre `[]`. Ad esempio:
   
   ```python
   lista = [1, 2, "tre", 4.0]
   lista.append(oggetto): appende l'oggetto in fondo alla lista
   lista.insert(indice, oggetto): inserisce l'oggetto nella posizione indicata dall'indice
   lista.pop(indice): estrae l'oggetto in posizione indice dalla lista
   lista.pop(): estrae l'ultimo elemento della lista
   lista.sort(): ordina gli oggetti contenuti - modifica lista in-place!
   sorted(lista) non modifica la lista originale
   len(lista): ritorna il numero di elementi contenuti in una lista
   ```

6. **Tuple:** Le tuple sono simili alle liste ma sono immutabili, definite con parentesi tonde `()`. Ad esempio:
   
   ```python
   tupla = (1, 2, "tre")
   ```

7. **Dizionari (Dictionaries):** I dizionari rappresentano collezioni di coppie chiave-valore. Si definiscono con parentesi graffe `{}`. Ad esempio:
   
   ```python
   dizionario = {"chiave1": 10, "chiave2": "valore"} #dizionario di coppie key->value
   #è un'associazione chiave-valore di più elementi(simili alle HashMap in Java)
   #Chiavi sono uniche nel dizionario e possono essere qualsiasi oggetto
   a[‘uno’] = ‘one’ -> {‘uno’: ‘one’, ‘due’: 2}
   a[‘tre’] = 3 -> {‘uno’: ‘one’, ‘due’: 2, ‘tre’: 3}
   #metodi
   .keys(): restituisce una lista con tutte le chiavi contenute nel dictionary
   .values(): restituisce una lista con tutti i valori contenuti nel dictionary
   .items(): restituisce una lista di tuple (chiave, valore) della[chiave] : elimina la chiave e il valore dal dizionario
   .pop(chiave): elimina e restituisce il valore operatore in: ‘uno’ in a -> True se la chiave ‘uno’ è presente in a
   .has_key(chiave): True se la chiave è presente nel dizionario
   ```

8. **Insiemi (Sets):** Gli insiemi sono collezioni non ordinate di elementi unici. Si definiscono con parentesi graffe `{}`. Ad esempio:

```python
insieme = {1, 2, 3, 4}
- Non ordinato -> Non posso accedere tramite indice
- Non replicati -> Lo stesso oggetto sarà presente al massimo una volta
A cosa servono i set? 
Eliminare i duplicati (per esempio partendo da una lista)
Test di appartenenza, invece di scorrere una lista si può usare in
L’implementazione della ricerca su set è più efficiente che su una lista
Esempi:
- Disgiunzione: S1.isdisjoint(S2)
- Unione: S1.union(S2) (simbolo “|”)
- Intersezione: S1.intersection(S2) (simbolo “&”)
- Differenza: S1.difference(S2) (simbolo “-”)
```

9. **None:** Il tipo di dato `None` è utilizzato per rappresentare l'assenza di un valore e spesso è restituito da funzioni senza un valore di ritorno esplicito.

## Costrutti di base

###### Cicli

```python
while b < 10
        b=b+1
    else:
        b=100
```

```python
for a in elenco:                                | range(inizio, fine, intervallo) range(0,10,2) -> 0,2,4,6,8
        print(a)                                    | range(inizio, fine) range(0,5) -> 0,1,2,3,4
    else:                                        | range(fine) range(5) -> 0,1,2,3,4
        print(‘vuoto’)                            | a = [‘a’, ‘b’] OPP a = ‘ab’ OPP  a = (‘a’, ‘b’)
                                            | for i in a: print(i) -> a b
Esempi con comportamenti anomali
a = set([‘a’, ‘b’])    ->    for i in a: print(i) -> b a
a = {‘a’:1, ‘b’:2}    ->    for i in a: print(i) -> a b
a = ‘abc’         ->    for i in enumerate(a) -> (0,’a’) (1,’b’) (2,’c’)
            for i,o in enumerate(a) -> 0 1 2
Per essere utilizzato come elenco deve avere un metodo _iter_() , _next_()
Esempio per a = [1,2]
    i = a._iter() POI i._next_() -> 1 POI i._next_() -> 2 POI i._next_() -> Eccez. Stop
```

###### Condizionale

```python
If condizione
        codice
    elif condizione
        codice
    else:
        codice
```

###### Operazioni

- Comando break: Interrompe un ciclo for/while

- Comando continue: Salta all'iterazione for/while successiva

- Clausola else: Può essere inserita alla fine di un blocco relativo ad un ciclo

- Viene eseguita (una volta sola) se un ciclo termina le sue iterazioni o quando la condizione del ciclo è valutata False

- Non viene eseguita in caso di break

- Moduli esterni: import pandas as PADA |  a = PADA.DataFrame()

##### Funzione VS Metodo

Inestata nella classe e non inestata

###### Passaggio di argomenti nella funzione

```python
a =[1,2,3] 
funz(*a) = funz(1,2,3)

a = {a:1, b:2, c:3}
funzione(**a) equivale a funzione(a=1,b=2,c=3)

def flatten(l):
res = []
if not hasattr(l, '__iter__'):
return [l]
```

#### CONCETTi DI ORDINE SUPERIORE

###### CLOSURE

e’ il concetto che una funzione figlia innestata all’interno di una funzione madre puo utilizzare/accedere alle variabili della madre. riassunto: entità incapsulate per effetto della closure.
Anche se la funz Madre termina le variabili delle funz. figlie non muoiono

```python
def encaps():
    b = 2
    def local():
        c = 3 + b
```

###### LAMBDA -> lambda function OR funzione anonima

passare una funzione senza definirla in un altro punto del codice e si definisce cosi 
lambda arg:valore di ritorno -> funz(lambda x:x**2, [1,2,3])

###### GENERATORI

possono essere sia funzioni sia espressioni, utilizzati in un ciclo.

Ad ogni iterazioni invece di ritornare un solo valore ne ritorna una serie Esempio:

yield seguito dal valore da tornare dentro la funzione viene trattata come un generatore, impilicitamente viene usato dai metodi __iter__ e __next__

```python
def range(stop):
i = 0
while i < stop:
yield i
i = i + 1

for y in range(10) print(ciao) #scorre la funzione range(stop) e quando arriva a yield si interrompe l’esecuzione del while e si ritorna a y il suo contenuto ovvero i, poi esegue quello che c'è dentro al for e si riprende da dove si era interrotta nel while -> i=i+1

a = [x**2 for x in range(10)] -> a conterrà una lista dei quadrati da 0 a 9
```

### SCOPE

![](https://lh7-us.googleusercontent.com/W0z7RJsq-ZshOwocji2DgYFP0LiB_zhIlsWj3zKKetMZrk0xCFqfsZu9xF3TcEGlDeY6ZlnhG8PrNq6Wl7z2Wd5UzMHuQJDfOQETZ97koWJGcR8Oj7S1gtEU05Wq7B4cLE8ahbk69rbWtaSzykgLLhI)

```python
print(‘ciao’) #Built-in: entità pre-installata dal sistema 

a = 1 #Entità definite nel codice

def encaps(): #Entità incapsulate per effetto della closure
       b = 2
       def local():
             c = 3 + b

def another(): #Entità locali: definite dentro il blocco
        d = 0
```

Dal punto print posso vedere le variabili a,b,c ma non D. Per capirlo? Si inizia dal Entità: Local > Enclosed > Global > Built-in

Esempi per capire gli Scope: Qual e’ l’output?

```python
def fun(x):
      print(x)
      x = ‘ciao’
      print(x)
x = 5
fun(x) #la fun prende una “copia” di x
print(x)
OUTPUT: 5 ; ciao ; 5
```

```python
def fun(x):
      print(x)
      x.append(3) #Se si chiama append lo si chiama sullo stesso oggetto poiché tutte e due le x puntano al medesimo oggetto
      print(x)
x = [1,2]
fun(x)  #la fun prende il riferimento di x
print(x)
OUTPUT: 1,2  ; 1,2,3 ; 1,2,3
```

### GESTIONE DELLE ECCEZIONI

in run time quando c'è un'anomalia, tale errore viene associato ad una sottoclasse della classe madre 

In modo automatico: causate da istruzioni generiche esempio: divisione per zero

in modo Manuale: i programmatori sollevano eccezioni utilizzando throw o raise

```python
try:
           codice

except Classe_eccezione as identificativo:

           codice
```

### DECORATORI

Aggiugnono funzionalità ad una funzione, e semplificano il suo utilizzo.

Es: misurare il tempo di esecuzione di una funzione

```python
def time_function(function):
    def new_function(x): #se si vuole dare più variabili (args*, kwargs**):
    start = time.time()
    value = function(x)
    end = time.time()
    print ("ci ha messo ", end - start, " secondi")
    return value
return new_function #qui si attiva la funzione e si passa in automatico x
f = time_function(func)#gli passo prima la funzione
f(5)
@time_function #Si definisce una funzione che prenda come parametro una funzione e restituisca una funzione
def funcEsempio(x)
      time.sleep(random.random()*x+(y-z))

#funcEsempio  adesso sara la funzione restituita da time_function
```

Scrivere un decoratore che arricchisca una funzione come segue:

1) Oltre a ritornare il risultato della funzione stessa, lo stampa anche a video.
2) Prima di eseguire chiede all’utente se vuole modificare il parametro in
   ingresso (opzione non possibile se vi sono più parametri)

```python
def decoratore_modifica_parametro(func):
    def wrapper(*args, **kwargs):
        if len(args) == 1 and not kwargs:
            parametro = args[0]
            print(f"La funzione restituirà il risultato per il parametro: {parametro}")
            risposta = input("Vuoi modificare il parametro in ingresso? (Sì/No): ").strip().lower()
            if risposta == "si":
                nuovo_valore = input("Inserisci il nuovo valore per il parametro: ")
                args = (nuovo_valore,)
                print(f"Nuovo parametro: {nuovo_valore}")
        risultato = func(*args, **kwargs)
        print(f"Risultato della funzione: {risultato}")
        return risultato
    return wrapper

# Esempio di utilizzo del decoratore
@decoratore_modifica_parametro
def mia_funzione(parametro):
    return parametro * 2

valore = 5
risultato = mia_funzione(valore)
```

### CLASSI E OGGETTI

Ricordiamo che tutto e' un oggetto, non esistono tipi primitivi o funzioni che non siano oggetti.

Qual e' la differenza tra questi due?

- Classe: definisce variabili e metodi contenuti

- Oggetto: istanza di una classe

- Istanza di una classe: var = NomeClasse() #che chiama il costruttore

```python
#Esmpio di classe
class NomeClasse:
    i = 0 #attributo della classe, per utilizzarlo da un altra classe NomeClasse.i
    def metodo1(self,arg1,arg2)
```

# 

Se io faccio un progetto e lo voglio distrubuire, senza creare un ambiente virtuale, lui va acercare build nel path di sistema, 

se installo il build attraveso build dentro il venv lo vedo solo li, ma se lo faccio globalmente lo vedono tutti

## Gestione della memoria

Cosa succede sotto, se faccio  A =1?
Viene salvato in memoria, ma come e' organizzato.

A seconda del punto del prgramma essi vengono salvati in aree  differenti,

Cosa ritorna il malloc: un puntatore.

int a = 0

due zone di memoria:

- Heap: non so dove e' puntato

- Stack: uno sopra l'altro, memoria del programma inizia dal basso e sale verso l'alto, per recupare devo salire di un tot di righe.

La variabile viene salvata nello stack.

La gestione della memoria prima in C era manuale, si fanno sia le malloc che le free

Gestione automatica: la memoria aumenta in python? viene gestito tutto dal Garbage collector

che viene usato da Java,

Python usa sia il Referenc Counting che Garbage collector.

In python cosa succede?

a = 1

Viene creato un oggetto 1 poi viene puntato ad A

a = 2  #viene creato un oggetto 2 e poi SOSTITUISCE (ELIMANDO 1) il puntatotre di A

Si basa sulla irrangiugibilita sintattica.

Reference Counting: un approccio semplice

 viene allocato l'oggetto e il contatore(che segna il numero delle reference), se il puntatore ha referenza 0 libera la memoria.

Tiene traccia dei numeri dei referenti

memory leak

a = {'k',1}

b = {'k',a}

d = {'k',b}

a=1 b=1

Garbage collector,cose?

e' un entita che sta ferma e ogni tot viene chiamato per analizzare la memoria e decide cosa cancellare.

Si attiva ogni tot tempo o quando la memoria occupata raggiunge un limite (Python)

- Tracing: vedono qualsiasi oggetto e capiscono quali sono referenziati o meno, cancella quelli non raggiungibili
  Gli oggetti radici(dove parte), variabili globali, locali, o argomenti di funzioni.
  Parte il garbage collector e cerca ogni riferimento collegato.
  Non fa una scansione,  e' reattivo, ogni cosa che vede si attiva
  Markand Sweep

- Ogni oggetto raggiungibile viene targato con valore di raggiungibilita, flag =1 raggiungibile flag = 0, no.

- Si riscansiona tutto per ogni albero e si marchiano i flag, poi si fa un secondo ciclo lineare per cancellare i flag con 0
  
  

Tri-color Marking:algoritmo organizzato insiemi: 

white: canditatto alla rimozione, posso diventare pero raggiungibile , grey: raggiungibili, black:

Esempio

Fase 1 , tutti gli oggetti radici, venongo aggiunti nel Grey-Set.

Tutti gli oggetti radici vanno nel grey set gli altri nel white, il black alliniizio e' vuoto

Fase 2:

Prendo ogni oggetto dal grey set e li scannerizzo , cerco solo nei bianchi.

Quando ho vinito tutti i suoi discendenti il precedente nodo lo porto al Black.

Arrivo alla fine che tutti i grey sara vuoto, e ci saranno alcuni nodo nel white che sono possibili cancellarli

Rilascio memorio



- Garbage collector
  
  - Generational
    Gli oggetti piu vecchi e' piu probabili che rimangono vivi.
    Questi dividono gli oggetti per anzianita, ogni volta che is attivano controllano gli oggetti e vedono se si possono cancellare in base,
    Le genrazione piu giovani le controllero molto piu volte, invece quelli piu vecchi esempio la radice non cambiera mai e viene controllato infatti meno volte.
    Approccio molto veloce, perche analizzo solo il sotto insieme, il contro e' se un oggetto vecchio non e' piu raggiungibile lo controllo solamente molto dopo.
    Come si classifica:
    
    - Eden: appena creati
    
    - Survivor 2: sopravvissuto ad un certo numero di cicli
    
    - Suvivor 1: sopravive a molto piu ciclo
    
    - Old: oggetti piu vecchi
    
    Analizzo gli Eden, se hanno un oggetto referenziato sono sopravvisuti ad un ciclo, etc.. 
  
  - f
    
    

- Generali
  
  
  
  

Python approccio ibridi

Reference counting non attivo,

Generational garbage in cui la generazione Eden analizzo con piu frequenza, older meno frequenza

Si puo disabilitare il garbage collector e avere solo reference counting

Posso lanciare su una generazione specificia



Il sistema operativo mette a disposizione diversi strumenti ma non sono granulari: 

Libreria tracemalloc .



Come gestisce la memoria l' interprete di  Python?

a = 1, 

creo l'oggetto 1 in memoria, l'interprete se fa tanti a=1, dovrei fare tanti malloc quanti le a allocate.

Molto dispendioso, ecco perche si usano delle tecniche per minimizzare le malloc e le free.

l'interprete e' processo che  valuta il nostro programma, e concede un spazio virtuale (stack e heap) di memoria.  L'oggetto lo mettiamo dentro heap privato del python e poi l'Allocattore gestira poi la riduzione.

Un ciclo, ogni volta che incremento sto creando un nuovo intero, un nuovo free.
Troppa allocazione, ecc

Se mi serve di piu di heap python chiamo il so per fare la malloc.

Se l'oggetto e' troppo grande chiamo direttaente la malloc ma se l'oggetto ha un allocatore specifico ...

Heap privato come viene gestito, 
Arena : spazio privato contenente degli oggetti, quando creo un nuovo oggetto la inserisco nel arena piu piena, sia perche faccio piu facilemnte la free, non posso liberare la memoria.
Io ho bisogno di liberare un arena piu velocemente, in piu se ho tutti gli oggetti vicini, io ho probabilita che le posso portare in cache piu facilmente.

divisa in Pool: Ogni pool ha una dimensione contigua e la dimensione e' un file del sistema operativo, ogni pool e' diviso in piu blocchi, un blocco e' un oggetto,

ogni oggetto e' un blocco, di cui dimensioni fissa per ogni blocco.

se io ho un blocco da 4, nello stesso pool avro allinterno dei blocchi con stessa dimensione. quindi 4, se io ho un oggetto stringa di dimensione 10, il blocco 10 andra nel pool di blocco pool.

Se satura l'arena, io creo un altra arena.













### Debug

Esiste un modulo per dubuggare, faccio debuggher per il codice sorgente.

Modulo pdb > runnato con argomento una stringa di codice:

python3 -m pdb <program>, legge e apre un interprete mostranod i vari comandi:

h significa help

comandi che possiamo dare al debugger

w(here) ->stampa la traccia dello stacke,flusso delle funzioni/comandi effettuate

u(p) -> alzo lo scope, vedo di piu 

b (reak) nome file) -> posso mettere un break point ad una certa riga, si puo usare anche con la condizione,quando e' vero mi fermo.

cl(ear) 





09/01 Scritto Protoclli
12/01 Orale Protocolli
22/01 Fisica
23/01 Statistica
15/02 Architettura
20/02 Python Scritto
27/02 Python Orale



### File I/O

Cose un file? Astrazione della memoria qualsiasi tipo di memoria o dispotivi esempre una webcam viene vista come un file dal so.

Identifichiamo il file da path e nome. Come si apre un file in pyhthon?

Bisogna per forza chiudere il file, perche non scrive diretamenre nel file prima viene salvato in un buffer e poi dopo salva su hard disk

Leggo l'intero documento:

fd = open("miofile", "r" ) ci ritorna un descrittore, un riferimento che ci riferisce a quel file

fd = open("miofile", "r" )  scrivo nel file.fd.close. a -> append

L'istruzione with crea un contesto, uno scope con caraterisiche aggiugnitva

with fa delle istruzioni preliminari e 

with --- as v:  post operazioni e poi chiude il file automaticamente.



Scrivere dei byte nel file "miofile", "w"

Pickle, 

Salvare qualcosa di piu complesso si usa questo modulo, che serializza un oggetto



Compare le performance del C e del Python

cProfile modulo che serve per profilare parti di codice del esecuzione.

# Parsing argomenti

passare edgli argomenti in input ad un programma

./.a.out primo_arg secondo_arg

sys.argv abbiamo una lista importata in ingresso input

Primo argomento il nome del programma.

il modulo argparse che gestice molti aspetti.

arguments = parser.pares_args()





Prova Pratica
