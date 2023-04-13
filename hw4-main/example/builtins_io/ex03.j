.class public ex03
.super java/lang/Object
.method public static writelnI(I)V
.limit locals 5
.limit stack 5
    getstatic java/lang/System/out Ljava/io/PrintStream;
    iload 0
    invokevirtual java/io/PrintStream/println(I)V
    return
.end method

.method public static writelnR(F)V
    .limit locals 5
    .limit stack 5
    getstatic java/lang/System/out Ljava/io/PrintStream;
    fload 0
    invokevirtual java/io/PrintStream/println(F)V
    return
.end method

.method public static writelnS(Ljava/lang/String;)V
    .limit locals 5
    .limit stack 5
    getstatic java/lang/System/out Ljava/io/PrintStream;
    aload 0
    invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
    return
.end method

.method public static readlnI()I
    .limit locals 10
    .limit stack 10
    ldc 0
    istore 1
LAB1:
    getstatic java/lang/System/in Ljava/io/InputStream;
    invokevirtual java/io/InputStream/read()I
    istore 2
    iload 2
    ldc 10
    isub
    ifeq LAB2
    iload 2
    ldc 32
    isub
    ifeq LAB2
    iload 2
    ldc 48
    isub
    ldc 10
    iload 1
    imul
    iadd
    istore 1
    goto LAB1
LAB2:
    iload 1
    ireturn
.end method
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 1
    ldc 2
    iadd
    invokestatic ex03/writelnI(I)V
    ldc 1
    ldc 2
    isub
    invokestatic ex03/writelnI(I)V
    ldc 1
    ldc 2
    imul
    invokestatic ex03/writelnI(I)V
    ldc 1
    ldc 2
    idiv
    invokestatic ex03/writelnI(I)V
    ldc 1.000000
    ldc 2.000000
    fadd
    invokestatic ex03/writelnR(F)V
    ldc 1.000000
    ldc 2.000000
    fsub
    invokestatic ex03/writelnR(F)V
    ldc 1.000000
    ldc 2.000000
    fmul
    invokestatic ex03/writelnR(F)V
    ldc 1.000000
    ldc 2.000000
    fdiv
    invokestatic ex03/writelnR(F)V
    ldc 1
    ldc 2
    if_icmpgt L1
    ldc 0
    goto L2
L1:
    ldc 1
L2:
    invokestatic ex03/writelnI(I)V
    ldc 1
    ldc 2
    if_icmplt L3
    ldc 0
    goto L4
L3:
    ldc 1
L4:
    invokestatic ex03/writelnI(I)V
    ldc 1
    ldc 2
    if_icmpeq L5
    ldc 0
    goto L6
L5:
    ldc 1
L6:
    invokestatic ex03/writelnI(I)V
    ldc 1
    ldc 2
    if_icmple L7
    ldc 0
    goto L8
L7:
    ldc 1
L8:
    invokestatic ex03/writelnI(I)V
    ldc 1
    ldc 2
    if_icmpge L9
    ldc 0
    goto L10
L9:
    ldc 1
L10:
    invokestatic ex03/writelnI(I)V
    ldc 1
    ldc 2
    if_icmpne L11
    ldc 0
    goto L12
L11:
    ldc 1
L12:
    invokestatic ex03/writelnI(I)V
    ldc 1.000000
    ldc 2.000000
    fcmpg
    ldc 1
    if_icmpeq L13
    ldc 0
    goto L14
L13:
    ldc 1
L14:
    invokestatic ex03/writelnI(I)V
    ldc 1.000000
    ldc 2.000000
    fcmpg
    ldc -1
    if_icmpeq L15
    ldc 0
    goto L16
L15:
    ldc 1
L16:
    invokestatic ex03/writelnI(I)V
    ldc 1.000000
    ldc 2.000000
    fcmpg
    ldc 0
    if_icmpeq L17
    ldc 0
    goto L18
L17:
    ldc 1
L18:
    invokestatic ex03/writelnI(I)V
    ldc 1.000000
    ldc 2.000000
    fcmpg
    ldc 1
    if_icmplt L19
    ldc 0
    goto L20
L19:
    ldc 1
L20:
    invokestatic ex03/writelnI(I)V
    ldc 1.000000
    ldc 2.000000
    fcmpg
    ldc -1
    if_icmpgt L21
    ldc 0
    goto L22
L21:
    ldc 1
L22:
    invokestatic ex03/writelnI(I)V
    ldc 1.000000
    ldc 2.000000
    fcmpg
    ldc 0
    if_icmpne L23
    ldc 0
    goto L24
L23:
    ldc 1
L24:
    invokestatic ex03/writelnI(I)V
new java/lang/StringBuffer
dup
invokespecial java/lang/StringBuffer/<init>()V
    ldc "1"
invokevirtual java/lang/StringBuffer/append(Ljava/lang/String;)Ljava/lang/StringBuffer;
    ldc "2"
invokevirtual java/lang/StringBuffer/append(Ljava/lang/String;)Ljava/lang/StringBuffer;
invokevirtual java/lang/StringBuffer/toString()Ljava/lang/String;
    invokestatic ex03/writelnS(Ljava/lang/String;)V
    return
.end method
