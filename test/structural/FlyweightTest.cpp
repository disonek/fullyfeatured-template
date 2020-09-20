#include <gtest/gtest.h>
#include <memory>
#include "Flyweight.hpp"

using namespace testing;

namespace flyweight {

class Client
{
public:
    void interface(const struc::FlyweightFactory& factory)
    {
        struc::DrawContext drawContext{{factory.getFlyweight("AAA")}, {{1, 5}, {9, 0}, {2, 9}, {7, 3}, {4, 8}}};
        abstract::Product containState{"AAA"};
        abstract::Product notContainState{"___"};
        EXPECT_EQ(drawContext.getDisplay()[5][1], containState);
        EXPECT_EQ(drawContext.getDisplay()[0][9], containState);
        EXPECT_EQ(drawContext.getDisplay()[9][2], containState);
        EXPECT_EQ(drawContext.getDisplay()[3][7], containState);
        EXPECT_EQ(drawContext.getDisplay()[8][4], containState);
        EXPECT_EQ(drawContext.getDisplay()[0][0], notContainState);
        EXPECT_EQ(drawContext.getDisplay()[5][5], notContainState);
    }
};
}

TEST(FlyweightTest, main)
{
    struc::FlyweightFactory factory;
    flyweight::Client client;
    client.interface(factory);
}
