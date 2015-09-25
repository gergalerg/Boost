#include <iostream>
#include <algorithm>
#include <vector>

struct printNumberClass {
    template <typename T>
    void operator() (T y) { std::cout << "y: " << y << '\n'; }
} printNumberFunction;
/*
template <char CH, size_t SIZE>
struct empty_string_policy
{
    static std::string empty_value() 
    {
        return std::string{SIZE, CH};
    }
    static bool is_empty_value(const std::string& v) 
    {
        return v.size() == SIZE &&
                std::all_of(v.begin(), v.end(),
                        [](char c) {return c == CH; });
    }
};

using Null3Policy = empty_string_policy<"\0", 3>;
*/

template <int>
void foo(std::vector<int>* x) {
}

using arr12 = std::array<int, 12>;

int main() {
    int modulo = 2;
    int reverso = 3;
    int sum = 0;
    std::vector<int> Numbers {1,2,3,4,5,6,7,8,9,10};
    std::for_each(Numbers.begin(), Numbers.end(), [reverso, &sum](int x) -> int { std::cout << "x % " << reverso
            << "  " << x % reverso << "\n"; sum += x; });
    std::cout << sum << std::endl;   
    std::cout << '\n';
    std::vector<int>* t = new std::vector<int> {1,2,3,4,5};
    for (auto i: *t) std::cout << i << '\t';
    foo<4>(0);
    std::cout << std::endl;
    
    arr12 arr1{1,2,3,4,5};
    for (auto x: arr1) std::cout << x << '\t';

}
