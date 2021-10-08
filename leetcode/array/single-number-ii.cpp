//
// Created by 我叫城北徐公° on 2021/9/27.
//

//  137. 只出现一次的数字 II
//
//  给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
//
//
//
//  示例 1：
//
//  输入：nums = [2,2,3,2]
//  输出：3
//
//  示例 2：
//
//  输入：nums = [0,1,0,1,0,1,99]
//  输出：99
//
//
//
//  提示：
//
//  1 <= nums.length <= 3 * 104
//  -231 <= nums[i] <= 231 - 1
//  nums 中，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        unordered_map<int, short> count;
        for (auto& n: nums)
        {
            auto finder = count.find(n);
            if (finder != count.end()) finder->second++;
            else count[n] = 1;
        }

        for (auto& pair: count)
        {
            if (pair.second == 1) return pair.first;
        }
        return -1;
    }
};
