//
// Created by 我叫城北徐公° on 2021/10/9.
//

//  152. 乘积最大子数组
//
//          给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
//
//
//
//  示例 1:
//
//  输入: [2,3,-2,4]
//  输出: 6
//  解释: 子数组 [2,3] 有最大乘积 6。
//
//  示例 2:
//
//  输入: [-2,0,-1]
//  输出: 0
//  解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。


#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int max = INT_MIN;
        int n = 1;
        for (auto& num: nums)
        {
            n *= num;
            max = std::max(max, n);
            if (num == 0) n = 1;
        }
        n = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int num = nums[i];
            n *= num;
            max = std::max(max, n);
            if (num == 0) n = 1;
        }
        return max;
    }
};