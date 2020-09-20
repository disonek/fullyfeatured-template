#include "Product.hpp"

namespace abstract {

Product::Product(std::string&& one)
    : desc{std::move(one)}
{
}

Product::Product(std::string&& one, std::string&& two, std::string&& three)
    : desc{std::move(one) + "_" + std::move(two) + "_" + std::move(three)}
{
}

bool Product::operator<(const Product& other) const
{
    return desc < other.desc;
}

bool Product::operator==(const Product& other) const
{
    return desc == other.desc;
}

void Product::print() const
{
    std::cout << desc << std::endl;
}

std::string Product::getDesc() const
{
    return desc;
}
}
