//
// Created by 我叫城北徐公° on 2021/10/21.
//

//  189. 旋转数组
//
//          给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//
//
//
//  进阶：
//
//  尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
//  你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
//
//
//
//  示例 1:
//
//  输入: nums = [1,2,3,4,5,6,7], k = 3
//  输出: [5,6,7,1,2,3,4]
//  解释:
//  向右旋转 1 步: [7,1,2,3,4,5,6]
//  向右旋转 2 步: [6,7,1,2,3,4,5]
//  向右旋转 3 步: [5,6,7,1,2,3,4]
//
//  示例 2:
//
//  输入：nums = [-1,-100,3,99], k = 2
//  输出：[3,99,-1,-100]
//  解释:
//  向右旋转 1 步: [99,-1,-100,3]
//  向右旋转 2 步: [3,99,-1,-100]
//
//
//
//  提示：
//
//  1 <= nums.length <= 2 * 104
//  -231 <= nums[i] <= 231 - 1
//  0 <= k <= 105


#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        int start = 0;
        int startBak = 0;
        int cur = start;
        int count = 0;
        int next;
        int tmp = nums[cur];
        while (count < nums.size())
        {
            if (startBak != start)
            {
                cur = start;
                startBak = start;
                tmp = nums[start];
            }
            next = calc_next(cur + k, nums.size());
            if (next == start) start++;
            int innerTmp = tmp;
            tmp = nums[next];
            nums[next] = innerTmp;
            count++;
            cur = next;
        }
    }

private:

    int calc_next(int cur, int size)
    {
        if (cur < size) return cur;
        else return cur % size;
    }
};