//
// Created by 我叫城北徐公° on 2022/1/27.
//

//  229. 求众数 II
//
//  给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
//
//
//
//
//
//  示例 1：
//
//  输入：[3,2,3]
//  输出：[3]
//
//  示例 2：
//
//  输入：nums = [1]
//  输出：[1]
//
//  示例 3：
//
//  输入：[1,1,1,3,3,2,2,2]
//  输出：[1,2]
//
//
//
//  提示：
//
//  1 <= nums.length <= 5 * 104
//  -109 <= nums[i] <= 109
//
//
//
//  进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//map法
//class Solution
//{
//public:
//    vector<int> majorityElement(vector<int>& nums)
//    {
//        unordered_map<int, int> map;
//        vector<int> res;
//        int threshold = nums.size() / 3;
//        for (auto& num: nums)
//        {
//            auto iter = map.find(num);
//            if (iter != map.end()) ++iter->second;
//            else map.insert(pair<int, int>(num, 1));
//        }
//        for (auto& iter: map)
//        {
//            if (iter.second > threshold) res.push_back(iter.first);
//        }
//        return res;
//    }
//};

//摩尔投票法
class Solution
{
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        vector<int> res;
        int num1, num2, count1, count2;
        num1 = num2 = count1 = count2 = 0;
        for (auto& num: nums)
        {
            if (num == num1)
            {
                count1++;
                continue;
            }
            if (num == num2)
            {
                count2++;
                continue;
            }
            if (count1 == 0)
            {
                num1 = num;
                count1 = 1;
                continue;
            }
            if (count2 == 0)
            {
                num2 = num;
                count2 = 1;
                continue;
            }
            count1--;
            count2--;
        }

        count1 = count2 = 0;
        for (auto& num: nums)
        {
            if (num == num1) count1++;
            else if (num == num2) count2++;
        }
        if (count1 > nums.size() / 3) res.push_back(num1);
        if (count2 > nums.size() / 3) res.push_back(num2);
        return res;
    }
};


//int main(void)
//{
//    vector<int> nums = {1, 2, 3, 4, 5};
//    Solution s;
//    vector<int> res = s.majorityElement(nums);
//    for (auto& n: res)
//    {
//        cout << n << endl;
//    }
//    return 0;
//}