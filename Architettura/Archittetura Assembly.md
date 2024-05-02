## 

# ASSEMBLY

## ISA

sta per "Instruction Set Architecture", che in italiano si traduce in "Architettura del Set di Istruzioni". Si tratta di un'interfaccia tra il software e l'hardware di un sistema informatico che definisce il set di istruzioni disponibili per il processore e il modo in cui tali istruzioni vengono eseguite. In altre parole, l'ISA definisce il vocabolario di istruzioni che un processore può comprendere e eseguire, insieme alle regole e agli indirizzi relativi a tali istruzioni.

Non tutti i processori quindi hanno lo stesso insieme di istruzioni(ISA)

Essenzialmente, l'ISA fornisce una specifica del modo in cui il software può comunicare con l'hardware del sistema, fornendo istruzioni per eseguire operazioni come somma, sottrazione, moltiplicazione, lettura/scrittura di dati in memoria, gestione dei flussi di controllo e altro ancora.

Esistono diverse ISA, ognuna delle quali è progettata per soddisfare esigenze specifiche in termini di prestazioni, complessità, consumo energetico e altro ancora. Ad esempio, ci sono ISA progettate per microcontrollori embedded che richiedono un'efficienza energetica e una semplicità elevate, e ci sono ISA progettate per supercomputer che devono eseguire calcoli ad alta velocità su grandi quantità di dati.

Tra le ISA più note ci sono x86, utilizzata principalmente nei computer desktop e portatili basati su processori Intel e AMD, e ARM, utilizzata in una vasta gamma di dispositivi mobili, microcontrollori, sistemi embedded e supercomputer.

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-29-13-17-26-image.png)

## Cisc vs Risc?

La differenza tra l'architettura CISC (Complex Instruction Set Computer) e RISC (Reduced Instruction Set Computer) si basa principalmente sulla complessità delle istruzioni e sulla gestione dei registri nel processore.

Nell'architettura CISC, il design è caratterizzato da istruzioni complesse che eseguono operazioni più sofisticate in una singola istruzione. Questo mette la complessità sul hardware, poiché il processore deve essere in grado di interpretare e eseguire un'ampia varietà di istruzioni complesse. Di conseguenza, il codice software può risultare più semplice poiché compiti complessi possono essere eseguiti con poche istruzioni. Tuttavia, il costo è che un processore CISC richiede generalmente più transistor per implementare queste istruzioni più complesse.

D'altra parte, nell'architettura RISC, le istruzioni sono più semplici e atomiche, eseguendo operazioni di base elementari in istruzioni più piccole. Questo rende il codice dei programmi più grande, poiché possono essere necessarie più istruzioni per eseguire un compito complesso. Tuttavia, i processori RISC hanno generalmente più registri a disposizione rispetto ai processori CISC. I registri aggiuntivi in un processore RISC consentono una maggiore velocità di esecuzione delle istruzioni e una migliore ottimizzazione del codice.

Ad esempio, consideriamo un'operazione di addizione. In un'architettura CISC, potrebbe esserci un'istruzione "ADD" che non solo esegue l'addizione, ma può anche caricare i dati dai registri. In un'architettura RISC, invece, ci potrebbero essere istruzioni separate per caricare i dati dai registri (istruzioni di caricamento) e per eseguire l'addizione (istruzione di addizione). Anche se questo richiede più istruzioni nel caso di RISC, la presenza di più registri consente una maggiore efficienza nell'esecuzione del codice.

In sintesi, mentre il CISC mette la complessità sul hardware con istruzioni più complesse, il RISC opta per istruzioni più semplici e atomiche, ma offre più registri per una maggiore efficienza nell'esecuzione del codice.

## RISC V

Questo ISA è progettato per essere semplice, regolare e flessibile, con l'obiettivo di favorire l'implementazione efficiente dei processori.

L'ISA RISC-V fornisce un set di istruzioni completo per eseguire una vasta gamma di operazioni. Queste istruzioni possono essere divise in tre categorie principali:

1. **Formato delle istruzioni R**: Questo formato è utilizzato per istruzioni che coinvolgono tre registri: due registri di ingresso e un registro di destinazione. Il formato delle istruzioni R include campi come Opcode (codice operazione), Rs1 (primo registro di ingresso), Rs2 (secondo registro di ingresso), Rd (registro di destinazione), Funct3 e Funct7 (codici di funzione aggiuntivi).

2. **Formato delle istruzioni I**: Questo formato è utilizzato per istruzioni che coinvolgono un registro di ingresso e un valore immediato (costante) o un offset aggiunto all'indirizzo di base. Il formato delle istruzioni I include campi come Opcode, Rs1 (registro di ingresso), Immediate (valore immediato).

3. **Formato delle istruzioni S**: Questo formato è utilizzato per istruzioni che coinvolgono due registri e un offset aggiunto all'indirizzo di base. Il formato delle istruzioni S include campi come Opcode, Rs1 (indirizzo di base), Rs2 (numero del registro di provenienza), e Immediate (offset).

Cose lo spiling?Lo "spilling" si verifica quando il contenuto di un registro deve essere
 temporaneamente spostato dalla memoria del processore (registri) alla 
memoria principale (RAM) a causa dei pochi 32 registri disponibili.Una volta che i registri necessari sono stati liberati, i dati possono 
essere recuperati dalla memoria principale e ripristinati nei registri.

I registri piu importanti?

### Caratteristiche principali di RISC-V:

- **Repertorio di istruzioni:** RISC-V ha un set di istruzioni che comprende operazioni aritmetiche, logiche, di caricamento e memorizzazione, operazioni di ramificazione, operazioni di spostamento e operazioni logiche bitwise.

- **Operandi dei registri:** Le istruzioni di RISC-V utilizzano principalmente operandi dei registri. RISC-V dispone di 32 registri generali a 64 bit, utilizzati per dati frequentemente accessibili.

- **Operandi immediati:** RISC-V supporta operandi immediati, che sono costanti specificate direttamente nell'istruzione.

- **Memoria:** La memoria principale viene utilizzata per dati compositi come array e strutture. Le istruzioni di caricamento e memorizzazione vengono utilizzate per trasferire dati tra la memoria e i registri.

- **Formati di istruzioni:** RISC-V utilizza vari formati di istruzioni per codificare le operazioni, tra cui R-type (registri), I-type (caricamento e aritmetica con immediato), S-type (memoria store), SB-type (branch), U-type (immediato superiore), e UJ-type (salto incondizionato).

- **Comparazioni condizionali:** RISC-V supporta istruzioni per comparazioni condizionali come "beq" (branch if equal) e "bne" (branch if not equal), utili per implementare istruzioni di controllo del flusso come "if" e "while" nel codice.

- **Operazioni logiche:** RISC-V offre istruzioni per operazioni logiche bitwise come AND, OR, XOR e shift, utili per la manipolazione di bit.

## Registri RISC-V

I registri cosa sono?

I registri sono come i depositi della CPU, spazi di memoria molto veloci utilizzati per contenere dati temporanei, indirizzi di memoria, valori di ritorno da funzioni e altro ancora. In RISC-V, ci sono 32 registri principali, ciascuno di 64 bit. Questo significa che possono contenere valori di lunghezza massima di 64 bit, ovvero 8 byte.

In generale, l'utilizzo dei registri è fondamentale per il funzionamento efficiente di un programma, poiché l'accesso ai dati nei registri è molto più veloce rispetto all'accesso alla memoria principale. Tuttavia, poiché ci sono un numero limitato di registri disponibili, è importante utilizzarli in modo efficiente e pianificare come verranno utilizzati durante l'esecuzione del programma.

Registri RiscV:

- **x0**: Valore costante 0
- **x1**: Indirizzo di ritorno (usato per indicare l'indirizzo a cui tornare dopo una chiamata di funzione)
- **x2**: Puntatore dello stack (usato per tenere traccia dell'indirizzo dello stack)
- **x3**: Puntatore globale (usato per accedere alle variabili globali)
- **x4**: Puntatore al thread (usato per l'accesso a variabili specifiche del thread)
- **x5 - x7, x28 - x3**1: Registri temporanei (usati per memorizzare dati temporanei durante l'esecuzione del programma)
- **x8**: Puntatore al frame (usato per tenere traccia dello stack frame durante l'esecuzione delle funzioni)
- **x9, x18 - x27**: Registri salvati (usati per salvare valori importanti durante l'esecuzione di una funzione)
- **x10 - x11**: Argomenti/risultati della funzione (usati per passare argomenti alla funzione e restituire risultati)
- **x12 - x17**: Altri argomenti della funzione (usati per passare argomenti aggiuntivi alla funzione)

Ma come faccio con gli array? Uso la load memory 

Esempio $A[12]=h+A[8]$

```assembly
ld x9, 64(x22): Questa istruzione carica un valore dalla memoria in un registro. Viene caricato il valore dalla posizione di memoria ottenuta sommando 64 a quello contenuto nel registro x22 e il risultato viene caricato nel registro x9.
add x9, x21, x9: Qui avviene un'addizione tra i contenuti di due registri, x21 e x9. Il risultato viene memorizzato nel registro x9. In pratica, questo aggiunge il contenuto di x21 al valore precedentemente caricato in x9.
sd x9, 96(x22): Questa istruzione memorizza il contenuto del registro x9 nella memoria. Il valore viene memorizzato nella posizione di memoria ottenuta sommando 96 al contenuto del registro x22.
```

## Basic Block

Un basic block è un'unità di base nel flusso di controllo di un programma, costituito da una sequenza di istruzioni consecutive senza interruzioni di controllo di flusso come condizioni "if", cicli "while", o salti incondizionati. Ogni basic block inizia con l'istruzione iniziale e termina con l'istruzione finale, senza interruzioni nel mezzo.

L'importanza dei basic block risiede nella loro natura atomica: sono sequenze di istruzioni che vengono eseguite in modo continuo e senza interruzioni. Questo li rende una base solida per l'analisi e l'ottimizzazione del codice, poiché è possibile considerare un basic block come un'entità autonoma che può essere analizzata e ottimizzata indipendentemente da altri blocchi.

Quando il compilatore analizza un programma, identifica i basic block dividendo il codice in segmenti di istruzioni che possono essere eseguiti senza salti di controllo. Questa suddivisione facilita l'ottimizzazione del codice, poiché consente al compilatore di applicare tecniche specifiche a ciascun blocco per migliorare le prestazioni o ridurre la complessità. Inoltre, i basic block sono utilizzati anche in altre fasi del processo di compilazione, come l'allocazione dei registri e la generazione del codice macchina.

In sintesi, i basic block sono una componente fondamentale nell'analisi e nell'ottimizzazione del codice sorgente, fornendo una suddivisione chiara e atomica delle istruzioni in sequenze senza interruzioni di controllo di flusso.

Per esempio, considera il seguente codice:

```
1. x = 5;
2. y = 10;
3. z = x + y;
4. if (z > 15) {
5.     w = 20;
6. } else {
7.     w = 30;
8. }
9. result = w * 2;
```

In questo codice, ci sono due basic block principali:

1. Il primo basic block contiene le istruzioni dalle righe 1 alla 3, poiché non ci sono istruzioni di ramificazione al suo interno.
2. Il secondo basic block contiene le istruzioni dalle righe 4 alla 8, poiché c'è un'istruzione di ramificazione alla fine del blocco (la riga 4).

Il codice può essere rappresentato con i seguenti basic block:

Basic Block 1:

```
1. x = 5;
2. y = 10;
3. z = x + y;
```

Basic Block 2:

```
4. if (z > 15) {
5.     w = 20;
6. } else {
7.     w = 30;
8. }
9. result = w * 2;
```

I basic block sono utilizzati dal compilatore per applicare ottimizzazioni come la riduzione delle espressioni costanti, l'eliminazione del codice morto e la ristrutturazione del flusso di controllo. Queste ottimizzazioni possono migliorare le prestazioni del programma e ridurre la complessità del codice generato.

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-29-13-56-08-image.png)

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-29-13-56-35-image.png)

### Tipo R (Registro)

Le istruzioni di tipo R coinvolgono registri e operazioni aritmetiche e logiche. Ad esempio, consideriamo l'istruzione `add`, che esegue un'addizione tra due registri e salva il risultato in un terzo registro.

**Esempio:**

```assembly
add x3, x1, x2
```

Questo esempio esegue un'addizione tra i contenuti dei registri `x1` e `x2`, e salva il risultato in `x3`.

### Tipo I (Immediato)

Le istruzioni di tipo I coinvolgono un immediato, che è un valore costante, insieme a registri e operazioni. Prendiamo l'istruzione `addi`, che aggiunge un valore immediato a un registro.

**Esempio:**

```assembly
addi x3, x1, 10
```

In questo esempio, viene aggiunto il valore immediato 10 al contenuto del registro `x1`, e il risultato viene salvato in `x3`.

### Tipo S (Store)

Le istruzioni di tipo S sono utilizzate per memorizzare dati in memoria. Ad esempio, consideriamo l'istruzione `sw`, che memorizza una parola (4 byte) in memoria.

**Esempio:**

```assembly
sw x3, 0(x1)
```

Questa istruzione memorizza il contenuto del registro `x3` nella posizione di memoria indicata dal contenuto del registro `x1`, con uno spostamento di 0 byte.

### Operazioni Logiche

Le operazioni logiche manipolano i bit nei registri e possono essere utilizzate per vari scopi. Prendiamo ad esempio l'istruzione `and`, che esegue un'operazione di AND logico tra due registri.

**Esempio:**

```assembly
and x3, x1, x2
```

Questa istruzione esegue un'operazione di AND logico tra i contenuti dei registri `x1` e `x2`, e il risultato viene salvato in `x3`.

### Istruzioni di Controllo

Le istruzioni di controllo consentono di modificare il flusso di esecuzione del programma. Prendiamo l'istruzione `beq`, che salta a un'etichetta specifica se due registri sono uguali.

**Esempio:**

```assembly
beq x1, x2, label
```

Questa istruzione confronta i contenuti dei registri `x1` e `x2`, e se sono uguali, il controllo viene trasferito all'etichetta `label`.

### Cicli

I cicli sono implementati utilizzando salti condizionati, consentendo di eseguire ripetutamente un blocco di istruzioni finché una certa condizione è verificata. Prendiamo un esempio di ciclo utilizzando l'istruzione `beq` per un conteggio fino a 10.

**Esempio:**

```assembly
loop:
    addi x1, x1, 1
    bne x1, x0, loop
```

In questo esempio, il programma incrementa continuamente il contenuto del registro `x1` di 1 e poi salta all'etichetta `loop` finché `x1` non diventa zero.

Questi esempi illustrano il funzionamento di diversi tipi di istruzioni nel contesto di RISC-V, evidenziando come vengono utilizzate per eseguire operazioni specifiche e controllare il flusso di esecuzione del programma.

# Come convertire da una formato all'altro

### Conversione da Formato R a Formato I:

#### Istruzione R: `add s0, zero, a1`

- `add` (Tipo R)
- Destinazione: `s0` (Registro)
- Sorgente 1: `zero` (Registro costante)
- Sorgente 2: `a1` (Registro)

#### Conversione in Formato I:

Utilizziamo l'istruzione `addi` (Aggiunta immediata) per convertire in formato I:

- Destinazione: `s0` (Registro)
- Sorgente 1: `a1` (Registro)
- Immediato: `0` (Valore costante)

#### Istruzione Convertita:

- `addi s0, a1, 0`

### Conversione da Formato R a Formato S:

#### Istruzione R: `or x18, x1, x30`

- `or` (Tipo R)
- Destinazione: `x18` (Registro)
- Sorgente 1: `x1` (Registro)
- Sorgente 2: `x30` (Registro)

#### Conversione in Formato S:

Per convertire in formato S, dobbiamo scegliere un registro base e un offset per l'indirizzamento della memoria.

- Registro Base: `x1`
- Offset: 0 (Possiamo usare l'offset zero perché stiamo copiando direttamente il valore da `x30` a `x18`)

#### Istruzione Convertita:

- `sw x30, 0(x1)`

### Conversione da Formato I a Formato R:

#### Istruzione I: `addi s0, a1, 0`

- `addi` (Tipo I)
- Destinazione: `s0` (Registro)
- Sorgente: `a1` (Registro)
- Immediato: `0` (Valore costante)

#### Conversione in Formato R:

Per convertire in formato R, dobbiamo rimuovere l'immediato e mantenere solo i registri.

- `add` (Tipo R)
- Destinazione: `s0` (Registro)
- Sorgente 1: `a1` (Registro)
- Sorgente 2: `zero` (Registro costante)

#### Istruzione Convertita:

- `add s0, a1, zero`

### Conversione da Formato S a Formato R:

#### Istruzione S: `sw x30, 0(x1)`

- `sw` (Tipo S)
- Registro da Memorizzare: `x30` (Registro)
- Offset: 0
- Registro Base: `x1` (Registro)

#### Conversione in Formato R:

Per convertire in formato R, dobbiamo mantenere i registri e l'operazione, ma rimuovere l'offset.

- `or` (Tipo R)
- Destinazione: Nessuna (Possiamo ignorare questo campo poiché il risultato non è necessario)
- Sorgente 1: `x1` (Registro)
- Sorgente 2: `x30` (Registro)

#### Istruzione Convertita:

- `or x1, x30, x1`

Questi sono gli esempi di conversione da un formato all'altro basati sulle istruzioni fornite.

## 10. Instruction Set Architecture - Procedure calling

I computer a programma memorizzato sono un concetto fondamentale nel campo dell'informatica. Le istruzioni sono rappresentate in binario, proprio come i dati, e sia le istruzioni che i dati sono memorizzati nella memoria. Questo consente ai programmi di operare su altri programmi, ad esempio attraverso compilatori e linker. La compatibilità binaria permette ai programmi compilati di funzionare su diversi computer, grazie agli ISA (Instruction Set Architecture) standardizzati.

La traduzione e l'avvio di un programma coinvolgono diversi passaggi. In primo luogo, il compilatore traduce il programma in istruzioni macchina, fornendo le informazioni necessarie per costruire un programma completo dai vari pezzi. Questo include una sezione di testo con le istruzioni tradotte, una sezione di dati statici, informazioni di rilocazione per i contenuti che dipendono dalla posizione assoluta del programma caricato, una tabella dei simboli per le definizioni globali e i riferimenti esterni, e informazioni di debug per associare il codice sorgente.

La concatenazione dei moduli di oggetto produce un'immagine eseguibile. Questo processo coinvolge la risoluzione delle etichette (per determinare i loro indirizzi) e l'applicazione di correzioni per i riferimenti dipendenti dalla posizione e esterni. Successivamente, il programma viene caricato dalla memoria del file immagine sul disco nella memoria effettiva del computer. Durante questo processo, le dimensioni dei segmenti vengono lette dall'header, lo spazio di indirizzamento virtuale viene creato, il codice e i dati inizializzati vengono copiati in memoria e gli argomenti vengono impostati nello stack. Infine, il controllo viene passato alla routine di avvio.

Il collegamento dinamico permette di caricare e collegare solo le procedure di libreria quando vengono chiamate, evitando così il sovraccarico dell'immagine causato dal collegamento statico di tutte le librerie referenziate (in modo transitivo). Ciò consente anche di aggiornare automaticamente le nuove versioni delle librerie.

Infine, le procedure di chiamata in RISC-V seguono un insieme specifico di passaggi, tra cui il posizionamento dei parametri nei registri, il trasferimento del controllo alla procedura, l'acquisizione di spazio di archiviazione per la procedura, l'esecuzione delle operazioni della procedura, il posizionamento del risultato nel registro per il chiamante e il ritorno al punto di chiamata.

Questo approccio al design dei computer a programma memorizzato è guidato da principi come la semplicità, la velocità e i compromessi ben ponderati per garantire un funzionamento efficiente e affidabile.

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-25-11-51-51-image.png)
