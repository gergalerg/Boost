#include <iostream>

struct power {
private:
    double _sum;
public:
    explicit power(double d) : _sum(d) {}
    double get_sum() { return _sum; };
};

int main()
{
    power t(3);
    std::cout << t.get_sum();
}