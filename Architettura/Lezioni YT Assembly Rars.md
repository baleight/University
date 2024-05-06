# Lezioni YT Assembly Rars

Rars:

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-02-22-20-01-image.png)

Teoria:

Questo codice Assembly è scritto per il simulatore RARS (RISC-V Assembler and Runtime Simulator). Qui ci sono alcune spiegazioni riguardo alle istruzioni e ai segmenti del codice:

1. `.equ _SYS_EXIT, 93` e `.equ _SYS_WRITE, 64`: Queste istruzioni definiscono delle costanti che rappresentano i numeri delle syscall per `exit` e `write` nel sistema operativo. Questo è utile per rendere il codice più leggibile e manutenibile.

2. `.global _start`: Questa istruzione dichiara che `_start` è un simbolo globale. In molti sistemi operativi Unix-like, il punto di ingresso di un programma è il simbolo `_start`.

3. `.section .bss`: Questa sezione contiene variabili che non sono inizializzate e vengono allocate nello spazio BSS (Block Started by Symbol). In questo caso, sembra che non ci siano variabili definite in questa sezione.

4. `.section .data`: Questa sezione contiene dati inizializzati che possono essere modificati durante l'esecuzione del programma. Al momento non sembra esserci nulla definito in questa sezione nel codice fornito.

5. `.section .rodata`: Questa sezione contiene dati in sola lettura (Read-Only Data). Nel codice fornito, è presente una stringa "Hello mondo!\n" definita come `msg`.

6. `.section .text`: Questa sezione contiene il codice eseguibile del programma.

7. `_start:`: Questo è il punto di ingresso del programma. L'esecuzione del programma inizia da qui.

8. `li a0, 0`, `la a1, msg`, `li a2, 13`: Queste istruzioni caricano i parametri necessari per la syscall `write` nei registri appropriati. In particolare:
   
   - `a0` viene caricato con il file descriptor per stdout.
   - `a1` viene caricato con l'indirizzo della stringa `msg`.
   - `a2` viene caricato con la lunghezza della stringa, che in questo caso è 13 caratteri.

9. `li a7, _SYS_WRITE` e `ecall`: Queste istruzioni impostano il registro `a7` con il numero della syscall `write` e poi effettuano la syscall.

10. `li a7, _SYS_EXIT` e `ecall`: Queste istruzioni impostano il registro `a7` con il numero della syscall `exit` e poi effettuano la syscall, terminando il programma.

In sintesi, il programma stampa "Hello mondo!\n" sulla console e termina.

## Struttura del programma ASM:

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-04-10-56-17-image.png)

La struttura del programma Assembly che hai fornito segue una convenzione comune per i programmi RISC-V e ha diverse sezioni ben definite:

1. **Definizione delle costanti**: Inizia con la definizione delle costanti usando l'istruzione `.equ`. Questo rende il codice più leggibile e manutenibile, in particolare quando si fa riferimento a valori noti come i numeri delle syscall.

2. **Inizio del programma**: Si dichiara il punto di ingresso principale del programma, comunemente etichettato come `_start`. Questo è il punto da cui inizia l'esecuzione del programma.

3. **Sezioni di dati**: Ci sono varie sezioni dedicate a diverse tipologie di dati:
   
   - `.bss`: Questa sezione contiene variabili non inizializzate. Queste variabili occupano spazio nella memoria, ma non hanno valori iniziali.
   - `.data`: Questa sezione contiene dati inizializzati, che possono essere modificati durante l'esecuzione del programma.
   - `.rodata`: Questa sezione contiene dati in sola lettura, come le stringhe.

4. **Sezione del testo**: Questa è la parte principale del codice, dove sono contenute le istruzioni eseguibili. Di solito è etichettata come `.text` ed è dove si trovano le istruzioni Assembly che compongono il programma.

Dentro la sezione del testo, è comune trovare:

- **Definizione del punto di ingresso**: L'etichetta `_start` indica il punto di ingresso del programma.

- **Chiamate di sistema**: All'interno del programma, ci sono chiamate di sistema per eseguire operazioni come la scrittura su standard output (`write`) e l'uscita dal programma (`exit`). Queste chiamate di sistema coinvolgono la preparazione dei registri appropriati con i parametri necessari e l'invocazione della syscall tramite l'istruzione `ecall`.

In generale, questa struttura organizzativa aiuta a mantenere il codice organizzato e comprensibile, dividendo il programma in sezioni logiche e utilizzando etichette per identificare punti di interesse come il punto di ingresso e le diverse sezioni dei dati.

## [Lezione 1](https://www.youtube.com/watch?v=9rBoZFPEHWo)

Codice C

```c
x = (x-2)+y
if( x< 0)
    x=x+1
else
    y=y+1
```

```python
.global start
.text
start:
li t0, 10
li t1, 8
addi t0, t0, -2
add t0,t0, t1
#per convezione si punta sul else se x e maggiore di 0
bge t0,zero,else
addi t0,t0,1
else:
addi t1,t1,1

exit: #chiamo una sistem call esempio il print o il return 0
addi x17, x0, 10#10 e'la chiamata per uscire
ecall
```

## [Lezione 2](https://www.youtube.com/watch?v=y3V8Lvh82nc)

Programma che carichi 3 numeri interi t0,t1,t2 e poi si inserisca il valore massimo tra i tre numeri nel registro t3

```python
.globl start
.text
start:
li t0, 10 
li t1, 12
li t2, 14

primoif: #primo if
ble t0, t1, condizione1 #vero se no si fa sulla prossima riga se false
addi t3,t0,0
j secondoif #jUMP

secondoif: #Secondo if
ble t3,t2,condizione2 #if(w<z)
add t3,t3,0 #w=w
j end

condizione1:
addi t3,t1,0 #w=y
j secondoIF

condizione2:
addi t3,t2,0 #w=z
j end
#stampo il valore piu alto sulla console
end:
li a7, 1
add a0,t3,zero
ecall
#esco dal programma
addi x17, x0, 10
ecall
```

## [Lezione 3](https://www.youtube.com/watch?v=xVpiy6aWi8Q)

Converti C

```c
int n=8
int r=1
int a=0
int b=1
while (n>0){
    r=a+b
    a=b
    b=r
    n=n-1
}
```

```python
addi n, zero, 8
addi r, zero, 1
addi a, zero, 0
add1 b, zero, 1
loop:
beq n, zero, exit
add t0,a,b
add r,r,t0
add a,zero,b
add b,zero,r
addi n,n,-1
j loop

exit: #chiamo una sistem call esempio il print o il return 0
addi x17, x0, 10#10 e'la chiamata pe
```

## [Lezione 4](https://www.youtube.com/watch?v=IufKaw4_e0w)

Si scriva un programma che carichi 4 numeri interi presenti in gia' in memoria in  word contigue e calcoli la media aritmetica.

il valore calcolato va salvato in un ulteriore posizione della memoria contigua a quelle usate per il calcolo.

```python

```
