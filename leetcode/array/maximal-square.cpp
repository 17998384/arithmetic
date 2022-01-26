//
// Created by 我叫城北徐公° on 2022/1/26.
//

//  221. 最大正方形

//  在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。

//
//
//  示例 1：
//
//  输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
//  输出：4
//
//  示例 2：
//
//  输入：matrix = [["0","1"],["1","0"]]
//  输出：1
//
//  示例 3：
//
//  输入：matrix = [["0"]]
//          输出：0
//
//
//
//  提示：
//
//  m == matrix.length
//          n == matrix[i].length
//  1 <= m, n <= 300
//  matrix[i][j] 为 '0' 或 '1'

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int size = matrix.size();
        short** dp = new short* [size];
        short max = 0;
        for (int i = 0, colSize = matrix[0].size(); i < size; i++)
        {
            dp[i] = new short[colSize]();
            if (i == 0)
            {
                for (int j = 0; j < colSize; j++)
                {
                    if (matrix[i][j] != '0')
                    {
                        dp[0][j] = 1;
                        max = 1;
                    }
                    else dp[0][j] = 0;
                }
            }
            else
            {
                if (matrix[i][0] != '0')
                {
                    dp[i][0] = 1;
                    max = 1;
                }
                else dp[i][0] = 0;
            }
        }
        for (int i = 1, colSize = matrix[0].size(); i < size; i++)
        {
            for (int j = 1; j < colSize; j++)
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = (short) (min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1);
                    max = std::max(max, dp[i][j]);
                }
            }
        }
        for (int i = 0; i < size; i++) delete[] dp[i];
        delete[] dp;
        return max * max;
    }
};

//int main(void)
//{
//    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
//                                   {'1', '0', '1', '1', '1'},
//                                   {'1', '1', '1', '1', '1'},
//                                   {'1', '0', '1', '1', '0'}};
//    Solution s;
//    int maxArea = s.maximalSquare(matrix);
//    cout << maxArea << endl;
//    return 0;
//}