PROGRAM test_array_assignment(input, output, error);
VAR a: ARRAY[1..5] of INTEGER;
VAR b: INTEGER;
VAR c: ARRAY[1..2] of ARRAY[1..5] of INTEGER;

BEGIN

  writelnS("a[1..5]:");
  b := 1;
  WHILE b <= 5 DO
  BEGIN
    a[b] := b + 1;
    writelnI(a[b]);
    b := b + 1;
  END;

  writelnS("c[1][1..5]:");
  b := 1;
  WHILE b <= 5 DO
  BEGIN
    writelnI(c[1][b]);
    b := b + 1;
  END;

  writelnS("c[1] := a[1..5];");
  c[1] := a;

  writelnS("c[1][1..5]:");
  b := 1;
  WHILE b <= 5 DO
  BEGIN
    writelnI(c[1][b]);
    b := b + 1;
  END;

  writelnS("a[1] := 100;");
  a[1] :=  100;

  writelnS("c[1][1..5]:");
  b := 1;
  WHILE b <= 5 DO
  BEGIN
    writelnI(c[1][b]);
    b := b + 1;
  END;

END.
