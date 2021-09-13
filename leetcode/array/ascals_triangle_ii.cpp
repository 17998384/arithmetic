//
// Created by 我叫城北徐公° on 2021/9/13.
//

//  119. 杨辉三角 II
//
//  给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
//
//  在「杨辉三角」中，每个数是它左上方和右上方的数的和。
//
//
//
//  示例 1:
//
//  输入: rowIndex = 3
//  输出: [1,3,3,1]
//
//  示例 2:
//
//  输入: rowIndex = 0
//  输出: [1]
//
//  示例 3:
//
//  输入: rowIndex = 1
//  输出: [1,1]
//
//
//
//  提示:
//
//  0 <= rowIndex <= 33
//
//
//
//  进阶：
//
//  你可以优化你的算法到 O(rowIndex) 空间复杂度吗？


#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getRow(int numRows)
    {
        numRows++;
        vector<int> res(numRows);
        for (int i = 1; i <= numRows; ++i)
        {
            int tmp = -1;
            for (int j = 0; j < i; j++)
            {
                if (i <= 2)
                {
                    res[j] = 1;
                    continue;
                }
                if (j > 0 && j < i - 1)
                {
                    if (tmp != -1)
                    {
                        int _tmp = res[j];
                        res[j] = tmp + res[j];
                        tmp = _tmp;
                    }
                    else
                    {
                        tmp = res[j];
                        res[j] = res[j - 1] + res[j];
                    }
                }
                else res[j] = 1;
            }
        }
        return res;
    }
};
