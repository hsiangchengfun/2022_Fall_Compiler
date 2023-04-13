.class public ex04
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 1
    ifne L1
    ldc 1
    goto L2
L1:
    ldc 0
L2:
    invokestatic io/writelnI(I)V
    ldc 1.000000
    fneg
    invokestatic io/writelnR(F)V
    return
.end method
