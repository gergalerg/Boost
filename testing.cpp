#define BOOST_TEST_MODULE example 
#include <boost/test/included/unit_test.hpp>

class MyClass {
private:
    int x;
    const char * name;
public:
    MyClass() {}
    MyClass(int myint) : x(myint) {}
    MyClass(const char * mychar) : name(mychar) {}
    void Show() { std::cout << "name: " << name << " int: " << x << std::endl; }
    bool is_valid() { if (name) return true; }
};

int add( int i, int j) { return i + j; }

BOOST_AUTO_TEST_CASE( free_test_function )
{
    BOOST_CHECK(add(2,2) == 4  );
    MyClass herb("Herb");
    MyClass gerg("gerg");
    BOOST_CHECK(herb.is_valid());
    BOOST_CHECK(gerg.is_valid());
}
