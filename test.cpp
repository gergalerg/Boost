#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <functional>
#include <random>



int myrand() {
    return rand() % 100;
}

int main()
{
    std::random_device rd;
    std::mt19937 mersenne(rd());
    std::srand((unsigned)time(0));
    std::vector<int>  l;
    for (int i = 0; i < 100; ++i) {
        l.push_back( mersenne() % 100);
    }
    for (int i = 0; i < 100; ++i) {
        std::cout << l[i] << '\t';
    }
}