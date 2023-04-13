.class public fibonacci_recursive
.super java/lang/Object
.field public static a I
.field public static a F
.field public static a Ljava/lang/String;
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
.method public static fa_0(I)I
.method public static fa_0(I)F
.method public static fa_0(I)Ljava/lang/String;
.limit locals 50
.limit stack 50
    getstatic fibonacci_recursive/a I
    ldc 1
    if_icmpeq L1
    ldc 0
    goto L2
L1:
    ldc 1
L2:
    if_icmpge L1
    ldc 0
    goto L2
L1:
    ldc 1
L2:
    if_icmple L1
    ldc 0
    goto L2
L1:
    ldc 1
L2:
    if_icmpne L1
    ldc 0
    goto L2
L1:
    ldc 1
L2:
    ifeq L3
    ldc 1
    goto L4
L3:
    getstatic fibonacci_recursive/a I
    ldc 0
    if_icmpeq L4
    ldc 0
    goto L5
L4:
    ldc 1
L5:
    if_icmpge L4
    ldc 0
    goto L5
L4:
    ldc 1
L5:
    if_icmple L4
    ldc 0
    goto L5
L4:
    ldc 1
L5:
    if_icmpne L4
    ldc 0
    goto L5
L4:
    ldc 1
L5:
    ifeq L6
    ldc 0
    goto L7
L6:
    getstatic fibonacci_recursive/a I
    ldc 1
    isub
    invokestatic fibonacci_recursive/fa_0(I)I
    getstatic fibonacci_recursive/a I
    ldc 1
    isub
    getstatic fibonacci_recursive/a I
    ldc 2
    isub
    getstatic fibonacci_recursive/a I
    ldc 2
    isub
    iadd
L7:
L8:
.end method
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 0
    putstatic fibonacci_recursive/a I
    ldc 0.0
    putstatic fibonacci_recursive/a F
    ldc ""
    putstatic fibonacci_recursive/a Ljava/lang/String;
    invokestatic fibonacci_recursive/readlnI()I
    putstatic fibonacci_recursive/a I
    getstatic fibonacci_recursive/a I
    getstatic fibonacci_recursive/a I
    invokestatic fibonacci_recursive/writelnI(I)V
    return
.end method
