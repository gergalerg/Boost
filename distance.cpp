#include <iostream>

using namespace std;

class Distance
{
private:
    int feet;
    int inches;
public:
    Distance() { feet = 0; inches = 0; }
    Distance(int f, int i) : feet(f), inches(i) {}
    //overload function call
    Distance operator() (int a, int b, int c)
    {
        Distance D;
        // just put random calculation
        D.feet = a + c + 10;
        D.inches = b + c + 100;
        return D;
    }

    // method to display distance
    void displayDistance() { cout << "Ft: " << feet << 
                            " In: " << inches << endl; }
};

int main()
{
    Distance D1(11, 10), D2;

    cout << "First distance: ";
    D1.displayDistance();
    Distance myd2;
    myd2 = D1(10, 10, 10);
    cout << "\nSecond distance: ";
    D2.displayDistance();

}