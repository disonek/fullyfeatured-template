#pragma once

#include <memory>
#include "Builder.hpp"

namespace creatt {

class Director
{
public:
    explicit Director(std::unique_ptr<BuilderClassic>&& builder);
    Director() = default;
    void setBuilder(std::unique_ptr<BuilderClassic>&& newBuilder);
    abstract::Products getProducts();

private:
    std::unique_ptr<BuilderClassic> builder;
    abstract::Products products;
};
}
