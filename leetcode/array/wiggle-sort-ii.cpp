//
// Created by 我叫城北徐公° on 2022/6/28.
//

//  324. 摆动排序 II
//
//  给你一个整数数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。
//
//  你可以假设所有输入数组都可以得到满足题目要求的结果。
//
//
//
//  示例 1：
//
//  输入：nums = [1,5,1,1,6,4]
//  输出：[1,6,1,5,1,4]
//  解释：[1,4,1,5,1,6] 同样是符合题目要求的结果，可以被判题程序接受。
//
//  示例 2：
//
//  输入：nums = [1,3,2,2,3,1]
//  输出：[2,3,1,3,1,2]
//
//
//
//  提示：
//
//  1 <= nums.length <= 5 * 104
//  0 <= nums[i] <= 5000
//  题目数据保证，对于给定的输入 nums ，总能产生满足题目要求的结果
//
//
//
//          进阶：你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    void wiggleSort(vector<int>& nums)
    {
        priority_queue<int> heap;
        int size = nums.size();
        for (int& num: nums) heap.push(num);
        for (int i = 1; i < size && !heap.empty(); i += 2)
        {
            nums[i] = heap.top();
            heap.pop();
        }
        for (int i = 0; i < size && !heap.empty(); i += 2)
        {
            int top = heap.top();
            if (i + 1 < size && top < nums[i + 1])
            {
                nums[i] = top;
            }
            else
            {
                vector<int> tmp;
                while (!heap.empty())
                {
                    if (i + 1 < size && top < nums[i + 1])
                    {
                        nums[i] = top;
                        break;
                    }
                    else if (size % 2 != 0 && i == size - 1) nums[i] = top;
                    tmp.push_back(top);
                    heap.pop();
                }
                for (auto& num: tmp) heap.push(num);
            }
            heap.pop();
        }
    }
};

//int main(void)
//{
//    vector<int> v = {1, 4, 3, 4, 1, 2, 1, 3, 1, 3, 2, 3, 3};
//    Solution s;
//    s.wiggleSort(v);
//}