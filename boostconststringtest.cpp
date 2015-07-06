#define BOOST_TEST_MODULE const_string test 
#include <boost/test/included/unit_test.hpp>
#include <string>

class const_string 
{
private:
    std::string name;
public:
    const_string() {}
    const_string( std::string const& s) : name(s) {}
    const_string( char const* s) : name(s) { std::cout << "called char const* s" << std::endl;}
    const_string( char const* s, size_t length ) :
            name(s) {}
    //const_string(char const* begin, char const* end) : name {}
    // access methods
    char const* data() const {}
    size_t length() const { return name.size(); }
    bool is_empty() const { if ()}
};

BOOST_AUTO_TEST_CASE(constructors_test )
{
    const_string cs0("");
    BOOST_CHECK_EQUAL( cs0.length(), (size_t)0 );
}