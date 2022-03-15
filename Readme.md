Pre-processed C90 to MIPS Compiler
============================================

Program build and execution
---------------------------
The compiler is built using the command:

    make bin/c_compiler

The compilation function is invoked using the flag `-S`, with the source file and output file specified on the command line:

    bin/c_compiler -S [source-file.c] -o [dest-file.s]
    
Our test suite can be run by first building the project and then running the test script:

    make
    ./test_deliverable/run_tests.sh

Some additional features are included for debugging purposes such as a print function which shows the structure of the parse tree visually. This can be built using the following command, which then takes input from the standard input stream.

	make bin/print_tree
	bin/print_tree


Feature List
-----
The list below is a non-exhaustive list of the features supported by our compiler, aligned with those outlined in the spec.

* a file containing just a single function with no arguments
* variables of `int` type and their pointers
* local variables
* arithmetic and logical expressions
* if-then-else statements
* while loops
* files containing multiple functions that call each other
* functions that take up to four parameters
* for loops
* arrays declared globally (i.e. outside of any function in your file)
* arrays declared locally (i.e. inside a function)
* reading and writing elements of an array
* recursive function calls
* the `enum` keyword
* `switch` statements
* the `break` and `continue` keywords
* calling externally-defined functions (i.e. the file being compiled declares a function, but its definition is provided in a different file that is linked in later on)
* functions that take more than four parameters
* mutually recursive function calls
* locally scoped variable declarations (e.g. a variable that is declared inside the body of a while loop, such as `while(...) { int x = ...; ... }`.
* the `typedef` keyword
* the `sizeof(...)` function (which takes either a type or a variable)
* taking the address of a variable using the `&` operator
* dereferencing a pointer-variable using the `*` operator
* pointer arithmetic
* character literals, including escape sequences like \n

Conversely, the features explicitly not supported are:
* variables of double, float, char, unsigned, structs
* strings (as NULL-terminated character arrays)
* declaration and use of structs

