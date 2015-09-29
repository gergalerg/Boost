#include <boost/optional.hpp>
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <time.h>


class locked_device {
    explicit locked_device(const char* /*param*/) {
        // We have unique access to device
        std::cout << "Device is locked\n";
    }
public: 
    ~locked_device() {
        std::cout << "\nDevice is released\n";
    }
    void use() {
        std::cout << "Success!\n";
    }
    static boost::optional<locked_device> try_lock_device() {
        /* if (rand() % 2 == 0) {
            // failed to lock device
            return boost::none;
        }
        Sucess! */
        return locked_device("Device name");
    }
};

int main()
{
    // Boost has a library called random. if you wonder
    for (int i = 0; i < 10; ++i) {
        boost::optional<locked_device> t = locked_device::try_lock_device();
        // optional is converted to bool
        if (t) {
            t->use();
            return 0;
        } else {
            std::cout << "...trying again....\n";
        }
        std::cout << "Failure\n";
        return -1;
    }
}