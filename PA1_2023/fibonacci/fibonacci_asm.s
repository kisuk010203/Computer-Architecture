	.option nopic
	.attribute arch, "rv32i2p1_m2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	2
	.globl	fibonacci
	.type	fibonacci, @function
	
fibonacci:
	
	#------Your code starts here------
	# fibonacci number : a0
	addi sp, sp, -12
	sw ra, 4(sp)
	sw a0, 0(sp)

	addi t0, a0, -2
	bgt t0, x0, Loop

	addi a0, x0, 1
	addi sp, sp, 12
	# Load return value to reg a0
	#------Your code ends here------

	jr	ra
	.size	fibonacci, .-fibonacci
	.ident	"GCC: (g2ee5e430018) 12.2.0"

Loop:
	addi a0, a0, -1
	jal ra, fibonacci
	addi t1, a0, 0
	sw t1, 8(sp)
	lw a0, 0(sp)

	addi a0, a0, -2
	jal ra, fibonacci
	lw t1, 8(sp)
	add t1, t1, a0
	lw ra, 4(sp)
	lw a0, 0(sp)
	addi a0, t1, 0

	addi sp, sp, 12
	jalr x0, 0(x1)
