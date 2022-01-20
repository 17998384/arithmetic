//
// Created by 我叫城北徐公° on 2021/10/22.
//

//  209. 长度最小的子数组
//
//          给定一个含有 n 个正整数的数组和一个正整数 target 。
//
//  找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
//
//
//
//  示例 1：
//
//  输入：target = 7, nums = [2,3,1,2,4,3]
//  输出：2
//  解释：子数组 [4,3] 是该条件下的长度最小的子数组。
//
//  示例 2：
//
//  输入：target = 4, nums = [1,4,4]
//  输出：1
//
//  示例 3：
//
//  输入：target = 11, nums = [1,1,1,1,1,1,1,1]
//  输出：0
//
//
//
//  提示：
//
//  1 <= target <= 109
//  1 <= nums.length <= 105
//  1 <= nums[i] <= 105
//
//
//
//  进阶：
//
//  如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。


#include <vector>
#include <iostream>
#include <list>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        list<int> list;
        int sum = 0;
        int minCount = INT_MAX;
        for (auto& num: nums)
        {
            if (sum >= target)
            {
                minCount = min((int) list.size(), minCount);
                while (list.size())
                {
                    sum -= list.front();
                    list.pop_front();
                    if (sum >= target) minCount = min((int) list.size(), minCount);
                    else break;
                }
            }
            list.push_back(num);
            sum += num;
        }
        while (list.size() && sum >= target)
        {
            minCount = min((int) list.size(), minCount);
            sum -= list.front();
            list.pop_front();
        }
        return minCount == INT_MAX ? 0 : minCount;
    }
};