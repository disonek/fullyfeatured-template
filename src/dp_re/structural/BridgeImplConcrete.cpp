#include "BridgeImplConcrete.hpp"

namespace struc {

abstract::Products Barrack::getProducts()
{
    return {abstract::Product{"Marine"},
            abstract::Product{"Medic"},
            abstract::Product{"Firebat"},
            abstract::Product{"Ghost"}};
}

abstract::Products Factory::getProducts()
{
    return {abstract::Product{"Vulture"}, abstract::Product{"Tank"}, abstract::Product{"Goliath"}};
}
}
