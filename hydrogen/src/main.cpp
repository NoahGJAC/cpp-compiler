#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>
#include <vector>

#include "parser.hpp"
#include "tokenization.hpp"


//TODO: Parse before turning tokens to assembly
std::string  tokens_to_asm(const std::vector<Token>& tokens){
    std::stringstream output;
    output << "global _start\n_start:\n";
    for (int i = 0; i < tokens.size(); i++){
        const Token& token = tokens.at(i);
        if (token.type == TokenType::exit){
            if (i + 1 < tokens.size() && tokens.at(i + 1).type == TokenType::int_lit){
                if (i +2 < tokens.size() && tokens.at(i + 2).type == TokenType::semi){
                    // rax register, 60 = exit syscall name
                    output << "    mov rax, 60\n";
                    // arg0 rdi error_code
                    output << "    mov rdi," << tokens.at(i + 1).value.value() << "\n";
                    output << "    syscall";
                }
            }
        }
    }
    return output.str();
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Incorrect Usage. Correct usage:" << std::endl;
        std::cerr << "hydro <input.hy>" << std::endl;
        return EXIT_FAILURE;
    }
    std::string contents;
    {
        std::stringstream contents_stream;
        std::fstream input(argv[1], std::ios::in);
        contents_stream << input.rdbuf();
        contents = contents_stream.str();
        input.close(); // close the file
    }
    // move gives the pointer to Tokenizer and contents loses it
    Tokenizer tokenizer(std::move(contents));
    std::vector<Token> tokens = tokenizer.tokenize();

    {
        std::fstream file("out.asm", std::ios::out);
        file << tokens_to_asm(tokens);
    }

    system("nasm -felf64 out.asm");
    system("ld -o out out.o");

    return EXIT_SUCCESS;
}