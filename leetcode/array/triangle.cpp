//
// Created by 我叫城北徐公° on 2021/9/13.
//

//  120. 三角形最小路径和
//
//          给定一个三角形 triangle ，找出自顶向下的最小路径和。
//
//  每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
//
//
//
//  示例 1：
//
//  输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
//  输出：11
//  解释：如下面简图所示：
//  2
//  3 4
//  6 5 7
//  4 1 8 3
//  自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
//
//  示例 2：
//
//  输入：triangle = [[-10]]
//          输出：-10
//
//
//
//  提示：
//
//  1 <= triangle.length <= 200
//  triangle[0].length == 1
//  triangle[i].length == triangle[i - 1].length + 1
//  -104 <= triangle[i][j] <= 104
//
//
//
//  进阶：
//
//  你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题吗？


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        unordered_map<string, int> map;
        int res = dfs(triangle, 0, 0, map);
        return res;
    }

private:

    int dfs(vector<vector<int>>& triangle, int depth, int idx, unordered_map<string, int>& map)
    {
        if (depth == triangle.size() - 1) return triangle[depth][idx];
        string key = to_string(depth) + "_" + to_string(idx);
        if (map.find(key) != map.end()) return map[key];
        int left = dfs(triangle, depth + 1, idx, map);
        int right = dfs(triangle, depth + 1, idx + 1, map);
        int min = std::min(triangle[depth][idx] + left, triangle[depth][idx] + right);
        map[key] = min;
        return min;
    }
};
