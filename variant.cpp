#include <boost/variant.hpp>
#include <iostream>
#include <vector>
#include <string>

int main()
{
    typedef boost::variant<int, const char*, std::string> my_var_t;
    std::vector<my_var_t> some_values;
    some_values.push_back(std::string("Wow"));
    some_values.push_back(10);
    some_values.push_back("Hello There");
    const char* t = boost::get<const char *>(some_values.back());
    //s += " That is great\n";
    std::cout << t;

    typedef boost::variant<boost::blank, int, const char*, std::string> my_var_s;
    // default const will construct oan 
    // instance of boost::blank
    my_var_s var;
    // 'which()' method returns and index of a type
    // currently held by the variant
    assert(var.which() == 0); // Empty state
    var = "Hello Dear reader";
    assert(var.which() != 0);


    boost::variant<int, std::string> variable(3);
    std::string greeting = "Hello";
    variable(greeting);
    int s1 = boost::get<int>(variable);
    std::cout << "\ns1 = " << s1 << "\n";
    return 0;
}