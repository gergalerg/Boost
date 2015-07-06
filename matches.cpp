// How to use:
// $ cat mails.txt | ./matches
// How to compile:
// $  g++ -I /usr/lib/x86_64-linux-gnu/ matches.cpp -o matches /usr/lib/x86_64-linux-gnu/libboost_regex.a
//
// You have to link to the libboost_regex for some reason.
#include <boost/regex.hpp>
#include <iostream>
#include <string>

int main()
{
    std::string line;
    boost::regex pat( "^Subject: (Re: |Aw: )*.(.*)" );

    while (std::cin)
    {
        std::getline(std::cin, line);
        boost::smatch matches;
        if (boost::regex_match(line, matches, pat))
                std::cout << matches[2] << std::endl;
    }

    return 0;
}
