#include <gtest/gtest.h>
#include <algorithm>
#include <deque>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace testing;
class StandardTest : public ::testing::Test
{
public:
};

TEST(StandardTest, all_of)
{
    auto lamb = [](int singleElement) { return singleElement % 2; };
    std::unordered_set<int> inputTrue{1, 3, 5, 7};
    EXPECT_TRUE(std::all_of(inputTrue.cbegin(), inputTrue.cend(), lamb));
    std::unordered_set<int> inputFalse{1, 3, 5, 7, 2};
    EXPECT_FALSE(std::all_of(inputFalse.cbegin(), inputFalse.cend(), lamb));
}

TEST(StandardTest, any_of)
{
    auto lamb = [](int singleElement) { return singleElement % 2; };
    std::unordered_set<int> inputTrue{2, 4, 5, 8};
    EXPECT_TRUE(std::any_of(inputTrue.cbegin(), inputTrue.cend(), lamb));
    std::unordered_set<int> inputFalse{4, 6, 8, 10, 2};
    EXPECT_FALSE(std::any_of(inputFalse.cbegin(), inputFalse.cend(), lamb));
}

TEST(StandardTest, none_of)
{
    std::string inputTrue{"Ala ma kota"};

    EXPECT_TRUE(
        std::none_of(inputTrue.cbegin(), inputTrue.cend(), [](int singleElement) { return singleElement == 'q'; }));
    EXPECT_FALSE(
        std::none_of(inputTrue.cbegin(), inputTrue.cend(), [](char singleElement) { return singleElement == 'l'; }));
}

TEST(StandardTest, for_each)
{
    std::unordered_map<std::string, char> umap{{"Ala ma kota", 'k'}, {"Ala ma psa", 'p'}};

    std::deque<std::string> result;
    std::for_each(umap.cbegin(), umap.cend(), [&result](std::pair<std::string, char> pair) {
        result.emplace_back(std::string{pair.second} + "->" + pair.first);
    });
    EXPECT_TRUE(std::all_of(
        result.cbegin(), result.cend(), [](std::string s) { return s == "p->Ala ma psa" || s == "k->Ala ma kota"; }));
}

TEST(StandardTest, for_each_n)
{
    //NEXT TO DO
}


TEST(StandardTest, count_and_count_if)
{
    std::string input{"count_and_count_if"};
    auto result = std::count(input.cbegin(), input.cend(), 'a');
    EXPECT_EQ(result, 1);
    result = std::count_if(input.cbegin(), input.cend(), [](char elem){return elem == '_';});
    EXPECT_EQ(result, 3);
}
