#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class Printer
{
private:
    boost::asio::deadline_timer timer_;
    int count_;
public:
    Printer(boost::asio::io_service& io);
    ~Printer() { std::cout << "Final count is " << count_ << "\n"; }
    void print();
};

Printer::Printer(boost::asio::io_service& io) :
        timer_(io, boost::posix_time::seconds(1)), count_(0)
{
        timer_.async_wait(boost::bind(&Printer::print, this)); 
}
//Printer::Printer(boost::asio::io_service& io) :
 //       timer_(io, boost::posix_time::seconds(1)), count_(0)

void Printer::print() {
    if (count_ < 5)
    {
        std::cout << count_ << "\n";
        ++count_;

        timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(1));
        timer_.async_wait(boost::bind(&Printer::print, this));
    }
}
int main()
{
    boost::asio::io_service io;
    Printer p(io);
    io.run();
    return 0;
}