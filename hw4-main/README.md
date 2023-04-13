# ICD22 Homework4

There are three test case set in this homework.

You can use `make example`, `make test`, `make bonus` to run them.

We provide simple argument parser in `parser.y`, if `output` is not `NULL`, please use it as assembly filename, otherwise you can use the PROGRAM name as filename.

It would be something like:
```
codegen( ProgNode ){
  char fn[128];
  prog = node->name;
  // Output format *.j
  sprintf(fn, "%s.j", node->name);
  fd = fopen(output ? output : fn, "w"); 
  gen("..."); // Generate your assembly...
  fclose(fd);
}
```

- Use float to implement real type.

Bonus:
- nested (pure) function
- string operation
- array assignment

Material:
- [mapping](http://www2.cs.uidaho.edu/~jeffery/courses/445/code-jasmin.html)
- [tutorial](http://saksagan.ceng.metu.edu.tr/courses/ceng444/link/f3jasmintutorial.html)
- [instruction](https://docs.oracle.com/javase/specs/jvms/se7/html/jvms-6.html#jvms-6.5.saload)

Note the example of `x := y + z (strings)` in [mapping](http://www2.cs.uidaho.edu/~jeffery/courses/445/code-jasmin.html):
```
java/lang/StringBuffer/append(java/lang/String;)Ljava/lang/StringBuffer;
```
should be:
```
java/lang/StringBuffer/append(Ljava/lang/String;)Ljava/lang/StringBuffer;
```

Hints:
- you may initialize the variables manually
- We have some built-in function such as `writelnI`, `writelnS`, and you can find the implementation at `example/builtin-io/*.j`.
