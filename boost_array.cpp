#include <boost/array.hpp>
#include <iostream>
#include <cassert>
#include <algorithm>

struct add_1 : public std::unary_function<char, void> {
    void operator() (char& c) const {
        ++c;
    }
};

typedef boost::array<char, 4> array4_t;
array4_t& vector_advance(array4_t& val) {
    std::for_each(val.begin(), val.end(), add_1());
    return val;
}

int main()
{
    array4_t val  = {66,67,68,69};
    for (auto x: val) std::cout << x << '\t';
    array4_t val_res = vector_advance(val);
    assert(val.size() == 4);
    assert(val[0] == 67);
    std::cout << sizeof(char) * array4_t::static_size;
}
