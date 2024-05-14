

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
		
