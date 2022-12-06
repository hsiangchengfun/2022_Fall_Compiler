#pragma list off
PROGRAM foo(input, output, error) ;
   var r: array[5..15] of array[7.. 20] of integer;  // 2-dimesional array

   begin  
	r[7][8] := 5;
	r[9][10] := 100;

	r[7][23] := 5;  // compile-time range check
	r[19][9] := 5;  // compile-time range check
	x := 15;
	y := 7;
	r[9][x+y] := 5;  // run-time range check

	r[y][x-y] := r[y][x-y] + 7 + r[y][x-y];
	writeln(r[y][x-y]);   // answer is 17.
	r[y][x-y] := r[y+2][r[y][x-y]+5]+5;
	writeln(r[y][x-y]);   // answer is 105.

   end.   // this is the end of the program
