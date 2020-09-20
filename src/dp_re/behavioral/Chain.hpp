#pragma once

#include <memory>
#include "Product.hpp"

namespace behav {

class ChainHandler
{
public:
    virtual ~ChainHandler() = default;
    ChainHandler(const ChainHandler&) = default;
    ChainHandler& operator=(const ChainHandler&) = default;
    ChainHandler(ChainHandler&&) = default;
    ChainHandler& operator=(ChainHandler&&) = default;

    ChainHandler();
    std::shared_ptr<ChainHandler> setNextHandler(std::shared_ptr<ChainHandler> next);
    virtual abstract::Product chandle(std::string tag);

protected:
    std::shared_ptr<ChainHandler> nextHandler;
};

class ChainHandlerCastle : public ChainHandler
{
    abstract::Product chandle(std::string tag) override;
};

class ChainHandlerBastion : public ChainHandler
{
    abstract::Product chandle(std::string tag) override;
};

class ChainHandlerTower : public ChainHandler
{
    abstract::Product chandle(std::string tag) override;
};
}
