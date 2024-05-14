.globl start
.data
	num: .word 5
.text
start:
la a0, num
lw a0, 0(a0)
jal ra, fib

li a7, 10
ecall

fib:
beq a0,zero,fine
li t1, 1
beq a0, t1, else_if

else:
addi sp,sp, -8
sw ra, 0(sp)
sw a0, 4(sp)

sub a0,a0,t1

jal fib
addi t2,a0,0 # salvo il valore di fib(n-1)

lw a0,4(sp)
lw ra 0(sp)
addi sp, sp,8

addi sp,sp, -12
sw ra, 0(sp)
sw a0, 4(sp)
sw t2, 8(sp)

li t3, 2
sub a0,a0,t3
j fib
addi t4,a0,0

lw ra 0(sp)
lw a0, 4(sp)
lw t2, 8(sp)
addi sp,sp 12

#sommiamo i valori di ritorno
add a0,t4,t2
jr ra




else_if:
li a0, 1
jr ra #ret stessa cosa

fine:
li a0,0
jr ra #return 0