//
//  permute.c
//  arithmetic
//
//  46.全排列

//  给定一个 没有重复 数字的序列，返回其所有可能的全排列。
//
//  示例:
//
//  输入: [1,2,3]
//  输出:
//  [
//    [1,2,3],
//    [1,3,2],
//    [2,1,3],
//    [2,3,1],
//    [3,1,2],
//    [3,2,1]
//  ]

//  Created by 我叫城北徐公° on 2020/11/16.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

/*
    第一种解法
 */

//int* dp;
//
//int dp_size = 0;
//
//static int contains(int num)
//{
//    for (int i = 0; i < dp_size; i++)
//    {
//        if (dp[i] == num)
//            return 1;
//    }
//    return 0;
//}
//
//void dfs(int* nums, int numsSize,int** res,int* returnSize)
//{
//    if (dp_size == numsSize)
//    {
//        res[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
//        for (int i = 0; i < numsSize; i++)
//        {
//            res[*returnSize][i] = dp[i];
//        }
//        (*returnSize)++;
//        return;
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (contains(nums[i]))
//            continue;
//        dp[dp_size++] = nums[i];
//        dfs(nums, numsSize, res, returnSize);
//        dp[--dp_size] = -1;
//    }
//}
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
//{
//    int** res = (int**)malloc(sizeof(int*) * 100000);
//    dp = (int*)calloc(numsSize, sizeof(int));
//    for (int i = 0; i < numsSize; i++) dp[i] = -1;
//    *returnSize = 0;
//    dfs(nums, numsSize, res, returnSize);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * *returnSize);
//    for (int i = 0; i < *returnSize; i++)
//    {
//        (*returnColumnSizes)[i] = numsSize;
//    }
//    return res;
//}

/*
    第二种解法
 */


int* dp;

int* dp2;

int get_next(int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        if (!dp[i])
            return i;
    }
    return -1;
}

void dfs(int* nums, int numsSize,int** res,int* returnSize,int tier)
{
    
    int i = get_next(numsSize);
    if (i == -1)
    {
        res[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++)
        {
            res[*returnSize][i] = nums[dp2[i]];
        }
        (*returnSize)++;
        return;
    }
    for (; i < numsSize; i++)
    {
        if (dp[i] != 0)
            continue;
        dp[i] = 1;
        dp2[tier] = i;
        dfs(nums, numsSize, res, returnSize,tier + 1);
        dp[i] = 0;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int** res = (int**)malloc(sizeof(int*) * 100000);
    dp = (int*)calloc(numsSize, sizeof(int));
    dp2 = (int*)calloc(numsSize, sizeof(int));
    *returnSize = 0;
    int tier = 0;
    dfs(nums, numsSize, res, returnSize,tier);
    *returnColumnSizes = (int*)malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < *returnSize; i++)
    {
        (*returnColumnSizes)[i] = numsSize;
    }
    return res;
}



int main_permute(void)
{
    int arr[] = {1,2,3,4,5};
    int returnSize;
    int* returnColumnSizes;
    int** res = permute(arr, sizeof(arr) / sizeof(arr[0]), &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < sizeof(arr) / sizeof(arr[0]); j++)
        {
            printf("%d",res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
