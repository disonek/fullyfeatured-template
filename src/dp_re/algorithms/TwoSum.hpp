#pragma once

#include <unordered_map>
#include <utility>
#include <vector>

namespace algo {

class TwoSum
{
public:
    std::pair<int, int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> vecToSet;
        for(uint32_t i = 0; i < nums.size(); i++)
        {
            vecToSet.insert({nums[i], i});
        }

        for(uint32_t i = 0; i < nums.size(); i++)
        {
            auto it = vecToSet.find(target - nums[i]);
            if(it != vecToSet.cend())
                if(it->second != static_cast<int>(i))
                {
                    return std::make_pair(i, it->second);
                }
        }

        return std::make_pair(0, 0);
    }
};
} // namespace algo
