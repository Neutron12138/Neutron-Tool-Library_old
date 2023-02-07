#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

class MyApp : public ntl::Application
{
public:
    MyApp() = default;
    ~MyApp() override = default;

public:
    void onCreated() override
    {
        std::cout << "onCreated" << std::endl;
    }

    void onDestroyed() override
    {
        std::cout << "onDestroyed" << std::endl;
    }

    void onIdle(const ntl::Time &delta_time) override
    {
        std::cout << "onIdle" << std::endl;
    }
};

int main()
{
    MyApp app;
    return app.run();
}