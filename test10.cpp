#include <iostream>
#include <string>
#include <typeinfo>

class A {
protected:
    std::string name;
public: 
    A(std::string n) : name(n) {}
    virtual void show() { std::cout << typeid(*this).name() << '\n'; }
};

class B : public A
{
public:
    B(std::string n) : A(n) {}
    virtual void show()  { std::cout << typeid(*this).name() << '\n'; }
};

class C
{
    std::string name;
public:
    C(std::string  n) : name(n) {}
    void show() { std::cout << typeid(*this).name() << '\n'; }
};

class D : public C {
public:
    D(std::string n) : C(n) { }
    void sayYouSayMe() { show(); }
    void sayWhat() { sayYouSayMe(); }
};

void foo(A *a) { std::cout << typeid(*a).name() << '\n'; }

int main()
{
    A *a1 = new A("a1");
    B *b1 = new B("b1");
    C *c1 = new C("c1");
    D *d1  = new D("d1");
    foo(a1);
    foo(b1);
    d1->sayWhat();

}