.class public test_array
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
    putstatic test_array/b I
    ldc 0.0
    putstatic test_array/b F
    ldc ""
    putstatic test_array/b Ljava/lang/String;
    ldc 2
    ldc 1
    multianewarray [[I 2
    putstatic test_array/a [[I
    ldc 2
    ldc 2
    multianewarray [[I 2
    putstatic test_array/c [[I
    a
    ldc 1
    ldc 1
    putstatic test_array/a I
    a
    ldc 2
    ldc 2
    putstatic test_array/a I
    c
    ldc 1
    ldc 1
    invokestatic test_array/a()I
    ldc 1
    putstatic test_array/c I
    c
    ldc 1
    ldc 2
    invokestatic test_array/a()I
    ldc 2
    putstatic test_array/c I
    c
    ldc 2
    ldc 1
    invokestatic test_array/a()I
    ldc 2
    invokestatic test_array/a()I
    ldc 1
    iadd
    putstatic test_array/c I
    c
    ldc 2
    ldc 2
    invokestatic test_array/a()I
    ldc 2
    invokestatic test_array/a()I
    ldc 2
    iadd
    putstatic test_array/c I
    invokestatic test_array/c()I
    ldc 1
    ldc 1
    invokestatic test_array/c()I
    ldc 1
    ldc 2
    iadd
    invokestatic test_array/c()I
    ldc 2
    ldc 1
    iadd
    invokestatic test_array/c()I
    ldc 2
    ldc 2
    iadd
    invokestatic test_array/writelnI(I)V
    return
.end method
