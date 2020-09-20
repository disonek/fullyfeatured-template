#pragma once
#include "Product.hpp"

namespace struc {
class Target
{
public:
    virtual ~Target() = default;
    Target(Target&&) = default;
    Target& operator=(Target&&) = default;
    Target(const Target&) = default;
    Target& operator=(const Target&) = default;

    Target()
        : products{{abstract::Product{"regularProduct"}}}
    {
    }

    virtual abstract::Products getProducts();

protected:
    abstract::Products products;
};

class AdapterPlugin
{
public:
    abstract::Product getSpecialProduct()
    {
        return abstract::Product{"specialProduct"};
    }
};

class AdapterByMember : public Target
{
public:
    abstract::Products getProducts() override;
    AdapterPlugin plugin;
};

class AdapterByInterherance : public Target, private AdapterPlugin
{
public:
    abstract::Products getProducts() override;
};
}
