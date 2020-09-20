#include <gtest/gtest.h>
#include <memory>
#include "Bridge.hpp"
#include "BridgeImpl.hpp"
#include "BridgeImplConcrete.hpp"
#include "Utils.hpp"

using namespace testing;

namespace bridge {

class Client
{
public:
    void interface(std::shared_ptr<struc::Bridge> bridge, std::set<std::string>&& toCompare)
    {
        dp_tests::checkProductDesc(bridge->getProductsDesc(), std::move(toCompare));
    }
};
}
class BridgeTest : public ::testing::Test
{
public:
    bridge::Client client;
};

TEST_F(BridgeTest, BridgeStandard)
{
    std::shared_ptr<struc::Bridge> bridge = std::make_shared<struc::BridgeStandard>();
    client.interface(bridge, {{"Marine"}, {"Medic"}, {"Firebat"}, {"Ghost"}});

    bridge->setImplemenation(std::make_unique<struc::Factory>());
    client.interface(bridge, {{"Vulture"}, {"Tank"}, {"Goliath"}});
}

TEST_F(BridgeTest, BridgeSpecial)
{
    std::shared_ptr<struc::Bridge> bridge = std::make_shared<struc::BridgeSpecial>();
    client.interface(
        bridge,
        {{"special->Marine->^&*"}, {"special->Medic->^&*"}, {"special->Firebat->^&*"}, {"special->Ghost->^&*"}});

    bridge->setImplemenation(std::make_unique<struc::Factory>());
    client.interface(bridge, {{"special->Vulture->^&*"}, {"special->Tank->^&*"}, {"special->Goliath->^&*"}});
    // EXPECT_TRUE(false);
}
