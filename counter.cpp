// how to compile:
// g++ counter.cpp -o counter -lboost_program_options
#include <boost/program_options.hpp>
#include <iostream>
namespace opt = boost::program_options;
//using namespace boost::program_options;

int main(int argc, char *argv[])
{
    opt::options_description desc("All options");
    desc.add_options()
        ("help", "Produce help message")
        ("compression", opt::value<int>(), "set compression level")
    ;
    opt::variables_map vm;
    // parsing and storing arguments
    opt::store(opt::parse_command_line(argc, argv, desc), vm);
    opt::notify(vm);
    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }
    if (vm.count("compression")) {
        std::cout << "Compression level was set to "
            << vm["compression"].as<int>() << ".\n";
    } else {
        std::cout << "compression level was not set.\n";
    }
}