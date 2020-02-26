Pre-processed C90 to MIPS Compiler
============================================

Team Members
---------------------------
Olly Lemon Larkin (oll16)

Lau Jun Kit Darrick (dl5215)

Developer Notes
-------------
Our management logs can be found in the management directory. It contains (in .csv format) an effort log, a milestone log and a list of the test cases we developed to test the functionality of our project. This readMe was also used as a checklist to track our implementation of the features we wanted to support, and serves as documentation on our development. As such, it should be considered as part of the "management" component of our project.  

Tests were added beyond what was specified for assessment, and the assessed tests are named in capital letters.  

All constructs are functionally lexed and parsed, but only the ones listed in the feature list are fully integrated with the other features. All functioning constructs will also not work when used in conjunction with a unsupported construct. For example, the sizeof function works if passed arguments of int, int* and typedef'ed constructs, but will fail for double,unsigned,char,etc. Below is list specifying notable features and where they fail.

* sizeof, typedef, referencing(&), dereferencing(*) and arithmetic/logical operators only permit operations on int or int pointer operands, as other data types are not supported.

* While char is not explicitly supported, the lexing and parsing of character literals have been implemented. They are implicitly cast to int in the assignment process, as the 8-bit char value will be placed in a 32-bit register without sign extension.


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

