#include "ChainMy.hpp"

namespace behav {

MyChainHandler& MyChainHandler::addNext(std::unique_ptr<MyChainHandler>&& next)
{
    handlers.emplace_front(std::move(next));
    return *this;
}

std::pair<bool, abstract::Product> MyChainHandler::chandle(std::string tag)
{
    for(const auto& handler : handlers)
    {
        if(handler->chandle(tag).first)
        {
            return handler->chandle(tag);
        }
    }

    return std::make_pair(false, abstract::Product{""});
}

std::pair<bool, abstract::Product> MyChainHandlerZerg::chandle(std::string tag)
{
    if("Zergling" == tag)
        return std::make_pair(true, abstract::Product{"Zerg"});
    else
    {
        return std::make_pair(false, abstract::Product{""});
    }
}

std::pair<bool, abstract::Product> MyChainHandlerProtoss::chandle(std::string tag)
{
    if("Zelot" == tag)
        return std::make_pair(true, abstract::Product{"Protoss"});
    else
    {
        return std::make_pair(false, abstract::Product{""});
    }
}

std::pair<bool, abstract::Product> MyChainHandlerTerran::chandle(std::string tag)
{
    if("Marine" == tag)
        return std::make_pair(true, abstract::Product{"Terran"});
    else
    {
        return std::make_pair(false, abstract::Product{""});
    }
}
}
