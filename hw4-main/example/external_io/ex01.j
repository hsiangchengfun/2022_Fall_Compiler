.class public ex01
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 1
    invokestatic io/writelnI(I)V
    ldc 2.000000
    invokestatic io/writelnR(F)V
    ldc "3"
    invokestatic io/writelnS(Ljava/lang/String;)V
    ldc "input:"
    invokestatic io/writelnS(Ljava/lang/String;)V
    invokestatic io/readlnI()I
    invokestatic io/writelnI(I)V
    return
.end method
