# Lezioni YT Assembly Rars

## [Lezione 1]([Assembly - RISC-V con RARS - Architettura Elaboratori #1 - YouTube](https://www.youtube.com/watch?v=9rBoZFPEHWo)[Assembly - RISC-V con RARS - Architettura Elaboratori #1 - YouTube](https://www.youtube.com/watch?v=9rBoZFPEHWo))

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

## [Lezione 2]([Assembly - RISC-V con RARS - Architettura Elaboratori #2 - YouTube](https://www.youtube.com/watch?v=y3V8Lvh82nc))

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

## [Lezione 3]([Assembly - RISC-V con RARS - Architettura Elaboratori #3 - YouTube](https://www.youtube.com/watch?v=xVpiy6aWi8Q))

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

## [Lezione 4]([Assembly - RISC-V con RARS - Architettura Elaboratori #4 - YouTube](https://www.youtube.com/watch?v=IufKaw4_e0w))

Si scriva un programma che carichi 4 numeri interi presenti in gia' in memoria in  word contigue e calcoli la media aritmetica.

il valore calcolato va salvato in un ulteriore posizione della memoria contigua a quelle usate per il calcolo.

```python

```
