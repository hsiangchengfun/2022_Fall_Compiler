.class public ex10
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 1
    ldc 1
    if_icmpeq L3
    ldc 0
    goto L4
L3:
    ldc 1
L4:
    ifne L1
    ldc 2
    invokestatic io/writelnI(I)V
    goto L2
L1:
    ldc 1
    invokestatic io/writelnI(I)V
L2:
    return
.end method
