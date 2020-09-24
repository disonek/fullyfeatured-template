#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
#include <memory>
#include "Director.hpp"
#include "TypeDeduction.hpp"

using namespace testing;

namespace builder {
class Client
{
public:
    void interface(creatt::Director& director, std::set<std::string>&& toCompare)
    {
        checkIfResultIsEmpty(
            abstract::compareProductDesc(abstract::getProductDesc(director.getProducts()), std::move(toCompare)));
    }

private:
    void checkIfResultIsEmpty(const std::set<std::string>&& result)
    {
        if(!result.empty())
        {
            std::for_each(result.cbegin(), result.cend(), [](std::string desc) { std::cout << desc << std::endl; });
            EXPECT_TRUE(false);
        }
    }
};
}

class BuilderTest : public ::testing::Test
{
public:
    builder::Client client;
};

TEST_F(BuilderTest, creatteInConstructor)
{
    abstract::ScopedStatisticTool s;
    auto director = creatt::Director{std::make_unique<creatt::TowerBuilder>()};

    client.interface(director, {"Naga", "Solmyr", "Titan"});
}

TEST_F(BuilderTest, setBuilder)
{
    abstract::ScopedStatisticTool s;

    auto director = creatt::Director{};

    director.setBuilder(std::make_unique<creatt::TowerBuilder>());
    client.interface(director, {"Naga", "Solmyr", "Titan"});

    director.setBuilder(std::make_unique<creatt::CastleBuilder>());
    client.interface(director, {"Archangiel", "Adele", "Marksman"});
}
