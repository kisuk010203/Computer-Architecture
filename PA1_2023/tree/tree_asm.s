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
	addi sp, sp, -16
	sw a0, 0(sp)
	sw ra, 4(sp)
	addi t0, x0, 4 # cur
	addi t1, x0, 0 # head
	sw t0, x0, 8(sp)
	sw t1, x0, 12(sp)
	sw a0, 0(a1)

	addi t5, x0, 0 # ans
	jal ra, Loop

	addi a0, x0, 0
	addi sp, sp, 12

	# Load return value to reg a0
	#------Your code ends here------

	jr	ra
	.size	tree, .-tree
	.ident	"GCC: (g2ee5e430018) 12.2.0"

Loop:
	addi sp, sp, -12
	lw t0, 8(sp) # cur
	lw t1, 12(sp) # head
	beq t0, t1, Exit

	add t6, a1, t1 # t6 is queue[head]
	addi t1, t1, 4
	sw t1, 12(sp)

	lw t2, 0(t6) # val
	lw t3, 4(t6) # left
	lw t4, 8(t6) # right

	addi a0, t3, 0
	bne t3, x0, AddNode

	addi a0, t4, 0
	bne t4, x0, AddNode

	add t5, t5, t2

	lw a0, 0(sp)
	j Loop

AddNode:
	add t6, a1, t0
	sw a0, 0(t6)
	addi t0, t0, 4

Exit:
	lw ra, 4(sp)
	lw a0, 0(sp)
	addi sp, sp, 16
	jalr x0, 0(ra)
