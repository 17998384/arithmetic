//
// Created by 我叫城北徐公° on 2022/2/14.
//

#include <iostream>
#include <vector>

//  260. 只出现一次的数字 III
//
//  给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
//
//
//
//  进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
//
//
//
//  示例 1：
//
//  输入：nums = [1,2,1,3,2,5]
//  输出：[3,5]
//  解释：[5, 3] 也是有效的答案。
//
//  示例 2：
//
//  输入：nums = [-1,0]
//  输出：[-1,0]
//
//  示例 3：
//
//  输入：nums = [0,1]
//  输出：[1,0]
//
//  提示：
//
//  2 <= nums.length <= 3 * 104
//  -231 <= nums[i] <= 231 - 1
//  除两个只出现一次的整数外，nums 中的其他数字都出现两次



using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        int tmp = nums[0];
        for (int i = 1, size = nums.size(); i < size; i++) tmp ^= nums[i];
        int find = 1;
        while ((tmp & find) == 0) find <<= 1;
        vector<int> v1, v2, res;
        res.resize(2);
        for (auto& n: nums) n & find ? v1.push_back(n) : v2.push_back(n);
        res[0] = v1[0], res[1] = v2[0];
        for (int i = 1, size = v1.size(); i < size; i++) res[0] ^= v1[i];
        for (int i = 1, size = v2.size(); i < size; i++) res[1] ^= v2[i];
        return res;
    }
};

//int main(void)
//{
//    Solution s;
//    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5};
//    vector<int> res = s.singleNumber(nums);
//    cout << res[0] << " , " << res[1] << endl;
//    return 0;
//}