PROGRAM ex09(input, output, error);
    VAR a: ARRAY[1..2] of INTEGER;
    VAR b: ARRAY[1..2] of ARRAY[1..2] of INTEGER;
BEGIN
  a[2] := 1;
  b[1][2] := 2;
  writelnI(a[2]);
  writelnI(b[1][2]);
END.
