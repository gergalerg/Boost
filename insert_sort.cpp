#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <array>

#define SIZE 8

template <typename U>
std::array<int, SIZE> insert_sort(std::array<U, SIZE> &l) {
    for (int j = 1; j < l.size(); j++) {
        int key =  l[j];
        int i = j - 1;
        while (i > -1 && l[i] > key) {
            l[i+1] = l[i];
            i = i -1;
        }
        l[i+1] = key;
    }
    return l;
}


BOOST_AUTO_TEST_CASE(insertSort) 
{

    std::array<int, SIZE> l = {2,5,4,3,1,8,6,7};
    std::array<int, SIZE> sorted = {1,2,3,4,5,6,7,8};
    std::array<int, SIZE> sorted2 = sorted;

    BOOST_CHECK(l  == sorted );
    BOOST_CHECK(insert_sort(l) == sorted);
    BOOST_CHECK(sorted2 == sorted);
}
