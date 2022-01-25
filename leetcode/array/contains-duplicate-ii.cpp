//
// Created by 我叫城北徐公° on 2022/1/24.
//

//  219. 存在重复元素 II

//  给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。
//
//
//
//  示例 1：
//
//  输入：nums = [1,2,3,1], k = 3
//  输出：true
//
//  示例 2：
//
//  输入：nums = [1,0,1,1], k = 1
//  输出：true
//
//  示例 3：
//
//  输入：nums = [1,2,3,1,2,3], k = 2
//  输出：false
//
//
//
//
//
//  提示：
//
//  1 <= nums.length <= 105
//  -109 <= nums[i] <= 109
//  0 <= k <= 105


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int, pair<int, int>> lowHigh;
        for (int i = 0, size = nums.size(); i < size; i++)
        {
            unordered_map<int, pair<int, int>>::iterator entry;
            if ((entry = lowHigh.find(nums[i])) != lowHigh.end())
            {
                auto& pair = entry->second;
                pair.first = pair.second;
                pair.second = i;
                if (abs(pair.second - pair.first) <= k) return true;
            }
            else lowHigh[nums[i]] = pair<int, int>(i, i);
        }
        return false;
    }
};