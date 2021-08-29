//
// Created by 我叫城北徐公° on 2021/8/29.
//

//  78. 子集
//
//          给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
//
//  解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
//
//
//
//  示例 1：
//
//  输入：nums = [1,2,3]
//  输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
//
//  示例 2：
//
//  输入：nums = [0]
//  输出：[[],[0]]
//
//
//
//  提示：
//
//  1 <= nums.length <= 10
//  -10 <= nums[i] <= 10
//  nums 中的所有元素 互不相同



#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        recall(res, tmp, nums, 0);
        return res;
    }

private:

    void recall(vector<vector<int>>& res, vector<int> tmp, vector<int>& nums, int i)
    {
        res.push_back(tmp);
        for (int size = nums.size(); i < size; i++)
        {
            tmp.push_back(nums[i]);
            recall(res, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }
};

int main_subsets(void)
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> res = s.subsets(nums);
    for (auto& v : res)
    {
        for (auto& num : v) cout << num << " ";
        cout << endl;
    }
    return 0;
}