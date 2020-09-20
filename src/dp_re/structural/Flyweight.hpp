#pragma once
#include <array>
#include <cstdint>
#include <iostream>
#include <map>
#include <memory>
#include "Product.hpp"

namespace struc {

struct UniqueState
{
    uint32_t x;
    uint32_t y;
};

using SharedState = abstract::Product;
using DisplayArray = std::array<std::array<abstract::Product, 10>, 10>;

class Flyweight
{
public:
    Flyweight(SharedState sharedState)
        : sharedState{sharedState}
    {
    }

    void operation(UniqueState uniqueState, DisplayArray& display)
    {
        display.at(uniqueState.y).at(uniqueState.x) = sharedState;
    }

private:
    SharedState sharedState;
};

class FlyweightFactory
{
public:
    FlyweightFactory()
        : flyweightsCache{{"AAA", std::make_shared<Flyweight>(SharedState{"AAA"})},
                          {"ABC", std::make_shared<Flyweight>(SharedState{"ABC"})}}
    {
    }

    Flyweight getFlyweight(std::string key) const
    {
        if(flyweightsCache.find(key) != flyweightsCache.end())
            return *flyweightsCache.find(key)->second;

        return Flyweight{SharedState{""}};
    }

private:
    std::map<std::string, std::shared_ptr<Flyweight>> flyweightsCache;
};

class DrawContext
{
public:
    DrawContext(Flyweight fly, std::vector<UniqueState> us)
        : flyweight{fly}
        , uniqueStates{us}
    {
        std::array<abstract::Product, 10> basic;
        basic.fill(abstract::Product{"___"});
        display.fill(std::move(basic));
        for(auto us : uniqueStates)
            flyweight.operation(us, display);
    }

    void draw()
    {
        for(auto y : display)
        {
            for(auto x : y)
                std::cout << x.getDesc();
            std::cout << std::endl;
        }
    }

    DisplayArray getDisplay() const;

private:
    Flyweight flyweight;
    std::vector<UniqueState> uniqueStates;

    DisplayArray display;
};
}
