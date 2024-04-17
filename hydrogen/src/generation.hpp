#pragma once

#include "parser.hpp"

class Generator {
public:
    inline explicit Generator(NodeExit root)
        : m_root(std::move(root))
    {

    }

    [[nodiscard]] std::string generate() const
    {
        std::stringstream output;
        output << "global _start\n_start:\n";

        // rax register, 60 = exit syscall name
        output << "    mov rax, 60\n";
        // arg0 rdi error_code
        output << "    mov rdi," << m_root.expr.int_lit.value.value() << "\n";
        output << "    syscall";
        return output.str();
    }
private:
    const NodeExit m_root;
};