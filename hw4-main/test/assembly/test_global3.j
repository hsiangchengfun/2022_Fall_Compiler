.class public test_global3
.super java/lang/Object
.field public static a I
.field public static a F
.field public static a Ljava/lang/String;
.field public static b I
.field public static b F
.field public static b Ljava/lang/String;
.field public static c F
.field public static c Ljava/lang/String;
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
.method public static tt_0()I
.method public static tt_0()F
.method public static tt_0()Ljava/lang/String;
.limit locals 50
.limit stack 50
.field public static a [I
.field public static b [I
    a
    ldc 1
    ldc 10
    b
    ldc 1
    getstatic test_global3/a I
    ldc 1
    ldc 11
    iadd
    getstatic test_global3/b I
    ldc 1
.end method
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 0
    putstatic test_global3/a I
    ldc 0.0
    putstatic test_global3/a F
    ldc ""
    putstatic test_global3/a Ljava/lang/String;
    ldc 0
    putstatic test_global3/b I
    ldc 0.0
    putstatic test_global3/b F
    ldc ""
    putstatic test_global3/b Ljava/lang/String;
    ldc 0.0
    putstatic test_global3/c F
    ldc ""
    putstatic test_global3/c Ljava/lang/String;
    ldc 2
    ldc 1
    multianewarray [[I 2
    putstatic test_global3/a [[I
    ldc 2
    ldc 1
    multianewarray [[I 2
    putstatic test_global3/b [[I
    ldc 3
    putstatic test_global3/a I
    ldc 4
    putstatic test_global3/b I
    invokestatic test_global3/tt_0()I
    invokestatic test_global3/writelnI(I)V
    return
.end method
