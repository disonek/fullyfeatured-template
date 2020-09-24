#pragma once

#include <memory>
#include "Product.hpp"

namespace creatt {

class BuilderClassic
{
public:
    virtual ~BuilderClassic() = default;
    BuilderClassic();
    BuilderClassic(BuilderClassic&&) = default;
    BuilderClassic& operator=(BuilderClassic&&) = default;
    BuilderClassic(const BuilderClassic&) = default;
    BuilderClassic& operator=(const BuilderClassic&) = default;

    virtual abstract::Products getBuilderProducts() = 0;
    void addProduct(std::string&& product);
    BuilderClassic& addFluentProduct(std::string&& product);

protected:
    abstract::Products products;
};

class TowerBuilder : public BuilderClassic
{
    abstract::Products getBuilderProducts() override;
};
class CastleBuilder : public BuilderClassic
{
    abstract::Products getBuilderProducts() override;
};
}
