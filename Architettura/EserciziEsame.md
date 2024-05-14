# Esercizi d'esame





---

## Binario > Assembly:

Ricordando lo schema di codifica delle istruzioni RISC-V R-type

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-03-14-42-22-image.png)![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-03-14-42-43-image.png)

### 1: `0000 0001 1010 0010 1100 0101 1011 0011`✔

​	`xor x17, x2, x26`

### 2:`0000 0000 0010 0011 0111 0011 1011 0011`✔

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

Sito per convertire in esadecimale
https://www.eg.bucknell.edu/~csci206/riscv-converter/index.html

Ecco un breve riassunto dei passaggi per

bne x10, x11, 4

1. **Identificazione del tipo di istruzione**: Hai riconosciuto che l'istruzione è di tipo SB (branch) dal Green Card, poiché è una BNE (Branch Not Equal).

2. **Ricerca dei valori dei campi dell'istruzione**: Hai determinato i valori corretti per opcode e funct3 dall'informazione fornita nel Green Card.

3. **Conversione in binario**: Hai convertito i registri e i valori immediati in binario, rappresentando i registri come i loro numeri in binario e l'immediato come i suoi bit binari.

4. **Organizzazione dei bit**: Hai organizzato i bit in base alla struttura dell'istruzione SB, seguendo l'ordine specificato nel Green Card.

5. **Conversione in esadecimale**: Infine, hai raggruppato i bit in gruppi di 4 e li hai convertiti in equivalenti esadecimali.

Il risultato finale è stato "**0x08B51263**". Questo rappresenta correttamente l'istruzione BNE x10, x11, 4 in formato esadecimale per il linguaggio assembly RISC-V. Se hai ulteriori domande o hai bisogno di ulteriori chiarimenti su qualcosa, non esitare a chiedere!

### 1: `bne x10, x11, 0xC `✔

- <mark>opcode</mark>(7 bit) 110 0111 - 67
- imm[11:1] (11 bit)
- <mark>funct3 </mark>(3 bit) 001 - 1
- rs1 (5 bit)
- rs2 (5 bit)
- imm[12] (1 bit)
- <mark>funct7</mark> 000 000 0

```
0x00BA1C67
```



### 2: `bne x29, x10, 0xFFC `✔

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

### 3: `bne x5, x6, 0xFE9` ✔

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

### 4: `xor x12, x5, x6` ✔

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

### 5: `blt x2, x3, 0x7F0` ✔

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-06-14-51-36-image.png)

 `0111 1110 0011 0001 0100 0000 1110 0111`

### 6: `addi x10, x10, 4` ✔

0x00450513 no Sbagliato -> 0x00457513 corretto

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-06-15-25-04-image.png)

7:

Dato il seguente stralcio di codice assembly RISC-V

```nasm
L1: add s1,s2,a0
sb a1,0(s1)
beq s0,zero,L2
addi s2,s2,1
jal zero,L1
L2: jalr zero, ra
```

Si produca l’equivalente codice binario. Dove sono implicate istruzioni di alterazione del control
flow si trasformino le label nei corrispondenti offset di salto.

```nasm
# Aggiunge il contenuto di x18 e x10 e memorizza il risultato in x9
add x9, x18, x10

# Memorizza il contenuto di x11 nell'indirizzo puntato da x9
sb x11, 0(x9)

# Se il contenuto di x8 è uguale a 0, salta a 0x006 (3 istruzioni avanti)
beq x8, x0, 0x012

# Incrementa il contenuto di x18 di 1
addi x18, x18, 1

# Salta all'indirizzo L1 (4 istruzioni indietro)
jal x0, L1

# Salta all'indirizzo contenuto in x1
jalr x0, 0(x1)
```

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-06-20-36-14-image.png)

---

## Esadecimale > Binario > Assembly

### 1: `0x0073C433 `✔ 

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

### 2: `0xFEA59CE7`✔

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

### 3: `0x00450513`✔

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-06-14-53-18-image.png)

```assembly
addi x10, x10, 4
Utilizza un immediato ovvero una costante si 4
Non ha i bit disordinati ovvero come nel bne che sono una nella 12 e l'altra nel 1:4,no
Ha 12 bit di immediato 
|anche se i primi quattro bit sono zero, l'immediato rimane un valore a 12 bit esteso  a 32 bit per l'elaborazione. Pertanto, in questo caso, l'immediato avrà comunque una  lunghezza di 12 bit, esteso a 32 bit per l'elaborazione effettiva dell'istruzione.
```

### 4: `0x7F802403` ?

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-06-15-35-12-image.png)

```
lw x8, 2036(x0)
```



### 5: ✔

Si consideri il seguente frammento di memoria istruzioni (indirizzo,
istruzione):

```esadecimale
0x44 0x00052483
0x48 0x00940433
0x4C 0x00450513
0x50 0xFEB54AE7
```

Basandosi sulle tabelle di decodifica fornite in appendice
**a)** Tradurre le istruzioni in un corrispondente stralcio di programma assembly. [5 pt]

```nasm
0000 0000 0000 0101 0 010 01001 000 0011
0000 0000 1001 0100 0 000 01000 011 0011
0000 0000 0100 0101 0 000 01010 001 0011
1111 1110 1011 0101 0 100 10101 110 0111
lw x9, 0(x10)
add x8, x8, x9
addi x10, x10, 4
blt x10, x11, 1111 1111 1010 (0xFFA) 
```

**b)** Dire se nel programma tradotto ci sono istruzioni che alterano il control flow. In caso affermativo, osservando gli indirizzi a cui sono memorizzate le istruzioni tradurre opportunamente i loro campi immediato in modo da riscrivere il
programma assembly con le corrispondenti label 

sapendo che il PC per la blt è 0x50, e che la blt shifta il suo immediato a sinistra di un bit prima di utilizzarlo, la label diventa:
![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-06-15-54-42-image.png)

### 7:

Usando le tabelle fornite in appendice si decodifichi il seguente binario RISC-V

```nasm
# Hesadecimale:
0x0014 0x00052483      # Indirizzo: 0x0014, Valore: 0x00052483
0x0018 0x00990933      # Indirizzo: 0x0018, Valore: 0x00990933
0x001C 0x00450513      # Indirizzo: 0x001C, Valore: 0x00450513
0x0020 0x00140413      # Indirizzo: 0x0020, Valore: 0x00140413
0x0024 0xFEB448E7      # Indirizzo: 0x0024, Valore: 0xFEB448E7

# Codice RISC-V:
LOOP:                   # Etichetta per il ciclo
    lw s1, 0(a0)        # Carica il valore dalla memoria all'indirizzo contenuto in a0 in s1
    add s2, s2, s1      # Aggiunge il valore di s1 a s2
    addi a0, a0, 4      # Incrementa l'indirizzo in a0 di 4 byte (per puntare al prossimo dato)
    addi s0, s0, 1      # Incrementa il contatore s0 di 1
    blt s0, a1, LOOP    # Salta all'etichetta LOOP se s0 è minore di a1

# Codice Assembly:
LOOP:                   # Etichetta per il ciclo
    lw x9, 0(x10)       # Carica il valore dalla memoria all'indirizzo contenuto in x10 in x9
    add x18, x18, x9    # Aggiunge il valore di x9 a x18
    addi x10, x10, 4    # Incrementa l'indirizzo in x10 di 4 byte (per puntare al prossimo dato)
    addi x8, x8, 1      # Incrementa il contatore x8 di 1
    blt x8, x11, LOOP   # Salta all'etichetta LOOP se x8 è minore di x11

# L’immediato vale 0xFF8 senza Lshift (1pt) e 0xFF0 con Lshift (2pt)
```

### 8:

```nasm
# Hesadecimale:
0x4000 0x00A904B3    # Istruzione: beq x8, x0, 0x00A
0x4004 0x00B48023    # Istruzione: add x9, x18, x10
0x4008 0x00040A67    # Istruzione: sb x11, 0(x9)
0x400C 0x00190913    # Istruzione: addi x18, x18, 1
0x4010 0xFF1FF06F    # Istruzione: jal x0, 0xFFFF8
0x4014 0x00008067    # Istruzione: jalr x0, 0(x1)

# Codice RISC-V:
beq x8, x0, 0x00A    # Salta a 0x00A se x8 è uguale a x0
add x9, x18, x10     # x9 = x18 + x10
sb x11, 0(x9)        # Memorizza il contenuto di x11 all'indirizzo puntato da x9
addi x18, x18, 1     # x18 = x18 + 1
jal x0, 0xFFFF8      # Salta a 0xFFFF8
jalr x0, 0(x1)       # Salta all'indirizzo contenuto in x1

# Codice Assembly:
L1:                   # Etichetta L1
beq x8, x0, L2       # Salta a L2 se x8 è uguale a x0
add x9, x18, x10     # x9 = x18 + x10
sb x11, 0(x9)        # Memorizza il contenuto di x11 all'indirizzo puntato da x9
addi x18, x18, 1     # x18 = x18 + 1
jal x0, L1           # Salta a L1
L2:                   # Etichetta L2
jalr x0, 0(x1)       # Salta all'indirizzo contenuto in x1
```

### 9:

Dato il seguente programma binario RISC-V

```
0x00a00513
0x004000ef
Oxff810113
0x00813023
0x00000413
0x00a40433
0xfff50513
Oxfea04ce3
0x00013403
0x00810113
0x00008067
```

Si produca l'equivalente codice assembly. Dove sono implicate istruzioni di alterazione del control flow si trasformino gli offset di salto in opportune label. Si descriva la struttura e funzionalità del codice.

## Da C a Assembly

### 1:

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

### 2:   ✔

```nasm
int i = 0;
while (save[i] == k) {
i += 1;
}
return i;
}
```

```assembly
#k -> x10
#save*-> x11

addi x5, x5, 0 #i


loop:
    slli x6,x5,3 #x6+i*8
    add x7,x11,x6 #x7= save[i]
    
    beq x7, x10, ret #x7 == k esci, while esci finche e' vero
    addi x5,x5,1 #i++ altrimenti
    j loop #ritorna indietro

ret:
    mv ra, i
    jalr x0, 0(ra)
#Salta all'indirizzo contenuto in ra che e' la chiamata di funzione e restituisce al chiamante
```





### 3:

Quale espressione C corrisponde alle seguenti istruzioni RISC-V? Si assuma che le variabili
f, g, h, i, j siano assegnate ai registri x5, x6, x7, x28, x29, rispettivamente, che A e B siano array di
double (8 bytes), e che il loro indirizzo base sia nei registri x10 e x11.

```nasm
slli x30, x5, 3 // x30 = f*8
add x30, x10, x30 // x30 = &A[f]
slli x31, x6, 3 // x31 = g*8
add x31, x11, x31 // x31 = &B[g]
ld x5, 0(x30) // f = A[f]
addi x12, x30, 8 // x12 = &A[f] + 8 = &A[f+1]
ld x30, 0(x12) // x30 = A[f+1]
add x30, x30, x5 // x30 = A[f+1]+f
sd x30, 0(x31) // B[g] = A[f+1]+f        

```

Output: `B[g] = A[f+1]+f`

### 4: ✔

```c
clear1 (int array[], int size) {
int i;
for (i= 0; i< size; i+= 1)
array[i] = 0;
}
```

Si scriva il corrispondente programma assembly RISC-V, assumendo che gli argomenti vengano
forniti in x10 e x11:

```nasm
li x5, 0          // i = 0

loop1:
    slli x6, x5, 3     // x6 = i * 8
    add x7, x10, x6    // x7 = address of array[i]
    sd x0, 0(x7)       // array[i] = 0
    addi x5, x5, 1     // i = i + 1
    blt x5, x11, loop1 // if (i < size), go to loop1

```

### 5:

```c
typedef lli long long int;
lli myfun (lli a, lli b, lli c, lli d)
{
lli toret;
toret = ((a << 5) + b) – ((c >> 2) + d);
return toret;
}
```

### 6:

Implementare in assembly RISCV la funzione C memcpy
`void memcpy(void* dest, const void src, size_t count);`
che prende in ingresso un puntatore a un buffer di memoria destinazione dest, un puntatore a un buffer di memoria sorgente src e un numero di bytes count. La funzione copia count bytes di src in dest.
Gestire correttamente lo stack come da calling convention, cosi come il passaggio dei parametri di ingresso e di uscita sui registri appropriati. Scrivere la funzione main che invoca memcpy. mostrando anche l'allocazione degli array sul segmento dati statico del file ELF.



### Assembly a C

### 1:  ✔

```nasm
CIC:
addi x5, x0, 0
addi x6, x0, 0
addi x29, x0, 100
ld x7, 0(x10)
add x5, x5, x7
addi x10, x10, 8
addi x6, x6, 1
blt x6, x29, CIC
```

```c
int Ris = 0;
int n=100;
for (int i=0; i<n; i++)
Ris = Ris + MemVett[i];
```

### 2: ✔

```nasm
CICLO: beq x6, x0, FINE
       addi x6, x6, -1
       addi x5, x5, 2
       jal x0, CICLO
FINE:
```

#### a. Scrivere la procedura C equivalente. Si supponga che i registri x5 e x6 contengano rispettivamente le variabili intere acc e i.

```c

while (i>0)
{
acc += 2;
i--;
}
oppure while (i-- > 0) acc += 2;
oppure for ( ; i>0; i--) acc += 2;
```

#### b. Si supponga che il registro x6 sia inizializzato col valore numerico N. 

Quante istruzioni RISC-V verranno eseguite dal ciclo riportato sopra?

> N x 4 + 1
>
> Quindi, se il ciclo viene eseguito "N" volte, avrai "4N" istruzioni  all'interno del ciclo, e poi c'è una istruzione di salto (jal) che porta nuovamente all'inizio del ciclo. Quindi, il totale delle istruzioni  sarà "4N + 1".

#### c. Sostituire l’istruzione beq con l’istruzione blt. Scrivere l’equivalente codice C.

```c
while (i >= 0)
    acc += 2;
	i--;
```









---

## Cosa ritorna/fa il programma?

### 1:  ✔

si assuma che corrisponda all'implementazione di una funzione la cui interfaccia C è
`int fun (int n);`

```assembly
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

Ritorna
$$
2^n
$$
L'istruzione `jalr` (Jump and Link Register) è utilizzata per
 effettuare un salto a un'istruzione a un indirizzo specificato, 
memorizzare l'indirizzo dell'istruzione successiva nel registro `$ra` (registro di salvataggio) e caricare l'indirizzo di destinazione da un registro anziché un valore immediato.

### 2: ✔

Quale e' il valore contenuto in x5 dopo l'esecuzione di questa istruzione:

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

1*2*2*2*2*2*2 =64 2 alla 6

ho spostato a sinistra 1: 00**1**00000

### 3: ✔

```assembly
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

### 4: ✔

```assembly
//assumiamo che x12 = 0 e x13 = 10
CICLO:
blt x13, x0, EXIT //x13 < 0 exit , 11 volte
addi x13, x13, -1 //x13 = x13 -1
addi x12, x12, 2 //x12=x12+2 //2*11
jal x0, CICLO //jump al ciclo
EXIT:
```

`2*2*2 *2*2*2 *2*2*2*2*2 = 22`

### 5: ✔

```assembly
.globl main            # Dichiarazione globale della funzione main

.data                  # Sezione dei dati
arr: .word 10, 3, 4, 2, 1  # Dichiarazione e inizializzazione di un array di 5 parole
n: .word 5             # Dichiarazione e inizializzazione di una variabile intera

.text                  # Sezione del codice
main:                  # Etichetta per la funzione main

    la t0, arr         # Carica l'indirizzo di memoria dell'array arr nel registro t0
    la t1, n           # Carica l'indirizzo di memoria della variabile n nel registro t1
    lb t1, 0(t1)       # Carica il valore di n (numero di elementi nell'array) nel registro t1
    lw t2, 0(t0)       # Carica il primo elemento dell'array arr nel registro t2

ciclo:                 # Etichetta per il ciclo

    addi t1, t1, -1    # Decrementa il contatore n
    beq t1, zero, exit # Se il contatore n è zero, salta all'etichetta exit
    slli t3, t1, 2     # Calcola l'offset per l'elemento corrente nell'array (moltiplicando l'indice per 4)
    add t3, t0, t3     # Calcola l'indirizzo di memoria dell'elemento corrente nell'array
    lw t3, 0(t3)       # Carica l'elemento corrente dell'array nell'elemento t3
    sub t2, t2, t3     # Sottrae l'elemento corrente di arr da t2
    j ciclo            # Salta all'inizio del ciclo

exit:                  # Etichetta per l'uscita dalla funzione
```

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-06-15-45-01-image.png)

### 6: ✔

```assembly
fun:
    li t0, 5          # Carica il valore 5 nel registro t0
    li t1, 1          # Carica il valore 1 nel registro t1
    add s0, t0, t1   # Somma i valori nei registri t0 e t1 e memorizza il risultato in s0
    mv a0, s0         # Copia il valore da s0 ad a0 per passarlo come argomento a fun2
    jal ra, fun2      # Chiama la funzione fun2 e salta all'indirizzo di ritorno
    add a0, a0, t0   # Aggiunge il valore nel registro t0 al valore restituito da fun2 e memorizza il risultato in a0
    ret               # Restituisce al chiamante

fun2:
    addi t0, a0, 1    # Incrementa il valore in a0 di 1 e memorizza il risultato in t0
    ret               # Restituisce al chiamante
```

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-06-15-45-59-image.png)

Il pezzo di codice assembly fornito non rispetta la convenzione di chiamata standard (calling convention) poiché non gestisce correttamente i registri utilizzati per passare gli argomenti e restituire i valori.

Nel codice assembly RISC-V, la convenzione di chiamata prevede di utilizzare determinati registri per passare gli argomenti e restituire i valori. Di solito, ad esempio, i valori restituiti sono memorizzati nel registro `a0`, mentre gli argomenti vengono passati attraverso i registri `a0`, `a1`, `a2`, ecc.

In questo codice assembly, la funzione `fun()` carica il risultato di `fun2()` nel registro `a0` senza rispettare la convenzione di chiamata. Inoltre, non salva il valore di ritorno della funzione `fun2()` prima di modificarlo, quindi potrebbe sovrascrivere il valore necessario per essere restituito al chiamante.

Una versione corretta del codice dovrebbe rispettare la convenzione di chiamata standard e garantire che il valore di ritorno di `fun2()` sia memorizzato e restituito correttamente al chiamante. Ad esempio:

```assembly
fun:
    li t0, 5          # Carica il valore 5 nel registro t0
    li t1, 1          # Carica il valore 1 nel registro t1
    add s0, t0, t1    # Somma i valori nei registri t0 e t1 e memorizza il risultato in s0
    mv a0, s0         # Copia il valore da s0 ad a0 per passarlo come argomento a fun2
    jal ra, fun2      # Chiama la funzione fun2 e salta all'indirizzo di ritorno
    mv s1, a0         # Salva il valore restituito di fun2 in s1
    add a0, s1, t0    # Aggiunge il valore nel registro t0 al valore restituito da fun2 e memorizza il risultato in a0
    ret               # Restituisce al chiamante

fun2:
    addi t0, a0, 1    # Incrementa il valore in a0 di 1 e memorizza il risultato in t0
    mv a0, t0         # Memorizza il risultato in a0 per la restituzione
    ret               # Restituisce al chiamante
```

In questa versione corretta del codice, il valore restituito da `fun2()` viene memorizzato prima di modificarlo e viene utilizzato il registro `a0` per la restituzione del valore.

### 7: ✔

Sapendo che il valore contenuto nel registro t2 al termine del programma è
10, dire che valore ha la variabile n. Motivare la risposta.

```nasm
.globl main             # Dichiarazione globale della funzione main

.data                   # Sezione dei dati
arr: .word 10, 3, 4, 2, 1   # Array di parole con valori predefiniti
n: .word ???            # Dichiarazione di una variabile n di tipo word (da specificare)

.text                   # Sezione del codice
main:                   # Inizio della funzione main

    la t0, arr          # Carica l'indirizzo di memoria dell'array arr nel registro t0
    la t1, n            # Carica l'indirizzo di memoria della variabile n nel registro t1
    lb t1, 0(t1)        # Carica il valore della variabile n nel registro t1 (supponendo che sia un byte)
    lw t2, 0(t0)        # Carica il primo elemento dell'array arr nel registro t2

ciclo:                  # Etichetta per il ciclo

    addi t1, t1, -1     # Decrementa il valore di n
    beq t1, zero, exit  # Se il valore di n è zero, esce dal ciclo
    slli t3, t1, 2      # Calcola l'offset per l'elemento corrente nell'array (moltiplicando l'indice per 4)
    add t3, t0, t3      # Calcola l'indirizzo di memoria dell'elemento corrente nell'array
    lw t3, 0(t3)        # Carica l'elemento corrente dell'array nell'elemento t3
    sub t2, t2, t3      # Sottrae l'elemento corrente di arr da t2
    j ciclo             # Salta all'inizio del ciclo

exit:                   # Etichetta per l'uscita dalla funzione
```

Il loop mette in t2 il valore di arr[0], poi in un loop si vanno a sottrarre gli altri
elementi dell’array a partire da quello di indice più alto e tornando a ritroso. Se alla fine del programma in t2 c’è ancora 10 vuol dire che il loop non ha mai eseguito.
Perché ciò avvenga la beq deve risultare true dalla prima volta, e perché ciò succeda
occorre che in t1 ci sia inizialmente 1. **n=1**

### 8:  ✔

Si supponga che x5 contenga il valore 0x0000 0000 0101 0000. Determinare il contenuto
di x6 dopo l’esecuzione delle seguenti istruzioni:

```nasm
      bge x5, x0, ELSE
      jal x0, FINE
ELSE: ori x6, x0, 2
FINE:
```

Ritorna `2`

### 9: ✔

Quale e' il valore contenuto in x5 dopo l'esecuzione di questa istruzione:

```assembly
//x5=0
//x6=10
Ciclo:
    blt x6, x0, exit //x6 < 0
    addi x6, x6, -1
    addi x5, x5, 3 // 3*11
    jal x0, ciclo
exit

x5 = 3+3+3 +3+3 -> 33
```





---

## Scegli la risposta corretta:

### 1:

La moltiplicazione in RISC-V:
<mark>**a)** </mark>Può essere sostituita con uno shift a sinistra quando il moltiplicatore è una potenza
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

Altro:

se devo spostarmi per offset multiplo di due slli x6, x11, 3 -> x6 = k*8 ho schiftato di 3 e come dire che ho moltiplicato per 8

### 2:

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-04-16-01-24-2024-05-04-15-47-18-2024-05-02-19-45-39-image.png) 

Shift moltiplicazione per 2,perche si moltiplica per due? Un brach e' un alterazione del control flow lineare(istruzione piu 4 piu 4 piu 4), il minimo salto quindi che non e' un control flow lineare? e' il doppio, il salto piu piccolo possibile e di due byte e non di 4

Il risultato finale dell'esercizio è 0x2000 0FFE. Per capire come si è arrivati a questo risultato, bisogna considerare diversi concetti relativi al calcolo dell'offset e alla codifica delle istruzioni nel formato compatto.

1. Calcolo dell'offset per l'istruzione branch if equal (beq): 
   Il campo immediato dell'istruzione beq è di 12 bit, il che significa che può rappresentare un'offset compreso tra -2048 e 2047. Tuttavia, essendo l'offset positivo, il valore massimo rappresentabile è (0111 1111 1111)₂, che in decimale è 2047.

2. **Shift e moltiplicazione per due:** 
   Quando viene eseguita un'istruzione di salto condizionato come beq, l'offset viene moltiplicato per due prima di essere sommato al valore del program counter (PC). <mark>Questo perché le istruzioni sono allineate in memoria ogni 4 byte (o 2 byte nel caso dell'estensione C dell'instruction set compatto a 16 bit). </mark>.>Quindi, un salto di 1 istruzione corrisponde a un offset di 4 byte, quindi un'istruzione successiva nel flusso del programma si trova a 4 byte di distanza da quella corrente.

3. **Massimo salto in avanti:** Considerando il valore del PC iniziale di 0x2000 0000 e aggiungendo l'offset massimo di 2047 moltiplicato per due, otteniamo:
   
   0x2000 0000 + (2047 * 2) = 0x2000 0000 + 4094 = 0x2000 0FFE

Quindi, il risultato finale è 0x2000 0FFE, che rappresenta l'indirizzo più grande che può essere raggiunto tramite l'istruzione beq partendo da un PC di 0x2000 0000.

### 3: NO

Un sistema di branch prediction:

A) Consente di risolvere il problema degli structure hazards, soprattutto in architetture
provviste di cache
<mark>**B)**</mark> Permette di ridurre le penalità dovute a control  hazards, soprattutto in pipeline lunghe
C) Può essere implementato con una semplice ALU a n bit
<mark>**D)**</mark> Se di tipo dinamico, tiene traccia del risultato degli ultimi salti condizionali, e assume
che il comportamento sia identico in futuro.

### 4: ✔

I registri `x5 e x6 `di un processore RISC-V contengano i valori `0x8000 0000 0000 0000` e
`0xD000 0000 0000 0000`, rispettivamente. Quale affermazione è corretta?
a) Non c’è overflow se si esegue l’istruzione add x30, x5, x6
**<mark>b)</mark>** Non c’è overflow se si esegue l’istruzione sub x30, x6, x5
c) Non c’è overflow se si esegue l’istruzione sub x30, x5, x6
d) Nessuna delle precedenti

### 5: ✔

Il blocco di istruzioni seguente è **idempotente**, cioè lo stato della macchina al termine
dell’esecuzione è identico a quello d’inizio, eccettuato il program counter.
A) andi x11, x11, 0
**<mark>B)</mark>** add x11, x11, x0
**<mark>C)</mark>** xor x28, x28, x29
    xor x28, x28, x29
D) beq x0, x0, x0

> le istruzioni di tipo R sono operazioni aritmetiche o logiche sui  registri che non modificano lo stato della macchina o il flusso di  esecuzione del programma, mentre le istruzioni di tipo I e SB possono  alterare il flusso di esecuzione del programma, ad esempio modificando  il flusso di esecuzione tramite salti condizionali o ramificazioni.
>

### 6: ✔

In caso di chiamata di una funzione foglia (i.e., che non chiama altre funzioni):
**<mark>a)</mark>** È possibile evitare di salvare sullo stack l'indirizzo di ritorno del chiamante
b) È possibile sporcare i "saved registers" senza preoccuparsi di ripristinarli al termine della
funzione chiamata
**<mark>c)</mark>** In generale, è possibile evitare di salvare sullo stack il valore degli argomenti passati dal chiamante al chiamato
d) È consigliabile ritornare alla funzione chiamante attraverso l'istruzione `jal x1, ProcedureLabel`

### 7: STUDIA

Nel tipico memory layout di una architettura RISC-V:
a) Figura lo spazio per i dati (statici o dinamici), ma non per il codice
b) I dati statici e i dati dinamici sono entrambi allocati nello spazio riservato allo heap
**<mark>c)</mark>** Stack e memoria dinamica crescono in direzioni opposte contendendosi lo stesso spazio di memoria
**<mark>d)</mark>** Si trovano indirizzi puntati da frame pointer e stack pointer

> Nel tipico memory layout di un'architettura RISC-V, i dati statici vengono solitamente posizionati nella sezione del programma eseguibile, mentre i dati dinamici, come gli array o gli oggetti allocati dinamicamente, vengono allocati nello heap.
>
> Ecco una panoramica generale del memory layout tipico di un programma in esecuzione su un'architettura RISC-V:
>
> 1. **Testo del programma (code segment o text segment):** Contiene il codice eseguibile del programma, come le istruzioni del programma scritte in linguaggio assembly o linguaggi di programmazione ad alto livello compilati. Questa parte della memoria è solitamente di sola lettura (read-only) e contiene istruzioni eseguibili.
>
> 2. **Dati statici (data segment):** Questa sezione contiene i dati statici del programma, come variabili globali o costanti dichiarate all'interno del codice. Questi dati sono in genere inizializzati durante la fase di caricamento del programma e rimangono costanti per tutta la durata dell'esecuzione del programma.
>
> 3. **BSS (Block Started by Symbol):** Questa sezione contiene variabili globali non inizializzate o inizializzate a zero. Durante la fase di caricamento del programma, la memoria per queste variabili viene riservata, ma non viene assegnato alcun valore iniziale. 
>
> 4. **Stack:** Lo stack viene utilizzato per la gestione delle chiamate di funzione e delle variabili locali. Cresce verso il basso e viene utilizzato per memorizzare informazioni di contesto delle chiamate di funzione, come gli indirizzi di ritorno, i parametri delle funzioni e le variabili locali. 
>
> 5. **Heap:** Lo heap è una zona di memoria dinamica che viene utilizzata per l'allocazione di memoria durante l'esecuzione del programma. È comunemente utilizzato per allocare memoria per oggetti di dimensioni variabili, come array o strutture dati, e viene gestito esplicitamente dal programmatore tramite chiamate alle funzioni di allocazione della memoria come malloc() o new() e alle funzioni di deallocazione della memoria come free() o delete().
>
> In sintesi, i dati statici vengono memorizzati nel data segment, mentre i dati dinamici vengono allocati nello heap. Lo stack viene utilizzato per la gestione delle chiamate di funzione e delle variabili locali, mentre il testo del programma contiene il codice eseguibile.
>

### 8: STUDIA

Il linguaggio C ha molti costrutti per le decisioni e i cicli, mentre l’assembly RISC-V ne ha pochi
perché:
a) Meno costrutti decisionali rendono il codice facile da leggere e da capire
**<mark>b)</mark>** Meno costrutti decisionali semplificano il design del livello dell’ISA, che è responsabile
dell’esecuzione
**<mark>c)</mark>** Più costrutti decisionali significano meno linee di codice, il che generalmente riduce il tempo
di programmazione
d) Nessuna delle precedenti

> <mark>b:</mark> **Semplificazione del design dell'ISA:**
> Le architetture RISC, come RISC-V, sono progettate con un set di istruzioni ridotto (RISC sta per Reduced Instruction Set Computer). Questo approccio è stato scelto per semplificare il design e l'implementazione del processore. Limitare il numero di istruzioni e costrutti decisionali nell'ISA semplifica l'architettura del processore, riducendo la complessità del hardware e facilitando l'implementazione di un'architettura efficiente e ad alte prestazioni.
>
> <mark>c:</mark> **Riduzione del tempo di programmazione:**
> L'uso di più costrutti decisionali nei linguaggi di programmazione di alto livello, come C, può facilitare la scrittura del codice e renderlo più leggibile e mantenibile. I costrutti come if, else, switch e loop for consentono ai programmatori di scrivere codice in modo più conciso e espressivo, affrontando diverse condizioni e iterazioni in modo più intuitivo. Di conseguenza, i programmatori possono scrivere codice più rapidamente e con meno sforzo, riducendo il tempo di sviluppo complessivo del software.
>
> In sintesi, la scelta di limitare i costrutti decisionali nell'ISA delle architetture RISC come RISC-V è principalmente guidata dalla necessità di semplificare il design del processore e rendere l'implementazione hardware più efficiente. D'altra parte, l'uso di più costrutti decisionali nei linguaggi di programmazione di alto livello come C è motivato dalla necessità di scrivere codice in modo più rapido, conciso e intuitivo, riducendo così il tempo di sviluppo complessivo del software.

### 9:  ✔

Le istruzioni di salto condizionato in RISC-V:
**<mark>a)</mark>** Realizzano il controllo di flusso della logica del programma
b) Implementano il tic dell'orologio del sistema (clock)
c) Non usano la ALU per il loro funzionamento
d) Possono avere tra gli operandi degli indirizzi da valutare

> In sintesi, le istruzioni di salto condizionato in RISC-V utilizzano l'ALU per valutare le condizioni e calcolare gli indirizzi di salto, ma non possono valutare direttamente gli indirizzi come operandi perché prendono decisioni basate solo su dati presenti nei registri o sullo stato corrente della CPU.
>
> Quindi, le istruzioni di salto condizionato in RISC-V non possono avere tra gli operandi degli indirizzi da valutare perché queste istruzioni sono progettate per prendere decisioni basate solo su dati presenti nei registri o sulle condizioni correnti dello stato della CPU. L'indirizzo di destinazione del salto è specificato direttamente nell'istruzione di salto e non viene valutato come un operando separato.
>



### 10: ✔

`and rd, rs1, rs2`

Quali affermazioni sul funzionamento di un datapath pipelined sono corrette?
a) La ALU e la data memory eseguono entrambe lavoro utile
**<mark>b)</mark>** La immediate generation unit non esegue lavoro utile
**<mark>c)</mark>** Durante la fase di decode il register file esegue lavoro utile
d) La ALU non esegue lavoro utile

> Per comprendere perché la "immediate generation unit" (unità di generazione immediata), durante il funzionamento di un datapath pipelined, non esegue lavoro utile mentre altre unità sì, dobbiamo esaminare il ruolo e il funzionamento di ciascuna unità nel pipeline.
>
> 1. **Immediate Generation Unit (IGU):** Questa unità è responsabile della generazione delle immediate, cioè dei valori immediati o costanti utilizzati nelle istruzioni. Nel pipeline, l'IGU non esegue lavoro utile perché il valore immediato è noto già durante la fase di fetch dell'istruzione successiva. L'IGU prepara l'immediato per l'istruzione successiva mentre il processore sta eseguendo l'istruzione corrente, ma il suo lavoro non contribuisce direttamente all'avanzamento dell'istruzione corrente nel pipeline.
>
> 2. **Register File (RF):** Il register file è responsabile della lettura e della scrittura nei registri del processore. Durante la fase di decode, l'unità di decodifica deve leggere i registri per ottenere i valori degli operandi. Quindi, il register file esegue lavoro utile durante la fase di decode fornendo i valori dei registri necessari per l'esecuzione dell'istruzione corrente.
>
> 3. **Arithmetic Logic Unit (ALU):** L'ALU è responsabile dell'esecuzione di operazioni aritmetiche e logiche. Durante la fase di esecuzione, l'ALU esegue le operazioni specificate dall'istruzione corrente, come addizioni, sottrazioni, confronti, ecc. Pertanto, durante questa fase, l'ALU esegue lavoro utile producendo il risultato dell'operazione.
>
> 4. **Data Memory (DM):** La memoria dei dati è responsabile dell'accesso ai dati in memoria. Tuttavia, molte istruzioni non coinvolgono l'accesso alla memoria dei dati, quindi durante la fase di accesso alla memoria, la DM potrebbe non eseguire lavoro utile. Solo le istruzioni che coinvolgono il caricamento o il salvataggio di dati in memoria richiedono l'accesso alla DM.
>
> In sintesi, l'IGU non esegue lavoro utile durante l'esecuzione dell'istruzione corrente perché prepara i valori immediati per l'istruzione successiva. Al contrario, il register file fornisce i valori dei registri necessari per l'istruzione corrente durante la fase di decode, l'ALU esegue operazioni utili durante la fase di esecuzione e la data memory può non eseguire lavoro utile se l'istruzione corrente non coinvolge l'accesso ai dati in memoria.

### 11:

Quali delle seguenti affermazioni sono corrette?
a) Il valore restituito da una lettura dipende da quali blocchi si trovano nella cache.
**<mark>b)</mark>** Le gerarchie di memorie sfruttano la località temporale.
c) Accedere al livello più alto della gerarchia di cache ha il costo più alto del sistema di memoria.
**<mark>d)</mark>** La maggior parte della capacità di una gerarchia di memoria si trova nel livello più basso.



1. Perche il valore restituito da una lettera NON dipende da quali blocchi si trovano nella cache?
2. Le gerarchie di memorie sfruttano le localita' temporale?

3. Perche accedere al livello piu alto dell agerarchia di cache non ha il costo piu alto del sistema di memoria?

4. Perche la maggior parte della capacita di una gerarchia di memoria si trova nel livello piu basso?







---

## Scrivere un pezzo di codice assembly

### 1: 

che effettui l’operazione `arr[1] = arr[0] + arr[2]`

```nasm
lw t0, 0(s0)    # Carica il contenuto di arr[0] nel registro t0
lw t1, 8(s0)    # Carica il contenuto di arr[2] nel registro t1
add t2, t0, t1  # Somma il contenuto di t0 (arr[0]) e t1 (arr[2]), e salva il risultato in t2
sw t2, 4(s0)    # Salva il contenuto di t2 (somma di arr[0] e arr[2]) nella posizione di memoria arr[1] s0)
```

---

### 2:

$$
{ 2^N, \text{ se } O = 0 \quad \log_2 N, \text{ se } O = 1 }
$$



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

### 3:

Si scriva una funzione sommatoria che prende in ingresso un intero n e ritorna
la sommatoria mostrata sotto. Se n è non positivo la funzione ritorna -1, se è nullo
ritorna 0: 
$$
1^1 + 2^2 +3^3 +. . . +𝑛^𝑛
$$
Per svolgere il calcolo la funzione sommatoria deve chiamare una funzione elev che
prende in ingresso un intero a e restituisce aa.
Si scrivano le funzioni sommatoria e elev rispettando la calling convention RISC-V e
gestendo opportunamente lo stack e il register file, utilizzando i registri appropriati.

```nasm
# Calculates 1^1 + 2^2 + 3^3 + … + N^N
# a0 contains N. Returns 0 if N=0. Returns -1 if N<0
sommatoria:
    blt a0, zero, endNeg   # Se N è negativo, salta a endNeg
    beq a0, zero, endZero  # Se N è zero, salta a endZero
    addi sp, sp, -16       # Fai spazio per 4 parole nello stack
    sw ra, 0( sp )         # Salva l'indirizzo di ritorno nello stack
    sw s0, 4( sp )         # Salva il registro s0 nello stack
    sw s1, 8( sp )         # Salva il registro s1 nello stack
    sw s2, 12( sp )        # Salva il registro s2 nello stack
    add s0, a0, zero       # Inizializza s0 con il parametro N
    li s1, 0               # Inizializza s1 (accumulator) a 0
    li s2, 1               # Inizializza s2 (iterator (i)) a 1
loop:
    bgt s2, s0, end       # Se (i > N) esce dal ciclo
    mv a0, s2             # Imposta a0 al valore di s2, impostando
                          # gli argomenti per la chiamata di funzione
    jal ra, elev          # Chiama la funzione ELEV
    add s1, s1, a0        # Aggiunge il valore restituito in s1
    addi s2, s2, 1        # Incrementa s2 (i) di 1
    jal zero, loop        # Salta nuovamente all'etichetta loop
end:
    mv a0, s1             # Imposta a0 a s1, il valore di ritorno
    lw ra, 0( sp )        # Ripristina ra
    lw s0, 4( sp )        # Ripristina s0
    lw s1, 8( sp )        # Ripristina s1
    lw s2, 12( sp )       # Ripristina s2
    addi sp, sp, 16       # Libera lo spazio nello stack
    jal zero, return      # Esce dalla funzione
endNeg:
    li a0, -1              # Imposta a0 a -1, il valore di ritorno
    jal zero, return       # Esce dalla funzione
endZero:
    li a0, 0               # Imposta a0 a 0, il valore di ritorno
return:
    jr ra                  # Ritorna al chiamante

# a0: a
# Calcola a^a
elev:
    li t0, 1               # Iteratore del ciclo
    mv t1, a0              # Risultato
    beq a0, t0, end_pow    # Se a == 1 non c'è niente da fare
loop_pow:
    mul t1, t1, a0         # Moltiplica t1 per a0
    addi t0, t0, 1         # Incrementa l'iteratore
    bgt a1, t0, loop_pow   # Se a > iteratore continua il ciclo
ret1:
    mv a0, t1              # Prepara il valore di ritorno
end_pow:
    jr ra
```

### 4:

 Si scriva una funzione assembly RISC-V Init che prende in ingresso un array A e
la sua dimensione n e inizializza l’array come indicato sotto:

```nasm
for (i=0; i<n; i++)
A[i] = fun(-i)
```

NON occorre implementare la funzione fun, solo invocarla rispettando le convenzioni
sull’utilizzo dei registri per le chiamate a funzione. Gestire opportunamente lo stack nel
rispetto della calling convention RISC-V

```nasm
# a0 contains A
# a1 contains N
# Populates A as follows: A[i] = fun(-i) → i=[0:N)
Init:
    bge zero, a1, end      # Handle null/negative N input
    addi sp, sp, -16       # Make space for 4 words on the stack
    sw ra, 0( sp )         # Store the return address
    sw s0, 4( sp )         # Store register s0
    sw s1, 8( sp )         # Store register s1
    sw s2, 12( sp )        # Store register s2
    add s0, a0, zero       # Save base address of A
    li s1, 0               # Set s1 (array offset) equal to 0
    li s2, 0               # Set s2 (iterator (i)) equal to 0
loop:
    bge s2, a1, end        # if (0 >= n) goto end
    mv a0, s2              # Set a0 to i
    sub a0, zero, a0       # then to -i
    jal ra, fun            # Call the function ELEV
    slli s1, s2, 2         # calculate array offset (i*4)
    add s1, s0, s1         # calculate &A[i]
    sw a0, 0(s1)           # A[i] = fun(-i)
    addi s2, s2, 1         # Increment s2 (i) by 1
    jal zero, loop         # Jump back to the loop label
end:
    lw ra, 0( sp )         # Restore ra
    lw s0, 4( sp )         # Restore s0
    lw s1, 8( sp )         # Restore s1
    lw s2, 12( sp )        # Restore s2
    addi sp, sp, 16        # Free space on the stack
    jr ra                  # Return to the caller
```

### 5:

Si scriva in assembly RISC-V una funzione revert che prende in ingresso due
stringhe (array di caratteri) str e reverse e copi in reverse la stringa str al contrario.
Ad esempio, se str contiene la stringa “Pippo”, la funzione mette in reverse la
stringa “oppiP”. Specificamente, il codice C della funzione da realizzare è il
seguente:

```nasm
char *revert (char *str, char *reverse)
{
int i = 0;
int l = strlen (str);
while (str[i] != ‘\0’)
{
reverse[l-1-i]= str[i];
i++;
}
reverse[l] = ‘\0’;
return reverse;
}
```

Implementare la funzione rispettando le convenzioni sull’utilizzo dei registri per le
chiamate a funzione. Gestire opportunamente lo stack nel rispetto della calling convention RISC-V.
Si ricorda che la funzione strlen ha la seguente sintassi e semantica:
size_t strlen(const char *s);
SEMANTICA: La funzione strlen() calcola la lung hezza della stringa s, (inteso come ilnumero di caratteri dell'array puntato da s) escluso il terminatore '\0'.
Si ricorda anche che il tipo size_t è equivalente al tipo int in termini di dimensioni in bytes.
NON occorre implementare la funzione strlen, solo invocarla rispettando le convenzioni
sull’utilizzo dei registri per le chiamate a funzione

```nasm
# a0 contains *str
# a1 contains *reverse
# Reverses STR and puts it in REVERSE
revert:
    addi sp, sp, -32    # Riserva spazio nello stack per i registri
    sd s0, 0(sp)        # Salva il registro s0 nello stack
    sd s1, 8(sp)        # Salva il registro s1 nello stack
    sd s2, 16(sp)       # Salva il registro s2 nello stack
    sd ra, 24(sp)       # Salva l'indirizzo di ritorno nello stack

    li s0, 0            # Inizializza l'indice di loop (i) a 0
    mv s1, a0           # Salva il puntatore a *str in s1 per uso futuro
    jal ra, strlen      # Chiama la funzione strlen per ottenere la lunghezza di *str. La lunghezza viene memorizzata in a0.

loop:
    add s1, s1, s0      # Calcola l'indirizzo di memoria di str[i]
    lb s1, 0(s1)        # Carica il carattere corrente di str[i] in s1

    beq s1, zero, end   # Se il carattere corrente è '\0', termina il loop

    addi s2, a0, -1     # Calcola l'indice dell'ultimo carattere di *str (l-1)
    sub s2, s2, s0      # Calcola l'indice del carattere corrente all'indietro (l-1-i)
    add s2, a1, s2      # Calcola l'indirizzo di memoria per reverse[l-1-i]

    sb s1, 0(s2)        # Memorizza il carattere corrente di str[i] in reverse[l-1-i]

    addi s0, s0, 1      # Incrementa l'indice di loop (i)
    j loop              # Ritorna all'inizio del loop

end:
    add s2, a1, a0      # Calcola l'indirizzo di memoria per reverse[l]
    sb zero, 0(s2)      # Aggiunge il terminatore di stringa '\0' a reverse[l]

    mv a0, a1           # Imposta il puntatore a reverse come valore di ritorno

    ld s0, 0(sp)        # Ripristina il registro s0 dallo stack
    ld s1, 8(sp)        # Ripristina il registro s1 dallo stack
    ld s2, 16(sp)       # Ripristina il registro s2 dallo stack
    ld ra, 24(sp)       # Ripristina l'indirizzo di ritorno dallo stack
    addi sp, sp, 32     # Libera lo spazio nello stack

    ret                 # Restituisce al chiamante
```

### 6:

Scrivere una funzione assembly RISCV mystrcpy che prenda in ingresso una stringa
destinazione dest, una stringa sorgente src, un numero di bytes b e una direzione d. La funzione
deve copiare i primi b caratteri della stringa src sulla stringa dst, terminandola col terminatore
‘\0’. Se il numero di bytes b indicato dovesse essere più grande del numero di caratteri effettivamente presenti nella stringa src quest’ultima verrà interamente copiata nella stringa dst. Se la direzione d è pari a 0 la copia deve essere diretta, se è pari a 1 deve essere invertita.

```sass
Es.
char x[10] = “distintivo”;
char y[10];
mystrcpy(y, x, 4, 0) produce y = “dist” = {‘d’, ‘i’, ‘s’, ‘t’, ‘\0’}
mystrcpy(y, x, 4, 1) produce y = “tsid” = {‘t’, ‘s’, ‘i’, ‘d’, ‘\0’}
```

Gestire correttamente lo stack come da calling convention, così come il passaggio dei parametri di ingresso e di uscita sui registri appropriati. Scrivere la funzione main che invoca mystrcpy, mostrando anche l’allocazione degli array sul segmento dati statico del file ELF.

```nasm
# Definizione della funzione mystrcpy
mystrcpy:
    addi sp, sp, -24    # Regola lo stack per 24 bytes
    sd s0, 0(sp)        # Salva s0 nello stack
    sd s1, 8(sp)        # Salva s1 nello stack
    sd s2, 16(sp)       # Salva s2 nello stack
    li s2, 0            # Inizializza il contatore i a 0

    # Controlla la direzione d
    bne a3, zero, L2    # Se d != 0, esegui la copia invertita

L1:                     # Etichetta per il ciclo (copia diretta)
    add s0, s2, a1     # s0 = indirizzo di src[i]
    lbu s0, 0(s0)      # s0 = src[i]
    add s1, s2, a0     # s1 = indirizzo di dest[i]
    sb s0, 0(s1)       # dest[i] = src[i]
    beq s0, zero, L4   # Se src[i] == '\0', esci dal ciclo
    addi s2, s2, 1     # Incrementa i di 1
    j L1               

L2:                     # Etichetta per determinare la lunghezza di src
    add s0, s2, a1     # s0 = indirizzo di src[i]
    lbu s0, 0(s0)      # s0 = src[i]
    beq s0, zero, L22  # Se src[i] == '\0', esci dal ciclo
    addi s2, s2, 1     # Incrementa i di 1
    j L2               

L22:                    # s2 contiene ora la lunghezza della stringa src
    blt s2, a2, L23    # Se s2 < b, vai a L23
    mv s2, a2          # Altrimenti, s2 = b

L23:                    # Gestione del carattere di terminazione
    add s1, s2, a0     # s1 = indirizzo di dest[i]
    sb zero, 0(s1)     # dest[strlen(STR)] = '\0'
    addi s2, s2, -1    # Decrementa i di 1
    mv a2, s2          # Aggiusta B
    li s2, 0           # Azzera i

L3:                     # Etichetta per il ciclo (copia invertita)
    add s0, s2, a1     # s0 = indirizzo di src[i]
    lbu s0, 0(s0)      # s0 = src[i]
    add s1, a2, -1     # s1 = b - 1
    sub s1, s1, s2     # s1 = b - 1 - i
    add s1, s1, a0     # s1 = indirizzo di dest[b-1-i]
    sb s0, 0(s1)       # dest[i] = src[i]
    beq s2, zero, L4   # Se src[i] == '\0', esci dal ciclo
    addi s2, s2, -1    # Decrementa i di 1
    j L23              

L4:                     # Ripristina i registri salvati
    ld s0, 0(sp)
    ld s1, 8(sp)
    ld s2, 16(sp)
    addi sp, sp, 24    # Dealloca 24 bytes dallo stack
    ret                 # Ritorna
```

### 7:

Implementare in assembly RISCV la funzione C strncpy
`char *strncpy(char *dest, const char *src, size_t n); `che prende in ingresso una stringa destinazione dest, una stringa sorgente src e un numero di bytes n. La funzione copia al più n caratteri di src in dest, terminandola col terminatore ‘\0’.
Se n > strlen(src) allora src verrà interamente copiata in dst.
Gestire correttamente lo stack come da calling convention, così come il passaggio dei parametri di ingresso e di uscita sui registri appropriati. Scrivere la funzione main che invoca strncpy, mostrando anche l’allocazione degli array sul segmento dati statico del file ELF.

- Main e dati 1pt
- 1pt per la gestione dello stack
- 2pt per la corretta gestione di strlen<n
- 3pt per la corretta implementazione della copia principale

```nasm
# Definizione della funzione strncpy
strncpy:
    addi sp, sp, -24    # Regola lo stack per 24 bytes
    sd s0, 0(sp)        # Salva s0 nello stack
    sd s1, 8(sp)        # Salva s1 nello stack
    sd s2, 16(sp)       # Salva s2 nello stack
    li s2, 0            # Inizializza il contatore i a 0

L1:                     # Etichetta per il ciclo
    add s0, s2, a1     # s0 = indirizzo di src[i]
    lbu s0, 0(s0)      # s0 = src[i]
    add s1, s2, a0     # s1 = indirizzo di dest[i]
    sb s0, 0(s1)       # dest[i] = src[i]
    beq s0, zero, L3   # Se src[i] == '\0', esci dal ciclo
    addi s2, s2, 1     # Incrementa i di 1
    beq s2, a2, L2     # Se i == n, esci dal ciclo
    j L1               # Prossima iterazione del ciclo

L2:                     # Etichetta per la gestione del terminatore
    sb zero, 1(s1)      # dest[strlen+1] = '\0'

L3:                     # Etichetta per la fine della copia
    ld s0, 0(sp)        # Ripristina s0 dallo stack
    ld s1, 8(sp)        # Ripristina s1 dallo stack
    ld s2, 16(sp)       # Ripristina s2 dallo stack
    addi sp, sp, 24     # Dealloca 24 bytes dallo stack
    ret                 # Ritorna
n
```

### 8:

Implementare in assembly RISCV la funzione C strcat
`char *strcat(char *dest, const char *src);`
La funzione strcat() concatena la stringa src aggiungendola al termine della stringa dest.
La concatenazione avviene copiando la stringa src a partire dal terminatore della stringa desc. La copia di src e' comprensiva del suo terminatore. L'area di memoria puntata da dest deve essere sufficientemente ampia da accogliere entrambe le stringhe ed il terminatore '\0',
quindi dest deve essere dimensionata almeno per contenere `strlen(dest) + strlen(src) + 1 caratteri.`
Gestire correttamente lo stack come da calling convention, così come il passaggio dei parametri
di ingresso e di uscita sui registri appropriati. Scrivere la funzione main che invoca strcat, mostrando anche l’allocazione degli array sul segmento dati statico del file ELF.

- Main e dati 1pt
- 1pt per la gestione dello stack
- 4pt per la corretta implementazione della copia principale

```nasm
# SOLUZIONE // a0 = dest; a1 = src;
strcat:
    addi sp, sp, -32    # Regola lo stack per 32 bytes
    sd s0, 0(sp)        # Salva s0 nello stack
    sd s1, 8(sp)        # Salva s1 nello stack
    sd s2, 16(sp)       # Salva s2 nello stack
    sd s3, 24(sp)       # Salva s3 nello stack
    li s2, 0            # Inizializza l'indice i a 0
    li s3, 0            # Inizializza l'indice j a 0

    # Cerca il terminatore di dest
L1:
    add s1, s2, a0      # s1 = indirizzo di dest[i]
    lbu s1, 0(s1)       # s1 = dest[i]
    beq s1, zero, L2    # Se dest[i] == 0, procedi alla copia
    addi s2, s2, 1      # Incrementa i di 1
    j L1                # Prossima iterazione del ciclo

    # Indicizzazione di dest con s2 (i) e src con s3 (j)
L2:
    add s0, s3, a1      # s0 = indirizzo di src[j]
    lb s0, 0(s0)        # s0 = src[j]
    add s1, s2, a0      # s1 = indirizzo di dest[i]
    sb s0, 0(s1)        # dest[i] = src[j]
    beq s0, zero, L3    # Se src[j] == 0, esci
    addi s2, s2, 1      # Incrementa i di 1
    addi s3, s3, 1      # Incrementa j di 1
    j L2                # Prossima iterazione del ciclo

L3:
    ld s0, 0(sp)        # Ripristina s0 dallo stack
    ld s1, 8(sp)        # Ripristina s1 dallo stack
    ld s2, 16(sp)       # Ripristina s2 dallo stack
    ld s3, 24(sp)       # Ripristina s3 dallo stack
    addi sp, sp, 32     # Libera 32 bytes dallo stack
    ret                 # Ritorna
```

## Domande aperte:

### 1: ✔ Si descriva brevemente la calling convention del RISC-V, evidenziando le differenze tra temporary registers e saved registers.

Registri temporanei e registri salvati.
Anche i registri salvati sono temporanei, ma i registri salvati sono gestiti diversamente: i registri temporanei non sono preservati dal chiamante (caller) e sono volatili tra le chiamate; se il chiamante vuole essere sicuro di non avere valori modificati all'interno dei registri temporanei, deve salvarli.
I registri salvati, invece, sono preservati tra le chiamate; perché per convenzione chi scrive la funzione li salva, assicurandoli. Quindi, apprendiamo adesso che noi non avremmo dovuto salvare i nostri, perché era responsabilità del chiamante assicurarli.
In breve:
→ se ho bisogno di pochi registri, uso quelli temporanei e non gestisco il salvataggio
→ se ho bisogno di tanti registri e mi tocca usare quelli salvati, dentro la funzione devo gestire i salvataggi vari.

La calling convention del RISC-V definisce le regole e le convenzioni che regolano come le funzioni interagiscono tra loro durante l'esecuzione del programma. Tra le principali convenzioni ci sono quelle riguardanti i registri temporanei e i registri salvati.

1. **Registri temporanei (temporary registers):** I registri temporanei non sono preservati tra le chiamate di funzione. Questi registri sono volatili e possono essere sovrascritti da una qualsiasi funzione senza la necessità di essere salvati e ripristinati. Il chiamante non è tenuto a garantire l'integrità dei dati all'interno dei registri temporanei.

2. **Registri salvati (saved registers):** I registri salvati, invece, sono preservati tra le chiamate di funzione. È responsabilità della funzione chiamata (callee) salvare e ripristinare i valori dei registri salvati se vuole modificarli. Questo garantisce che i valori contenuti nei registri salvati non vengano modificati accidentalmente dalle chiamate di funzione.

In sintesi:

- Se una funzione ha bisogno di pochi registri, può utilizzare i registri temporanei senza dover gestire il salvataggio e il ripristino.
- Se una funzione ha bisogno di molti registri, deve utilizzare i registri salvati e gestire il salvataggio e il ripristino all'interno della funzione stessa.

In generale, l'uso dei registri temporanei è preferibile quando possibile, poiché non richiede operazioni aggiuntive di salvataggio e ripristino e può portare a una maggiore efficienza del codice. Tuttavia, quando si utilizzano molti registri, è necessario utilizzare i registri salvati e seguire le convenzioni appropriate per garantire l'integrità del programma.





### 2: ✔ Si descrivano le principali differenze nella gestione dello stack quando si implementa una funzione foglia rispetto ad una funzione non foglia. 
Nel contesto dell'architettura di un calcolatore, una "funzione foglia" e una "funzione non foglia" possono riferirsi a due concetti diversi, quindi fornirò una panoramica generale di come la gestione dello stack potrebbe variare in base a questi due scenari:

1. **Funzione foglia**: Una funzione foglia è una funzione che non chiama altre funzioni all'interno del suo corpo. In questo caso, quando la funzione foglia viene chiamata, solitamente non è necessario salvare lo stato dello stack, poiché non ci sono chiamate ricorsive o richiami di altre funzioni che potrebbero sovrascrivere il contesto dello stack attuale. Quindi, la gestione dello stack in una funzione foglia potrebbe comportare meno operazioni di salvataggio e ripristino dello stato dello stack.

2. **Funzione non foglia**: Una funzione non foglia è una funzione che chiama altre funzioni all'interno del suo corpo. Quando una funzione non foglia viene chiamata, è necessario gestire il salvataggio dello stato dello stack corrente (come i registri di base e i puntatori dello stack) per poter tornare correttamente al contesto della funzione chiamante una volta che la funzione è completata. Questo comporta il salvataggio dei registri importanti, come il puntatore di base dello stack (stack pointer) e il puntatore di base del frame della funzione corrente (frame pointer), prima di chiamare altre funzioni, e il ripristino di questi registri una volta che la funzione è completata.

In generale, la gestione dello stack in una funzione non foglia potrebbe essere più complessa rispetto a una funzione foglia a causa della necessità di gestire i contesti di chiamata e ritorno delle funzioni. Questo può richiedere un maggiore utilizzo della memoria stack e potrebbe influenzare le prestazioni dell'applicazione.





# Appendice: Tabelle  di codifica delle istruzioni RISC-V

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-06-21-46-44-image.png)

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-06-21-47-09-image.png)



![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-06-21-47-18-image.png) 



