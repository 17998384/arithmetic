//
//  unique_paths.c
//  arithmetic
//
//  62.不同路径
//
//  一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//
//  机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//
//  问总共有多少条不同的路径？
//
//
//  Created by 我叫城北徐公° on 2020/12/4.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>

int uniquePaths(int m, int n)
{
    //优化动态规划
    //dp
    int dp[n];
    for (int i = 0; i < n; i++) dp[i] = 1;
    //初始化边界
    for (int i = 1;i < m;i++)
        for (int j = 1;j < n;j++)
            dp[j] = dp[j - 1] + dp[j];
    return dp[n - 1];
}
