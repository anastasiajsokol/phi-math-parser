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
        class token_iterator {
            private:
                buffered_input_wrapper<input_type, sentinel_type> stream;
                const sentinel_type& end;
                Token buffer;

                void load_next_token(){
                    
                }

            public:
                token_iterator(input_type&& stream, const sentinel_type& end) : stream(std::move(stream)), end(end) {}

                token_iterator& operator ++(){
                    load_next_token();
                    return *this;
                }

                const Token& operator *() const {
                    return buffer;
                }
                
                bool operator ==(const Token& token) const {
                    return buffer.type == token.type;
                }
        } iterator;

    public:
        Lexer(input_type&& stream, const sentinel_type& end) : iterator(std::move(stream), end(end)) {}

        token_iterator& begin(){
            return iterator;
        }

        Token end(){
            return Token{-1, -1, "EOI", TokenType::eoi};
        }
};

};

#endif
