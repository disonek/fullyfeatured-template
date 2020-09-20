#pragma once
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>

namespace algo {

class FindLongestString
{
public:
    static int lengthOfLongestSubstring(std::string word)
    {
        std::set<int> res;

        for(unsigned int currentMainIndex = 0; currentMainIndex < word.size(); currentMainIndex++)
        {
            std::string buffer{};

            for(unsigned int bufferIndex = currentMainIndex; bufferIndex < word.size(); bufferIndex++)
            {
                auto findRes = buffer.find(word.at(bufferIndex));
                if(findRes == std::string::npos)
                {
                    buffer += word.at(bufferIndex);
                }
                else
                {
                    res.insert(buffer.size());
                    break;
                }
            }
            res.insert(buffer.size());
        }
        return *res.cend();
    }
};
} // namespace algo
