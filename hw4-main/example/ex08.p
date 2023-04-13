PROGRAM ex08(input, output, error);
    FUNCTION f(a:integer) :integer;
    begin
        f := a;
    end;
    FUNCTION g :integer;
    begin
        g := 1;
    end;
BEGIN
    writelnI(f(g));
END.
