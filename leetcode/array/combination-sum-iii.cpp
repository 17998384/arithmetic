//
// Created by 我叫城北徐公° on 2022/1/24.
//

//  216. 组合总和 III

//  找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
//
//  说明：
//
//  所有数字都是正整数。
//  解集不能包含重复的组合。
//
//  示例 1:
//
//  输入: k = 3, n = 7
//  输出: [[1,2,4]]
//
//  示例 2:
//
//  输入: k = 3, n = 9
//  输出: [[1,2,6], [1,3,5], [2,3,4]]


#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combination_sum_3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        int sum = 0;
        dfs(res, tmp, k, n, sum, 1);
        return res;
    }

private:

    void dfs(vector<vector<int>>& res, vector<int>& tmp, int k, int n, int& sum, int i)
    {
        if (sum == n && tmp.size() == k)
        {
            res.push_back(tmp);
            return;
        }
        if (tmp.size() > k) return;
        for (; i <= 9; i++)
        {
            tmp.push_back(i);
            sum += i;
            dfs(res, tmp, k, n, sum, i + 1);
            tmp.pop_back();
            sum -= i;
        }
    }
};