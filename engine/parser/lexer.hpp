#ifndef PHI_MATH_ENGINE_PARSER_LEXER_HPP
#define PHI_MATH_ENGINE_PARSER_LEXER_HPP

#include <iterator>

namespace phimath {

template <std::input_iterator stream> requires std::same_as<std::iter_value_t<stream>, char>
class Lexer {
    private:
    public:
};

};

#endif
