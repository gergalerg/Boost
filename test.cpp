// this compiles with 
// clang++ -stdlib=libc++ -std=c++1y -o test test.cpp
#include <iostream>
#include <boost/bind.hpp>
#include <typeinfo>

struct Base
{
    Base() { }
    ~Base() { }
    virtual void Show() { std::cout << '\n' <<  typeid(*this).name(); }
};

struct Derived : Base
{
    Derived() {}
    ~Derived() {}
};


int main()
{
    std::shared_ptr<Base> p = std::make_shared<Base>();
    std::shared_ptr<Base> p1 = p;
    std::cout << p1.use_count();
    p->Show();
    Derived d1;
    d1.Show();

}