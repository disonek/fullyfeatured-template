#pragma once
#include <iostream>
#include <string>
#include "Product.hpp"

namespace struc {

class BridgeImpl
{
public:
    virtual ~BridgeImpl() = default;
    BridgeImpl(BridgeImpl&&) = default;
    BridgeImpl& operator=(BridgeImpl&&) = default;
    BridgeImpl(const BridgeImpl&) = default;
    BridgeImpl& operator=(const BridgeImpl&) = default;

    virtual abstract::Products getProducts() = 0;

protected:
    BridgeImpl() = default;
};
}
