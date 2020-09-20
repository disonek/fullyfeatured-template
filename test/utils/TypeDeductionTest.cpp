#include <gtest/gtest.h>
#include <type_traits>
#include "Product.hpp"
#include "StatisticTool.hpp"
#include "TypeDeduction.hpp"

using namespace testing;

namespace dp_tests {

TEST(TypeDeductionTest, byConstRefObject)
{
   abstract::ScopedStatisticTool s;
   auto product = abstract::Product{};

   abstract::StatisticTool::resetStatistic();
   dp_tests::byConstRef(product);
}

TEST(TypeDeductionTest, byConstRefMovedObject)
{
   abstract::ScopedStatisticTool s;
   auto product = abstract::Product{};

   abstract::StatisticTool::resetStatistic();
   dp_tests::byConstRef(std::move(product));
}

TEST(TypeDeductionTest, byConstRefConstObject)
{
   abstract::ScopedStatisticTool s;
   const auto constProduct = abstract::Product{};

   abstract::StatisticTool::resetStatistic();
   dp_tests::byConstRef(constProduct);
}

TEST(TypeDeductionTest, byRefObject)
{
   abstract::ScopedStatisticTool s;
   auto product = abstract::Product{};

   abstract::StatisticTool::resetStatistic();
   dp_tests::byRef(product);
}

TEST(TypeDeductionTest, byRefConstObjdect)
{
   abstract::ScopedStatisticTool s;
   const auto constProduct = abstract::Product{};

   abstract::StatisticTool::resetStatistic();
   dp_tests::byRef(constProduct);
}

TEST(TypeDeductionTest, byUniversalRefObject)
{
   abstract::ScopedStatisticTool s;
   auto product = abstract::Product{};

   abstract::StatisticTool::resetStatistic();
   dp_tests::byUniversalRef(product);
}

TEST(TypeDeductionTest, byUniversalRefMovedObject)
{
   abstract::ScopedStatisticTool s;
   auto product = abstract::Product{};

   abstract::StatisticTool::resetStatistic();
   dp_tests::byUniversalRef(std::move(product));
}

TEST(TypeDeductionTest, byUniversalRefConstObject)
{
   abstract::ScopedStatisticTool s;
   const auto constProduct = abstract::Product{};

   abstract::StatisticTool::resetStatistic();
   dp_tests::byUniversalRef(constProduct);
}

TEST(TypeDeductionTest, byValueObject)
{
   abstract::ScopedStatisticTool s;
   auto product = abstract::Product{};

   abstract::StatisticTool::resetStatistic();
   dp_tests::byValue(product);
}

TEST(TypeDeductionTest, byValueMovedObject)
{
   abstract::ScopedStatisticTool s;
   auto product = abstract::Product{};

   abstract::StatisticTool::resetStatistic();
   dp_tests::byValue(std::move(product));
}

TEST(TypeDeductionTest, test)
{
   abstract::ScopedStatisticTool s;
   const auto product = abstract::Product{};

   abstract::StatisticTool::resetStatistic();
   dp_tests::byValue(&product);
}

TEST(TypeDeductionTest, byValueConstObject)
{
   abstract::ScopedStatisticTool s;
   const auto constProduct = abstract::Product{};

   abstract::StatisticTool::resetStatistic();
   dp_tests::byValue(constProduct);
}

TEST(TypeDeductionTest, byPointerObject)
{
   abstract::ScopedStatisticTool s;
   auto product = abstract::Product{};

   abstract::StatisticTool::resetStatistic();
   dp_tests::byPointer(&product);
}

TEST(TypeDeductionTest, byPointerConstObject)
{
   abstract::ScopedStatisticTool s;
   auto product = abstract::Product{};
   const abstract::Product* productPointer = &product;

   abstract::StatisticTool::resetStatistic();
   dp_tests::byPointer(productPointer);
}
}
