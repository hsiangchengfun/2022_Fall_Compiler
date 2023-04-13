PROGRAM test_nested_function(input, output, error);
VAR a, b: INTEGER;

FUNCTION ss(rr :INTEGER) : INTEGER;
var d: INTEGER;
  FUNCTION tt(rr : INTEGER) : INTEGER;
  var e: INTEGER;
  BEGIN
     e := rr * 3;
     tt := rr + d - e + b;
  END;
BEGIN
  d := rr - 4;
  ss := tt(rr)
END;

BEGIN
  b := -5;
  a := ss(3);
  writelnI(a)
END.
