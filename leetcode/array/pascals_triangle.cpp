//
// Created by 我叫城北徐公° on 2021/9/13.
//

//  118. 杨辉三角
//
//          给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
//
//  在「杨辉三角」中，每个数是它左上方和右上方的数的和。
//
//
//
//  示例 1:
//
//  输入: numRows = 5
//  输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
//
//  示例 2:
//
//  输入: numRows = 1
//  输出: [[1]]
//
//
//
//  提示:
//
//  1 <= numRows <= 30



#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res(numRows);
        for (int i = 1; i <= numRows; ++i)
        {
            vector<int> tmp(i);
            for (int j = 0; j < i; j++)
            {
                if (i <= 2)
                {
                    tmp[j] = 1;
                    continue;
                }
                vector<int>& prev = res[i - 2];
                if (j - 1 >= 0 && prev.size() > j) tmp[j] = prev[j - 1] + prev[j];
                else tmp[j] = 1;
            }
            res[i - 1] = tmp;
        }
        return res;
    }
};
