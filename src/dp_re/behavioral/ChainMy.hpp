#pragma once

#include <deque>
#include <memory>
#include "Product.hpp"

namespace behav {

class MyChainHandler
{
public:
    virtual ~MyChainHandler() = default;
    MyChainHandler(MyChainHandler&&) = default;
    MyChainHandler& operator=(MyChainHandler&&) = default;
    MyChainHandler() = default;

    MyChainHandler(const MyChainHandler&) = delete;
    MyChainHandler& operator=(const MyChainHandler&) = delete;
    MyChainHandler& addNext(std::unique_ptr<MyChainHandler>&& next);
    virtual std::pair<bool, abstract::Product> chandle(std::string tag);

protected:
    std::deque<std::unique_ptr<MyChainHandler>> handlers;
};

class MyChainHandlerZerg : public MyChainHandler
{
public:
    std::pair<bool, abstract::Product> chandle(std::string tag) override;
};

class MyChainHandlerProtoss : public MyChainHandler
{
public:
    std::pair<bool, abstract::Product> chandle(std::string tag) override;
};

class MyChainHandlerTerran : public MyChainHandler
{
public:
    std::pair<bool, abstract::Product> chandle(std::string tag) override;
};
}
