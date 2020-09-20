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
        for(auto i = 0; i < static_cast<int>(nums.size()); i++)
        {
            vecToSet.insert({static_cast<int>(nums[i]), i});
        }

        for(auto i = 0; i < static_cast<int>(nums.size()); i++)
        {
            auto it = vecToSet.find(target - nums[i]);
            if(it != vecToSet.cend())
                if(it->second != i)
                {
                    return std::make_pair(i, it->second);
                }
        }

        return std::make_pair(0, 0);
    }
};
}
