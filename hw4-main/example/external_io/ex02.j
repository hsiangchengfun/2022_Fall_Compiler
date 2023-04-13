.class public ex02
.super java/lang/Object
.field public static a F
.field public static b I
.field public static c Ljava/lang/String;
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 0.0
    putstatic ex02/a F
    ldc 0
    putstatic ex02/b I
    ldc ""
    putstatic ex02/c Ljava/lang/String;
    getstatic ex02/a F
    invokestatic io/writelnR(F)V
    getstatic ex02/b I
    invokestatic io/writelnI(I)V
    getstatic ex02/c Ljava/lang/String;
    invokestatic io/writelnS(Ljava/lang/String;)V
    return
.end method
