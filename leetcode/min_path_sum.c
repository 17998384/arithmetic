//
//  min_path_sum.c
//  arithmetic
//
//  64. 最小路径和
//
//  给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//
//  说明：每次只能向下或者向右移动一步。
//
//  Created by 我叫城北徐公° on 2020/12/4.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>

int minPathSum(int** grid, int gridSize, int* gridColSize)
{
    int height = gridSize;
    int width = gridColSize[0];
    for (int i = 1;i < height;i++) grid[i][0] += grid[i - 1][0];
    for (int j = 1;j < width;j++) grid[0][j] += grid[0][j - 1];
    for (int i = 1;i < height;i++)
        for (int j = 1;j < width;j++)
        {
            int a = grid[i - 1][j],b = grid[i][j - 1];
            grid[i][j] += a > b ? b : a;
        }
    return grid[height - 1][width - 1];
}
