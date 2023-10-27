#ifndef PHI_MATH_ENGINE_UTILITY_BUFFERED_INPUT_HPP
#define PHI_MATH_ENGINE_UTILITY_BUFFERED_INPUT_HPP

#include <iterator>
#include <optional>

namespace phimath {

template <std::input_iterator input_stream, typename sentinel_type = input_stream> requires std::sentinel_for<sentinel_type, input_stream>
class buffered_input_iterator {
    private:
        std::optional<std::iter_value_t<input_stream>> buffer;
        input_stream base;

    public:
        using difference_type = input_stream::difference_type;
        using value_type = std::iter_value_t<input_stream>;

        buffered_input_iterator(input_stream&& base) : base(std::move(base)), buffer(std::nullopt) {}

        const value_type& operator *(){
            if(buffer){
                return buffer.value();
            }
            return *base;
        }

        buffered_input_iterator& operator ++(){
            buffer = std::nullopt;
            ++base;
        }

        bool operator ==(const sentinel_type& sentinel) const {
            return (base == sentinel) && !buffer;
        }
};

template <std::input_iterator input_stream, typename sentinel_type = input_stream> requires std::sentinel_for<sentinel_type, input_stream>
class buffered_input {
    private:
        buffered_input_iterator<input_stream, sentinel_type> iterator;
        const sentinel_type sentinel;

    public:
        buffered_input(input_stream&& base, const sentinel_type&& sentinel) : iterator(std::move(base)), sentinel(std::move(sentinel)) {}

        buffered_input_iterator& begin(){
            return iterator;
        }

        const sentinel_type& end() const {
            return sentinel;
        }
};

};

#endif
