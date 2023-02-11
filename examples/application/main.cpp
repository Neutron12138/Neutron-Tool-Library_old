#include <iostream>
#define NEUTRONTL_CONFIG_USE_APPLICATION
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

class MyApp : public ntl::Application
{
public:
    MyApp() = default;
    ~MyApp() override = default;

public:
    using ntl::Application::run;
    int run(const std::vector<std::string> &args) override
    {
        for (auto iter = args.cbegin(); iter != args.cend(); iter++)
            std::cout << *iter << std::endl;
        std::cout << "----------" << std::endl;
        return run();
    }

public:
    void onCreated() override
    {
        std::cout << "onCreated" << std::endl;
    }

    void onDestroyed() override
    {
        std::cout << "onDestroyed" << std::endl;
    }

    void onIdle() override
    {
        std::cout << "onIdle" << std::endl;
    }
};

ntl::Application &get_application()
{
    static MyApp app;
    return app;
}