# Si supponga che il program counter (PC) contenga l’indirizzo 0x2000 0000.

## a) Quale range di indirizzi può essere raggiunto utilizzando l’istruzione branch-if-equal (bge) instruction? (Ovvero, qual è l’insieme dei possibili valori che il PC può assumere dopo l’esecuzione dell’istruzione bge?)

Per calcolare il range di indirizzi che possono essere raggiunti utilizzando l'istruzione RISC-V `branch-if-equal` (BGE), è necessario comprendere come funziona questa istruzione.

L'istruzione BGE confronta due registri e, se sono uguali, il programma salta a un indirizzo relativo rispetto al PC attuale. Il salto può essere sia in avanti che all'indietro rispetto al PC corrente.

Supponendo che l'istruzione BGE sia nel formato:

```
BGE rs1, rs2, offset
```

dove `rs1` e `rs2` sono i registri da confrontare e `offset` è l'offset di salto, possiamo calcolare il range di indirizzi come segue:

- Se `rs1` è uguale a `rs2`, allora il salto sarà eseguito, portando il PC a `PC + offset`.
- L'offset può essere sia positivo che negativo. Se è positivo, il salto sarà in avanti rispetto al PC corrente, se è negativo, sarà all'indietro.

Per esempio, se l'offset è `-100`, il PC si sposterà all'indietro di 100 istruzioni.

Pertanto, per calcolare il range di indirizzi possibili, dobbiamo considerare il valore massimo e minimo che può assumere l'offset.

- Se l'offset è negativo, il valore minimo sarà `PC - 2^12` (il limite inferiore degli offset per le istruzioni branch).
- Se l'offset è positivo, il valore massimo sarà `PC + 2^12 - 4` (il limite superiore degli offset per le istruzioni branch, sottraendo 4 perché gli offset devono essere multipli di 4).

Quindi, considerando che il PC contiene l'indirizzo `0x2000 0000`, il range di indirizzi possibili sarà:

- Minimo: `0x2000 0000 - 2^12 = 0x1FFF F000`
- Massimo: `0x2000 0000 + 2^12 - 4 = 0x2000 0FFC`

Quindi, il range di indirizzi possibili che il PC può assumere dopo l'esecuzione dell'istruzione BGE sarà compreso tra `0x1FFF F000` e `0x2000 0FFC`.

## b) Cosa cambia nelle risposte al punto precedente se si utilizza la variante unsigned del confronto? (bgeu)


Se stiamo considerando la variante unsigned dell'istruzione di confronto (`bgeu`), ciò significa che stiamo confrontando i valori nei registri come unsigned integers anziché signed integers. 

Nella variante `bgeu`, il salto avviene se il primo registro (rs1) è maggiore o uguale al secondo registro (rs2) come unsigned integers. L'implementazione della differenza rispetto a `bge` è che non viene considerato il bit di segno durante il confronto.

Quindi, il calcolo del range di indirizzi possibili dopo l'esecuzione dell'istruzione `bgeu` sarà simile, ma con la differenza che non ci saranno distinzioni di segno nel confronto.

- Se l'offset è negativo, il valore minimo sarà lo stesso: `PC - 2^12`.
- Se l'offset è positivo, il valore massimo sarà lo stesso: `PC + 2^12 - 4`.

Poiché la variante unsigned non considera i bit di segno, i calcoli non differiranno nei limiti superiori e inferiori degli offset. Pertanto, il range di indirizzi possibili che il PC può assumere dopo l'esecuzione dell'istruzione `bgeu` sarà lo stesso: compreso tra `0x1FFF F000` e `0x2000 0FFC`.

## c) Quale range di indirizzi può essere raggiunto utilizzando l’istruzione jump-and-link (jal) instruction? (Ovvero, qual è l’insieme dei possibili valori che il PC può assumere dopo
l’esecuzione dell’istruzione jal?)
L'istruzione RISC-V `jal` (jump-and-link) viene utilizzata per saltare a un indirizzo specifico e memorizzare l'indirizzo successivo (PC + 4) nel registro di link (ra), il quale è solitamente utilizzato per implementare le chiamate di funzione o i salti a subroutine.

Il calcolo del range di indirizzi possibili dopo l'esecuzione di un'istruzione `jal` dipende dall'indirizzo specifico a cui si sta saltando.

Poiché l'istruzione `jal` utilizza un immediato di 20 bit per indicare l'indirizzo destinazione, l'indirizzo raggiungibile può variare.

Il campo immediato è firmato, il che significa che può essere positivo o negativo. Pertanto, il range di indirizzi raggiungibili da `jal` sarà:

- Se l'indirizzo immediato è negativo, il PC si sposterà all'indietro di un numero di istruzioni pari al valore dell'immediato (considerando il segno). Il PC può quindi variare da `PC - 2^20` a `PC - 4`.
- Se l'indirizzo immediato è positivo, il PC si sposterà in avanti di un numero di istruzioni pari al valore dell'immediato. Il PC può quindi variare da `PC + 4` a `PC + 2^20 - 4`.

Quindi, il range di indirizzi possibili che il PC può assumere dopo l'esecuzione dell'istruzione `jal` sarà compreso tra `PC - 2^20` e `PC + 2^20 - 4`.

## d) Quale range di indirizzi può essere raggiunto utilizzando l’istruzione jump-and-link- register (jalr)? (Ovvero, qual è l’insieme dei possibili valori che il PC può assumere
dopo l’esecuzione dell’istruzione jalr?)
L'istruzione RISC-V `jalr` (jump-and-link-register) esegue un salto a un indirizzo calcolato sommando un immediato a un registro e memorizzando l'indirizzo successivo (PC + 4) nel registro di link (ra), che di solito viene utilizzato per le chiamate di funzione o i salti a subroutine.

Il calcolo del range di indirizzi possibili dopo l'esecuzione di un'istruzione `jalr` dipende dall'indirizzo specifico a cui si sta saltando e dall'immediato che viene sommato al registro.

Poiché l'istruzione `jalr` utilizza un immediato di 12 bit per indicare l'offset e somma questo offset a un registro, il range di indirizzi raggiungibili può variare.

Il campo immediato è firmato, il che significa che può essere positivo o negativo. Pertanto, il range di indirizzi raggiungibili da `jalr` sarà:

- Se l'offset è negativo, il PC si sposterà all'indietro di un numero di istruzioni pari al valore dell'offset (considerando il segno). Il PC può quindi variare da `PC - 2^12` a `PC - 4`.
- Se l'offset è positivo, il PC si sposterà in avanti di un numero di istruzioni pari al valore dell'offset. Il PC può quindi variare da `PC + 4` a `PC + 2^12 - 4`.

Quindi, il range di indirizzi possibili che il PC può assumere dopo l'esecuzione dell'istruzione `jalr` sarà compreso tra `PC - 2^12` e `PC + 2^12 - 4`.

# Si consideri di voler realizzare una nuova istruzione RISC-V chiamata rpt.

Questa istruzione combina il controllo della condizione di terminazione di un loop e il decremento di un contatore in un’unica istruzione.

Per esempio, l’istruzione rpt x29, loop funzionerebbe nel seguente modo: if (x29 > 0) { x29 = x29 −1; goto loop }

## a) Se doveste aggiungere questa istruzione all’instruction set RISC-V, quale formato di istruzione sarebbe il più appropriato? Perché?



il formato I-Type sarebbe il più adatto. Questo formato consente di  codificare un'operazione che coinvolge un registro (nel nostro caso, il  registro contenente il contatore) e un immediato (l'etichetta per il  salto condizionale). Inoltre, poiché l'istruzione `rpt`  richiede un'operazione di decremento, il formato I-Type può essere  esteso per includere un campo per l'operazione di sottrazione.



## b) Qual è la più corta sequenza di istruzioni RISC-V che esegue la stessa operazione?

Per eseguire la stessa operazione dell'istruzione `rpt x29, loop` utilizzando le istruzioni RISC-V esistenti, possiamo combinare diverse istruzioni per ottenere lo stesso risultato. Ad esempio, possiamo utilizzare un confronto, un salto condizionale e un'istruzione di decremento del registro per simulare l'effetto dell'istruzione `rpt`.

Ecco un'ipotetica sequenza di istruzioni RISC-V che potrebbe eseguire la stessa operazione:

```assembly
loop_start:
    # Confronto per verificare se il contatore (x29) è maggiore di 0
    bgtz x29, loop_body   # Salta a loop_body se x29 > 0
    # Se x29 <= 0, esci dal loop
    # Altrimenti, decrementa x29 e ritorna all'inizio del loop
    jal x0, loop_end

loop_body:
    # Decremento del registro x29
    addi x29, x29, -1   # Decrementa il contatore
    # Salto all'inizio del loop
    jal x0, loop_start

loop_end:
    # Fine del loop
```

In questa sequenza di istruzioni:

1. `bgtz` effettua un salto condizionale alla label `loop_body` se il registro `x29` è maggiore di 0.
2. `addi` decrementa il valore del registro `x29` di 1.
3. `jal` effettua un salto incondizionato alla label `loop_start`, ripetendo il ciclo.

Questa sequenza di istruzioni simula il comportamento dell'istruzione `rpt x29, loop`, ma richiede diverse istruzioni per raggiungere lo stesso risultato.

## Si consideri il seguente loop RISC-V:
```assembly
LOOP:
beq x6, x0, DONE
addi x6, x6, -1
addi x5, x5, 2
jal x0, LOOP
DONE:
```

## a) Si assuma che il registro x6 sia inizializzato al valore 10. Che valore si trova alla fine nel registro x5, assumendo che x5 sia inizialmente 0?

Per risolvere questo problema, possiamo seguire il flusso del programma e aggiornare i valori dei registri `x5` e `x6` durante ogni iterazione del loop.

Inizialmente, supponiamo che `x5` sia 0 e `x6` sia 10.

1. `beq x6, x0, DONE`: Dato che `x6` non è uguale a 0, non salta al punto `DONE`.
2. `addi x6, x6, -1`: `x6` diventa 9.
3. `addi x5, x5, 2`: `x5` diventa 2.
4. `jal x0, LOOP`: Salta all'inizio del loop.

Il loop continua fino a quando `x6` diventa 0.

Alla fine del loop, `x5` contiene la somma di 2 per ogni iterazione del loop, poiché `x5` viene incrementato di 2 ad ogni iterazione. Poiché il loop viene eseguito 10 volte (partendo da 10), il valore finale di `x5` sarà:

\[ x5 = 0 + 2 \times 10 = 20 \]

Quindi, alla fine del loop, il valore nel registro `x5` sarà 20.

## b) Si assuma che il registro x6 sia inizializzato al valore N. Quante istruzioni RISC-V vengono eseguite?
Per determinare quante istruzioni RISC-V vengono eseguite durante l'esecuzione del loop, dobbiamo considerare il flusso del programma e contare quante istruzioni vengono eseguite ad ogni iterazione del loop.

Il loop termina quando il registro `x6` diventa 0. Ad ogni iterazione, vengono eseguite quattro istruzioni:

1. `beq x6, x0, DONE`: Una istruzione di branch che verifica se `x6` è uguale a zero per determinare se uscire dal loop.
2. `addi x6, x6, -1`: Una istruzione per decrementare il valore di `x6`.
3. `addi x5, x5, 2`: Una istruzione per incrementare il valore di `x5`.
4. `jal x0, LOOP`: Una istruzione di salto incondizionato per tornare all'inizio del loop.

Quindi, durante ogni iterazione del loop, vengono eseguite quattro istruzioni.

Il numero totale di istruzioni eseguite dipende dal valore iniziale di `x6` (indicato come N). Se `x6` è inizializzato a N, allora il numero totale di istruzioni eseguite sarà 4 volte il valore di N, poiché ad ogni iterazione del loop vengono eseguite quattro istruzioni.

Quindi, il numero totale di istruzioni eseguite sarà 4 * N.

## c) Si sostituisca l’istruzione “beq x6, x0, DONE” con l’istruzione “blt x6, x0, DONE”. Come cambiano le risposte ai punti precedenti?

non cambia nulla



# Si consideri il seguente stralcio di codice assembly RISC-V

```assembly
li s0, 0
LOOP:
lw s1, 0(a0)
add s2, s2, s1
addi a0, a0, 4
addi s0, s0, 1
blt s0, a1, LOOP
```

## a) [2 pt] Si traduca il codice assembly in codice C. Si dica cosa fa il programma, sapendo che in a0 e in a1 vengono passati rispettivamente:

1. L’indirizzo di un array int arr[10, 10, 10, 10, 10, 10]
2. Una costante intera n che contiene il numero di elementi dell’array arr (6).

Il codice assembly RISC-V fornito legge gli elementi di un array di interi, memorizzati in memoria a partire dall'indirizzo contenuto nel registro `a0`. In ogni iterazione del loop, un elemento dell'array viene caricato nel registro `s1` usando l'istruzione `lw`, quindi viene sommato al registro `s2`. L'indirizzo base dell'array (`a0`) viene incrementato di 4 (che corrisponde alla dimensione di un intero) in ogni iterazione del loop utilizzando l'istruzione `addi`. Il registro `s0` tiene traccia del numero di iterazioni del loop. Il loop continua finché il contenuto di `s0` è minore della costante `a1`. Alla fine del loop, il risultato della somma degli elementi dell'array viene mantenuto nel registro `s2`.

Traducendo questo codice assembly in codice C, otteniamo qualcosa del genere:

```c
int sum_array(int *arr, int n) {
    int i, sum;
    sum = 0;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
```

Questo programma C calcola la somma degli elementi di un array di interi. La funzione `sum_array` prende in input un puntatore all'array `arr` e la dimensione `n` dell'array. Itera attraverso gli elementi dell'array, sommandoli uno per uno e restituendo infine il risultato della somma.

Nel contesto fornito, l'array `arr` contiene sei elementi, ciascuno con un valore di 10, e `n` è impostato su 6. Quindi, alla fine del programma, il valore di `s2` (o `sum` nella versione C) sarà 60 (ovvero 10 + 10 + 10 + 10 + 10 + 10).

## b) [2 pt] Si assuma che lo stralcio di codice dato costituisca il corpo di una funzione fun. Si estenda il codice perché venga gestito correttamente il salvataggio dei registri opportuni e il passaggio degli argomenti/valori di ritorno secondo la calling convention. Si scriva anche la funzione chiamante (es. il main), allocando l’array arr e la costante intera n sul segmento dati inizializzati del file ELF.

```
.data
arr:
.word 10, 20, 30, 40, 50   # Esempio di un array di 5 parole
n:
.word 5                    # Esempio di una costante intera

.text
main:
    la a0, arr              # Carica l'indirizzo di arr in a0
    lw a1, n                # Carica il valore di n in a1
    jal ra, fun             # Chiama la funzione fun
    # Valore di ritorno in s2

    # Fai qualcosa con il valore di ritorno, ad esempio stampalo
    # ...
    
    # Fine del programma
    li a7, 10               # Exit syscall
    ecall

fun:
    # Salvataggio dei registri necessari secondo la calling convention
    addi sp, sp, -16        # Fai spazio per 4 registri nello stack
    sw ra, 0(sp)            # Salva il registro di ritorno ra
    sw s0, 4(sp)            # Salva s0
    sw s1, 8(sp)            # Salva s1
    sw s2, 12(sp)           # Salva s2

    li s0, 0                # Inizializza il contatore s0 a 0
    li s2, 0                # Inizializza il risultato s2 a 0

LOOP:
    lw s1, 0(a0)            # Carica il valore dall'indirizzo a0 in s1
    add s2, s2, s1          # Aggiungi s1 a s2
    addi a0, a0, 4          # Incrementa l'indirizzo a0 di 4 byte
    addi s0, s0, 1          # Incrementa il contatore s0 di 1
    blt s0, a1, LOOP        # Salta al LOOP se s0 < a1

    # Ripristino dei registri e ritorno
    lw ra, 0(sp)            # Ripristina il registro di ritorno ra
    lw s0, 4(sp)            # Ripristina s0
    lw s1, 8(sp)            # Ripristina s1
    lw s2, 12(sp)           # Ripristina s2
    addi sp, sp, 16         # Libera lo spazio nello stack
    ret                     # Ritorna al chiamante
  
```



## c) [6 pt] Considerando la funzione appena scritta, si assuma che la prima istruzione di questa funzione venga allocata in memoria a partire  all’indirizzo 0x0040 0000. Si codifichino le istruzioni appartenenti al solo loop (cioè le sole istruzioni dello stralcio di codice dato, esclusa la li) nel linguaggio macchina RISC-V utilizzando le tabelle di conversione date in appendice. Si indichi a quale indirizzo ciascuna di queste istruzioni viene allocata.

Per codificare le istruzioni del loop nel linguaggio macchina RISC-V utilizzando le tabelle di conversione, dobbiamo prima tradurre ogni istruzione in binario, poi posizionarla all'indirizzo corrispondente, considerando che la prima istruzione della funzione è allocata all'indirizzo 0x0040 0000.

Ecco le istruzioni del loop tradotte in linguaggio macchina RISC-V:

```assembly
# lw s1, 0(a0)
0000000 00000 00001 00010 000 00000 0000011

# add s2, s2, s1
0000000 00001 00010 100 00000 00000 0110011

# addi a0, a0, 4
000000000100 00000 00010 000 00100 0010011

# addi s0, s0, 1
0000000 00010 00010 001 00001 0010011

# blt s0, a1, LOOP
000000000001 00010 00010 000 00000 1100011
```

Ora, assegniamo a ciascuna istruzione l'indirizzo corrispondente, partendo dall'indirizzo 0x0040 0000:

- `lw s1, 0(a0)` è all'indirizzo `0x0040 0000`.
- `add s2, s2, s1` è all'indirizzo `0x0040 0004`.
- `addi a0, a0, 4` è all'indirizzo `0x0040 0008`.
- `addi s0, s0, 1` è all'indirizzo `0x0040 000C`.
- `blt s0, a1, LOOP` è all'indirizzo `0x0040 0010`.

Quindi, ecco le istruzioni del loop codificate nel linguaggio macchina RISC-V con i rispettivi indirizzi di memoria:

```assembly
0x0040 0000: 0000000 00000 00001 00010 000 00000 0000011
0x0040 0004: 0000000 00001 00010 100 00000 00000 0110011
0x0040 0008: 000000000100 00000 00010 000 00100 0010011
0x0040 000C: 0000000 00010 00010 001 00001 0010011
0x0040 0010: 000000000001 00010 00010 000 00000 1100011
```

d) [BONUS] Si riscriva il loop originale in maniera da ridurre il numero di istruzioni eseguite.



Scrivere un programma assembly RISC-V che implementi una funzione C, chiamata stringToDec, avente la seguente signature:
int stringToDec (char *numero)
La funzione converte una stringa ASCII (l’argomento char *numero), che rappresenta un numero decimale intero positivo o negativo espresso in forma testuale, in un numero intero,
che viene poi ritornato al chiamante. Il programma assume che il registro x10 contenga l’indirizzo della stringa numero, che è così composta:
• un carattere “+” or “−” opzionale (potrebbe non esserci);
• una qualunque combinazione di cifre decimali tra 0 e 9, che rappresentano il numero;
• il carattere terminatore ‘\0’.
Il programma deve calcolare il numero intero corrispondente a questa stringa di cifre, e mettere
il risultato dentro x10. Se il programma trova un carattere diverso da quelli descritti deve
terminare con un segnale di errore, cioè mettendo il valore -1 in x10.

Esericioz tutor