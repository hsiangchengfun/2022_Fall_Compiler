PROGRAM test_function(input, output, error);
VAR a, b: INTEGER;
VAR c: REAL;

FUNCTION ss(rr :INTEGER) : INTEGER;
BEGIN
  ss := rr
END;

BEGIN
  a := ss(ss(ss(ss(3))));
  writelnI(a)
END.
