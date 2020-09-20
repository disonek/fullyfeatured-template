#include <gtest/gtest.h>
#include <memory>
#include "Adapter.hpp"
#include "Utils.hpp"

using namespace testing;

namespace adapter {

class Client
{
public:
    void interface(std::shared_ptr<struc::Target> target, std::set<std::string>&& toCompare)
    {
        abstract::Products products = target->getProducts();
        std::set<std::string> productsDesc;
        std::for_each(products.cbegin(), products.cend(), [&productsDesc](abstract::Product product) {
            productsDesc.emplace(product.getDesc());
        });

        dp_tests::checkProductDesc(productsDesc, toCompare);
    }
};
}
class AdapterTest : public ::testing::Test
{
public:
    adapter::Client client;
};

TEST_F(AdapterTest, AdapterByMember)
{
    std::shared_ptr<struc::Target> target = std::make_shared<struc::Target>();
    client.interface(target, {{"regularProduct"}});
    target = std::make_shared<struc::AdapterByMember>();
    client.interface(target, {{"regularProduct"}, {"specialProduct"}});
}

TEST_F(AdapterTest, AdapterByInterherance)
{
    std::shared_ptr<struc::Target> target = std::make_shared<struc::Target>();
    client.interface(target, {{"regularProduct"}});
    target = std::make_shared<struc::AdapterByInterherance>();
    client.interface(target, {{"regularProduct"}, {"specialProduct"}});
}
