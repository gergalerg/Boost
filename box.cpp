#include <iostream>
using namespace std;

class Box
{
public:
    double getVolume(){ return ln * br * ht; }
    void setLength( double len) { ln = len; }
    void setBreadth(double bre) { br = bre; }
    void setHeight(double hei)  { ht = hei; }

    // Overloaded operators to add 2 box objects
    Box operator+(const Box& b)
    {
        Box box;
        box.ln = this->ln + b.ln;
        box.br = this->br + b.br;
        box.ht = this->ht + b.ht;
        return box;
    }
private:
    double ln;
    double br;
    double ht;
};

int main() 
{
    Box one;
    Box two;
    Box three;
    double volume = 0.0;   // store the volume of the box here

    one.setLength(6.0);
    one.setBreadth(7.0);
    one.setHeight(5.0);

    two.setLength(10.0);
    two.setBreadth(5.0);
    two.setHeight(11.0);

    cout << "Vol of one: " << one.getVolume() << endl;
    three = one + two;
    cout << "Vol of three: " << three.getVolume() << endl;


    return 0;
}