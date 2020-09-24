#pragma once

#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

namespace algo {

class SingleNumber
{
public:
    static int singleNumber(std::vector<int>&& nums)
    {
        std::set<int> firstBuffer;
        std::set<int> secondBuffer;

        for(auto& it : nums)
        {
            if(firstBuffer.cend() != firstBuffer.find(it))
                secondBuffer.insert(it);
            else
                firstBuffer.insert(it);
        }

        std::set<int> res;
        std::set_difference(firstBuffer.cbegin(),
                            firstBuffer.cend(),
                            secondBuffer.begin(),
                            secondBuffer.end(),
                            std::inserter(res, res.cbegin()));

        return *res.cbegin();
    }
};

class HappyNumber
{
public:
    static bool happyNumber(int n)
    {
        for(int trys = 0; trys < 100; trys++)
        {
            std::deque<int> separatedDigits;

            int i = n;
            while(i >= 9)
            {
                separatedDigits.push_front(i % 10);
                i /= 10;
            }
            separatedDigits.push_front(i);

            for(auto single : separatedDigits)
            {
                std::cout << single << std::endl;
            }

            std::deque<int> squaredDigits;
            std::transform(
                separatedDigits.cbegin(), separatedDigits.cend(), std::back_inserter(squaredDigits), [](int digit) {
                    return digit * digit;
                });

            for(auto single : squaredDigits)
            {
                std::cout << single << std::endl;
            }

            int sum = std::accumulate(squaredDigits.begin(), squaredDigits.end(), 0);
            if(sum == 1)
                return true;
            else
                n = sum;
        }

        return false;
    }
};

int maxSubArray(std::vector<int>&& nums)
{
    int max = nums.at(0);
    int thisPlaceEndSubarrayMax = nums.at(0);

    if(nums.size() == 1)
    {
        return thisPlaceEndSubarrayMax;
    }
    for(uint32_t i = 1; i < nums.size(); i++)
    {
        thisPlaceEndSubarrayMax = std::max(nums.at(i), nums.at(i) + thisPlaceEndSubarrayMax);
        max = std::max(max, thisPlaceEndSubarrayMax);
    }

    return max;
}

void moveZeroes(std::vector<int>& nums)
{
    int zeros{0};
    auto end_iter = std::remove_if(nums.begin(), nums.end(), [&zeros](int num) {
        if(num == 0)
        {
            zeros++;
            return true;
        }
        else
            return false;
    });

    nums = std::vector<int>{nums.begin(), end_iter};

    for(int i = 0; i < zeros; i++)
    {
        nums.push_back(0);
    }
}
} // namespace algo
