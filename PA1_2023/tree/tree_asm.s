	.option nopic
	.attribute arch, "rv32i2p1_m2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	2
	.globl	tree
	.type	tree, @function
tree:

	#------Your code starts here------
	# root tree node addr : a0, queue array addr : a1
	addi sp, sp, -12
	sw a0, 0(sp)
	sw ra, 4(sp)

	bne a0, x0, Loop
	addi a0, x0, 0
	addi sp, sp, 12
	jr	ra
	.size	tree, .-tree
	.ident	"GCC: (g2ee5e430018) 12.2.0"

Loop:
	lw t0, 0(a0) # val
	blt t0, x0, ZeroRootCase # zerorootcase
	sw t0, 8(sp)

	lw a0, 4(a0) # left
	jal ra, tree
	lw t0, 8(sp)
	add t0, t0, a0
	sw t0, 8(sp)

	lw a0, 0(sp)
	lw a0, 8(a0) # right
	jal ra, tree
	lw t0, 8(sp)
	add t0, t0, a0

	lw ra, 4(sp)
	lw a0, 0(sp)
	addi a0, t0, 0
	addi sp, sp, 12
	jalr x0, 0(ra)

ZeroRootCase:
	addi a0, x0, 0
	lw ra, 4(sp)
	addi sp, sp, 12
	jalr x0, 0(ra)
