#ifndef PHI_MATH_ENGINE_DATATYPE_TOKEN_HPP
#define PHI_MATH_ENGINE_DATATYPE_TOKEN_HPP

#include <stddef.h>
#include <string>

namespace phimath {

enum class TokenType {
    num,    // numeric
    sep,    // seperator
    bop,    // binary operator
    uop,    // unary operator
    var,    // variable
    fun,    // function
    eoi,    // end of input
};

struct Token {
    size_t line, column;
    std::string value;
    TokenType type;
};

};

#endif