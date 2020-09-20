#pragma once
#include <memory>
#include <set>
#include <string>
#include "BridgeImpl.hpp"

namespace struc {

class Bridge
{
public:
    virtual ~Bridge();
    explicit Bridge(std::unique_ptr<BridgeImpl>&& impl);
    Bridge() = delete;
    Bridge(Bridge&&) = default;
    Bridge& operator=(Bridge&&) = default;
    Bridge(const Bridge&) = delete;
    Bridge& operator=(const Bridge&) = delete;

    virtual std::set<std::string> getProductsDesc() = 0;
    void setImplemenation(std::unique_ptr<BridgeImpl>&& impl);

protected:
    std::unique_ptr<BridgeImpl> impl;
};

class BridgeStandard : public Bridge
{
public:
    BridgeStandard();
    std::set<std::string> getProductsDesc() override;
};

class BridgeSpecial : public Bridge
{
public:
    BridgeSpecial();
    std::set<std::string> getProductsDesc() override;
};
}
