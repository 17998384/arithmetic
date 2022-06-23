//
// Created by 我叫城北徐公° on 2022/4/1.
//

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        bitset<100001> bitset;
        for (const auto &item : nums)
        {
            if (bitset.test(item)) return item;
            bitset.set(item, true);
        }
        return 0;
    }
};
