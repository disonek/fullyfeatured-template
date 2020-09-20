#pragma once
#include "BridgeImpl.hpp"

namespace struc {
class Barrack : public BridgeImpl
{
public:
    abstract::Products getProducts();
    void print();
};

class Factory : public BridgeImpl
{
public:
    abstract::Products getProducts();
};
}
