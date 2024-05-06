# Esercizi su Rars videolezioni

## Esercizio 01

<img src="file:///C:/Users/baleo/Pictures/GitUni/imagesMarkText/2024-05-05-15-33-39-image.png" title="" alt="" width="346">

```nasm
globl main
.data    
    str1: string "i:"
    str2: string "\n"
.text
main:
    li t0, 0 #1
    li t1, 10 #n
    li a7, 4 
loop:
    beq t0, t1, exit
    la a0, str1
    ecall
    li a7, 1
    mv a0, t0
    ecall
    la a0, str2
    l1 a7, 4
    ecall
    addi t0, t0, 1
    j loop
exit:
    li a0, 0
    li a7, 93
    ecall
```

## Esercizio 02

<img src="file:///C:/Users/baleo/Pictures/GitUni/imagesMarkText/2024-05-05-15-33-01-image.png" title="" alt="" width="402">

```nasm
globl main
.data    
    str1: string "sum:"
    str2: string "\n"
.text
main:
    li a7, 4               # Carica il codice di servizio per la stampa di una stringa
    la a0, str1            # Carica l'indirizzo della stringa str1 in a0
    ecall                  

    li a0, 10              # Carica il valore 10 in a0
    jal ra, sum            # Salta e salva l'indirizzo di ritorno, invocando la funzione sum
    li a7, 1               # Carica il codice di servizio per la stampa di un intero
    ecall                  

    la a0, str2            # Carica l'indirizzo della stringa str2 in a0
    li a7, 4               # Carica il codice di servizio per la stampa di una stringa
    ecall                  


    li t0, 0               # Inizializza t0 a 0 (indice i)
    li a0, 0               # Inizializza a0 a 0 (valore di ritorno della funzione sum)

exit:
    li a0, 0               # Carica il valore 0 in a0 (codice di uscita)
    li a7, 93              # Carica il codice di servizio per l'uscita dal programma
    ecall                  

sum:
    li t0, 0               # Inizializza t0 a 0 (indice i)
    li t1, 0               # Inizializza t1 a 0 (somma dei numeri)

sum_loop:
    beq t0, a0, sum_end    # Se t0 è uguale a a0 (valore passato alla funzione), salta a sum_end
    add t1, t1, t0         # Aggiunge il valore di t0 a t1 (somma)
    addi t0, t0, 1         # Incrementa t0 di 1
    j sum_loop             # Salta a sum_loop

sum_end:
    mv a0, t1              # Muove il valore di t1 (somma) in a0 (valore di ritorno)
    jr ra                  # Salta all'indirizzo di ritorno
```

10 > 45

## Esercizio 3

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-05-05-16-07-08-image.png)
