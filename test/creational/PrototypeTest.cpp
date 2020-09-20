#include <gtest/gtest.h>

#include <algorithm>
#include <memory>

#include "Prototype.hpp"
#include "Utils.hpp"


using namespace testing;

namespace prototype {
class Client
{
public:
    void interface(std::shared_ptr<creatt::Prototype> prototype, std::vector<std::string>&& toCompare)
    {
        std::vector<abstract::Product> prototypeProducts = prototype->clone()->getProducts();
        std::vector<std::string> productsDescs;
        std::for_each(prototypeProducts.cbegin(),
                      prototypeProducts.cend(),
                      [&productsDescs](abstract::Product product) { productsDescs.emplace_back(product.getDesc()); });

        dp_tests::checkProductDesc(productsDescs, toCompare);
    }
};
} // namespace prototype

class PrototypeTest : public ::testing::Test
{
public:
    prototype::Client client;
};

TEST_F(PrototypeTest, basic)
{
    abstract::ScopedStatisticTool s;
    std::shared_ptr<creatt::Prototype> prototype = std::make_shared<creatt::PrototypeCastle>();
    client.interface(prototype, {"Pikeman", "Archer", "Griffin", "Swordman"});
    prototype = std::make_shared<creatt::PrototypeNecropolis>();
    client.interface(prototype, {"Skieleton", "Walking dead", "Whih", "Vampire"});
}
