Esercizi Assembly:

### Esercizio 1

Si convertano le seguenti istruzioni da un formato all’altro.

1. `add s0, zero, a1`
2. `or x18, x1, x30`

![](C:\Users\baleo\Pictures\GitUni\imagesMarkText\2024-04-25-11-13-34-image.png)

#### Soluzione:

1. `add s0, zero, a1` → `add x8, x0, x11`

2. `or x18, x1, x30` → `or s2, ra, t5`

3. `add s0, zero, a1` → `add x8, x0, x11`: In RISC-V, `s0` e `a1` sono rispettivamente registri salvati e argomento. Cambiamo il formato da `add` a `addi` e sostituiamo i registri con i relativi registri RISC-V.

4. `or x18, x1, x30` → `or s2, ra, t5`: Qui stiamo trasformando i registri RISC-V `x18`, `x1`, e `x30` in `s2`, `ra`, e `t5` rispettivamente.

### Esercizio 2 con soluzione

Si assuma di avere un array in memoria così inizializzato:

```c
int* arr = {1,2,3,4,5,6,0}
```

Si assuma che l’indirizzo base dell’array risieda in s0.

Cosa fanno i seguenti frammenti di codice? Si assuma che i frammenti eseguano in sequenza.
a)

```assembly
lw t0, 12(s0) // t0 = arr[3]
slli t1, t0, 2 // t1 = 4 * t0 = 16
add t2, s0, t1 // t2 = arr + t1 = &arr[4]
lw t3, 0(t2) // t3 = arr[4]
addi t3, t3, 1 // t3 = arr[4] + 1
sw t3, 0(t2) // arr[4] = arr[4] + 1
```

b)

```assembly
lw t0, 0(s0) // t0 = arr[0] = 1
xori t0, t0, 0xFF // t0 = t0 ^ 0xFFF = -2
addi t0, t0, 1 // t0 = t0 + 1 = -1
```

### Esercizio 3 con soluzione

Si converta il seguente frammento di codice C in assembly RISC-V:

```c
// s0 -> a, s1 -> b
// s2 -> c, s3 -> z
int a = 4, b = 5, c = 6, z;
z = a + b + c + 10;
```

#### Soluzione:

```assembly
addi s0, zero, 4
addi s1, zero, 5
addi s2, zero, 6
add s3, s0, s1
add s3, s3, s2
addi s3, s3, 10
```

### Esercizio 4

Si converta il seguente frammento di codice C in assembly RISC-V:

```c
// s0 -> int * p = intArr;
// s1 -> a;
*p = 0;
int a = 2;
p[1] = p[a] = a;
```

#### Soluzione:

```assembly
# Memorizza il valore zero nella posizione di memoria puntata da s0
sw zero, 0(s0)   # *p = 0

# Carica l'immediato 2 nel registro s1
addi s1, zero, 2   # a = 2

# Memorizza il contenuto di s1 (che è 2) nella posizione di memoria ottenuta aggiungendo 4 a s0
sw s1, 4(s0)   # p[1] = 2

# Moltiplica il contenuto di s1 per 4 e memorizza il risultato in t0
slli t0, s1, 2   # t0 = a * 4

# Aggiunge il contenuto di s0 a t0 e memorizza il risultato in t0
add t0, t0, s0   # t0 = &p + (a * 4)

# Memorizza il contenuto di s1 (che è 2) nella posizione di memoria ottenuta sommando 0 a t0
sw s1, 0(t0)   # p[a] = 2
```

### Esercizio 5

Si converta il seguente frammento di codice C in assembly RISC-V:

```c
// s0 -> a, s1 -> b
int a = 5, b = 10;
if(a + a == b) {
    a = 0;
} else {
    b = a - 1;
}
```

#### Soluzione:

```assembly
addi s0, zero, 5
addi s1, zero, 10
add t0, s0, s0
bne t0, s1, else
xor s0, zero, zero
jal zero, exit
else:
addi s1, s0, -1
exit:
```

### Esercizio 6

Si converta il seguente frammento di assembly RISC-V in codice C e si dica cosa fa:

```assembly
addi s0, zero, 0
addi s1, zero, 1
addi t0, zero, 30
loop:
beq s0, t0, exit
add s1, s1, s1
addi s0, s0, 1
jal zero, loop
exit:
```

#### Soluzione:

```c
// Calcola s1 = 2^30
s1 = 1;
for (s0 = 0; s0 < 30; s0++)
{
    s1 *= 2;
}
```

### Esercizio 7

Si converta il seguente frammento di codice C in assembly RISC-V:

```c
// s0 -> n, s1 -> sum
// si assuma n > 0 per iniziare
for (int sum = 0; n > 0; n--)
{
    sum += n;
}
```



#### Soluzione:

```assembly
addi s1, zero, 0
loop:
beq s0, x0, exit
add s1, s1, s0
addi s0, s0, -1
jal zero, loop
exit:
```
