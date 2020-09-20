#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <FindLongestString.hpp>
#include <General.hpp>
#include <TwoSum.hpp>

using namespace testing;

TEST(TwoSumTest, main)
{
    algo::TwoSum s{};

    std::vector<int> input{11, 7, 2, 15};
    std::pair<int, int> result = s.twoSum(input, 17);
    EXPECT_EQ(result.first, 2);
    EXPECT_EQ(result.second, 3);
}

TEST(FindLongestString, main)
{
    //EXPECT_EQ(algo::FindLongestString::lengthOfLongestSubstring("alaz"), 3);
    //EXPECT_EQ(algo::FindLongestString::lengthOfLongestSubstring("alkzo"), 5);
}

TEST(SingleNumber, main)
{
    EXPECT_EQ(algo::SingleNumber::singleNumber(std::vector<int>{1, 1, 2, 3, 4, 3, 4}), 2);
}

TEST(HappyNumber, main)
{
    EXPECT_EQ(algo::HappyNumber::happyNumber(19), true);
}

TEST(maxSubArray, main)
{
    EXPECT_EQ(algo::maxSubArray({-2, 1, 3, 4, 7, 2, 1, -5, 4}), 18);
    EXPECT_EQ(algo::maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 4}), 6);
    EXPECT_EQ(algo::maxSubArray({1}), 1);
    EXPECT_EQ(algo::maxSubArray({1, 2}), 3);
    EXPECT_EQ(algo::maxSubArray({-1, -2}), -1);
}

TEST(moveZeroes, main)
{
    std::vector<int> input{1, 0, 2, 3, 0, 1, 2, 0};
    algo::moveZeroes(input);
    EXPECT_THAT(input, ElementsAreArray({1, 2, 3, 1, 2, 0, 0, 0}));
    //    EXPECT_THAT(input, ElementsAreArray({1, 2, 3, 1, 2}));
    input = {0};
    algo::moveZeroes(input);
    EXPECT_THAT(input, ElementsAreArray({0}));
}
