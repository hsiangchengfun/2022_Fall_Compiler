PROGRAM test_nestedStmt(input, output, error) ;
   var a, b, d: integer;
   begin
    a := 1;
    b := 7;
    d := 9;
    if a < b + 3 then
    begin
        if a+5 > b-2 then
        begin
                while a < b do
            begin
                while b < 11 do
                begin
                    b := b + 2
                    end;
                a := a + 10
                end;
        end else d := d + 100;
    end else d:= d + 1000;
    writelnI(a);  // a is 11.
    writelnI(b);  // b is 11.
    writelnI(d);  // d is 9.
   end.   // this is the end of the program
