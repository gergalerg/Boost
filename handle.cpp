#include <iostream>

class Handle {
public:
    Handle();                       // Constructor
    Handle(const Handle&);          // Copy constructor
    Handle(Handle&&);               // Move constructor
    Handle& operator=(const Handle&); // copy assignment operator
    ~Handle();                      // Destructor 
private:
    struct CheshireCat; // Not defined here.
    CheshireCat* smile;  // Handle
};

struct Handle::CheshireCat {
    int a;
    int b;
};

Handle::Handle() : smile(new CheshireCat()) {}

Handle::Handle(const Handle& other) 
        : smile(new CheshireCat(*other.smile)) { }

Handle::Handle(Handle&& other) : smile(0) {
    std::swap(smile, other.smile);
}

Handle& Handle::operator=(const Handle &other) {
    if (this != &other) {
        *smile = *(other.smile);
    }
    return *this;
}

Handle::~Handle() {
    delete smile;
}
int main() 
{
    Handle bach;
    Handle johann;
    johann = bach;
    return 0;
}