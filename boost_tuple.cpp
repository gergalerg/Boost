#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <string>
#include <iostream>
#include <set>

boost::tuple<int, std::string> almost_a_pair(10, "Hello");
boost::tuple<int, float, double, int> quad(10, 1.0f, 10.0, 1);

int main()
{
    std::set< boost::tuple<int, double, int> > s;
    s.insert(boost::make_tuple(1,1.0, 2));
    s.insert(boost::make_tuple(2,10.0, 2));
    s.insert(boost::make_tuple(3,100.0, 3));

    auto  t1 = s.begin();
    std::cout << t1 << std::endl;
}