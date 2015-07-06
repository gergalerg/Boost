#include <iostream>
#include "stacktp.h"

template <template <typename T> class Thing>
class Crab
{
private:
    Thing<int> s1;
    Thing<double> s2;
public:
    Crab() {};
    // assumes the Thing class has push and pop() members
    bool push(int a, double x) { return s1.push(a) && s2.push(x); }
    bool pop(int & a, double & x) { return s1.pop(a) && s2.pop(x); }
};

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    Crab<Stack> nebula;
    Stack<int> myints;
    int five = 5;
    int ten  = 10;
    int eleven = 11;
    myints.push(five);
    myints.push(ten);
    myints.push(eleven);
    std::cout << myints.numitems() << std::endl;
    myints.pop(five);
    std::cout << myints.numitems() << std::endl;


    return 0;
}