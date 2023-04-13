.class public ex11
.super java/lang/Object
.field public static a I
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 0
    putstatic ex11/a I
L1:
    getstatic ex11/a I
    ldc 5
    if_icmpne L3
    ldc 0
    goto L4
L3:
    ldc 1
L4:
    ifeq L2
    getstatic ex11/a I
    invokestatic io/writelnI(I)V
    getstatic ex11/a I
    ldc 1
    iadd
    putstatic ex11/a I
    goto L1
L2:
    return
.end method
