#include <iostream>
#include <cassert>

template <typename T>
class Zero_Init
{
    T val;
public:
    Zero_Init() : val(static_cast<T>(0)) {}
    Zero_Init(T val) : val(val) {}
    operator T&() { return val; }
    operator T() const { return val; }
};

int main()
{
    Zero_Init<int> i; 
    assert (i == 0);
    i = 7; 
}