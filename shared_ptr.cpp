#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
#include <typeinfo>

struct Base
{
    Base() { std::cout << " Base::Base()\n"; }
    ~Base() { std::cout << "Base::~Base()\n";}
};

struct Derived : public Base
{
    Derived()  { std::cout << " Derived::Derived()\n"; }
    ~Derived() { std::cout << " Derived::~Derived()\n"; }
};

void thr(std::shared_ptr<Base> p)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::shared_ptr<Base> lp = p; // thread-safe, even though the 
                                    // shared use_count is incremented
   {
    static std::mutex io_mutex;
    std::lock_guard<std::mutex> lk(io_mutex);
    std::cout << "local pointer in a thread:\n"
            << " lp.get() = " << lp.get()
            << ", lp.use_count() = " << lp.use_count() << "\n";
   } 
}

void timer(int x) { 
    std::this_thread::sleep_for(std::chrono::seconds(x)); 
    std::cout << "This thread gone for " << x << " seconds\n";
    {
        static std::mutex io_mutex;
        std::lock_guard<std::mutex> lk(io_mutex);
    }

}

int main()
{
    //std::shared_ptr<Base> p = std::make_shared<Derived>();
//    std::thread t1(thr, p), t2(thr, p);
    std::thread t1(timer, 3), t2(timer, 2), t3(timer, 5);
    t1.join(); t2.join(); t3.join();
}