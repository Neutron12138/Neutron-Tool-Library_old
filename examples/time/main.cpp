#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

class MyCT : public ntl::CountdownTimer
{
public:
    MyCT() = default;
    ~MyCT() = default;

    public:
    void onStarted()
    {
        std::cout << ntl::get_current_time().as_clocks() << std::endl;
    }

    void onTimeUp()
    {
        std::cout << ntl::get_current_time().as_clocks() << std::endl;
    }
};

int main()
{
    ntl::Time curr = ntl::get_current_time();
    std::cout << curr.as_clocks() << std::endl;

    MyCT ct;
    ct.set_duration(ntl::OneSecond);
    ct.start(ntl::CountdownTimer::CountdownType::Block);
    return 0;
}