#include <gtest/gtest.h>

#include <algorithm>

#include "Chain.hpp"
#include "ChainMy.hpp"
#include "Utils.hpp"

using namespace testing;

namespace chain {
class Client
{
public:
    auto interface(std::shared_ptr<behav::ChainHandler> chainHandler, std::set<std::string> requests)
    {
        decltype(requests) result;
        std::for_each(requests.cbegin(), requests.cend(), [&result, &chainHandler](std::string singleTestImput) {
            result.emplace(chainHandler->chandle(singleTestImput).getDesc());
        });
        return result;
    }

    auto myInterface(behav::MyChainHandler myHandler, std::vector<std::string> requests)
    {
        decltype(requests) result;
        std::for_each(requests.cbegin(), requests.cend(), [&result, &myHandler](std::string singleTestImput) {
            if(myHandler.chandle(singleTestImput).first)
            {
                result.emplace_back(myHandler.chandle(singleTestImput).second.getDesc());
            }
        });
        return result;
    }
};
} // namespace chain

class ChainTest : public ::testing::Test
{
public:
    chain::Client client;
};

TEST_F(ChainTest, main)
{
    std::shared_ptr<behav::ChainHandler> castle = std::make_shared<behav::ChainHandlerCastle>();
    std::shared_ptr<behav::ChainHandler> bastion = std::make_shared<behav::ChainHandlerBastion>();
    std::shared_ptr<behav::ChainHandler> tower = std::make_shared<behav::ChainHandlerTower>();

    castle->setNextHandler(bastion)->setNextHandler(tower);
    auto result = client.interface(castle, {{"Kyrre"}, {"Valecsa"}, {"Solmyr"}});
    dp_tests::checkProductDesc(std::move(result), {{"Bastion Hero"}, {"Tower Hero"}, {"Castle Hero"}});
}

TEST_F(ChainTest, myHandler)
{
    behav::MyChainHandler zerg;
    zerg.addNext(std::make_unique<behav::MyChainHandlerZerg>())
        .addNext(std::make_unique<behav::MyChainHandlerTerran>())
        .addNext(std::make_unique<behav::MyChainHandlerProtoss>());

    auto result = client.myInterface(std::move(zerg), {{"Marine"}, {"Zergling"}, {"Zelot"}});
    dp_tests::checkProductDesc(std::move(result), {{"Terran"}, {"Zerg"}, {"Protoss"}});
}
