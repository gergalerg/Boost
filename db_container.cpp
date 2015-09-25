#include <boost/any.hpp>
#include <boost/variant.hpp>
#include <vector>
#include <string>
#include <typeinfo>
#include <algorithm>
#include <iostream>

// This typedefs and methods will be in our header
typedef boost::any cell_t;
typedef std::vector<cell_t>  db_row_t;

// This is just an example
db_row_t get_row() {
    db_row_t row;
    double t = 12.4;
    row.push_back(10);
    row.push_back(10.1f);
    row.push_back(t);
    row.push_back(std::string("Hello again"));
    return row;
}

// This is how a user will use your classes
struct db_sum: public std::unary_function<boost::any, void> {
private:
    double& sum_;
public:
    explicit db_sum(double& sum) : sum_(sum) {}
    double get_sum() { return sum_;};
    void operator() (const cell_t& value) {
        const std::type_info& ti = value.type();
        if (ti == typeid(int)) {
            sum_ += boost::any_cast<int>(value);
        } else if (ti == typeid(float)) {
            sum_ += boost::any_cast<float>(value);
        } else if (ti == typeid(double)) {
            sum_ += boost::any_cast<double>(value);
        }
    }
};

int main()
{
   db_row_t row = get_row();
   double res = 0.0;
   std::for_each(row.begin(), row.end(), db_sum(res));
   std::cout << "Sum of arithmetic types in db row is " << res << std::endl; 
   std::cout << db_sum(res).get_sum();
   return 0;
}