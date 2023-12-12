addi x1, x0, 1
addi x2, x0, 2
addi x3, x0, 3
addi x4, x0, 4
beq x1, x2, 14
addi x5, x0, 5
beq x2, x3, 10
addi x6, x0, 6
beq x3, x4, 6
ld x7, 16(x0)
beq x3, x7, 14
addi x1, x0, -1
addi x2, x0, -1
addi x3, x0, -1
addi x4, x0, -1
addi x5, x0, -1
addi x6, x0, -1
halt