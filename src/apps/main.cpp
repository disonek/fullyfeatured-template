#include <chrono>
#include <iostream>
#include <map>
#include <memory>
#include <unordered_map>
#include <vector>
#include "Hello.hpp"

// TO DO => explain situation

void f()
{
    std::this_thread::sleep_for(std::chrono::seconds{1});
    std::cout << "Hello ala" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds{2});
    throw;
}

int main()
{
    using namespace std::chrono_literals;

    std::cout << std::this_thread::get_id() << std::endl;

    concurr::ScopedThread st{std::thread([]() {
        std::this_thread::sleep_for(std::chrono::seconds{2});
        std::cout << "Hello 2" << std::endl;
    })};

    auto lam = [] { f(); };
    try
    {
        lam();
    }
    catch(...)
    {
        std::cout << "Hello catch" << std::endl;
    }
}
