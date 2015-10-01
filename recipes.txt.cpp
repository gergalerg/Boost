//To compile with c++14 features you have to use libc++.
//The below will compile all c++14 stuff (so far).

$ clang++ -stdlib=libc++ -std=c++1y -pedantic -o test test.cpp 

// **********************************************************
//to populate a vector with random first create a random device

#include <random>
std::random_device rd;
//Then use an algorithm on the device.
std::mt19937 mersenne(rd());
// Then use it
std::vector<int> l;
for (int i = 0; i < 10; ++i) {
    l.push_back(mersenne() % 100);
}
