.globl start
.text
start:
addi t0, zero, 8 #n
addi t1, zero, 1 #r
addi t2, zero, 0 #a
addi t3, zero, 1 #b
loop:
beq t0, zero, exit
add t4,t2,t3
add t1,t1,t4
add t2,zero,t3
add t3,zero,t1
addi t0,t0,-1
j loop

exit: #chiamo una sistem call esempio il print o il return 0
addi x17, x0, 10#uscire