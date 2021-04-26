//
// Created by 我叫城北徐公° on 2021/4/26.
//

//  59. 螺旋矩阵 II

//  给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
//
//
//
//  示例 1：
//
//  输入：n = 3
//  输出：[[1,2,3],[8,9,4],[7,6,5]]
//
//  示例 2：
//
//  输入：n = 1
//  输出：[[1]]
//
//
//
//  提示：
//
//  1 <= n <= 20


#include <stdio.h>
#include <stdlib.h>

static void fill(int* resIdx, int** res, int rowS, int rowE, int colS, int colE)
{
    //四层填充
    for (int i = colS; i <= colE; i++) res[rowS][i] = (*resIdx)++;
    for (int i = rowS + 1; i <= rowE - 1; i++) res[i][colE] = (*resIdx)++;
    for (int i = colE; i >= colS && rowS != rowE; i--) res[rowE][i] = (*resIdx)++;
    for (int i = rowE - 1; i >= rowS + 1 && colS != colE; i--) res[i][colS] = (*resIdx)++;
}

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    if (!n) return NULL;
    *returnSize = 1;
    int** res = malloc(n * sizeof(int*));
    *returnColumnSizes = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        res[i] = malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    int rowS = 0, rowE = n - 1, colS = 0, colE = n - 1;
    while ((rowS <= rowE) && (colS <= colE))
    {
        fill(returnSize, res, rowS, rowE, colS, colE);
        rowS++;
        colS++;
        rowE--;
        colE--;
    }
    *returnSize = n;
    return res;
}