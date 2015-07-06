// page 2736
#include <iostream>

class Example
{
public:
    Example(){feet = 0; inches = 0;}
    Example(int ft){}
    ~Example(){}
    int feet;
    int inches;
    void show_in() const{ std::cout << "Inches: " << inches << std::endl;}
    void show_ft() const { std::cout << "Feet" << feet << std::endl; }
    void use_ptr() const {}
};

int main()
{
    int Example::*pt = &Example::inches;
    Example ob1; // now inches exists
    Example ob2;
    ob1.inches = 12;
    Example *pq  = new Example;
    pq->inches = 11;
    std::cout << ob1.*pt << std::endl;
    std::cout << pq->*pt << std::endl;
    pt = &Example::feet;
    std::cout << ob1.*pt << std::endl;
    std::cout << pq->*pt << std::endl;


    return 0;
}