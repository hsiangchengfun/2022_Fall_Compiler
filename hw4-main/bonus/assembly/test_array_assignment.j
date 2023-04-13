.class public test_array_assignment
.super java/lang/Object
.field public static a [I
.field public static b I
.field public static b F
.field public static b Ljava/lang/String;
.field public static c [I
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
    ldc 0
    putstatic test_array_assignment/b I
    ldc 0.0
    putstatic test_array_assignment/b F
    ldc ""
    putstatic test_array_assignment/b Ljava/lang/String;
    ldc 5
    ldc 1
    multianewarray [[I 2
    putstatic test_array_assignment/a [[I
    ldc 2
    ldc 5
    multianewarray [[I 2
    putstatic test_array_assignment/c [[I
    ldc "a[1..5]:"
    invokestatic test_array_assignment/writelnS(Ljava/lang/String;)V
    ldc 1
    putstatic test_array_assignment/b I
L1:
    getstatic test_array_assignment/b I
    ldc 5
    if_icmple L2
    ldc 0
    goto L3
L2:
    ldc 1
L3:
    if_icmpne L2
    ldc 0
    goto L3
L2:
    ldc 1
L3:
    ifeq L4
    a
    getstatic test_array_assignment/b I
    getstatic test_array_assignment/b I
    ldc 1
    iadd
    putstatic test_array_assignment/a I
    invokestatic test_array_assignment/a()I
    getstatic test_array_assignment/b I
    invokestatic test_array_assignment/writelnI(I)V
    getstatic test_array_assignment/b I
    ldc 1
    iadd
    putstatic test_array_assignment/b I
    goto L1
L4:
    invokestatic test_array_assignment/writelnS(Ljava/lang/String;)V
    ldc 1
    putstatic test_array_assignment/b I
L5:
    getstatic test_array_assignment/b I
    ldc 5
    if_icmple L6
    ldc 0
    goto L7
L6:
    ldc 1
L7:
    if_icmpne L6
    ldc 0
    goto L7
L6:
    ldc 1
L7:
    ifeq L8
    invokestatic test_array_assignment/c()I
    ldc 1
    getstatic test_array_assignment/b I
    invokestatic test_array_assignment/writelnI(I)V
    getstatic test_array_assignment/b I
    ldc 1
    iadd
    putstatic test_array_assignment/b I
    goto L5
L8:
    invokestatic test_array_assignment/writelnS(Ljava/lang/String;)V
    c
    ldc 1
    invokestatic test_array_assignment/a()I
    putstatic test_array_assignment/c Ljava/lang/String;
    invokestatic test_array_assignment/writelnS(Ljava/lang/String;)V
    ldc 1
    putstatic test_array_assignment/b I
L9:
    getstatic test_array_assignment/b I
    ldc 5
    if_icmple L10
    ldc 0
    goto L11
L10:
    ldc 1
L11:
    if_icmpne L10
    ldc 0
    goto L11
L10:
    ldc 1
L11:
    ifeq L12
    invokestatic test_array_assignment/c()I
    ldc 1
    getstatic test_array_assignment/b I
    invokestatic test_array_assignment/writelnI(I)V
    getstatic test_array_assignment/b I
    ldc 1
    iadd
    putstatic test_array_assignment/b I
    goto L9
L12:
    invokestatic test_array_assignment/writelnS(Ljava/lang/String;)V
    a
    ldc 1
    ldc 100
    putstatic test_array_assignment/a I
    invokestatic test_array_assignment/writelnS(Ljava/lang/String;)V
    ldc 1
    putstatic test_array_assignment/b I
L13:
    getstatic test_array_assignment/b I
    ldc 5
    if_icmple L14
    ldc 0
    goto L15
L14:
    ldc 1
L15:
    if_icmpne L14
    ldc 0
    goto L15
L14:
    ldc 1
L15:
    ifeq L16
    invokestatic test_array_assignment/c()I
    ldc 1
    getstatic test_array_assignment/b I
    invokestatic test_array_assignment/writelnI(I)V
    getstatic test_array_assignment/b I
    ldc 1
    iadd
    putstatic test_array_assignment/b I
    goto L13
L16:
    return
.end method
