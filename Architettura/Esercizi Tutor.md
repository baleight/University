## Esercizi Tutor

### Fattoriale1

```assembly
# Note: .global and .text is optional on RARS (but you should still use it)
# (code on slides, not modified)
main:
	addi a0,x0,3
	jal ra,fact

fact:
	addi sp,sp,-8		# Prelude
	sw ra,4(sp)
	sw a0,0(sp)
	addi t0,a0,-1		# Variable setup
	bge t0,x0,L1		# Check if t0 >= 0
	addi a0,x0,1		# Early exit (epilogue)
	addi sp,sp,8
	jalr x0,0(ra)

L1: addi a0,a0,-1
	jal ra,fact			# Reursion with a0 - n - 1
	addi t1,a0,0		# Move return value (a0) into t1
	lw a0,0(sp)
	lw ra,4(sp)
	addi sp,sp,8
	mul a0,a0,t1		# Multiply return value (t1) by n (restored a0)
	jalr x0,0(x1)

```



```c
#Fattoriale
```



## Fattoriale

```assembly
# Note: .global and .text is optional on RARS (but you should still use it)
# (code on slides, not modified)
main:
    addi a0, x0, 3    # Carica il valore 3 nel registro a0 (input per il calcolo del fattoriale)
    jal ra, fact       # Chiama la funzione "fact", salvando l'indirizzo di ritorno nel registro ra

fact:
    addi sp, sp, -8   # Preparazione dello stack frame: sposta lo stack pointer per fare spazio per le variabili locali e il salvataggio dei registri
    sw ra, 4(sp)      # Salva il registro ra nello stack per preservarne il valore durante la chiamata a funzione
    sw a0, 0(sp)      # Salva il valore di a0 (input) nello stack per preservarlo durante la chiamata a funzione
    addi t0, a0, -1   # Prepara il parametro per la chiamata ricorsiva decrementando il valore di a0 di 1 e salvando il risultato in t0
    bge t0, x0, L1    # Se t0 (a0 - 1) è maggiore o uguale a zero, salta a L1, altrimenti procedi al calcolo del caso base
    addi a0, x0, 1    # Restituisce 1 come valore del fattoriale se l'input è 0 (caso base)
    addi sp, sp, 8    # Ripristina lo stack pointer dopo il salvataggio dei registri
    jalr x0, 0(ra)    # Ritorna al chiamante

L1:                   # Etichetta per il ramo del caso ricorsivo
    addi a0, a0, -1   # Decrementa il valore di a0 (input) di 1 in preparazione alla chiamata ricorsiva
    jal ra, fact      # Chiama ricorsivamente la funzione "fact", salvando l'indirizzo di ritorno in ra
    addi t1, a0, 0    # Copia il valore di ritorno (a0) in t1 per preservarlo
    lw a0, 0(sp)      # Ripristina il valore di a0 dallo stack
    lw ra, 4(sp)      # Ripristina il valore di ra dallo stack
    addi sp, sp, 8    # Ripristina lo stack pointer dopo il ripristino dei registri
    mul a0, a0, t1    # Calcola il fattoriale moltiplicando il valore di a0 per il valore di ritorno della chiamata ricorsiva (t1)
    jalr x0, 0(x1)    # Ritorna al chiamante

```

##  Fmul

```assembly


.data
constpi: 
.float	3.1415
const2:
.float	2

.text
main:
	li a0, 2
	flw fa0, constpi,t0 #fa0=3,14
	flw fs0, const2,t0 #fs0=2
	jal ra, mul2
			
	li a7, 2			# Print result
	ecall 
	
	li a7, 10			# Exit
	ecall
	

mul2:
	# fa0 -> A
	# a0 -> B
	addi sp, sp, -8
	sw  ra, 0(sp)
	fsw fs0, 4(sp)
	ble a0, zero, exit
	
	
	
	addi a0, a0, -1
	jal ra, mul2
	fmul.s fa0, fa0,fs0  # mul2(A, B-1) * 2
	
exit:
	lw  ra, 0(sp)
	flw fs0, 4(sp)
	addi sp, sp, 8
	ret

```



## String a decimale

```assembly

.data
str:
.asciz  "-123"


.text

main:

	la a0, str
	jal ra, str2dec
	
	li a7, 1		# PrintInt
	ecall

	li a7, 10		# Exit
	ecall	

str2dec:
# s -> a0
# res -> t0
# i -> t1
	lb t2, 0(a0)
	li t3, 43	# '+'
	beq	t2, t3, plus # s[0] == '+'
	li t3, 45	# '-'
	beq	t2, t3, plus # s[0] == '-'
	j loop
plus:
	addi t1, t1, 1
loop:
	add t4, t1, a0
	lb	t3, 0(t4) 	# t3 = a[i]
	beq t3, zero, loop_exit
	addi t6, zero, 10	# t6 = 10
	mul	t0, t0, t6		# s *= 10
	addi t3, t3, -48	
	add t0, t0, t3		# s += a[i] - 48
	addi, t1, t1, 1		# i++
	j loop
	
loop_exit:
	lb t2, 0(a0)
	li t3, 45	# '-'
	bne	t2, t3, exit	# s[0] != '-'
	sub t0, zero, t0	# Invert s
exit:
	mv a0, t0
	ret

```



## Sum square

```assembly


.global main


.text 

main:
		addi a0, x0, 5
		jal ra, sum_square
		addi a7, x0, 10			# Call RARS exit function
		ecall
halt:	j halt					# If eall does not work: infinite loop

sum_square:
								# Prologue
		addi sp, sp, -12
		sw	ra, 0(sp)
		sw 	s0, 4(sp)
		sw	s1, 8(sp)
								# Initialize variables
		addi s0, a0, 0
		addi s1, x0, 0
								# Main loop
loop:	bge x0, s0, out
		addi a0, s0, 0			# args[0] = i
		jal ra, square			# call square(i)
		add s1, s1, a0
		addi s0, s0, 1
		jal x0, loop
out:
		addi a0, s1, 0			# Setup return value
		lw ra, 0(sp)			# Epilogue
		lw s0, 4(sp)
		lw s1, 8(sp)
		addi sp, sp, 12
		jr ra
		
		
		

square:
								#  n -> a0
								#  i -> t0
								# sum -> t1
								# No prelude (leaf function)
		addi t0, x0, 0
		addi t1, x0, 0
square_loop:
		bge  t0, a0, square_out
		add  t1, t1, a0
		addi t0, t0, 1
		jal x0, square_loop

square_out:
		addi a0, t1, 0
		jr ra
		

```



Fibonaci

```assembly

.globl fib
.data
num: .word 5

.text
fib:
la a0, num
lw a0, 0(a0)

beq a0,zero, rzero
li t0, 1
beq a0,t0,runo

else:
#salvo i valori in memoria
addi sp,sp, -8
sw ra, 0(sp)
sw a0, 4(sp)

sub t1,a0,t0
j fib #la variabile di a0 non viene ritornata e quella del ciclo
se avessi mosso fib dopo il ripristino avrei utilizzato un altra a0
lw ra, 0(sp) #ripristino
lw a0, 4(sp)
addi sp,sp 8

#fib(n-2)
addi  sp,sp,-12
sw ra, 0(sp)
sw a0, 4(sp)
sw t1, 8(sp) #salvo il valore di fib(n-1)

li t2, 2
sub a0,a0,t2
j ra
lw ra, 0(sp) #ripristino
lw a0, 4(sp)
lw t1, 8(sp)
addi sp,sp 12


add a0, s0, s1
jr ra

runo:
addi a0,a0,1
jr ra

rzero:
addi a0, a0, 0
jr ra



```









