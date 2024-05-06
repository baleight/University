.globl main
.data    
    str1: .string "sum:"
    str2: .string "\n"
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

    j exit
    
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