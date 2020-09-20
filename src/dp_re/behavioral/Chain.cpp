#include "Chain.hpp"

namespace behav {

behav::ChainHandler::ChainHandler()
    : nextHandler{nullptr}
{
}

std::shared_ptr<behav::ChainHandler> behav::ChainHandler::setNextHandler(std::shared_ptr<behav::ChainHandler> next)
{
    nextHandler = next;
    return next;
}

abstract::Product ChainHandler::chandle(std::string tag)
{
    if(nullptr != nextHandler)
        return nextHandler->chandle(tag);
    return abstract::Product{"Handle not found"};
}

abstract::Product ChainHandlerCastle::chandle(std::string tag)
{
    if("Valecsa" == tag)
        return abstract::Product{"Castle Hero"};
    else
    {
        return ChainHandler::chandle(tag);
    }
}

abstract::Product ChainHandlerBastion::chandle(std::string tag)
{
    if("Kyrre" == tag)
        return abstract::Product{"Bastion Hero"};
    else
    {
        return ChainHandler::chandle(tag);
    }
}

abstract::Product ChainHandlerTower::chandle(std::string tag)
{
    if("Solmyr" == tag)
        return abstract::Product{"Tower Hero"};
    else
    {
        return ChainHandler::chandle(tag);
    }
}
}
