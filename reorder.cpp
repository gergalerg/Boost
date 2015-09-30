#include <vector>
#include <iostream>

class Number{};
inline Number operator + (Number, Number){ Number n;return n;};

struct mul_2_func_obj: public std::unary_function<Number, void> {
    Number operator() (Number n1) const {
        return n1 + n1;
    }
};

void mul_2_impl1(std::vector<Number>& values) {
    std::for_each(values.begin(), values.end(), mul_2_func_obj());
}
int main()
{


}