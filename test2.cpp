#include <iostream>
#include <boost/function.hpp>

void myfunc() {  };

typedef  int hello;
typedef boost::function< void () > vFv;
typedef boost::function< void (int x) > vFi;
typedef boost::function< void (int x, int y) > vF2;
typedef boost::function< void (int x, int y, int t) > vF3;
int main()
{
    int mt = vFv::arity;
    int m2 = vFi::arity;
    int m3 = vF2::arity;
    int m4 = vF3::arity;
    hello m6 = 6;
    std::cout << mt << std::endl;
    std::cout << m2 << std::endl;
    std::cout << m3 << std::endl;
    std::cout << m4 << std::endl;

    return 0;
}