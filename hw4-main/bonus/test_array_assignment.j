.class public test_array_assignment
.super java/lang/Object
.field public static a [I
.field public static b I
.field public static c [[I
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
    ldc 5
    multianewarray [I 1
    putstatic test_array_assignment/a [I
    ldc 0
    putstatic test_array_assignment/b I
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
    if_icmple L3
    ldc 0
    goto L4
L3:
    ldc 1
L4:
    ifeq L2
    getstatic test_array_assignment/a [I
    getstatic test_array_assignment/b I
    ldc 1
    isub
    getstatic test_array_assignment/b I
    ldc 1
    iadd
    iastore
    getstatic test_array_assignment/a [I
    getstatic test_array_assignment/b I
    ldc 1
    isub
    iaload
    invokestatic test_array_assignment/writelnI(I)V
    getstatic test_array_assignment/b I
    ldc 1
    iadd
    putstatic test_array_assignment/b I
    goto L1
L2:
    ldc "c[1][1..5]:"
    invokestatic test_array_assignment/writelnS(Ljava/lang/String;)V
    ldc 1
    putstatic test_array_assignment/b I
L5:
    getstatic test_array_assignment/b I
    ldc 5
    if_icmple L7
    ldc 0
    goto L8
L7:
    ldc 1
L8:
    ifeq L6
    getstatic test_array_assignment/c [[I
    ldc 1
    ldc 1
    isub
    aaload
    getstatic test_array_assignment/b I
    ldc 1
    isub
    iaload
    invokestatic test_array_assignment/writelnI(I)V
    getstatic test_array_assignment/b I
    ldc 1
    iadd
    putstatic test_array_assignment/b I
    goto L5
L6:
    ldc "c[1] := a[1..5];"
    invokestatic test_array_assignment/writelnS(Ljava/lang/String;)V
    getstatic test_array_assignment/c [[I
    ldc 1
    ldc 1
    isub
    getstatic test_array_assignment/a [I
    aastore
    ldc "c[1][1..5]:"
    invokestatic test_array_assignment/writelnS(Ljava/lang/String;)V
    ldc 1
    putstatic test_array_assignment/b I
L9:
    getstatic test_array_assignment/b I
    ldc 5
    if_icmple L11
    ldc 0
    goto L12
L11:
    ldc 1
L12:
    ifeq L10
    getstatic test_array_assignment/c [[I
    ldc 1
    ldc 1
    isub
    aaload
    getstatic test_array_assignment/b I
    ldc 1
    isub
    iaload
    invokestatic test_array_assignment/writelnI(I)V
    getstatic test_array_assignment/b I
    ldc 1
    iadd
    putstatic test_array_assignment/b I
    goto L9
L10:
    ldc "a[1] := 100;"
    invokestatic test_array_assignment/writelnS(Ljava/lang/String;)V
    getstatic test_array_assignment/a [I
    ldc 1
    ldc 1
    isub
    ldc 100
    iastore
    ldc "c[1][1..5]:"
    invokestatic test_array_assignment/writelnS(Ljava/lang/String;)V
    ldc 1
    putstatic test_array_assignment/b I
L13:
    getstatic test_array_assignment/b I
    ldc 5
    if_icmple L15
    ldc 0
    goto L16
L15:
    ldc 1
L16:
    ifeq L14
    getstatic test_array_assignment/c [[I
    ldc 1
    ldc 1
    isub
    aaload
    getstatic test_array_assignment/b I
    ldc 1
    isub
    iaload
    invokestatic test_array_assignment/writelnI(I)V
    getstatic test_array_assignment/b I
    ldc 1
    iadd
    putstatic test_array_assignment/b I
    goto L13
L14:
    return
.end method
