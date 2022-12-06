# ICD22 Homework3

## How port your homework2 to homework3

The scanner and parser is almost the same, you can refer the templates to modify your code.

In the assignment, you need to define some nodes to construct your Abstract Syntax Tree(AST) by your parser, then generate the symbol table and do some semantic analyses on it.

The format of messages that you need to print have already been defined in `include/info.h`, some warnings about semantic errors should be output to `stderr`, and the symbol table related messages need to be output to `stdout`, as stated in the header file.

Hints:

0. You may construct the AST first
1. Make symbol table by traversing your AST
2. Do semantic analysis, don't forget type check

Notes:

0. You can use the compare.sh to diff you output, use `bash compare.sh [testcase number]` or `bash compare.sh all`(wrong case only) to open `vimdiff` window, and you can type `ESC` and type `:qa!` to exit. If you want to stop the comparison, use `ctrl + z` to stop the process, and `kill %1` to kill it.
1. Assignments of function are only allowed in its compound statement, other function assignments would be treated as type error.

