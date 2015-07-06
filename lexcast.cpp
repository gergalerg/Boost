#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>


int main()
{
    float weight = 110;
    std::cout << "Your weight: " << weight << " lbs.\n"; 
    std::string gain = "A 10% increase raises ";
    std::string wt = boost::lexical_cast<std::string>(weight);
    gain = gain + wt + " to ";
    weight  = 1.1 * weight;
    gain = gain + boost::lexical_cast<std::string>(weight) + ".";
    std::cout << gain << std::endl;

}