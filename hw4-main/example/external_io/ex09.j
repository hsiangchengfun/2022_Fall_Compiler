.class public ex09
.super java/lang/Object
.field public static a [I
.field public static b [[I
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 2
    multianewarray [I 1
    putstatic ex09/a [I
    ldc 2
    ldc 2
    multianewarray [[I 2
    putstatic ex09/b [[I
    getstatic ex09/a [I
    ldc 2
    ldc 1
    isub
    ldc 1
    iastore
    getstatic ex09/b [[I
    ldc 1
    ldc 1
    isub
    aaload
    ldc 2
    ldc 1
    isub
    ldc 2
    iastore
    getstatic ex09/a [I
    ldc 2
    ldc 1
    isub
    iaload
    invokestatic io/writelnI(I)V
    getstatic ex09/b [[I
    ldc 1
    ldc 1
    isub
    aaload
    ldc 2
    ldc 1
    isub
    iaload
    invokestatic io/writelnI(I)V
    return
.end method
