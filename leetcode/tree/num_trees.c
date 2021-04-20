//
//  num_trees.c
//  arithmetic
//
//  96.不同的二叉搜索树
//
//  给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
//
//  示例:
//
//  输入: 3
//  输出: 5
//  解释:
//  给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
//
//
//  Created by 我叫城北徐公° on 2020/12/1.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>

int numTrees(int n)
{
    int dp[20] = {0};
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum += dp[j] * dp[i - 1 - j];
        }
        dp[i] = sum;
    }
    return dp[n];
}

int main_numTrees(void)
{
    numTrees(20);
    return 0;
}
