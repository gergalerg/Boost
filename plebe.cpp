#include <iostream>
#include <cmath>

class Plebe
{
private:
    int id;
public:
    Plebe() {}
    Plebe(int s) : id(s) {}
    explicit Plebe(double d) : id(d) {}
    ~Plebe(){}
    void showId() const { std::cout << id << std::endl;}
};

int main()
{
    Plebe a, b;
    double mydub = 1.5;
    a = 5;
    b = mydub;
    a.showId();
    b.showId();

    int x = 10;
    int y  = 23;
    int && r1 = 13;
    int & r2 = x + y;
    // double & r3 = std::sqrt(2.0);
    x= 57;
    std::cout << r2 << std::endl;


}