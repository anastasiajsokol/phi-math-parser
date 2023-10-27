#ifndef PHI_MATH_ENGINE_PARSER_LEXER_HPP
#define PHI_MATH_ENGINE_PARSER_LEXER_HPP

#include "../utility/buffered_input_wrapper.hpp"
#include "../datatype/token.hpp"
#include <iterator>
#include <cctype>

namespace phimath {

template <std::input_iterator input_type, typename sentinel_type = input_type> requires std::same_as<std::iter_value_t<input_type>, char> && std::sentinel_for<sentinel_type, input_type>
class Lexer {
    private:
        buffered_input_wrapper<input_type, sentinel_type> stream;
        const sentinel_type& end;

    public:
        Lexer(input_type&& stream, const sentinel_type&& end) : stream(std::move(stream)), end(end) {}
};

};

#endif
