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
