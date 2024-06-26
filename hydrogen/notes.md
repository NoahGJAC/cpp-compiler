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
Creating enum for different things we want to parse for (i.e. return keyword, integer literals, semicolons).  
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
Core of formal grammar. Production rules define how symbols should be replaced by sequences, like syntactic categories or constructs.
Used by parsers to construct parse trees and check the input.

## Parser  
A component of the compiler that checks the syntactical structure of the input. The parser constructs a parse tree from the grammar.

## Code Generation  
The phase where the compiler translate the source code into the target code (assembly).

# Part 3

## Grammar Updates
update to use parentheses, let keyword and equals. Updating parser nodes and tokens.

## Visitor  
A pattern that separates an algorithm from an object structure.
Used to traverse the abstract syntax tree generated by the parser. Each node can be visited by the visitor object and can perform operations on specific type of nodes.

## Stacks  
Used by compilers for managing functions calls, storing variables and evaluating expressions.

## Unordered/Hash Map
Used by compiler to map variable names to their stack locations. This allows the generator to quickly look up stack locations.

# Part 4

## Arena Allocator
A memory allocation system for predictable memory allocation and deallocation. Creates a large memory block and uses offsets to manage allocations. Leads to performance benefits in scenarios where there are many small allocations ande deallocations. Frequently used for compilers.

## Grammar Updates  
Added terms which can be integer literals or identifiers. Expressions can be made up of terms or binary expressions. Binary expressions in turn are expressions with binary operations ([Expr] + [Expr]).

# Part 5

## Precedence Climbing  
Parsing technique used in compilers to handle binary operator precedence. Useful for when operators have different precedences and associativity. Handles complex expressions in a single pass. Read more here: [Reference used in tutorial](https://eli.thegreenplace.net/2012/08/02/parsing-expressions-by-precedence-climbing).

# Part 6

## Scopes

## Assembly Jump