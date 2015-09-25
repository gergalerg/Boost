#include <iostream>
#include <random>
#include <time.h>
#include <functional>
#include <algorithm>
#include <boost/any.hpp>

struct power : public std::unary_function<boost::any, void> {
//private:
 //   double& _sum;
public:
  //  power(double& d) : _sum(d) {}
    double operator()(double x) {  return x * x; }
};

std::function<int(int)> power2 = [](int x){ return x * x; };

std::function<bool(int)> less_than_7 = [](int x) { return x < 7; };
int main()
{
    int x = 10;
    std::srand(time(NULL));
    std::cout << power()(3) << std::endl;
    std::cout << power2(3) << std::endl;
    std::cout << std::boolalpha << x << " is less than 7: " << less_than_7(x) << std::endl;
    std::vector<int> V(100);
    std::generate(V.begin(), V.end(), rand );
    for (auto x: V) std::cout << x << std::endl;


}