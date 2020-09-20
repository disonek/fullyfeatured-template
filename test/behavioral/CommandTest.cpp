#include <gtest/gtest.h>
#include <memory>
#include "Command.hpp"

using namespace testing;

namespace command {
class Client
{
public:
    void interface(std::shared_ptr<behav::InvokerDamager> damager, std::unique_ptr<behav::Command>&& command)
    {
        damager->addCommand(std::move(command));
    }
};
}

class CommandTest : public ::testing::Test
{
public:
    command::Client client;
};

TEST_F(CommandTest, main)
{
    std::shared_ptr<behav::InvokerDamager> damager{std::make_shared<behav::InvokerDamager>()};
    std::shared_ptr<behav::ReciverLeague> tank{std::make_shared<behav::ReciverLeague>("Tank")};
    client.interface(damager, std::make_unique<behav::CommandADAtack>(tank));

    damager->runCommands();
    EXPECT_EQ(tank->health, 90);
    damager->restoreCommands();
    EXPECT_EQ(tank->health, 100);

    client.interface(damager, std::make_unique<behav::CommandAPAtack>(tank));
    client.interface(damager, std::make_unique<behav::CommandADAtack>(tank));
    client.interface(damager, std::make_unique<behav::CommandAPAtack>(tank));
    client.interface(damager, std::make_unique<behav::CommandADAtack>(tank));
    damager->runCommands();
    EXPECT_EQ(tank->health, 40);
    damager->restoreCommands();
    EXPECT_EQ(tank->health, 100);
}
