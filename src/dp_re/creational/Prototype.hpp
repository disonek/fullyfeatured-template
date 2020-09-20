#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "Product.hpp"

namespace creatt {

class Prototype
{
public:
    virtual ~Prototype() = default;
    Prototype() = default;
    virtual std::unique_ptr<Prototype> clone() = 0;

    void print()
    {
        for(const auto& product : products)
            std::cout << product.getDesc() << std::endl;
    }

    std::vector<abstract::Product> getProducts() const;

protected:
    std::vector<abstract::Product> products;
};

class PrototypeCastle : public Prototype
{
public:
    std::unique_ptr<Prototype> clone() override;

    PrototypeCastle();
};

class PrototypeNecropolis : public Prototype
{
public:
    std::unique_ptr<Prototype> clone() override;

    PrototypeNecropolis();
};
}
