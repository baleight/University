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
