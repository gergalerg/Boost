#include <boost/any.hpp>
#include <vector>
#include <string>
#include <typeinfo>
#include <algorithm>
#include <iostream>

typedef boost::any cell_t;
typedef std::vector<cell_t> db_row_t;

// an example db row
db_row_t get_row(const char* /*query*/) {
    db_row_t row;
    row.push_back(10);
    row.push_back(10.1f);
    row.push_back(std::string("Hello Again"));
    return row;
}

// this  is how a user will use your classes
struct db_sum: public std::unary_function<boost::any void> {
private:
    double& sum_;
public:
    

}
int main() {

}