//
// Created by 我叫城北徐公° on 2021/8/29.
//

//  73. 矩阵置零
//
//          给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
//
//  进阶：
//
//  一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
//  一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
//  你能想出一个仅使用常量空间的解决方案吗？
//
//
//
//  示例 1：
//
//  输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
//  输出：[[1,0,1],[0,0,0],[1,0,1]]
//
//  示例 2：
//
//  输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
//  输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
//
//
//
//  提示：
//
//  m == matrix.length
//          n == matrix[0].length
//  1 <= m, n <= 200
//  -231 <= matrix[i][j] <= 231 - 1



#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        if (!matrix.size()) return;
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        bool row, col;
        row = col = false;
        //判断0行与0列是否为0
        for (auto &n: matrix[0]) if (!n) col = true;
        for (int i = 0; i < rowSize; i++) if (!matrix[i][0]) row = true;

        for (int i = 1; i < rowSize; i++)
        {
            for (int j = 1; j < colSize; j++)
            {
                if (!matrix[i][j])
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int n = 1; n < colSize; n++)
        {
            if (!matrix[0][n]) for (int i = 1; i < rowSize; i++) matrix[i][n] = 0;
        }
        for (int m = 1; m < rowSize; m++)
        {
            if (!matrix[m][0]) for (int i = 1; i < colSize; i++) matrix[m][i] = 0;
        }

        if (row) for (int i = 0; i < rowSize; i++) matrix[i][0] = 0;
        if (col) for (int i = 0; i < colSize; i++) matrix[0][i] = 0;
    }
};
