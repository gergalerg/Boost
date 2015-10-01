#include <iostream>
#include <vector>
#include <boost/bind.hpp>
#include <boost/ref.hpp>

int f(int a, int b) {
    return a + b;
}

int g(int a, int b, int c) {
    return a + b + c;
}

struct X
{
    bool f(int a);
};

X x;

int main()
{
    X x;
    std::shared_ptr<X> p(new X);
    std::shared_ptr<X> p2(new X);
    std::shared_ptr<X> p3(new X);
    std::shared_ptr<X> p4(new X);

    std::cout << "shared_ptr p: " << p.get() << '\n';
    std::cout << "shared_ptr p2: " << p2.get() << '\n';
    std::cout << "p.use_count() " << p.use_count() << '\n';
}