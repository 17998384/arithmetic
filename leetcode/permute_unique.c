//
//  permute_unique.c
//  arithmetic
//
//  47.全排列 II

//  给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
//
//
//
//  示例 1：
//
//  输入：nums = [1,1,2]
//  输出：
//  [[1,1,2],
//   [1,2,1],
//   [2,1,1]]
//
//  示例 2：
//
//  输入：nums = [1,2,3]
//  输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//
//
//
//  提示：
//
//      1 <= nums.length <= 8
//      -10 <= nums[i] <= 10


//  Created by 我叫城北徐公° on 2020/11/17.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int* dp;

static int dp_size = 0;

static int* dp2;

static int compare(void* a,void* b)
{
    return *((int*)a) - *((int*)b);
}

static void dfs(int* nums, int numsSize,int** res,int* returnSize)
{
    if (dp_size == numsSize)
    {
        res[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
        memcpy(res[(*returnSize)++], dp, sizeof(int) * numsSize);
        return;
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (dp2[i])
            continue;
        if (i > 0 && nums[i] == nums[i - 1] && !dp2[i - 1])
            continue;
        dp[dp_size++] = nums[i];
        dp2[i] = 1;
        dfs(nums, numsSize, res, returnSize);
        dp[--dp_size] = -1;
        dp2[i] = 0;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), compare);
    int** res = (int**)malloc(sizeof(int*) * 100000);
    dp = (int*)calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++) dp[i] = -1;
    dp2 = (int*)calloc(numsSize, sizeof(int));
    *returnSize = 0;
    dfs(nums, numsSize, res, returnSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < *returnSize; i++)
    {
        (*returnColumnSizes)[i] = numsSize;
    }
    free(dp);
    free(dp2);
    return res;
}

int main_permuteUnique(void)
{
    int arr[] = {0,1,0,0,9};
    int returnSize;
    int* returnColumnSizes;
    int** res = permuteUnique(arr, sizeof(arr) / sizeof(arr[0]), &returnSize, &returnColumnSizes);
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
