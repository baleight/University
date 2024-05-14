```c

int acc (int array[], int size) {
int i, sum = 0;
for (i= 0; i< size; i+= 1)
sum += array[i];
}
```



```assembly



se metti x0 e' asembly non risc v

#a0-> array*
#a1-> size
#t0->i 
#t1->sum

#

addi t0,t0,0

addi t1,t1,0


Loop:
	bgt t0,a1, exit
	slli t2,t0,2
	add t3,a0,t2
	lw t4,0(t3)
	add t1, t1,t4
	addi t0,t0,1
	jal x0, loop
exit:



```



```assembly
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

