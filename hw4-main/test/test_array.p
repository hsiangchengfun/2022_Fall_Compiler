PROGRAM test_array(input, output, error);
VAR a: ARRAY[1..2] of INTEGER;
VAR b: INTEGER;
VAR c: ARRAY[1..2] of ARRAY[1..2] of INTEGER;

BEGIN
  a[1] := 1;
  a[2] := 2;
  c[1][1] := a[1];
  c[1][2] := a[2];
  c[2][1] := a[2] + a[1];
  c[2][2] := a[2] + a[2];
  writelnI(c[1][1] + c[1][2] + c[2][1] + c[2][2])
END.
