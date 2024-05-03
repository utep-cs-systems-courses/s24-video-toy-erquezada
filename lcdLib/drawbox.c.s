	.arch msp430g2553
	.p2align 1,0
	.text

    .global drawBox
    .extern drawPixel

drawBox:
    sub #10, r1
    mov.b r12, 0(r1) ; acol
    mov.b r13, 1(r1) ; arow
    mov.b r14, 2(r1)
    mov r15, 6(r1)
    mov.b 0(r1), 3(r1)
    add.b 2(r1), 3(r1)
    mov.b 1(r1), 4(r1)
    add.b 2(r1), 4(r1)
    mov.b 0(r1), 5(r1)
    sub.b 2(r1), 5(r1)
top1:
    cmp.b 3(r1), 5(r1)
     jc out1
    mov.b 1(r1), 8(r1)
    sub.b 2(r1), 8(r1)
top2:
    cmp.b 4(r1), 8(r1)
     jc out2
    mov.b 5(r1), r12
    mov.b 8(r1), r13
    mov 6(r1), r14
    call #drawPixel
    add.b #1, 8(r1)
    jmp top2
out2:
    add.b #1, 5(r1)
    jmp top1
out1:
   add #10, r1
   pop r0
