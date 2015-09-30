// to compile:
//  clang++ -stdlib=libc++ -std=c++1y -pedantic -o test test.cpp 
//  Have to use libc++ libraries with std14. I don't know what pedantic 
// does in this case.

#include <iostream>

int main() 
{
    auto glambda = [](auto x, auto&& y) { return x < y; };
    std::cout << std::boolalpha;
    std::cout << glambda(3.0, 3.14);
}