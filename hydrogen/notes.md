# Part 1
## CMake  
Set up CMakeLists.txt to generate build files.  
## Install C++  
Since I don't have C++ installed in my environment I have to install it.  
    run $ sudo apt-get update && sudo apt-get install build-essential  
## Building my first project  
After creating a simple hello world program in ./src/main.cpp we can run  
    \$ cmake -S . -B build/  
This configures the project using our CMakeLists file and generates the build files in the build/ directory. Next we can run:  
    \$ cmake --build build/  
and  
    \$ ./build/hydro  
to see our output  
    Hello World!  
## CLion  
Install CLion, connect it to WSL and open project.  
## Lexical analysis
Creating parsable pieces from characters.  
### Tokens  
Creating enum for different things we want to parse for (ie. return keyword, integer literals, semicolons).  
Creating struct with the TokenType (enum) and the optional value of the token.  

### Parsing  
We can now parse a file and store tokens with a buffer.  

### Tokens to Assembly  
We can create assembly code out of the tokens are write them to an .asm file.
We can tell C++ to use an assembler on our new .asm file and use ld to create the object file.  

This gives us the executable that returns the exit code!  

# Part 2

## Refactoring  
Moving all token related code to tokenization header file.  
The new Tokenizer class makes use of peek and consume methods that improve tokenizing and readability.  

## Parse Trees  
Hierarchical representation of the language's syntax structure according to its grammar.
Each node represents productions of the grammar.  

## Formal Grammar  
Rules that define the syntax of programming languages.  

### Production Rules
Core of formal grammar. Production rules define how symbols should be replaced by sequences, like syntatic categories or constructs).
Used by parsers to construct parse trees and check the input.
## Parser  
A component of the compiler that checks the syntactical structure of the input. The parser constructs a parse tree from the grammar.

## Code Generation  
The phase where the compiler translate the source code into the target code (assembly).