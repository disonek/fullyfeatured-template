#include "Director.hpp"

namespace creatt {
Director::Director(std::unique_ptr<BuilderClassic>&& builder)
    : builder{std::move(builder)}
    , products{this->builder->getBuilderProducts()}
{
}

void Director::setBuilder(std::unique_ptr<BuilderClassic>&& newBuilder)
{
    this->builder = std::move(newBuilder);
}

abstract::Products Director::getProducts()
{
    if(nullptr == builder)
        return abstract::Products{};
    return builder->getBuilderProducts();
}
} // namespace creatt
