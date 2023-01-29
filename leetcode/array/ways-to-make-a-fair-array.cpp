//
// Created by 我叫城北徐公° on 2023/1/28.
//

//  1664. 生成平衡数组的方案数

//  给你一个整数数组nums。你需要选择 恰好一个下标（下标从 0开始）并删除对应的元素。请注意剩下元素的下标可能会因为删除操作而发生改变。
//
//  比方说，如果nums = [6,1,7,4,1]，那么：
//
//  选择删除下标 1 ，剩下的数组为nums = [6,7,4,1]。
//  选择删除下标2，剩下的数组为nums = [6,1,4,1]。
//  选择删除下标4，剩下的数组为nums = [6,1,7,4]。
//
//  如果一个数组满足奇数下标元素的和与偶数下标元素的和相等，该数组就是一个 平衡数组 。
//
//  请你返回删除操作后，剩下的数组nums是平衡数组 的方案数。
//
//
//
//  示例 1：
//
//  输入：nums = [2,1,6,4]
//  输出：1
//  解释：
//  删除下标 0 ：[1,6,4] -> 偶数元素下标为：1 + 4 = 5 。奇数元素下标为：6 。不平衡。
//  删除下标 1 ：[2,6,4] -> 偶数元素下标为：2 + 4 = 6 。奇数元素下标为：6 。平衡。
//  删除下标 2 ：[2,1,4] -> 偶数元素下标为：2 + 4 = 6 。奇数元素下标为：1 。不平衡。
//  删除下标 3 ：[2,1,6] -> 偶数元素下标为：2 + 6 = 8 。奇数元素下标为：1 。不平衡。
//  只有一种让剩余数组成为平衡数组的方案。
//
//  示例 2：
//
//  输入：nums = [1,1,1]
//  输出：3
//  解释：你可以删除任意元素，剩余数组都是平衡数组。
//
//  示例 3：
//
//  输入：nums = [1,2,3]
//  输出：0
//  解释：不管删除哪个元素，剩下数组都不是平衡数组。
//
//
//
//  提示：
//
//  1 <= nums.length <= 105
//  1 <= nums[i] <= 104

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int waysToMakeFair(vector<int> &nums)
    {
        int size = nums.size();
        int res = 0;
        vector<long> evenNumberPrefixSum((size + 1) / 2);
        vector<long> oddNumberPrefixSum(size / 2);
        if (!evenNumberPrefixSum.empty()) evenNumberPrefixSum[0] = nums[0];
        if (!oddNumberPrefixSum.empty()) oddNumberPrefixSum[0] = nums[1];
        for (int i = 2; i < size; i++)
        {
            int idx = i / 2;
            if (i % 2 == 0) evenNumberPrefixSum[idx] = evenNumberPrefixSum[idx - 1] + nums[i];
            else oddNumberPrefixSum[idx] = oddNumberPrefixSum[idx - 1] + nums[i];
        }
        for (int i = 0; i < size; i++)
        {
            int idx = i / 2;
            long evenNumberSum;
            long oddNumberSum = get_valid_index_prefix_sum(oddNumberPrefixSum, idx - 1) +
                                get_valid_index_prefix_sum(evenNumberPrefixSum, evenNumberPrefixSum.size() - 1) -
                                evenNumberPrefixSum[idx];
            if (i % 2 != 0)
                evenNumberSum = evenNumberPrefixSum[idx] +
                                get_valid_index_prefix_sum(oddNumberPrefixSum, oddNumberPrefixSum.size() - 1) -
                                oddNumberPrefixSum[idx];
            else
                evenNumberSum = get_valid_index_prefix_sum(evenNumberPrefixSum, idx - 1) +
                                get_valid_index_prefix_sum(oddNumberPrefixSum, oddNumberPrefixSum.size() - 1) -
                                get_valid_index_prefix_sum(oddNumberPrefixSum, idx - 1);
            if (evenNumberSum == oddNumberSum) res++;
        }
        return res;
    }

private:
    long get_valid_index_prefix_sum(vector<long> &prefixSum, int idx)
    {
        if (idx >= prefixSum.size() || idx < 0) return 0;
        return prefixSum[idx];
    }

};

//int main(void)
//{
//    Solution s;
//    vector<int> nums = {2};
//    int res = s.waysToMakeFair(nums);
//    cout << res << endl;
//    return 0;
//}