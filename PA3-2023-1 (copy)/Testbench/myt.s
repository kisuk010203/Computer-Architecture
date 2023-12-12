ld	x5, 0(x0)
ld	x6, 8(x0)
add	x9, x5, x6
ld	x7, 16(x0)
add	x10, x6, x7
add	x11, x9, x10
sd	x10, 40(x0)
sd	x9, 32(x0)
sd	x11, 48(x0)
add	x5, x0, x5
addi	x5, x5, 20
addi	x4, x5, 10
ld x12, 40(x0)
sd	x4, 56(x0)
halt

