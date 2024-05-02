# Primo assignment

## LocalOpts.h

```c
#ifndef LLVM_TRANSFORMS_LOCALOPTS_H // Se la macro LLVM_TRANSFORMS_LOCALOPTS_H non è definita...
#define LLVM_TRANSFORMS_LOCALOPTS_H // ...definiscila

#include <llvm/IR/Constants.h> // Includi il file Constants.h dalla libreria LLVM
#include "llvm/IR/PassManager.h" // Includi il file PassManager.h dalla libreria LLVM

namespace llvm { // Definisci un namespace llvm

class LocalOpts : public PassInfoMixin<LocalOpts> { // Definisci una classe chiamata LocalOpts che eredita dalla classe PassInfoMixin
public: // Specifica che i membri successivi sono pubblici
        PreservedAnalyses run(Module &M, ModuleAnalysisManager &AM); // Definisci un metodo pubblico chiamato run
        // che prende un riferimento a un oggetto Module e un riferimento a un oggetto ModuleAnalysisManager
        // e restituisce PreservedAnalyses
};

} // Fine del namespace llvm

#endif // Fine della macro ifndef, se LLVM_TRANSFORMS_LOCALOPTS_H non è definito, questo blocco viene incluso

//Cose un namespace? sono raggrupamenti logici di tutti i simboli come classi,funzioni, variabili etc..
// esempio questa classe LocalOPts e' accessibile utilizzando il nome completo llvm:LocalOPts
// serve per evitare i conflitti
```

## LocalOpts.c

Con il codice .c passaggio di ottimizzazione della LLVM che cerca di migliorare il codice del prgrammma.

```c
// includiamo i file header dell a libreria LLVM
#include "llvm/Transforms/Utils/LocalOpts.h" // Includi il file di intestazione per le ottimizzazioni locali
#include "llvm/IR/InstrTypes.h" // Includi il file di intestazione per i tipi di istruzione
#include "llvm/IR/Instructions.h" // Includi il file di intestazione per le istruzioni LLVM
#include <llvm/IR/Constants.h> // Includi il file di intestazione per le costanti LLVM
// Dichiariamo l'uso del namespace llvm
using namespace llvm; // Usa il namespace llvm

// Funzione per l'ottimizzazione dell'identità algebrica
bool algebraicIdentity(Instruction &I, Instruction::BinaryOps toDoOperation) {
  int pos = 0; // Posizione dell'operando all'interno dell'istruzione

  // Iterazione attraverso gli operandi dell'istruzione
  for (auto operand = I.op_begin(); operand != I.op_end(); operand++, pos++) {
    ConstantInt *costante = dyn_cast<ConstantInt>(operand); // Tentativo di ottenere una costante intera dall'operando

    if (costante) {
      APInt value = costante->getValue(); // Ottenimento del valore della costante

      // Verifica se si tratta di un'identità algebrica e sostituisci se necessario
      if ((value.isZero() && toDoOperation == Instruction::Add) || (value.isOne() && toDoOperation == Instruction::Mul)) {
        I.replaceAllUsesWith(I.getOperand(!pos)); // Sostituisci tutte le occorrenze dell'istruzione con l'altro operando
        outs() << "Trovata Algebraic Identity\n  nell'istruzione " << I << "\n  c'è un" << value << " in posizione " << pos << "\n\n"; // Stampa un messaggio
        return true; // Ritorna true se viene trovata un'identità algebrica
      }
    }
  }
  return false; // Ritorna false se non viene trovata un'identità algebrica
}

// Funzione per la riduzione della forza
bool strengthReduction(Instruction &I, Instruction::BinaryOps toDoOperantion) {
  int pos = 0; // Posizione dell'operando all'interno dell'istruzione

  // Iterazione attraverso gli operandi dell'istruzione
  for (auto operand = I.op_begin(); operand != I.op_end(); operand++, pos++) {
    ConstantInt *costante = dyn_cast<ConstantInt>(operand); // Tentativo di ottenere una costante intera dall'operando

    if (costante) {
      APInt value = costante->getValue(); // Ottenimento del valore della costante

      // Verifica se la costante è una potenza di 2 e applica la riduzione della forza se necessario
      if (value.isPowerOf2()) {
        int shiftValue = costante->getValue().exactLogBase2(); // Calcolo del valore dello shift

        Instruction::BinaryOps instructionType;

        // Determinazione del tipo di operazione binaria da eseguire
        if (toDoOperantion == Instruction::Mul)
          instructionType = Instruction::Shl;
        else
          instructionType = Instruction::LShr;

        // Creazione dell'istruzione di shift e inserimento dopo l'istruzione corrente
        Instruction *shiftInst = BinaryOperator::Create(instructionType, I.getOperand(!pos), ConstantInt::get(costante->getType(), shiftValue));
        shiftInst->insertAfter(&I);

        // Sostituzione delle occorrenze dell'istruzione corrente con l'istruzione di shift
        I.replaceAllUsesWith(shiftInst);
        outs() << "Trovata Strength Reduction\n  Da: " << I << "\n  A: " << *shiftInst << "\n\n"; // Stampa un messaggio
        return true; // Ritorna true se viene eseguita la riduzione della forza
      }
    }
  }
  return false; // Ritorna false se non viene eseguita la riduzione della forza
}

// Funzione per la riduzione della forza avanzata
bool advancedStrengthReduction(Instruction &I) {
  int pos = 0; // Posizione dell'operando all'interno dell'istruzione

  // Iterazione attraverso gli operandi dell'istruzione
  for (auto operand = I.op_begin(); operand != I.op_end(); operand++, pos++) {

    ConstantInt *costante = dyn_cast<ConstantInt>(operand); // Tentativo di ottenere una costante intera dall'operando

    if (costante) {
      APInt value = costante->getValue(); // Ottenimento del valore della costante
      Instruction::BinaryOps operationType;
      int shiftValue = 0;

      // Verifica se la costante meno uno o più uno è una potenza di 2 e applica la riduzione della forza avanzata se necessario
      if ((value + 1).isPowerOf2()) {
        shiftValue = (value + 1).exactLogBase2();
        operationType = Instruction::Sub;
      } else if ((value - 1).isPowerOf2()) {
        shiftValue = (value - 1).exactLogBase2();
        operationType = Instruction::Add;
      } else
        continue;

      // Creazione dell'istruzione di shift e inserimento dopo l'istruzione corrente
      Instruction *shiftInst = BinaryOperator::Create(BinaryOperator::Shl, I.getOperand(!pos), ConstantInt::get(costante->getType(), shiftValue));
      Instruction *sumInst = BinaryOperator::Create(operationType, I.getOperand(!pos), shiftInst);

      shiftInst->insertAfter(&I);
      sumInst->insertAfter(shiftInst);

      // Sostituzione delle occorrenze dell'istruzione corrente con l'istruzione di shift e somma
      I.replaceAllUsesWith(sumInst);
      outs() << "Trovata AdvancedStrength Reduction\n  Da:  " << I << "\n  A:   " << *shiftInst << " e " << *sumInst << "\n\n"; // Stampa un messaggio
      return true; // Ritorna true se viene eseguita la riduzione della forza avanzata
    }
  }
  return false; // Ritorna false se non viene eseguita la riduzione della forza avanzata
}

// Funzione per l'ottimizzazione delle istruzioni multiple
bool multiInstruction(Instruction &I, Instruction::BinaryOps toDoOperation) {
  int pos = 0; // Posizione dell'operando all'interno dell'istruzione

  // Iterazione attraverso gli operandi dell'istruzione
  for (auto opUser = I.op_begin(); opUser
```

## PassRegistry.def

MODULE_PASS("localopts", LocalOpts())

## Foo.optimized

un modulo LLVM ottimizzato e' stato generato a partire da .LL

Ogni riga di codice corrisponde a un 'istruzione LLVM che esegue una determinata operazione.

```llvm
; ModuleID = 'Foo.optimized.bc'   ; Identificatore univoco del modulo
source_filename = "Foo.ll"        ; Nome del file di origine

define dso_local i32 @foo(i32 noundef %0, i32 noundef %1) {   ; Definizione della funzione 'foo' che restituisce un intero 32-bit
  %3 = add nsw i32 %1, 1          ; Istruzione di aggiunta con segno, no-wrap
  %4 = mul nsw i32 %3, 2          ; Istruzione di moltiplicazione con segno, no-wrap
  %5 = shl i32 %3, 1              ; Istruzione di shift logico a sinistra
  %6 = shl i32 %0, 1              ; Istruzione di shift logico a sinistra
  %7 = sdiv i32 %6, 4             ; Istruzione di divisione con segno
  %8 = lshr i32 %6, 2             ; Istruzione di shift logico a destra
  %9 = mul nsw i32 %5, %8         ; Istruzione di moltiplicazione con segno, no-wrap
  %10 = add nsw i32 %0, 1         ; Istruzione di aggiunta con segno, no-wrap
  %11 = sub nsw i32 %10, 1        ; Istruzione di sottrazione con segno, no-wrap
  %12 = add nsw i32 %1, 0         ; Istruzione di aggiunta con segno, no-wrap
  %13 = mul nsw i32 %1, 15        ; Istruzione di moltiplicazione con segno, no-wrap
  %14 = shl i32 %1, 4             ; Istruzione di shift logico a sinistra
  %15 = sub i32 %1, %14           ; Istruzione di sottrazione
  ret i32 %9                      ; Istruzione di ritorno
}
```

## Foo.ll

Questo codice definisce una funzione LLVM chiamata foo che prende due parametri di tipo 'i32' e restituisce un valore intero a 32 bit.

```llvm
define dso_local i32 @foo(i32 noundef %0, i32 noundef %1) #0 {   ; Definizione della funzione 'foo' che restituisce un intero 32-bit
  %3 = add nsw i32 %1, 1          ; Istruzione di aggiunta con segno, no-wrap
  %4 = mul nsw i32 %3, 2          ; Istruzione di moltiplicazione con segno, no-wrap
  %5 = shl i32 %0, 1              ; Istruzione di shift logico a sinistra
  %6 = sdiv i32 %5, 4             ; Istruzione di divisione con segno
  %7 = mul nsw i32 %4, %6         ; Istruzione di moltiplicazione con segno, no-wrap
  %8 = add nsw i32 %0, 1         ; Istruzione di aggiunta con segno, no-wrap
  %9 = sub nsw i32 %8, 1        ; Istruzione di sottrazione con segno, no-wrap
  %10 = add nsw i32 %1, 0         ; Istruzione di aggiunta con segno, no-wrap
  %11 = mul nsw i32 %10, 15        ; Istruzione di moltiplicazione con segno, no-wrap
  ret i32 %7                      ; Istruzione di ritorno
}
```
