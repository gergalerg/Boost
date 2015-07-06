#include <iostream>
#include <unordered_map>
#include <vector>
#include <bitset>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::vector;

struct Key {
    std::string first;
    std::string second;
};

struct KeyHash {
    std::size_t operator() (const Key& k) const
    {
        return std::hash<std::string>()(k.first) ^
                (std::hash<std::string>()(k.second) << 1);
    }
};

int main()
{
    const char* name = "Greg";
    std::size_t n1;
    std::size_t n2;
    std::string str = "Meet the new boss...";
    n1 = std::hash<const char *>()(name);
    n2 = std::hash<std::string>()(str);

    cout << n1 << endl;
    cout << n2 << endl;

    return 0;
}