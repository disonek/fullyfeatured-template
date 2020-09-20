#include "Prototype.hpp"

namespace creatt {

std::unique_ptr<Prototype> PrototypeCastle::clone()
{
    return std::make_unique<PrototypeCastle>(*this);
}

PrototypeCastle::PrototypeCastle()
{
    products.emplace_back(abstract::Product{"Pikeman"});
    products.emplace_back(abstract::Product{"Archer"});
    products.emplace_back(abstract::Product{"Griffin"});
    products.emplace_back(abstract::Product{"Swordman"});
}

std::unique_ptr<Prototype> PrototypeNecropolis::clone()
{
    return std::make_unique<PrototypeNecropolis>(*this);
}

PrototypeNecropolis::PrototypeNecropolis()
{
    products.emplace_back(abstract::Product{"Skieleton"});
    products.emplace_back(abstract::Product{"Walking dead"});
    products.emplace_back(abstract::Product{"Whih"});
    products.emplace_back(abstract::Product{"Vampire"});
}

std::vector<abstract::Product> Prototype::getProducts() const
{
    return products;
}
}
