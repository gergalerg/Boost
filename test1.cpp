#include <iostream>
#include <boost/scoped_array.hpp>
#include <string>

class const_string 
{
private:
    std::string name;
public:
    const_string() {}
    const_string( std::string const& s) : name(s) {}
    const_string( char const* s) : name(s) {}
    const_string( char const* s, size_t length ) :
            name(s) {}
    //const_string(char const* begin, char const* end) : name {}
    // access methods
    char const* data() const { return name.c_str(); }
    size_t length() const { return name.size(); }
    bool is_empty() const { if (name.size() == 0) return 1; }
};
int main()
{
    std::string greg = "Greg";
    const_string melissa("Melissa");
    std::cout << melissa.is_empty()  << std::endl;
    boost::scoped_array<char> bart(new char[greg.size() + 1]);
    std::copy(greg.begin(), greg.end(), bart.get());
    bart[greg.size()] = '\0';
    std::cout << bart.get() << std::endl;
    //std::cout << melissa.data() << std:: endl;
    return 0;
}