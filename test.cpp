#include <iostream>
#include <string>
#include <vector>

template <typename Bag>
typename Bag::value_type min(const Bag & b)
{
    typename Bag::const_iterator it;
    typename Bag::value_type m = *b.begin();
    for (it = b.begin(); it != b.end(); ++it)
        if (*it < m) 
            m = *it;
    return m;
}

int main()
{
    using namespace std;
//    vector<string> input;
//    string temp;
//    while (cin >> temp && temp != "quit")
//        input.push_back(temp);
//    vector<string>::iterator want=
//        find(input.begin(), input.end(), string("bonus"));
//    if (want != input.end())
//    {
//        vector<string>::reference r = *want;
//        r = "bogus";
//    }
//    for (auto x : input) cout << x << " ";
//
    vector<int> temperatures;
    int indy;
    cout << "Enter temperatures: \n";
    while (cin >> indy && indy != 0)
        temperatures.push_back(indy);
    cout << "You entered: \n"; 
    for (auto x: temperatures) cout << x << " ";

    int coldest = min(temperatures);
    cout << "Min temp = " << coldest << "\n";
    

    return 0;
}