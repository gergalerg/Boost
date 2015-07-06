#include <iostream>
#include <vector>

class Items
{
    double x;
    double y;
    int m;
public:
    Items(){};
    Items (double xx, double yy, int mm) : x(xx), y(yy), m(mm) {}
    void ShowItems() { std::cout << "x = " << x << " y = " << y << " int m = " << m << std::endl; }
    //~Items(){}
};

int main()
{
    std::vector<Items> vt(10);

    vt.push_back(Items(8.2,2.8, 3));
    for (int i = 0; i < 10; i++)
        vt[i].ShowItems();

    return 0;
}