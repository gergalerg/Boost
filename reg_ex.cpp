#include <boost/regex.hpp>
#include <iostream>
#include <string>

int main()
{
    std::string line;
    std::string const reg_ex = "^Subject: (Re: |Aw: )*(.*)";
    boost::regex pat(reg_ex );
    /*

    while (std::cin)
    {
        std::getline(std::cin, line);
        boost::smatch matches;
        if (boost::regex_match(line, matches, pat))
            std::cout << matches[2] << std::endl;
    }
    */
}