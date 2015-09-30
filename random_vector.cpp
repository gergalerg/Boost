#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <functional>
#include <random>



int myrand() {  // this is just a func that returns a rand 100 number
    return rand() % 100;
}

int main()
{
    std::random_device rd;
    std::mt19937 mersenne(rd());
    //std::srand((unsigned)time(0));  Not needed here with random device.
    std::vector<int>  l;
    for (int i = 0; i < 100; ++i) {
        l.push_back( mersenne() % 100);
    }
    for (int i = 0; i < 100; ++i) {
        std::cout << l[i] << '\t';
    }
}