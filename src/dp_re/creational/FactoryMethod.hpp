#pragma once

#include <memory>
#include <string>
#include "Product.hpp"

namespace creatt {

class FactoryMethodByString
{
public:
    std::unique_ptr<abstract::Product> make(std::string&& toMake);
};

class FactoryMethod : public FactoryMethodByString
{
public:
    FactoryMethod() = default;
    virtual ~FactoryMethod() = default;
    FactoryMethod(const FactoryMethod&) = default;
    FactoryMethod& operator=(const FactoryMethod&) = default;
    FactoryMethod(FactoryMethod&&) = default;
    FactoryMethod& operator=(FactoryMethod&&) = default;

    virtual std::unique_ptr<abstract::Product> make() = 0;
};

class FactoryMethodHeroes : public FactoryMethod
{
public:
    std::unique_ptr<abstract::Product> make() override;
};

class FactoryMethodStarcraft : public FactoryMethod
{
public:
    std::unique_ptr<abstract::Product> make() override;
};

class TemplatedFactoryMethod
{
public:
    template <typename ToChange>
    std::unique_ptr<abstract::Product> make()
    {
        return std::make_unique<ToChange>();
    }
};

class HeroesProduct : public abstract::Product
{
public:
    HeroesProduct();
    explicit HeroesProduct(std::string&& one, std::string&& two, std::string&& three);
};

class StarcraftProduct : public abstract::Product
{
public:
    StarcraftProduct();
    explicit StarcraftProduct(std::string&& one, std::string&& two, std::string&& three);
};

template <typename... Ts>
auto makeVariadic(std::string&& tag, Ts&&... params)
{
    std::unique_ptr<abstract::Product> ret = nullptr;
    if("heroes" == tag)
        ret = std::make_unique<HeroesProduct>(std::forward<Ts>(params)...);
    if("starcraft" == tag)
        ret = std::make_unique<StarcraftProduct>(std::forward<Ts>(params)...);
    if(nullptr == ret)
        ret = std::make_unique<abstract::Product>("Empty");

    return ret;
}
}
