.class public test_nestedStmt
.super java/lang/Object
.field public static a I
.field public static a F
.field public static a Ljava/lang/String;
.field public static b I
.field public static b F
.field public static b Ljava/lang/String;
.field public static d I
.field public static d F
.field public static d Ljava/lang/String;
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
    putstatic test_nestedStmt/a I
    ldc 0.0
    putstatic test_nestedStmt/a F
    ldc ""
    putstatic test_nestedStmt/a Ljava/lang/String;
    ldc 0
    putstatic test_nestedStmt/b I
    ldc 0.0
    putstatic test_nestedStmt/b F
    ldc ""
    putstatic test_nestedStmt/b Ljava/lang/String;
    ldc 0
    putstatic test_nestedStmt/d I
    ldc 0.0
    putstatic test_nestedStmt/d F
    ldc ""
    putstatic test_nestedStmt/d Ljava/lang/String;
    ldc 1
    putstatic test_nestedStmt/a I
    ldc 7
    putstatic test_nestedStmt/b I
    ldc 9
    putstatic test_nestedStmt/d I
    getstatic test_nestedStmt/a I
    getstatic test_nestedStmt/b I
    ldc 3
    iadd
    if_icmplt L1
    ldc 0
    goto L2
L1:
    ldc 1
L2:
    if_icmpgt L1
    ldc 0
    goto L2
L1:
    ldc 1
L2:
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
    ifne L3
    getstatic test_nestedStmt/a I
    ldc 5
    iadd
    getstatic test_nestedStmt/b I
    ldc 2
    isub
    if_icmpgt L4
    ldc 0
    goto L5
L4:
    ldc 1
L5:
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
    ifne L6
L7:
    getstatic test_nestedStmt/a I
    getstatic test_nestedStmt/b I
    if_icmplt L8
    ldc 0
    goto L9
L8:
    ldc 1
L9:
    if_icmpgt L8
    ldc 0
    goto L9
L8:
    ldc 1
L9:
    if_icmpeq L8
    ldc 0
    goto L9
L8:
    ldc 1
L9:
    if_icmpge L8
    ldc 0
    goto L9
L8:
    ldc 1
L9:
    if_icmple L8
    ldc 0
    goto L9
L8:
    ldc 1
L9:
    if_icmpne L8
    ldc 0
    goto L9
L8:
    ldc 1
L9:
    ifeq L10
L10:
    getstatic test_nestedStmt/b I
    ldc 11
    if_icmplt L11
    ldc 0
    goto L12
L11:
    ldc 1
L12:
    if_icmpgt L11
    ldc 0
    goto L12
L11:
    ldc 1
L12:
    if_icmpeq L11
    ldc 0
    goto L12
L11:
    ldc 1
L12:
    if_icmpge L11
    ldc 0
    goto L12
L11:
    ldc 1
L12:
    if_icmple L11
    ldc 0
    goto L12
L11:
    ldc 1
L12:
    if_icmpne L11
    ldc 0
    goto L12
L11:
    ldc 1
L12:
    ifeq L13
    getstatic test_nestedStmt/b I
    ldc 2
    iadd
    putstatic test_nestedStmt/b I
    goto L10
L13:
    getstatic test_nestedStmt/a I
    ldc 10
    iadd
    putstatic test_nestedStmt/a I
    goto L11
L14:
    goto L15
L14:
    getstatic test_nestedStmt/d I
    ldc 100
    iadd
    putstatic test_nestedStmt/d I
L15:
    goto L16
L15:
    getstatic test_nestedStmt/d I
    ldc 1000
    iadd
    putstatic test_nestedStmt/d I
L16:
    getstatic test_nestedStmt/a I
    invokestatic test_nestedStmt/writelnI(I)V
    getstatic test_nestedStmt/b I
    invokestatic test_nestedStmt/writelnI(I)V
    getstatic test_nestedStmt/d I
    invokestatic test_nestedStmt/writelnI(I)V
    return
.end method
