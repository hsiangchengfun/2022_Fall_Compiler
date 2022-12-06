#pragma list off
PROGRAM foo(input, output, error) ;
   var s: array[5..15] of integer;  // 1-dimesional array

   begin  
	s[4] := 100;
	s[8] := 5;
	s[13] := 4;
	s[23] := 5;  // compile-time range check
	s[19] := 5;  // compile-time range check
	x := 15;
	y := 7;
	s[x+y] := 5;  // run-time range check
	s[x-y] := s[x-y] + 7 + s[x-y];
	s[x-y] := s[s[x-y]+5]+5;  
	writeln(s[x-y]); //  answer is 105
   end.   // this is the end of the program
