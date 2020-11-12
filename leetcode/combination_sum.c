//
//  combination_sum.c
//  arithmetic
//
//  39.组合总和

//  给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//  candidates 中的数字可以无限制重复被选取。
//
//  说明：
//
//      所有数字（包括 target）都是正整数。
//      解集不能包含重复的组合。
//
//  示例 1：
//
//  输入：candidates = [2,3,6,7], target = 7,
//  所求解集为：
//  [
//    [7],
//    [2,2,3]
//  ]
//
//  示例 2：
//
//  输入：candidates = [2,3,5], target = 8,
//  所求解集为：
//  [
//    [2,2,2,2],
//    [2,3,3],
//    [3,5]
//  ]

//  Created by 我叫城北徐公° on 2020/11/2.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buffer[30];
int buffer_p = 0;
int sum = 0;

static void DFS(int* candidates,int candidatesSize, int target, int* returnSize, int* returnColumnSizes,
                int** returnArr,int index)
{
    if (sum > target || index >= candidatesSize)
        return;
    if (sum == target)
    {
        int size = *returnSize;
        returnArr[size] = (int*)malloc(sizeof(int) * buffer_p);
        memcpy(returnArr[size], buffer, sizeof(int) * buffer_p);
        returnColumnSizes[size] = buffer_p;
        (*returnSize)++;
        return;
    }
    for (; index < candidatesSize; index++)
    {
        //如果第N层为当前本身，则continue
        if (candidates[index] == target && sum != 0)
            continue;
        if ((candidates[index] == candidates[index - 1]) && sum == 0)
            continue;
        sum += candidates[index];
        buffer[buffer_p++] = candidates[index];
        DFS(candidates, candidatesSize, target, returnSize, returnColumnSizes, returnArr, index);
        sum -= candidates[index];
        buffer_p--;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    int** returnArr = (int**)malloc(sizeof(int*) * 300);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 300);
    DFS(candidates,candidatesSize,target,returnSize,*returnColumnSizes,returnArr,0);
    return returnArr;
}

int main_combinationSum(void)
{
    //[8,10,6,3,4,12,11,5,9]
    //28
    int arr[] = {8,10,6,3,4,12,11,5,9};
    int target = 8;
    int returnSize = 0;
    int* returnColumnSizes;
    int** returnArr = combinationSum(arr, sizeof(arr) / sizeof(arr[0]), target, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d",returnArr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
