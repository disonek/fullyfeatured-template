#pragma once

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include "StatisticTool.hpp"

namespace abstract {
class Product : public StatisticTool
{
public:
    explicit Product(std::string&& one);
    explicit Product(std::string&& one, std::string&& two, std::string&& three);
    Product() = default;

    bool operator<(const Product& other) const;
    bool operator==(const Product& other) const;
    void print() const;
    std::string getDesc() const;

protected:
    std::string desc;
};

using Products = std::set<Product>;

template <typename T>
void printProducts(T&& products)
{
    std::for_each(std::forward<T>(products).cbegin(), std::forward<T>(products).cend(), [](auto&& product) {
        std::forward<decltype(product)>(product).print();
    });
}

template <typename T>
auto getProductDesc(T&& products)
{
    auto productsDesc = std::set<std::string>{};

    std::for_each(
        std::forward<T>(products).cbegin(), std::forward<T>(products).cend(), [&productsDesc](auto&& product) {
            productsDesc.emplace(std::forward<decltype(product)>(product).getDesc());
        });
    return productsDesc;
}

template <typename T>
T compareProductDesc(T&& productsLhs, T&& productsRhs)
{
    T diff;

    std::set_difference(std::forward<T>(productsLhs).cbegin(),
                        std::forward<T>(productsLhs).cend(),
                        std::forward<T>(productsRhs).cbegin(),
                        std::forward<T>(productsRhs).cend(),
                        std::inserter(diff, diff.begin()));
    return diff;
}
}
