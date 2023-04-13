PROGRAM test_array_slice(input, output, error);
VAR a: ARRAY[1..2] of ARRAY[3..5] of INTEGER;
FUNCTION slice(s :ARRAY[3..5] of INTEGER) : INTEGER;
BEGIN
  slice := s[3] + s[4] + s[5]
END;
BEGIN
  a[2][3] := 1;
  a[2][4] := 2;
  a[2][5] := 3;

  writelnI(slice(a[2]))
END.
