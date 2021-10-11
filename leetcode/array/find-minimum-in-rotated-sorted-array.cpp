//
// Created by 我叫城北徐公° on 2021/10/9.
//

//  153. 寻找旋转排序数组中的最小值
//          已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
//
//  若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
//  若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
//
//  注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。
//
//  给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
//
//
//
//  示例 1：
//
//  输入：nums = [3,4,5,1,2]
//  输出：1
//  解释：原数组为 [1,2,3,4,5] ，旋转 3 次得到输入数组。
//
//  示例 2：
//
//  输入：nums = [4,5,6,7,0,1,2]
//  输出：0
//  解释：原数组为 [0,1,2,4,5,6,7] ，旋转 4 次得到输入数组。
//
//  示例 3：
//
//  输入：nums = [11,13,15,17]
//  输出：11
//  解释：原数组为 [11,13,15,17] ，旋转 4 次得到输入数组。
//
//
//
//  提示：
//
//  n == nums.length
//  1 <= n <= 5000
//  -5000 <= nums[i] <= 5000
//  nums 中的所有整数 互不相同
//          nums 原来是一个升序排序的数组，并进行了 1 至 n 次旋转


#include <iostream>
#include <vector>

using namespace std;

//class Solution
//{
//public:
//    int findMin(vector<int>& nums)
//    {
//        if (nums.size() == 1) return nums[0];
//        if (nums[0] < nums[nums.size() - 1]) return nums[0];
//        for (int i = nums.size() - 1; i >= 1; i--)
//        {
//            if (nums[i] < nums[i - 1]) return nums[i];
//        }
//        return nums[0];
//    }
//};

class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        return binary_search(0, nums.size() - 1, nums);
    }

private:

    int binary_search(int low, int high, vector<int>& nums)
    {
        if (low == high) return nums[low];
        int half = (low + high) / 2;
        if (nums[half] > nums[high]) return binary_search(half + 1, high, nums);
        else return binary_search(low, half, nums);
    }
};