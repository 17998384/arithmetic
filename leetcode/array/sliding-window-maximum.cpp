//
// Created by 我叫城北徐公° on 2022/1/27.
//

#include <iostream>
#include <vector>
#include <queue>

//  239. 滑动窗口最大值
//
//          给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
//
//  返回 滑动窗口中的最大值 。
//
//
//
//  示例 1：
//
//  输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
//  输出：[3,3,5,5,6,7]
//  解释：
//  滑动窗口的位置                最大值
//  ---------------               -----
//  [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
//
//  示例 2：
//
//  输入：nums = [1], k = 1
//  输出：[1]
//
//
//
//  提示：
//
//  1 <= nums.length <= 105
//  -104 <= nums[i] <= 104
//  1 <= k <= nums.length



using namespace std;

template<class T>
class Cmp
{
public:

    bool operator()(T o1, T o2)
    {
        return o1->first < o2->first;
    }

};

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        /*
         * [9,10,9,-7,-4,-8,2,-6]
         * 5
         *
         */
        vector<int> res;
        vector<pair<int, bool>*> buffer;
        buffer.resize(nums.size());
        priority_queue<pair<int, bool>*, vector<pair<int, bool>*>, Cmp<pair<int, bool>*>> q;
        for (int i = 0, size = nums.size(); i < size; i++)
        {
            auto p = new pair<int, bool>(nums[i], true);
            buffer[i] = p;
            q.push(p);
            if (i >= k - 1)
            {
                while (!q.empty())
                {
                    p = q.top();
                    if (!p->second)
                    {
                        q.pop();
                        continue;
                    }
                    else
                    {
                        res.push_back(p->first);
                        break;
                    }
                }
                buffer[i + 1 - k]->second = false;
            }
        }
        for (auto& p: buffer) delete p;
        return res;
    }
};

//int main(void)
//{
//    vector<int> nums = {1};
//    Solution s;
//    vector<int> res = s.maxSlidingWindow(nums, 1);
//    for (auto& num: res) cout << num << endl;
//    return 0;
//}