#pragma list off
PROGRAM foo(input, output, error) ;
   var a, b, x, y: integer;

   begin  
	a := 7;
	b := 12;
	if (a > b-3) then y := 5 else;
	x := y + 6;  // y is probably not initialized.
   end.   // this is the end of the program
