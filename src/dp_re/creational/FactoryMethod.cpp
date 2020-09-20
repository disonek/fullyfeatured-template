#include "FactoryMethod.hpp"

namespace creatt {

std::unique_ptr<abstract::Product> FactoryMethodByString::make(std::string&& toMake)
{
    if("HeroesProduct" == toMake)
    {
        return std::make_unique<HeroesProduct>();
    }
    if("StarcraftProduct" == toMake)
    {
        return std::make_unique<StarcraftProduct>();
    }

    return std::make_unique<abstract::Product>();
}

std::unique_ptr<abstract::Product> FactoryMethodHeroes::make()
{
    return std::make_unique<HeroesProduct>();
}

std::unique_ptr<abstract::Product> FactoryMethodStarcraft::make()
{
    return std::make_unique<StarcraftProduct>();
}

HeroesProduct::HeroesProduct()
    : abstract::Product("HeroesProduct")
{
}

HeroesProduct::HeroesProduct(std::string&& one, std::string&& two, std::string&& three)
    : abstract::Product{"HeroesProduct->" + std::move(one), std::move(two), std::move(three)}
{
}

StarcraftProduct::StarcraftProduct()
    : abstract::Product("StarcraftProduct")
{
}

StarcraftProduct::StarcraftProduct(std::string&& one, std::string&& two, std::string&& three)
    : abstract::Product{"StarcraftProduct->" + std::move(one), std::move(two), std::move(three)}
{
}
}
