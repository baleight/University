# Esercizi d'esame

---

### 

---

### Si dica quale istruzione assembly corrisponde alla seguente stringa binaria:

Ricordando lo schema di codifica delle istruzioni RISC-V R-type

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-03-14-42-22-image.png)![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-03-14-42-43-image.png)

#### 1: `0000 0001 1010 0010 1100 0101 1011 0011`

#### 2:`0000 0000 0010 0011 0111 0011 1011 0011`

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-04-14-50-29-image.png)

- opcode: 011 0011 - 33

- rs1: 00110 - 6

- rs2: 00010 - 2

- rd: 00111 - 7

- funct3: 111 - 7

- funct7: 0000000 - 00

                                                    `and x7, x6, x2`

---

## Assembly > Esadecimale:

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-03-14-43-07-image.png)

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-03-14-43-22-image.png)

<mark>da fare su carta</mark>

### 1: `bne x10, x11, 0xC`

- <mark>opcode</mark>(7 bit) 110 0111 - 67
- imm[11:1] (11 bit)
- <mark>funct3 </mark>(3 bit) 001 - 1
- rs1 (5 bit)
- rs2 (5 bit)
- imm[12] (1 bit)
- <mark>funct7</mark> 000 000 0

### 2: `bne x29, x10, 0xFFC`

- opcode (7 bit) 110 0111 - 67
- imm[11:1] (11 bit)
- funct3 (3 bit) 001 - 1
- rs1 (5 bit)
- rs2 (5 bit)
- imm[12] (1 bit)

Per l'istruzione BNE (Branch Not Equal), la codifica del campo immediato è 12 bit, divisi come segue: il bit più significativo, poi gli 11 bit successivi, seguiti dal bit 0 e poi gli altri 4 bit meno significativi. Quindi, 0xFFC in binario è 1111 1111 1100. Ora dobbiamo convertire questa rappresentazione in binario per adattarla al formato immediato dell'istruzione SB-type.

Ora, se raggruppiamo i bit, otteniamo:

- 1 (bit 12)
- 11111111100 (bit 11-1)
- 0 (bit 0)
- 1111 (bit 10-7)

Traducendo questi gruppi di bit in esadecimale, otteniamo:

- bit 12: 1 (0x1)
- bit 11-1: 0xFFC (0xFFC)
- bit 0: 0 (0x0)
- bit 10-7: F (0xF)

Ora, per gli altri campi:

- opcode (bne): 1100011 (0x63 in esadecimale)
- rs1 (x29): 11101 (0x1D in esadecimale)
- rs2 (x10): 01010 (0xA in esadecimale)
- funct3 (bne): 001 (0x1 in esadecimale)

Mettendo tutto insieme, otteniamo la rappresentazione esadecimale corretta:

```
0xFEAE9CE7
```

### 3: `bne x5, x6, 0xFE9`

0xFE9 e' un immediato con 3 cifre esadeciamali

**bne**appartiene alla famiglia sb che ah questo formato:

da lui la configurazione dei bit

- Converti 0xFE9 in binario -> 1111 1110 1001
  Questi 12 bit sono sparsi negli altri campi,

- Formiamo i bit del immediato-> 1111110

- 5 bit de opcode i bit che vanno da 4 a 1-> 10011
  
  ![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-01-20-53-04-WhatsApp%20Image%202024-05-01%20at%2020.52.23_b6bbafb5.jpg)

- per x_5 traduciamo il numero 5 -> 00101 che rappresenta rs1  in rs2 mettiamo quindi 00101

- per rs1 <img src="file:///C:/Users/baleo/Pictures/GitUni/imagesMarkText/2024-05-04-15-39-03-2024-05-01-20-23-56-image.png" title="" alt="" width="158"> 00110

- bne ha come istruzione opcode(ce la do il prof) 1100111 e funct3 001

- Convertiamo il numero ottenuto in esadecimale
  
  <img src="file:///C:/Users/baleo/Pictures/GitUni/imagesMarkText/2024-05-04-15-39-31-2024-05-01-20-30-49-image.png" title="" alt="" width="423">

```
`0xfc6299e7`
```

### 4: `xor x12, x5, x6`

Interpretazione dei campi:

- Opcode: `0000011` (corrispondente a XOR in RISC-V)
- rs1: `00000` (x5)
- rs2: `00110` (x6)
- Funct3: `100` (è il codice per XOR)
- rd: `01100` (x12)

Ora possiamo riassemblare questi campi in una stringa binaria:

`0000 000-0 0110 -0010 1-100 -0110 0-011 0011`
Convertendo questa stringa binaria in esadecimale otteniamo:

```
0x062C633
```

### 5:

---

## Esadecimale > Assembly

### 1: `0x0073C433`

Cosa la compone?

- Traduciamola in formato binario `0000 0000 0111 0011 1100 0100 0011 0011`

- Otteniamo il nostro Opcode da gli ultimi 7 bit: 011 0011
  Appartiene alla famiglia R -> le istruzioni che hanno come operandi sempre dei registri

- Grazie alla famiglia sappiamo come dividere il binario 

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-04-15-43-41-2024-05-01-19-21-56-image.png)

- Guardiamo prima `OPCODE > f3 > f7`

- Con f3 100 sappiamo che e' un **xor**

- Dobbiamo inserire gli operandi rd l registro di destinazione e' 01000
  rs1 e il primo operando e rs2 e il secondo operando

- I registri sono 32 tramite la codifica di 01000 sappiamo che il registro corrisponde a x8, Ricorda se abbiamo una sola cifra sicuro che sara una potenza di 2^3

- Per Rs1 e Rs2 stessa cosa: 00111, 00111 che corrispondono x7 x7

L'istruzione e' xor x_8 , x_7 , x_7 ->raddopio x7 e lo aggiungo in x8

### 2: `0xFEA59CE7`

La stringa esadecimale 0xFEA59CE7 corrisponde alla seguente sequenza binaria:

```
1111 1110 1010 0101 1001 1100 1110 0111
```

Ecco come viene interpretata per ottenere l'istruzione assembly:

- I primi 7 bit (1111111) corrispondono all'opcode dell'istruzione branch not equal (bne) in RISC-V.
- I successivi 5 bit (01010) corrispondono al registro di destinazione (x10).
- I 5 bit successivi (01011) corrispondono al registro di origine (x11).
- Gli ultimi 12 bit (001100111101) corrispondono all'offset (offset immediato) dell'istruzione, che nel formato esadecimale è 0xFFC.

Quindi, l'istruzione assembly corrispondente è:

```
bne x11, x10, 0xFFC
```

### 3:

$\{ 2^N, \text{ se } O = 0 \quad \log_2 N, \text{ se } O = 1 \} ]$

```nasm
#Si assume che gli argomenti vengano passati nei registri a0(per O) e a1(per N)

.globl calculate_result

calculate_result:
    mv t1, a1        # Copia il valore di N in t1
    li t2, 0         # Inizializza t2 a 0 (contatore per la log2)
    li t3, 1         # Inizializza t3 a 1 (costante per la potenza)

    beq a0, zero, pow  # Se O = 0, salta a pow (calcolo della potenza)

log:
    srli t1, t1, 1    # Shift right logico di t1 di 1 (divisione per 2)
    addi t2, t2, 1    # Incrementa il contatore per la log2

    bgt t1, t3, log   # Se t1 > 1, torna a log

    mv a0, t2         # Se t1 = 1, copia il valore del contatore in a0 (risultato della log2)
    j end             # Salta a end

pow:
    sll a0, t3, t1    # Shift left logico di t3 (1) di t1 (N) (calcolo di 2^N)

end:
```

Spiegazione:

- La funzione inizia copiando il valore di N dal registro a1 al registro t1.
- Viene inizializzato il registro t2 a 0 per contare il numero di iterazioni per il calcolo della log2.
- Viene inizializzato il registro t3 a 1 per essere utilizzato come costante nella potenza.
- Se O è uguale a zero, salta direttamente al calcolo della potenza.
- Nel caso in cui O sia diverso da zero, la funzione esegue il calcolo della log2 di N.
- Una volta terminato il calcolo della log2, il risultato viene copiato in a0.
- Se O è zero, la funzione esegue il calcolo di 2^N utilizzando l'istruzione di shift a sinistra logica.
- Alla fine, la funzione termina.

---

## Cosa ritorna/fa il programma?

### 1:

si assuma che corrisponda all'implementazione di una funzione la cui interfaccia C è
`int fun (int n);`

```nasm
//a0=n
fun: addi s0, zero, 0 //s0=0
    addi s1, zero, 1 //s1=1
    add t0, zero, a0 //t0=a0
loop: beq s0, t0, exit //s0=t0 -> exit
    add s1, s1, s1 //s1=s1+s1
    addi s0, s0, 1 //s0=s0+1
    jal zero, loop
exit: add a0, zero, s1 //a0=s1
    jalr zero, 0(ra) //return ra[a]
```

Ritorna $2^n$

L'istruzione `jalr` (Jump and Link Register) è utilizzata per
 effettuare un salto a un'istruzione a un indirizzo specificato, 
memorizzare l'indirizzo dell'istruzione successiva nel registro `$ra` (registro di salvataggio) e caricare l'indirizzo di destinazione da un registro anziché un valore immediato.

### 2:

#### Quale e' il valore contenuto in x5 dopo l'esecuzione di questa istruzione:

```c
addi x5, x0, 1 //x5 = 1
addi x6, x0, 5 //x6 = 5
loop:
blt x6, x0, exit // x6 < 0 exit non uguale ma -1
addi x6, x6, -1 //x6 = x6 -1 
slli x5, x5, 1 //x5 = x5 * 2, shift a sinistra e come fare una potenza
jal x0, loop //6 volte
exit:
```

Cosa scegli tra: 2^5 o 2^6 ->

1*2*2*2*2*2*2 =64

#### Quale e' il valore contenuto in x5 dopo l'esecuzione di questa istruzione:

```nasm
//x5=0
//x6=10
Ciclo:
    blt x6, x0, exit //x6 < 0
    addi x6, x6, -1
    addi x5, x5, 3 // 3*11
    jal x0, ciclo
exit

x5 = 3*3*3 *3*3*3* *3*3*3* *3*3 > 33
```

### 3:

```qasm
//assumiamo int arr[6]={3,1,4,1,5,9}
s0=0xBRFFFFF00
add t0, x0, x0 //t0=0
loop: slti t1, t0, 6//slti rd,rs1,imm if(rs1<imm)rd=1 else rd=0
beq t1, 0, end //t1=0 per 6 volte
slli t2, t0, 2 //t2= t0*4
add t3, s0, t2 //t3=s0+t2
lw t4, 0(t3) //t4= t3[0]
sub t4, x0, t4 //t4= 0-t4
sw t4, 0(t3)//t3[0] = t4
addi t0, t0, 1 // t0=t0+1
jal x0, loop
end:
```

Produce in uscita la sovvrascrizione del array arr[6] in cui i valori sono il negato degli elementi in origine:

`int arr[6]={-3,-1,4-,1,-5,-9}`

s0=0xBRFFFFF00: Inizializzazione del registro `s0` con l'indirizzo base dell'array `arr`.
**add t0, x0, x0**: Inizializzazione del registro `t0` con zero. Questo registro funge da contatore per il loop.
**loop: slti t1, t0, 6**: Verifica se il valore contenuto in `t0` è inferiore a 6. Il risultato sarà memorizzato in `t1`.
**beq t1, 0, end**: Se il risultato di `slti` è 0 (quindi `t0` è uguale o maggiore di 6), il programma salta alla fine del loop.
**slli t2, t0, 2**: Moltiplica il valore di `t0` per 4 (shift left logico di 2 bit) e memorizza il risultato in `t2`.
**add t3, s0, t2**: Calcola l'indirizzo dell'elemento corrente dell'array sommando l'indirizzo base `s0` con l'offset calcolato in `t2`. Il risultato è memorizzato in `t3`.
**lw t4, 0(t3)**: Carica il contenuto della memoria all'indirizzo `t3` nell'elemento `t4`.
**sub t4, x0, t4**: Calcola il negativo del valore caricato da `t3` e lo memorizza in `t4`.
**sw t4, 0(t3)**: Memorizza il valore negativo calcolato in `t4` nella posizione di memoria corrispondente all'indirizzo `t3`.
**addi t0, t0, 1**: Incrementa il contatore del loop.
**jal x0, loop**: Salta all'etichetta `loop` per eseguire nuovamente il ciclo.
**end**: Etichetta per indicare la fine del loop.

### 4:

```nasm
//assumiamo che x12 = 0 e x13 = 10
CICLO:
blt x13, x0, EXIT //x13 < 0 exit , 11 volte
addi x13, x13, -1 //x13 = x13 -1
addi x12, x12, 2 //x12=x12+2 //2*11
jal x0, CICLO //jump al ciclo
EXIT:
```

`2*2*2 *2*2*2 *2*2*2*2*2 = 22`

### 5:

## Scegli la risposta corretta:

### 1:

La moltiplicazione in RISC-V:
a) Può essere sostituita con uno shift a sinistra quando il moltiplicatore è una potenza
di due
b) È realizzabile tramite una sequenza di sottrazioni
c) Richiede logica dedicata, spesso pipelined
d) Esegue in un ciclo come tutte le operazioni aritmetico-logiche

```nasm
mul a2, a0, a1
#Moltiplica i numeri in a0 e a1,
e salva il risultato in a2
```

a) **Può essere sostituita con uno shift a sinistra quando il moltiplicatore è una potenza di due**:

- Quando moltiplichiamo un numero per una potenza di due, in realtà stiamo eseguendo un'operazione di shift a sinistra. Ad esempio, moltiplicare per 2 è equivalente a uno shift a sinistra di un bit, moltiplicare per 4 è equivalente a uno shift a sinistra di due bit, e così via. Nei processori RISC-V e in molti altri, lo shift a sinistra è un'operazione molto semplice e veloce da eseguire, quindi quando il moltiplicatore è una potenza di due, è efficiente sostituire la moltiplicazione con uno shift a sinistra.

b) **È realizzabile tramite una sequenza di sottrazioni**: no

c) **Richiede logica dedicata, spesso pipelined**:

- Anche se la moltiplicazione può richiedere logica dedicata, la presenza di questa logica non è esclusivamente legata al fatto che la moltiplicazione debba essere pipelinata. Inoltre, non tutte le implementazioni di moltiplicazione utilizzano una pipeline.

d) **Esegue in un ciclo come tutte le operazioni aritmetico-logiche**:

- La moltiplicazione è solitamente più complessa rispetto alle operazioni aritmetico-logiche elementari, come l'addizione e la sottrazione, e di solito richiede più cicli di clock per essere eseguita. Non è sempre vero che la moltiplicazione possa essere eseguita in un singolo ciclo come altre operazioni aritmetico-logiche.

### 2:

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-04-16-01-24-2024-05-04-15-47-18-2024-05-02-19-45-39-image.png) 

Shift moltiplicazione per 2,perche si moltiplica per due? Un brach e' un alterazione del control flow lineare(istruzione piu 4 piu 4 piu 4), il minimo salto quindi che non e' un control flow lineare? e' il doppio, il salto piu piccolo possibile e di due byte e non di 4

Il risultato finale dell'esercizio è 0x2000 0FFE. Per capire come si è arrivati a questo risultato, bisogna considerare diversi concetti relativi al calcolo dell'offset e alla codifica delle istruzioni nel formato compatto.

1. Calcolo dell'offset per l'istruzione branch if equal (beq): 
   Il campo immediato dell'istruzione beq è di 12 bit, il che significa che può rappresentare un'offset compreso tra -2048 e 2047. Tuttavia, essendo l'offset positivo, il valore massimo rappresentabile è (0111 1111 1111)₂, che in decimale è 2047.

2. **Shift e moltiplicazione per due:** 
   Quando viene eseguita un'istruzione di salto condizionato come beq, l'offset viene moltiplicato per due prima di essere sommato al valore del program counter (PC). Questo perché le istruzioni sono allineate in memoria ogni 4 byte (o 2 byte nel caso dell'estensione C dell'instruction set compatto a 16 bit). Quindi, un salto di 1 istruzione corrisponde a un offset di 4 byte, quindi un'istruzione successiva nel flusso del programma si trova a 4 byte di distanza da quella corrente.

3. **Massimo salto in avanti:** Considerando il valore del PC iniziale di 0x2000 0000 e aggiungendo l'offset massimo di 2047 moltiplicato per due, otteniamo:
   
   0x2000 0000 + (2047 * 2) = 0x2000 0000 + 4094 = 0x2000 0FFE

Quindi, il risultato finale è 0x2000 0FFE, che rappresenta l'indirizzo più grande che può essere raggiunto tramite l'istruzione beq partendo da un PC di 0x2000 0000.

### 3:

---

## Scrivere un pezzo di codice assembly

### 1: che effettui l’operazione `arr[1] = arr[0] + arr[2]`

```nasm
lw t0, 0(s0)    # Carica il contenuto di arr[0] nel registro t0
lw t1, 8(s0)    # Carica il contenuto di arr[2] nel registro t1
add t2, t0, t1  # Somma il contenuto di t0 (arr[0]) e t1 (arr[2]), e salva il risultato in t2
sw t2, 4(s0)    # Salva il contenuto di t2 (somma di arr[0] e arr[2]) nella posizione di memoria arr[1] s0)
```

---

## Da C a Assembly

```nasm
int acc (int array[], int size) {
int i, sum = 0;
for (i= 0; i< size; i+= 1)
sum += array[i];
}
```

 Si scriva la corrispondente funzione assembly RISC-V, assumendo che gli
argomenti vengano forniti in x10 e x11 e gestendo opportunamente lo stack

```nasm
.globl acc# Dichiarazione globale della funzione
.text                   # Sezione del testo
acc:
    addi x5, x0, 0      // Inizializza il contatore i a 0 (x5 = i)
    addi x28, x0, 0     // Inizializza la variabile di accumulazione sum a 0 (x28 = sum)

loop1:
    slli x6, x5, 3      // Moltiplica il valore di i per 8 (dato che si sta utilizzando un array di interi, ciascun elemento occupa 8 byte)
                        // Questo calcola l'offset necessario per accedere all'i-esimo elemento dell'array
    add x7, x10, x6     // Calcola l'indirizzo del i-esimo elemento dell'array
                        // x10 contiene il puntatore all'array
                        // x7 conterrà l'indirizzo di array[i]

    lw x29, 0(x7)       // Carica il valore dell'i-esimo elemento dell'array in x29
                        // x29 contiene ora il valore di array[i]

    add x28, x28, x29   // Aggiunge il valore di array[i] alla somma corrente (x28 = sum + array[i])

    addi x5, x5, 1      // Incrementa il contatore i di 1 (i = i + 1)

    blt x5, x11, loop1  // Se i < size, salta a loop1
                        // x11 contiene la dimensione dell'array

    add x10, x28, x0    // Alla fine del ciclo, copia il valore della somma (x28) nel registro x10
                        // Questo è il valore che sarà restituito dalla funzione

    jalr x0, 0(x1)      // Ritorna al chiamante
```

### Assembly a C
