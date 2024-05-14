

.data
constpi:
.float	3.1415
const2:
.float	2

.text
main:
	li a0, 2
	flw fa0, constpi,t0
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
	
	flw fs0, const2,t0
	
	addi a0, a0, -1
	jal ra, mul2
	fmul.s fa0, fa0,fs0  # mul2(A, B-1) * 2
	
exit:
	lw  ra, 0(sp)
	flw fs0, 4(sp)
	addi sp, sp, 8
	ret
