#include <boost/variant.hpp>
#include <vector>
#include <string>
#include <iostream>

// This typedefs and methods will be in our header
typedef boost::variant<int, float, double, std::string> cell_t;
typedef std::vector<cell_t>  db_row_t;

// This is just an example
db_row_t get_row() {
    db_row_t row;
    double d = 13.1;
    row.push_back(10);
    row.push_back(10.1f);
    row.push_back(std::string("Hello again"));
    row.push_back(d);
    return row;
}

// This is how a user will use your classes
struct db_sum_visitor: public boost::static_visitor<double> {
    double operator() (int value) const {
        return value;
    }
    double operator() (float value) const {
        return value;
    }
    double operator() (double v) const {
        return v;
    }
    double operator() (const std::string& /*value*/) const {
        return 0.0;
    }
};

int main()
{
   db_row_t row = get_row();
   double res = 0.0;
   db_row_t::const_iterator it = row.begin(), end = row.end();
   for (; it != end; ++it) {
    res += boost::apply_visitor(db_sum_visitor(), *it);
   }
   std::cout << "sum of arithmetic types in db row is: " << res << std::endl;
   return 0;
}