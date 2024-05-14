
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
