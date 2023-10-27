#ifndef PHI_MATH_ENGINE_UTILITY_BUFFERED_INPUT_WRAPPER_HPP
#define PHI_MATH_ENGINE_UTILITY_BUFFERED_INPUT_WRAPPER_HPP

#include <iterator>
#include <optional>
 
namespace phimath {

template <std::input_iterator input_type, typename sentinel_type = input_type> requires std::sentinel_for<sentinel_type, input_type>
class buffered_input_wrapper {
    public:
        using value_type = std::iter_value_t<input_type>;

        buffered_input_wrapper(input_type&& stream) : stream(std::move(stream)), buffer(std::nullopt) {}
        
        const value_type& peek(){
            buffer = *stream;
            return *(++stream);
        }
        
        const value_type& operator *(){
            if(buffer){
                return buffer.value();
            }
            return *stream;
        }

        buffered_input_wrapper& operator ++(){
            if(buffer){
                buffer = std::nullopt;
            } else {
                ++stream;
            }
            return *this;
        }

        bool operator ==(const sentinel_type& sentinel) const {
            return stream == sentinel;
        }

        bool operator !=(const sentinel_type& sentinel) const {
            return stream != sentinel;
        }

    private:
        std::optional<value_type> buffer;
        input_type stream;
};

};

#endif
