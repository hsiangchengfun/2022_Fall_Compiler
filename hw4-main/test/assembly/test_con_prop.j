.class public test_con_prop
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
.method public static ss_0(I)I
.method public static ss_0(I)F
.method public static ss_0(I)Ljava/lang/String;
.limit locals 50
.limit stack 50
.end method
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 0
    putstatic test_con_prop/b I
    ldc 0.0
    putstatic test_con_prop/b F
    ldc ""
    putstatic test_con_prop/b Ljava/lang/String;
    ldc 2
    ldc 1
    multianewarray [[I 2
    putstatic test_con_prop/a [[I
    ldc 2
    ldc 2
    multianewarray [[I 2
    putstatic test_con_prop/c [[I
    a
    ldc 3
    ldc 4
    iadd
    ldc 6
    isub
    ldc 10
    putstatic test_con_prop/a I
    c
    ldc 1
    ldc 100
    ldc 0
    imul
    iadd
    ldc 1
    iadd
    ldc 2
    ldc 4
    ldc 2
    idiv
    iadd
    ldc 100
    putstatic test_con_prop/c I
    invokestatic test_con_prop/a()I
    ldc 1
    invokestatic test_con_prop/writelnI(I)V
    invokestatic test_con_prop/c()I
    ldc 2
    ldc 4
    invokestatic test_con_prop/writelnI(I)V
    return
.end method
