	.option nopic
	.attribute arch, "rv32i2p1_m2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	2
	.globl	digitsum
	.type	digitsum, @function
	
digitsum:
	addi a2, ra, 0
	addi t0, x0, 0
	jal ra, digitsumsingle
	add t0, t0, a0
	addi a0, a1, 0
	jal ra, digitsumsingle
	add t0, t0, a0
	addi a0, t0, 0
	addi ra, a2, 0
	jr	ra
	.size	digitsum, .-digitsum
	.ident	"GCC: (g2ee5e430018) 12.2.0"

digitsumsingle:
	addi t3, x0, 0
	addi t1, x0, 0
	addi t2, x0, 10
	Loop:
		rem t1, a0, t2
		add t3, t3, t1
		div a0, a0, t2
		bne a0, x0, Loop
	addi a0, t3, 0
	jalr x0, 0(ra)
