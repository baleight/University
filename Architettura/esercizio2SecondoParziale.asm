.globl main

.data
pi: .float 3.14
arr: .float 1.0, 2.0, 3.0, 4.0

.text
main:
    li t0, 4      # Carica il numero di elementi nell'array
    li t1, 0      # Inizializza l'indice di loop

    flw fs0, pi,x0  # Carica il valore di pi in fs0
    flw fs1, arr,x0 # Carica l'indirizzo di arr in fs1

loop:
    beq t1, t0, exit # Esci dal loop se t1 è uguale a t0

    slli t2, t1, 2   # Calcola l'offset moltiplicando t1 per 4 (dimensione di un float)
    add t2, t2, x0   # Aggiunge x0 all'offset (t2)

    flw fs2, (fs1, t2) # Carica il valore da memoria all'indirizzo fs1+offset in fs2

    fmul.s fs1, fs1, fs0  # Moltiplica fs1 per il valore di pi

    addi t1, t1, 1  # Incrementa t1
    j loop          # Salta al loop

exit:
    addi a0, x0, 0  # Aggiorna a0
    ret             # Ritorna
