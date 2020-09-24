#include "Builder.hpp"

namespace creatt {

BuilderClassic::BuilderClassic()
{
}

void BuilderClassic::addProduct(std::string&& product)
{
    products.emplace(std::move(product));
}

BuilderClassic& BuilderClassic::addFluentProduct(std::string&& product)
{
    products.emplace(std::move(product));
    return *this;
}

abstract::Products TowerBuilder::getBuilderProducts()
{
    addFluentProduct("Solmyr").addFluentProduct("Titan").addFluentProduct("Naga");
    return products;
}

abstract::Products CastleBuilder::getBuilderProducts()
{
    addProduct("Adele");
    addProduct("Archangiel");
    addProduct("Marksman");
    return products;
}
}
