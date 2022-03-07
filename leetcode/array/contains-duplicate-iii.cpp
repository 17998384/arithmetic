//
// Created by 我叫城北徐公° on 2022/1/25.
//

//  220. 存在重复元素 III

//  给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。
//
//  如果存在则返回 true，不存在返回 false。
//
//
//
//  示例 1：
//
//  输入：nums = [1,2,3,1], k = 3, t = 0
//  输出：true
//
//  示例 2：
//
//  输入：nums = [1,0,1,1], k = 1, t = 2
//  输出：true
//
//  示例 3：
//
//  输入：nums = [1,5,9,1,5,9], k = 2, t = 3
//  输出：false
//
//
//
//  提示：
//
//  0 <= nums.length <= 2 * 104
//  -231 <= nums[i] <= 231 - 1
//  0 <= k <= 104
//  0 <= t <= 231 - 1


#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        set<long> s;
        for (int i = 0, size = nums.size(); i < size; ++i)
        {
            //假设t = 2，num[j] = 3 ,那么1 <= nums[i] <= 5才符合条件，所以
            //假如nums[i] < nums[j]时，需要nums[j] - nums[i] >= t才符合条件，否则nums[i] - nums[j] <=t才可以
            int b = nums[i];
            //假设a比b小,即nums[i] < nums[j]时，需要nums[j] - nums[i] >= t，而我们要寻找a，则推导出b - t >=a，找出>=b - t的最小值
            auto a = s.lower_bound((long) b - t);
            //如果a比b大，即nums[i] > nums[j]时，需要nums[i] - nums[j] <= t，所以还需要再判断一步才可以
            //正好满足了我们所说的，假设t = 2，num[j] = 3 ,那么1 <= nums[i] <= 5才符合条件
            if (a != s.end() && (*a - b <= t)) return true;
            s.insert(b);
            if (s.size() > k) s.erase(nums[i - k]);
        }
        return false;
    }
};

//int main(void)
//{
//    /*
//     * [1,2,5,6,7,2,4]
//       4
//       0
//       [4,3,2,1,1,6,7,8]
//     */
//    /*
//     * [1,0,1,1]
//     * 1
//     * 2
//     */
//    vector<int> nums = {1, 0, 1, 1};
////    vector<int> nums = {1};
//    Solution s;
//    bool res = s.containsNearbyAlmostDuplicate(nums, 1, 2);
//    cout << res << endl;
//    return 0;
//}