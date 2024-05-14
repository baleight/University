> differenza cache associativa e direct mapped
> punti di forza e debolezza fully associative
> modificato
> cosa rende diverse due cache diverse a parità della dimensione di linea
> la località spaziale è sfruttata allo stesso modo quando una cache fully associative è meglio rispetto a una direct mapped?
> floating point unit
> **isa come facciamo a supportare una floating point unit? (quello che vede il programmatore) operazioni separate, registri separati modificato**
> scrivere una funzione di array di float che ha un contatore
> forma canonica
> differenza tra forma canonica e forma minima
> funzione somma che prende in ingresso un array di interi e ritorna la somma degli elementi 99 Blelia funzione somma che prende in ingresso un array di inte... chiamare dal main
> e il main ritorna 1 se il valore ritornato dalla funzione è maggiore di 0
> 0 se somma è 0
> n sul segmento dati insieme all'array modificato 
> del file elf 
> cos'è la memoria virtuale
> a cosa serve
> AS e perché si usano le pagine
> cache mi sa direct mapped con cold cache/hit/conflict miss
> esercizio d'esame
> funzione ingresso array di interi e num count
> ritorna somma elementi 

L'ISA (Instruction Set Architecture) di un calcolatore può supportare una Floating Point Unit (FPU) attraverso una serie di istruzioni specializzate e regole di gestione che consentono al processore di eseguire operazioni in virgola mobile in modo efficiente.

Ecco alcuni dei modi in cui un ISA può supportare una FPU:

1. **Istruzioni dedicate**: L'ISA può includere istruzioni specifiche progettate per operazioni in virgola mobile, come somma, sottrazione, moltiplicazione, divisione, radice quadrata, conversioni tra formati di dati, ecc. Queste istruzioni possono operare direttamente sui registri della FPU.

2. **Registri specializzati**: L'ISA può includere registri specializzati per l'archiviazione di dati in virgola mobile. Questi registri possono essere utilizzati esclusivamente per operazioni in virgola mobile e possono essere di dimensioni maggiori rispetto ai registri interi.

3. **Gestione delle eccezioni**: L'ISA deve definire regole per la gestione delle eccezioni in virgola mobile, ad esempio overflow, underflow, divisione per zero, ecc. Queste eccezioni devono essere segnalate in modo appropriato e gestite correttamente dal processore.

4. **Formati di dati**: L'ISA deve specificare i formati di dati in virgola mobile supportati, come il formato IEEE 754, che definisce la rappresentazione binaria per numeri in virgola mobile e le regole per operazioni aritmetiche su di essi.

5. **Istruzioni di caricamento e memorizzazione**: L'ISA deve includere istruzioni per il caricamento e la memorizzazione di dati in virgola mobile dalla memoria principale alla FPU e viceversa.

6. **Interazione con le istruzioni intere**: L'ISA deve definire come le istruzioni in virgola mobile interagiscono con le istruzioni intere. Ad esempio, possono essere necessarie istruzioni di conversione per convertire dati da interi a virgola mobile e viceversa.

Questi sono solo alcuni degli aspetti di come un ISA può supportare una FPU. In generale, l'obiettivo è garantire che le operazioni in virgola mobile possano essere eseguite in modo efficiente e affidabile sul processore.