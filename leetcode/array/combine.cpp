//
// Created by 我叫城北徐公° on 2021/8/29.
//

//  77. 组合
//
//          给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
//
//  你可以按 任何顺序 返回答案。
//
//
//
//  示例 1：
//
//  输入：n = 4, k = 2
//  输出：
//  [
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//  ]
//
//  示例 2：
//
//  输入：n = 1, k = 1
//  输出：[[1]]
//
//
//
//  提示：
//
//  1 <= n <= 20
//  1 <= k <= n


#include <vector>

using namespace std;

class Solution
{
public:

    void recall(vector<vector<int>>& res, vector<int>& tmp, int i, int n, int k)
    {
        if (tmp.size() == k)
        {
            res.push_back(tmp);
            return;
        }
        for (; i <= n; i++)
        {
            //如果剩下的数字不够填充，则不需要进行了
            if ((k - tmp.size()) > (n + 1 - i)) continue;
            tmp.push_back(i);
            recall(res, tmp, i + 1, n, k);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        recall(res, tmp, 1, n, k);
        return res;
    }
};
