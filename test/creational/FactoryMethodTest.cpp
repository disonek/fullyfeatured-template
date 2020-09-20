#include <gtest/gtest.h>

#include <memory>

#include "FactoryMethod.hpp"


using namespace testing;

namespace factorymethod {
class Client
{
public:
    void interface(abstract::Product product, std::string toCompare)
    {
        std::unique_ptr<Client> asd = std::make_unique<Client>();
        EXPECT_EQ(product.getDesc(), toCompare);
    }

    void interface(std::shared_ptr<creatt::FactoryMethod> factory, std::string toCompare)
    {
        EXPECT_EQ(factory->make()->getDesc(), toCompare);
    }
};
} // namespace factorymethod

class FactoryMethodTest : public ::testing::Test
{
public:
    factorymethod::Client client;
};

TEST_F(FactoryMethodTest, byString)
{
    creatt::FactoryMethodByString factory;
    client.interface(*factory.make("HeroesProduct"), "HeroesProduct");
    client.interface(*factory.make("StarcraftProduct"), "StarcraftProduct");
}

TEST_F(FactoryMethodTest, templated)
{
    creatt::TemplatedFactoryMethod factory;
    client.interface(*factory.make<creatt::HeroesProduct>(), "HeroesProduct");
    client.interface(*factory.make<creatt::StarcraftProduct>(), "StarcraftProduct");
}

TEST_F(FactoryMethodTest, byHierarhy)
{
    std::shared_ptr<creatt::FactoryMethod> factory = std::make_shared<creatt::FactoryMethodHeroes>();
    client.interface(factory, "HeroesProduct");
    factory = std::make_shared<creatt::FactoryMethodStarcraft>();
    client.interface(factory, "StarcraftProduct");
}

TEST_F(FactoryMethodTest, variadic)
{
    std::unique_ptr<abstract::Product> product =
        creatt::makeVariadic(std::string{"heroes"}, std::string{"one"}, std::string{"two"}, std::string{"three"});
    EXPECT_EQ(product->getDesc(), "HeroesProduct->one_two_three");

    product =
        creatt::makeVariadic(std::string{"starcraft"}, std::string{"one"}, std::string{"two"}, std::string{"three"});
    EXPECT_EQ(product->getDesc(), "StarcraftProduct->one_two_three");

    product = creatt::makeVariadic(std::string{"asd"}, std::string{"one"}, std::string{"two"}, std::string{"three"});
    EXPECT_EQ(product->getDesc(), "Empty");
}
