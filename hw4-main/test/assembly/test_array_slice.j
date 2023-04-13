.class public test_array_slice
.super java/lang/Object
.field public static a [I
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
.method public static slice_0(Ljava/lang/String;)I
.method public static slice_0(Ljava/lang/String;)F
.method public static slice_0(Ljava/lang/String;)Ljava/lang/String;
.limit locals 50
.limit stack 50
    ldc 3
    ldc 4
    iadd
    ldc 5
    iadd
.end method
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 2
    ldc 3
    multianewarray [[I 2
    putstatic test_array_slice/a [[I
    a
    ldc 2
    ldc 3
    ldc 1
    putstatic test_array_slice/a I
    a
    ldc 2
    ldc 4
    ldc 2
    putstatic test_array_slice/a I
    a
    ldc 2
    ldc 5
    ldc 3
    putstatic test_array_slice/a I
    invokestatic test_array_slice/a()I
    ldc 2
    invokestatic test_array_slice/slice_0(Ljava/lang/String;)I
    invokestatic test_array_slice/a()I
    ldc 2
    invokestatic test_array_slice/writelnI(I)V
    return
.end method
