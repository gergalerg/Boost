#include <iostream>
#include <typeinfo>
#include <vector>

struct X {
    std::vector<int> v1;
    X() { v1.reserve(1000); }
    X& operator=(X const & rhs) { static X tmp; tmp.v1 = rhs.v1; return tmp; }
    auto showCapacity() -> int { return v1.capacity();  }
};

int main() {
    X  x;
    X foobar();
    x.v1.push_back(333);
    std::cout << typeid(x).name() << std::endl;
    for (auto t: x.v1) std::cout << t << '\n';
    std::cout << "Test" <<  '\n';


}
