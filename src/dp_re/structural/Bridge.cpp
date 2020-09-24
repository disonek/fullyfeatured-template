#include "Bridge.hpp"

#include "BridgeImplConcrete.hpp"

namespace struc {

Bridge::~Bridge() = default;
Bridge::Bridge(std::unique_ptr<BridgeImpl>&& impl)
    : impl{std::move(impl)}
{
}

void Bridge::setImplemenation(std::unique_ptr<BridgeImpl>&& implToMove)
{
    this->impl = std::move(implToMove);
}

BridgeStandard::BridgeStandard()
    : Bridge(std::make_unique<Barrack>())
{
}

std::set<std::string> BridgeStandard::getProductsDesc()
{
    abstract::Products products = impl->getProducts();
    std::set<std::string> productsDesc;
    std::for_each(products.cbegin(), products.cend(), [&productsDesc](abstract::Product product) {
        productsDesc.emplace(product.getDesc());
    });

    return productsDesc;
}

BridgeSpecial::BridgeSpecial()
    : Bridge(std::make_unique<Barrack>())
{
}

std::set<std::string> BridgeSpecial::getProductsDesc()
{
    abstract::Products products = impl->getProducts();
    std::set<std::string> productsDesc;
    std::for_each(products.cbegin(), products.cend(), [&productsDesc](abstract::Product product) {
        productsDesc.emplace("special->" + product.getDesc() + "->^&*");
    });

    return productsDesc;
}
} // namespace struc
