#include "Adapter.hpp"

namespace struc {

abstract::Products Target::getProducts()
{
    return products;
}

abstract::Products AdapterByMember::getProducts()
{
    products.emplace(plugin.getSpecialProduct());
    return products;
}

abstract::Products AdapterByInterherance::getProducts()
{
    products.emplace(getSpecialProduct());
    return products;
}
}
