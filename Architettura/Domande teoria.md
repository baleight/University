# Domande teoria

#### Link utili

- [algo.ing.unimo.it](http://algo.ing.unimo.it/people/andrea/Didattica/Architetture/index.html)
- [wikichip.org](https://en.wikichip.org/wiki/risc-v)
- [en.wikiversity.org](https://en.wikiversity.org/wiki/Computer_architecture)
- 

#### Cose assembly?

 linguaggio binario tradotto in un formato capibile da un umano. Siamo al
livello più basso di linguaggio che un umano può gestire; sotto troviamo direttamente il
codice binario.

#### Quali sono i passaggi di conversione?

Il compilatore ha il ruolo di tradurre il linguaggio ad alto livello in assembly, L'assembler prende in ingresso un programma scritto in assembly e lo traduce in binario

Cose un ISA?

instruction set: repertorio di istruzioni che la macchina mette a disposizione del
compilatore. Ci sono instruction set semplici e complicati; i vecchi computer ne avevano
di semplici. Molti computer quotidiani hanno IS semplici

#### RiscV e Cisc?

Il RISC-V (Reduced Instruction Set Computer) è caratterizzato da un set di istruzioni ridotto, essenziale e semplice. È diventato popolare perché è una ISA "gratis" e aperta, permettendo l'integrazione in vari dispositivi. Inoltre, offre una licenza di microprocessore che consente di creare circuiti integrati. I processori RISC hanno circuiti dedicati per le poche istruzioni che possono eseguire, rendendo l'implementazione più semplice e meno costosa.

D'altro canto, i processori CISC (Complex Instruction Set Computer) utilizzati ancora oggi da Intel, presentano un set di istruzioni più ampio e complesso, con circuiti più complessi e micro-programmati. Questo permette di scrivere programmi più complessi in modo più semplice, ma richiede un hardware più elaborato e trasistori aggiuntivi per implementarlo. Le istruzioni load e store sono integrate in altre operazioni nei processori CISC. **In sintesi, mentre il RISC-V si concentra su un hardware più semplice e istruzioni load e store esplicite, il CISC offre istruzioni più complesse per una programmazione più agevole, a costo di un hardware più elaborato.**

#### Cosa ce nella CPU?

La CPU, o Unità Centrale di Elaborazione, è il cuore di un computer ed è composta da diversi componenti chiave. 

1. **ALU (Arithmetic Logic Unit)**: È responsabile dell'esecuzione delle operazioni aritmetiche (come l'addizione, la sottrazione, la moltiplicazione e la divisione) e delle operazioni logiche (come AND, OR, NOT) sui dati.

2. **Blocco di Registri**: Questo è un insieme di registri ad alta velocità che memorizzano temporaneamente i dati che la CPU sta elaborando. I registri possono includere registri generali, registri di indirizzo, registri di stato, e altri.

3. **Program Counter (PC)**: È un registro speciale che contiene l'indirizzo di memoria della prossima istruzione da eseguire. In pratica, funziona come un puntatore all'istruzione successiva nel programma.

4. **Memoria Istruzioni e Memoria Dati**: La memoria istruzioni contiene il codice delle istruzioni del programma che la CPU deve eseguire, mentre la memoria dati contiene i dati su cui la CPU deve operare. Nella maggior parte dei casi, le memorie sono realizzate utilizzando la tecnologia DRAM (Dynamic Random Access Memory).

Nel contesto di un'architettura RISC (Reduced Instruction Set Computer), il flusso di lavoro per l'elaborazione dei dati è tipicamente il seguente: 

1. **Caricamento dei dati nei registri**: Prima di eseguire un'operazione, i dati necessari vengono caricati nei registri dalla memoria dati.
2. **Esecuzione dell'operazione sull'ALU**: Una volta che i dati sono nei registri, l'ALU esegue l'operazione richiesta.
3. **Rimessa dei risultati nei registri**: Dopo aver eseguito l'operazione, i risultati vengono rimessi nei registri.
4. **Salvataggio dei dati nella memoria**: Infine, i risultati possono essere salvati nella memoria dati se necessario.

#### I registri di RiscV?

I registri sono come i depositi della CPU, spazi di memoria molto veloci utilizzati per contenere dati temporanei, indirizzi di memoria, valori di ritorno da funzioni e altro ancora. In RISC-V, ci sono 32 registri principali, ciascuno di 64 bit. Questo significa che possono contenere valori di lunghezza massima di 64 bit, ovvero 8 byte.

In generale, l'utilizzo dei registri è fondamentale per il funzionamento efficiente di un programma, poiché l'accesso ai dati nei registri è molto più veloce rispetto all'accesso alla memoria principale. Tuttavia, poiché ci sono un numero limitato di registri disponibili, è importante utilizzarli in modo efficiente e pianificare come verranno utilizzati durante l'esecuzione del programma.

Ecco una panoramica dei registri RISC-V più importanti:

- **x0**: È vincolato a mantenere costantemente il valore 0.
- **x1**: Utilizzato come registro per l'indirizzo di ritorno dalle funzioni.
- **x2**: Puntatore dello stack, utilizzato per tenere traccia dello stack.
- **x3**: Puntatore globale, utilizzato per accedere alle variabili globali.
- **x4**: Puntatore al thread, utilizzato per l'accesso a variabili specifiche del thread.
- **x5 - x7, x28 - x31**: Registri temporanei utilizzati per memorizzare dati temporanei durante l'esecuzione del programma.
- **x8**: Puntatore al frame, utilizzato per tenere traccia dello stack frame durante l'esecuzione delle funzioni.
- **x9, x18 - x27**: Registri salvati utilizzati per salvare valori importanti durante l'esecuzione di una funzione.
- **x10 - x11**: Utilizzati per contenere gli argomenti e i risultati delle funzioni.
- **x12 - x17**: Altri registri utilizzati per contenere argomenti aggiuntivi delle funzioni.

Per quanto riguarda il lavoro con strutture dati più complesse come gli array, si utilizza la memoria principale e si tengono nei registri solo i pezzi della struttura dati su cui si sta lavorando. Questo significa che prima di eseguire un'operazione su un array, è necessario caricare i dati pertinenti dalla memoria principale nei registri, eseguire l'operazione e poi eventualmente salvare i risultati nella memoria principale.

Per esempio, se si desidera lavorare con un array, si caricheranno i dati dell'array dai registri o dalla memoria principale nei registri, si eseguirà l'operazione desiderata (ad esempio, somma, sottrazione, moltiplicazione, divisione, ecc.) utilizzando l'ALU e altri componenti della CPU, e infine si salveranno eventualmente i risultati nella memoria principale. Questo processo coinvolge tipicamente le istruzioni di load (caricamento) e store (salvataggio) per trasferire i dati tra la memoria principale e i registri della CPU.

Per quanto riguarda la rappresentazione dei dati, RISC-V utilizza l'architettura little endian, dove il byte meno significativo di una parola di memoria è memorizzato all'indirizzo di memoria più basso. Inoltre, anche se l'architettura RISC-V è a 32 bit, si utilizza una parola da 1 byte. Se si desidera leggere porzioni più piccole di un byte, è necessario utilizzare operazioni di shift per accedere ai dati appropriati.

Infine, per eseguire operazioni con operandi costanti, si utilizzano le istruzioni con operando immediato, indicate aggiungendo una "i" alla fine del nome dell'istruzione (ad esempio, add → addi). Queste istruzioni sono ottimizzate per l'utilizzo di valori costanti, evitando la necessità di caricare costantemente i valori dalla memoria principale.

#### Altro dei registri:

I registri del RISC-V sono divisi in tre categorie principali: i registri di proprietà del chiamante, i registri di proprietà del chiamato e gli altri registri.

##### Registri di Proprietà del Chiamante

I registri di proprietà del chiamante sono quelli che non devono essere sovrascritti quando viene chiamata una funzione, oppure se vengono sovrascritti, devono essere ripristinati prima che la funzione restituisca. Questi sono:

- **s1..s11**: Registri salvati (Saved registers), che possono essere utilizzati per qualsiasi scopo.
- **sp**: Puntatore allo Stack (Stack Pointer), che punta al primo indirizzo dello stack disponibile per la scrittura. Viene decrementato quando si aggiunge qualcosa allo stack.
- **fp**: Puntatore al Frame (Frame Pointer), che punta all'inizio dello stack.

##### Registri di Proprietà del Chiamato

I registri di proprietà del chiamato possono essere sovrascritti quando viene chiamata una funzione, quindi devono essere salvati in memoria prima di chiamare la funzione. Questi sono:

- **t0..t6**: Registri temporanei (Temporary registers), che possono essere utilizzati per qualsiasi scopo.
- **ra**: Indirizzo di ritorno (Return Address), che indica l'indirizzo a cui continuare l'esecuzione del programma dopo aver terminato una funzione. Solitamente utilizzato con le istruzioni `jal` e `jalr`.
- **a0..a7**: Argomenti della funzione (Function Arguments), che contengono gli argomenti passati alla funzione se si trovano all'interno di essa. Se si trovano all'esterno di una funzione, contengono i valori restituiti dall'ultima funzione chiamata.

##### Altri Registri

- **zero**: Registro Zero, che ha sempre il valore 0 e non può essere modificato.
- **gp**: Puntatore Globale (Global Pointer), che punta a un indirizzo specifico.
- **tp**: Puntatore al Thread (Thread Pointer), che punta al thread-local storage.
- **pc**: Contatore di Programma (Program Counter), che indica l'indirizzo dell'istruzione correntemente in esecuzione.

#### Instruction vs Cache data? Perche e' piu facile da progettare l'instruction cache

Instruction cache ha miglior localita, sono tutti vicini i registri 

Istruzioni e dati, che proprieta devono avere? con la memoria istruzioni e; piu semplice perche devo solo leggere non scriverle come nella cache dati.

Instruction memory e cache dati sono due tipi di memoria utilizzati nella CPU per memorizzare dati diversi e hanno caratteristiche e funzioni differenti.

1. **Instruction Memory**: Questa memoria contiene le istruzioni del programma che la CPU deve eseguire. Le istruzioni sono rappresentate da sequenze di bit (0 e 1) e vengono lette dalla memoria istruzioni e decodificate dalla CPU per essere eseguite. L'Instruction Memory può essere implementata all'interno della DRAM, ma poiché le istruzioni sono lette frequentemente dalla CPU, si utilizzano spesso meccanismi di cache per ridurre i tempi di accesso e migliorare le prestazioni complessive del sistema.

2. **Cache Dati**: Questa memoria è utilizzata per memorizzare i dati su cui la CPU deve operare durante l'esecuzione del programma. Ad esempio, può contenere variabili, array, strutture dati e così via. La cache dati funziona in modo simile alla cache istruzioni, ma memorizza dati anziché istruzioni.

Progettare una cache istruzioni è generalmente considerato più semplice rispetto alla progettazione di una cache dati per diverse ragioni:

- **Accessi solo in lettura**: La memoria istruzioni viene solo letta dalla CPU durante l'esecuzione del programma, mentre la cache dati può essere sia letta che scritta. Questo significa che non ci sono operazioni di scrittura da gestire nella cache istruzioni, semplificando il suo design.

- **Accessi sequenziali**: Le istruzioni vengono solitamente eseguite in sequenza durante l'esecuzione del programma, quindi è possibile sfruttare la località temporale e spaziale per migliorare l'efficienza della cache istruzioni. Questo comporta una gestione più semplice della sostituzione delle righe della cache e dell'organizzazione dei dati.

- **Dimensioni più piccole**: La cache istruzioni tende ad essere più piccola rispetto alla cache dati, in quanto deve memorizzare solo le istruzioni del <mark>programma attualmente in esecuzione.</mark> Questo riduce la complessità del design e dei circuiti necessari per gestire la cache.

Quanto alla necessità di avere una gerarchia di cache anche tra il PC e la cache istruzioni, ciò dipende dalle specifiche esigenze e architetture del processore. In alcuni casi, una singola cache istruzioni potrebbe essere sufficiente, mentre in altri casi una gerarchia di cache può migliorare ulteriormente le prestazioni del sistema riducendo i tempi di accesso alla memoria istruzioni. Questo dipende da fattori come la dimensione della cache, la frequenza con cui vengono eseguite nuove istruzioni e la complessità dell'architettura del processore. In generale, l'utilizzo di una gerarchia di cache consente di ridurre i tempi di accesso alla memoria istruzioni e migliorare le prestazioni complessive della CPU.

#### il PC normalmente è incrementato ogni 4 perchè?

Perchè 4 sono byte e noi lavoriamo su un architettura a 32 bit → le istruzioni
sono a 32 bit → saltare da un istruzione alla prossima significa saltare di
32 bit → di solito c'è un contatore a cui viene sommato 4

#### Cose il fetch?

In poche parole prendere 32 bit dalla memoria eportarli dentro per poi processarli ovvere fase di **Encoding.**

Il fetch per l'architettura RISC-V è il processo attraverso il quale la CPU ottiene l'istruzione successiva da eseguire dalla memoria istruzioni. In RISC-V, il fetch è relativamente semplice e coinvolge la lettura di 32 bit (4 byte) dalla memoria istruzioni.

Ecco una panoramica del processo di fetch per RISC-V:

1. **Incremento del Program Counter (PC)**: Il PC è un registro speciale che contiene l'indirizzo di memoria dell'istruzione successiva da eseguire. Prima del fetch, il PC viene incrementato per puntare all'indirizzo dell'istruzione successiva.

2. **Accesso alla memoria istruzioni**: La CPU accede alla memoria istruzioni utilizzando l'indirizzo contenuto nel PC per ottenere i 32 bit corrispondenti all'istruzione successiva.

3. **Lettura dell'istruzione**: I 32 bit letti dalla memoria istruzioni vengono caricati nella CPU e interpretati come un'istruzione da eseguire. Questo processo coinvolge la decodifica dell'istruzione per comprendere quale operazione deve essere eseguita e su quali dati.

4. **Esecuzione dell'istruzione**: Una volta letta e decodificata, l'istruzione viene eseguita dalla CPU. Questo può coinvolgere l'accesso ai registri, l'esecuzione di operazioni aritmetiche o logiche sull'ALU, il recupero di dati dalla memoria dati, e così via.

5. **Ripetizione del ciclo**: Dopo l'esecuzione dell'istruzione corrente, il ciclo riprende con un nuovo fetch per ottenere l'istruzione successiva da eseguire, e il processo continua fino alla fine del programma.

In breve, il fetch per RISC-V coinvolge l'accesso alla memoria istruzioni, il recupero di 32 bit corrispondenti all'istruzione successiva e la preparazione di questi dati per l'esecuzione da parte della CPU.

#### Tipi di istruzioni del RiscV? Come le processo, fase di Encoding

Esempio Add e' di tipo R, Una istruzione load  esempio ld rd, offset(rx) dove rd e rx sono dei tipi registri mentre l'offset e' un immediato.

Nell'architettura RISC-V, le istruzioni sono suddivise in diversi tipi principali, ognuno dei quali ha un formato specifico e un insieme di funzioni associate. Ecco una panoramica dei tipi di istruzioni più comuni:

1. **R (Register)**: Queste istruzioni coinvolgono operazioni aritmetiche eseguite solo su registri. Ad esempio, add (addizione), sub (sottrazione), and (AND logico), or (OR logico), xor (XOR logico), e molti altri.

2. **I (Immediate)**: Queste istruzioni coinvolgono operazioni aritmetiche in cui uno degli operandi è un valore immediato, ovvero un valore costante incorporato nell'istruzione stessa. Possono anche includere operazioni di caricamento (load) in cui l'offset è un valore immediato. Esempi di istruzioni I includono addi (addizione con immediato), subi (sottrazione con immediato), lw (load word), sw (store word), e così via.

3. **S (Store)**: Queste istruzioni sono utilizzate per memorizzare dati dalla CPU nella memoria dati. Ad esempio, sw (store word) memorizza il contenuto di un registro in una posizione di memoria specificata.

4. **SB (Branch)**: Queste istruzioni sono utilizzate per eseguire salti condizionali basati sul risultato di un'operazione precedente. Ad esempio, beq (branch if equal) salta all'indirizzo specificato se due registri sono uguali.

5. **UJ (Jump)**: Queste istruzioni sono utilizzate per eseguire salti incondizionati, spesso utilizzati per implementare salti a lungo raggio all'interno del programma. Ad esempio, jal (jump and link) salta a un'etichetta specificata e salva l'indirizzo di ritorno nel registro specificato.

6. **U (Upper Immediate)**: Queste istruzioni sono utilizzate per operazioni che coinvolgono valori immediati più ampi rispetto a quelli supportati dalle istruzioni I. Ad esempio, lui (load upper immediate) carica una costante nei bit più significativi di un registro.

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-30-10-03-19-image.png)

### 1.Formato specifici del tipo R?<img src="file:///C:/Users/baleo/Pictures/GitUni/imagesMarkText/2024-04-30-12-28-48-image.png" title="" alt="" width="152">

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-30-12-26-11-image.png)

servono per speicificare un insieme di operandi e funzioni associate, che possono essere utilizzati per eseguire una vasta gamma di operazioni all'interno di un programma.

Nel formato dell'istruzione RISC-V, i campi delle istruzioni R sono progettati per consentire alla CPU di decodificare correttamente l'istruzione e eseguire l'operazione corrispondente. Ecco una spiegazione dei principali campi dell'istruzione R:

1. **Opcode (7 bit)**: Questo campo identifica la famiglia generale di istruzioni a cui appartiene l'istruzione. Gli ultimi 7 bit dell'istruzione rappresentano l'opcode e forniscono informazioni di base sulla tipologia di operazione da eseguire.

2. **funct3 (3 bit)**: Questo campo viene utilizzato per specificare l'istruzione all'interno della famiglia identificata dall'opcode. Ad esempio, per le istruzioni aritmetiche, il campo funct3 può indicare l'operazione specifica come addizione, sottrazione, AND logico, XOR logico, ecc.

3. **funct7 (7 bit)**: Questo campo è utilizzato principalmente per istruzioni aritmetiche estese che richiedono operandi di 64 bit. Ad esempio, nell'istruzione RISC-V per l'addizione con operandi di 64 bit (ad esempio add), il campo funct7 può specificare l'operazione esatta.

4. **rd (5 bit)**: Questo campo identifica il registro di destinazione dove il risultato dell'operazione sarà memorizzato. Poiché RISC-V supporta fino a 32 registri (da x0 a x31), è necessario un campo di 5 bit per rappresentare tutti i registri disponibili.

Quando la CPU esegue il fetch di un'istruzione dalla memoria, legge i campi dell'istruzione per determinare il tipo di operazione da eseguire e quali registri saranno coinvolti nell'operazione. Questa decodifica consente alla CPU di eseguire l'istruzione corretta e di instradare correttamente i dati attraverso il percorso di esecuzione.

L'istruzione viene inizialmente codificata in binario e può essere visualizzata in esadecimale per una rappresentazione più compatta e conveniente, specialmente quando si lavora con molte istruzioni. L'esadecimale è una base numerica che utilizza 16 cifre (0-9 e A-F), che corrispondono a sequenze di 4 bit in binario, facilitando la memorizzazione e la visualizzazione dei valori binari.

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-30-10-04-32-image.png)

#### Quale la cosa in comune per tutti formati?

OPCODE, quando faccio una fetch prendo gli ultimi 7 bit e sono in grado di capire in che posizione devo andare a recuperare l'informazione

#### Come funziona OPCODE? (non si devono imparare, te li da lui)

L'ordine del bit e il loro significa identificano una famiglia un insieme di istruzioni.

Nel caso add condivido funct3 e opcode quindi bisogna andare sul campo funct7

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-30-10-06-58-image.png)

### 2.Formato specifici del tipo I?<img src="file:///C:/Users/baleo/Pictures/GitUni/imagesMarkText/2024-04-30-12-28-22-image.png" title="" alt="" width="149">![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-30-12-25-49-image.png)

Il formato Immediate delle istruzioni in RISC-V è progettato per consentire l'utilizzo di operandi immediati, cioè valori costanti incorporati direttamente nell'istruzione stessa. Ecco una spiegazione dei principali campi del formato Immediate:

1. **Opcode (7 bit)**: Come nei formati precedenti, l'opcode identifica la famiglia di istruzioni a cui appartiene l'istruzione.

2. **rd (5 bit)**: Questo campo identifica il registro di destinazione dove il risultato dell'operazione sarà memorizzato. Nei formati R e I, i primi 5 bit dopo l'opcode rappresentano il registro di destinazione.

3. **funct3 (3 bit)**: Nei formati I, il campo funct3 è utilizzato per specificare il tipo di operazione o l'istruzione all'interno della famiglia identificata dall'opcode.

4. **rs1 (5 bit)**: Questo campo identifica il registro sorgente 1, ovvero il registro da cui verrà letto il primo operando per l'operazione immediata.

5. **imm (12 bit)**: Il campo immediato contiene il valore costante o l'offset che verrà utilizzato nell'operazione immediata. È qui che risiede il valore immediato, che può essere un numero in complemento a 2.

La confusione riguardante i 12 bit per il campo immediato è legata al fatto che in alcune istruzioni, come le istruzioni di tipo I, solo 12 bit sono effettivamente dedicati all'imm, mentre in realtà è comune trovarne solo 8. Questo perché RISC-V utilizza il concetto di "sign extension" per estendere un valore a 8 bit a un valore a 12 bit, quando necessario.

#### Cose il concetto di "sign extension"? Riempiri i biti rimanenti , estendere il bit più significativo a raggiungere i 12 bit

La "sign extension" è una tecnica utilizzata per estendere un valore a bit più corto a una lunghezza maggiore, mantenendo intatto il suo valore numerico e il suo segno. Questa tecnica è comunemente utilizzata nei sistemi in complemento a due, come nel caso delle architetture RISC-V.

Ecco come funziona la sign extension:

1. **Valore positivo**: Se il valore originale è positivo, vengono aggiunti bit di estensione a sinistra, tutti impostati su 0. Questo garantisce che il valore numerico non cambi e che il segno rimanga positivo.

2. **Valore negativo**: Se il valore originale è negativo, vengono aggiunti bit di estensione a sinistra, tutti impostati su 1. Questo mantiene il valore numerico corretto in complemento a due e preserva il segno negativo.

Ad esempio, se abbiamo un valore immediato a 8 bit come 1111 1111 (che rappresenta -1 in complemento a due), la sua estensione a 12 bit utilizzando la sign extension sarebbe 1111 1111 1111. Questo mantiene il valore -1 e il suo segno negativo.

Per quanto riguarda il campo immediato della istruzione beq (branch if equal), viene shiftato a sinistra di 1 bit perché gli indirizzi di memoria devono essere multipli di 2. Questo significa che il bit meno significativo dell'indirizzo è sempre 0. Quindi, aggiungendo uno 0 a sinistra dell'immediato, si garantisce che l'indirizzo di destinazione del salto sia sempre allineato correttamente.

Infine, mantenere l'opcode sempre negli ultimi 7 bit dell'istruzione, come nei formati RISC-V, aiuta a semplificare la logica del decodificatore dell'istruzione e la progettazione complessiva del processore, consentendo il riutilizzo della stessa logica per diverse famiglie di istruzioni. Esempio:

1. **+2**:
   
   - Valore a 8 bit: 0000 0010
   - Per estendere a 16 bit, aggiungiamo 8 bit di estensione a sinistra, impostati tutti su 0.
   - Sign extension: 0000 0000 0000 0010

2. **-2**:
   
   - Valore a 8 bit: 1111 1110
   - Per estendere a 16 bit, aggiungiamo 8 bit di estensione a sinistra, impostati tutti su 1.
   - Sign extension: 1111 1111 1111 1110

Questi esempi dimostrano come la tecnica della sign extension mantenga intatto il valore numerico e il segno del valore originale quando viene esteso a una lunghezza maggiore.lizzo della stessa logica per diverse famiglie di istruzioni.

### 3.Formato specifici del tipo S?<img title="" src="file:///C:/Users/baleo/Pictures/GitUni/imagesMarkText/2024-04-30-12-27-38-image.png" alt="" width="112" data-align="inline">

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-30-12-27-23-image.png)

L'istruzione di memorizzazione (store) nel formato del RISC-V è progettata per consentire il trasferimento di dati dalla CPU alla memoria principale (DRAM). Ecco una spiegazione dei suoi componenti:

```
sd x9, 64(x22)
```

- **sd**: Questo è l'opcode specifico per l'istruzione di memorizzazione.

- **x9**: Questo è il numero del registro sorgente, da cui verrà letto il dato da memorizzare nella memoria principale.

- **64**: Questo è l'offset, ovvero l'aggiunta al registro di base (x22) per calcolare l'indirizzo di memoria effettivo in cui memorizzare i dati. In questo caso, l'offset è 64.

- **x22**: Questo è il registro di base, che contiene l'indirizzo base della memoria principale in cui verranno memorizzati i dati.

Quindi, l'istruzione `sd x9, 64(x22)` indica che il valore contenuto nel registro `x9` deve essere memorizzato nella memoria principale all'indirizzo dato dalla somma dell'indirizzo base `x22` e l'offset `64`.

La differenza principale tra un'istruzione di memorizzazione e un'istruzione di caricamento è che nella memorizzazione non è necessario specificare un registro di destinazione perché il dato viene scritto direttamente nella memoria principale. L'opcode (`sd` nel nostro caso) e i registri sorgente (`x9` e `x22`) sono utilizzati per determinare quali dati memorizzare e dove memorizzarli.

#### Cosa ha di differente il formato store con il load, significato sintattico?

La differenza sta nel dove, mi serve il registro di destinazione nella load che nella store non ce.

1. **Load (caricamento)**:
   
   - L'istruzione di caricamento (load) viene utilizzata per trasferire dati dalla memoria principale (RAM) ai registri della CPU. 
   - Richiede un registro di destinazione dove memorizzare il dato letto dalla memoria.
   - Ad esempio, l'istruzione lw (load word) legge un valore da una posizione di memoria specificata e lo carica in un registro della CPU.

2. **Store (memorizzazione)**:
   
   - L'istruzione di memorizzazione (store) viene utilizzata per trasferire dati dai registri della CPU alla memoria principale (RAM).
   - Non richiede un registro di destinazione, poiché il suo scopo è quello di scrivere il dato presente in un registro specifico direttamente nella memoria.
   - Ad esempio, l'istruzione sw (store word) prende un valore da un registro della CPU e lo scrive in una posizione di memoria specificata.

Quindi, mentre entrambe le istruzioni coinvolgono l'accesso alla memoria, la differenza fondamentale sta nel fatto che load porta i dati dalla memoria ai registri della CPU, mentre store sposta i dati dai registri della CPU alla memoria. Questa distinzione è fondamentale per la gestione e la manipolazione dei dati all'interno di un programma.

#### Varianti di load e store:

Le istruzioni di load e store nelle architetture RISC-V possono variare in base al tipo di dato che stanno trattando e al modo in cui gestiscono i dati stessi. Ecco una panoramica delle varianti più comuni:

1. **Load e Store di Byte/Halfword**:
   
   - **lb (load byte)**: Carica un byte dalla memoria, estendendolo a 64 bit utilizzando il segno.
   - **lh (load halfword)**: Carica una metà di una parola (16 bit) dalla memoria, estendendola a 64 bit utilizzando il segno.
   - **lbu (load byte unsigned)**: Carica un byte dalla memoria, estendendolo a 64 bit con zeri.
   - **lhu (load halfword unsigned)**: Carica una metà di una parola (16 bit) dalla memoria, estendendola a 64 bit con zeri.
   - **sb (store byte)**: Memorizza il byte meno significativo di un registro nella memoria.
   - **sh (store halfword)**: Memorizza la metà meno significativa di un registro (16 bit) nella memoria.

2. **Load e Store di Word/Doubleword**:
   
   - **lw (load word)**: Carica una parola (32 bit) dalla memoria, estendendola a 64 bit utilizzando il segno.
   - **ld (load doubleword)**: Carica una doppia parola (64 bit) dalla memoria.
   - **lwu (load word unsigned)**: Carica una parola (32 bit) dalla memoria, estendendola a 64 bit con zeri.
   - **ldu (load doubleword unsigned)**: Carica una doppia parola (64 bit) dalla memoria, estendendola a 64 bit con zeri.
   - **sw (store word)**: Memorizza i 32 bit meno significativi di un registro nella memoria.
   - **sd (store doubleword)**: Memorizza un registro intero (64 bit) nella memoria.

Queste istruzioni sono progettate per manipolare dati di diversi formati e dimensioni nella memoria principale. Le istruzioni di load estendono i dati a 64 bit per poterli utilizzare efficacemente all'interno della CPU, mentre le istruzioni di store memorizzano i dati correttamente nella memoria, prendendo in considerazione i loro formati e le loro dimensioni.

### 4.Formato specifici del tipo U -> Load Upper Immediate (LUI)?

Ricorda:sappiamo scrivere fino a 12 bit, 20 piu significativi no, l'istruzione lui cosa? prende un valore che puo rappresentare 20 bit e lo sposta nei 20 bit piu significativi nel registro di destinazione che gli diamo in pasto.

Se io ho a=a+4: 4 ovvero l'immediato lo riesco ad inserire con 12 bit e quindi ad utilizzare addi, ma se per caso dovessi utilizzare un valore costante piu grande di 32 bit. Ci serve combinarne due.

<img src="file:///C:/Users/baleo/Pictures/GitUni/imagesMarkText/2024-04-30-17-06-26-image.png" title="" alt="" width="375">

è un'operazione utilizzata nell'architettura RISC-V per caricare una costante a 32 bit(per farlo concatena 2 istruzioni) nei 20 bit più significativi di un registro destinazione, mentre gli 12 bit meno significativi vengono impostati a 0. Questa istruzione è utile quando è necessario lavorare con costanti più grandi di 12 bit, che è il massimo consentito per le istruzioni immediate standard.

Ecco una spiegazione dettagliata del funzionamento della LUI:

1. **Operazione principale**: L'istruzione LUI prende una costante a 20 bit e la sposta nei 20 bit più significativi del registro destinazione. Questi 20 bit vengono copiati nei bit dal 31 al 12 del registro destinazione.

2. **Pulizia dei bit meno significativi**: Gli 12 bit meno significativi del registro destinazione vengono impostati a 0. Questo è importante perché l'istruzione LUI carica solo i bit più significativi del registro destinazione e non tocca i bit meno significativi.

In sostanza, l'istruzione LUI consente di caricare una costante a 32 bit nei 32 bit di un registro destinazione, sfruttando i 20 bit disponibili per le costanti più significative e impostando a 0 i restanti 12 bit. Questo è particolarmente utile quando si lavora con costanti di dimensioni superiori ai 12 bit consentiti dalle istruzioni immediate standard.

### Operazioni logiche in Assembly:

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-30-17-00-38-image.png) 

#### - Shift

Sposto i bit di un tot a sinistra o destra, se shifto a sinistra di una posizione e come moltiplicare il valore per $2^1$ se fosse a destra $2^{-1}$

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-30-17-12-08-image.png)

#### - And

#### - Or

### Le istruzioni condizionali e non condizionali nell'architettura RISC-V

includono le istruzioni di branch (condizionali) e le istruzioni di jump (non condizionali). Una delle istruzioni di branch più comuni è l'istruzione `beq` (branch if equal), che effettua un salto condizionato se due registri sono uguali. Invece, un esempio di istruzione di jump non condizionale è l'istruzione `jal` (jump and link), che esegue sempre un salto a un indirizzo specifico.

Ecco una spiegazione di base di queste istruzioni:

#### Istruzioni di Branch (Condizionali)

Le istruzioni di branch permettono al programma di prendere decisioni basate su condizioni specifiche. Una delle istruzioni di branch più comuni nel RISC-V è `beq` (branch if equal), che salta a un indirizzo specifico se due registri sono uguali. Ad esempio:

```
beq rs1, rs2, offset
```

Questa istruzione confronta i valori nei registri `rs1` e `rs2`. Se i valori sono uguali, il programma salta a un indirizzo che è l'offset rispetto all'istruzione di branch.

#### Istruzioni di Jump (Non Condizionali)

Esempio il for, lo switch case, if while etc..

Le istruzioni di jump consentono di eseguire un salto a un indirizzo specifico, senza condizioni. Un esempio di istruzione di jump nel RISC-V è `jal` (jump and link), che salta a un indirizzo specifico e memorizza l'indirizzo successivo (il valore del program counter dopo l'istruzione di jump) nel registro di ritorno `ra`. Ad esempio:

```
jal rd, target
```

Questa istruzione salta all'indirizzo `target` e memorizza l'indirizzo successivo nel registro `rd`.

Le istruzioni di branch sono utilizzate per controllare il flusso del programma in base a condizioni specifiche, mentre le istruzioni di jump sono utilizzate per eseguire salti non condizionati a indirizzi specifici. Entrambe sono importanti per la gestione del flusso di controllo all'interno di un programma RISC-V.

## Riassunto comandi RISCV

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-30-17-16-25-image.png)

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-30-17-16-42-image.png)

Formati:

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-30-17-17-38-image.png)

Chiamate di procedure

E' un alterazione del control flow, se ho una chiamata a funzione ho un grande salto e quindi mi serve un meccanismo per memorizzare il valore che aveva il program counter quando la funzione e' stata chiamata.

La chiamata a una procedura in RISC-V coinvolge diversi passaggi per garantire che la procedura venga eseguita correttamente e che il controllo venga restituito al punto di chiamata originale. Ecco una spiegazione dettagliata dei passaggi coinvolti:

1. **Posizionare i parametri nei registri da x10 a x17**: Prima di chiamare la procedura, è necessario caricare i parametri nei registri appropriati. In RISC-V, i registri da x10 a x17 sono spesso utilizzati per passare i parametri alle procedure.

2. **Trasferire il controllo alla procedura**: Per avviare l'esecuzione della procedura, viene utilizzata l'istruzione `jal` (jump and link). Questa istruzione effettua un salto all'indirizzo della procedura e memorizza l'indirizzo successivo (il valore del program counter dopo l'istruzione `jal`) nel registro di ritorno x1.

3. **Ottenere lo spazio per la procedura**: Prima di eseguire la procedura, potrebbe essere necessario allocare spazio per le variabili locali o altre strutture dati. In RISC-V, spesso si utilizza lo stack per questo scopo.

4. **Eseguire la procedura**: Una volta che lo spazio è stato allocato e i parametri sono stati caricati, la procedura può essere eseguita.

5. **Immettere il risultato in un registro**: Se la procedura restituisce un valore, il risultato può essere immesso in un registro specifico.

6. **Ritornare alla posizione di chiamata originale**: Dopo aver eseguito la procedura, il controllo viene restituito al punto di chiamata originale utilizzando l'istruzione `jalr` (jump and link register), che utilizza l'indirizzo memorizzato nel registro di ritorno x1 per tornare al punto di chiamata.

Esempio:

Supponiamo di avere una procedura chiamata `somma` che accetta due parametri interi, ne calcola la somma e restituisce il risultato. La procedura `somma` può essere definita come segue:

```assembly
somma:
    add a0, a0, a1    ; Somma i parametri a0 e a1
    jr ra             ; Torna al punto di chiamata
```

Ora, supponiamo di voler chiamare la procedura `somma` da un'altra parte del programma. Ecco come potrebbe apparire il codice assembly per effettuare la chiamata e gestire il ritorno:

```assembly
main:
    # Carica i parametri nei registri
    li a0, 5          ; Carica il primo parametro con il valore 5
    li a1, 7          ; Carica il secondo parametro con il valore 7

    # Chiamata alla procedura somma
    jal ra, somma     ; Salta alla procedura somma e memorizza l'indirizzo di ritorno in ra

    # Dopo la chiamata alla procedura, il risultato sarà nel registro a0
    # Possiamo stamparlo a schermo o utilizzarlo in altri modi
    li a7, 1          ; Carica il codice di sistema per la syscall di stampa intero
    ecall             ; Esegue la syscall per stampare il valore

    # Fine del programma
    li a7, 10         ; Carica il codice di sistema per l'exit
    ecall             ; Esegue la syscall per terminare il programma
```

### Formato SB Branch Short

Il formato SB (Branch Short) è utilizzato per le istruzioni di salto condizionale (branch) in RISC-V. Queste istruzioni permettono al programma di prendere decisioni e modificare il flusso di esecuzione del codice in base alle condizioni definite.

Ecco una spiegazione dettagliata del formato SB delle istruzioni di salto condizionale in RISC-V:

1. **Specifiche dell'istruzione di salto condizionale**:
   
   - Opcode: Identifica il tipo di istruzione di salto condizionale.
   - Due registri: I registri utilizzati per valutare la condizione di salto.
   - Indirizzo di destinazione: Specifica l'indirizzo target del salto.

2. **Obiettivi di salto vicini**:
   
   - La maggior parte degli obiettivi di salto nelle istruzioni di branch sono vicini rispetto alla posizione dell'istruzione di branch stessa.
   - Gli obiettivi possono essere sia in avanti che all'indietro rispetto all'istruzione di branch.

3. **Indirizzamento PC-relativo**:
   
   - Nel formato SB, l'indirizzo di destinazione del salto viene calcolato utilizzando l'indirizzo corrente dell'istruzione di branch (PC) e un immediato specificato nell'istruzione.
   - La formula per calcolare l'indirizzo di destinazione è: `Target address = PC + immediate × 2`.
   - Moltiplicando l'immediato per 2, si tiene conto del fatto che le istruzioni nel RISC-V sono allineate su limiti di parole (word boundaries), quindi il valore dell'immediato è espresso in numero di istruzioni da saltare, piuttosto che in byte.

4. **Indirizzamento fino alla mezza parola**:
   
   - L'indirizzamento delle istruzioni in RISC-V è effettuato fino alla mezza parola (halfword).
   - Ciò significa che il salto può essere effettuato solo a istruzioni allineate sul limite della mezza parola, che si trova ogni due istruzioni nel codice.

In sintesi, il formato SB delle istruzioni di salto condizionale in RISC-V consente di specificare istruzioni di branch con indirizzamento relativo al PC e con un raggio d'azione limitato fino alla mezza parola. Ciò offre un'ampia flessibilità nella gestione dei salti nel codice, consentendo di creare strutture decisionali complesse all'interno dei programmi.

### Memoria stack

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-02-22-21-50-image.png)

In un programma assembly, la memoria può essere segmentata in diverse sezioni, a seconda delle necessità del programma e del sistema operativo su cui viene eseguito. Tuttavia, la segmentazione della memoria può essere generalmente suddivisa in diverse categorie:

1. **Low Address Memory**: Questa è la parte inferiore della memoria e contiene solitamente il codice eseguibile del programma, i dati statici e altre informazioni cruciali per il programma. Qui sono inclusi il codice del programma (come le istruzioni assembly), le variabili globali e altre costanti.

2. **Dynamic Memory**: Questa parte della memoria è usata per la gestione dinamica della memoria, come l'allocazione e la deallocazione di memoria durante l'esecuzione del programma. Tipicamente, questa area include l'heap, dove vengono allocati i blocchi di memoria a richiesta tramite funzioni come `malloc()` in C o `new` in C++. La dimensione di questa sezione può variare a seconda delle necessità del programma e del sistema operativo.

3. **Initialized to Zero by Exec**: Questa parte della memoria è riservata per le variabili globali inizializzate a zero o a un valore predefinito direttamente dal file eseguibile durante la fase di caricamento. Questo può includere variabili globali inizializzate staticamente, come array e strutture.

4. **Local Memory (Stack)**: Questa parte della memoria è utilizzata per la gestione delle variabili locali e dei record di attivazione delle funzioni. Viene spesso chiamata "stack" e cresce e si contrae durante l'esecuzione del programma. Ogni chiamata di funzione crea un nuovo frame nello stack, che contiene le variabili locali e altri dati relativi alla funzione chiamata.

Pseudo-istruzioni che bisogna studiare solo quelli evidenziate:

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-02-22-41-25-image.png)

### Il processo di esecuzione delle istruzioni in un processore

può essere diviso in diverse fasi, o stadi, ciascuno dei quali svolge un compito specifico nell'elaborazione delle istruzioni. Qui di seguito, spiego ciascuno di questi stadi:

1. **Fetch (Recupero)**:
   
   - Il Program Counter (PC) contiene l'indirizzo dell'istruzione da eseguire.
   - L'istruzione viene letta dalla memoria usando l'indirizzo contenuto nel PC.
   - L'istruzione recuperata viene immagazzinata nel registro di istruzione.

2. **Decodifica**:
   
   - L'istruzione recuperata viene analizzata e decodificata per comprendere quale operazione deve essere eseguita e su quali dati.
   - Durante questo processo, vengono identificati i registri coinvolti nell'istruzione e le modalità di accesso alla memoria, se necessario.

3. **Esecuzione**:
   
   - In base al tipo di istruzione, l'unità di esecuzione decide come manipolare i dati.
   - Per istruzioni aritmetiche, la ALU (Unità Logica e Aritmetica) esegue l'operazione specificata sui dati.
   - Per le istruzioni di memoria, l'indirizzo di memoria è calcolato, e l'accesso alla memoria può avvenire per leggere o scrivere dati.
   - Per le istruzioni di salto condizionale (branch), viene calcolato se il salto deve essere effettuato o meno.

4. **Memoria**:
   
   - Se l'istruzione coinvolge l'accesso alla memoria, questo stadio comporta l'accesso effettivo alla memoria per leggere o scrivere dati.

5. **Writeback (Scrittura nel Registro)**:
   
   - Se l'istruzione ha prodotto un risultato che deve essere scritto in un registro, questo stadio esegue la scrittura del risultato nel registro appropriato.
   - Ad esempio, per le istruzioni aritmetiche, il risultato può essere scritto nel registro di destinazione specificato dall'istruzione.

Il "datapath" rappresenta il percorso dei dati attraverso questi stadi, mentre la "logica di controllo" è responsabile per controllare quali segnali devono essere attivati in ciascuno stadio, incluso il controllo dei multiplexer per instradare i dati attraverso i percorsi appropriati.

In breve, ogni istruzione attraversa questi stadi in sequenza, subendo le operazioni necessarie per completare la sua esecuzione. La logica di controllo gestisce il flusso di dati e il controllo tra i diversi stadi per garantire che l'istruzione venga eseguita correttamente.

### Differenza tra varie istruzioni:

Sì, ci sono differenze significative tra queste istruzioni nel contesto dell'assembly MIPS:

1. `li a0, t0`: Questa istruzione carica un valore immediato nel registro `$a0`. Il valore da caricare è quello contenuto nel registro `$t0`. Tuttavia, in MIPS non esiste un'istruzione `li` che carichi direttamente un valore da un registro, quindi `li` carica un valore immediato nel registro specificato.

2. `add a0, zero, t0`: Questa istruzione esegue un'addizione tra il contenuto del registro `$zero` (che ha sempre il valore 0 in MIPS) e il contenuto del registro `$t0`, quindi il risultato viene memorizzato nel registro `$a0`. Questo è un modo per copiare il contenuto di `$t0` in `$a0`.

3. `mv a0, t0`: Questa istruzione copia semplicemente il contenuto del registro `$t0` nel registro `$a0`. È un'abbreviazione comune per l'operazione di movimento (move) in MIPS assembly, comunemente utilizzata per copiare il contenuto di un registro in un altro.

4. `la a0, t0`: Questa istruzione carica l'indirizzo di memoria contenuto nel registro `$t0` nel registro `$a0`. Tuttavia, `la` è usato comunemente per caricare l'indirizzo di una label (etichetta) e non per l'indirizzo di un registro. Quindi, se `t0` contiene un indirizzo valido in memoria, questa istruzione non otterrà l'indirizzo contenuto in `t0`, ma caricherà l'indirizzo della label `t0` (che presumibilmente non è definita nel codice).

In breve, le prime tre istruzioni sono comuni e corrette in MIPS assembly, mentre l'ultima (`la a0, t0`) ha un utilizzo errato e non produce l'effetto desiderato, a meno che non si abbia una label `t0` definita nel codice, il che è improbabile.
