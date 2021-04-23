//
// Created by 我叫城北徐公° on 2021/4/23.
//

//  54. 螺旋矩阵
//
//  给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
//
//
//
//  示例 1：
//
//  输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//  输出：[1,2,3,6,9,8,7,4,5]
//
//  示例 2：
//
//  输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//  输出：[1,2,3,4,8,12,11,10,9,5,6,7]
//
//
//
//  提示：
//
//  m == matrix.length
//          n == matrix[i].length
//  1 <= m, n <= 10
//  -100 <= matrix[i][j] <= 100
//
#include <stdio.h>
#include <stdlib.h>

static void fill(int* res, int* resIdx, int** matrix, int rowS, int rowE, int colS, int colE)
{
    //四层填充
    for (int i = colS; i <= colE; i++) res[(*resIdx)++] = matrix[rowS][i];
    for (int i = rowS + 1; i <= rowE - 1; i++) res[(*resIdx)++] = matrix[i][colE];
    for (int i = colE; i >= colS && rowS != rowE; i--) res[(*resIdx)++] = matrix[rowE][i];
    for (int i = rowE - 1; i >= rowS + 1 && colS != colE; i--) res[(*resIdx)++] = matrix[i][colS];
}

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    *returnSize = 0;
    if (!matrixSize) return NULL;
    int colSize = matrixColSize[0];
    int* res = malloc(matrixSize * colSize * sizeof(int*));
    int rowS = 0, rowE = matrixSize - 1, colS = 0, colE = colSize - 1;
    while ((rowS <= rowE) && (colS <= colE))
    {
        fill(res, returnSize, matrix, rowS, rowE, colS, colE);
        rowS++;
        colS++;
        rowE--;
        colE--;
    }
    return res;
}