//
// Created by 我叫城北徐公° on 2022/1/27.
//

//  238. 除自身以外数组的乘积
//
//          给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
//
//
//
//  示例:
//
//  输入: [1,2,3,4]
//  输出: [24,12,8,6]
//
//
//
//  提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
//
//  说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
//
//  进阶：
//  你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）


#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> buffer1;
        vector<int> buffer2;
        vector<int> res;
        int size = nums.size();
        buffer1.resize(size);
        buffer2.resize(size);
        res.resize(size);
        for (int i = 0; i < size; i++)
        {
            if (i == 0 || i == size - 1)
            {
                buffer1[0] = nums[0];
                buffer2[size - 1] = nums[size - 1];
            }
            else
            {
                buffer1[i] = nums[i] * buffer1[i - 1];
                buffer2[size - 1 - i] = nums[size - 1 - i] * buffer2[size - i];
            }
        }
        res[0] = buffer2[1];
        res[size - 1] = buffer1[size - 2];
        for (int i = 1; i < size - 1; i++)
        {
            res[i] = buffer1[i - 1] * buffer2[i + 1];
        }
        return res;
    }
};

//int main(void)
//{
//    vector<int> nums = {1, 2, 3, 4};
//    Solution s;
//    vector<int> res = s.productExceptSelf(nums);
//    for (auto& num: res)
//    {
//        cout << num << endl;
//    }
//    return 0;
//}
