//
//  combination_sum2.c
//  arithmetic
//
//  40.组合总数2

//  给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//  candidates 中的每个数字在每个组合中只能使用一次。
//
//  说明：
//
//      所有数字（包括目标数）都是正整数。
//      解集不能包含重复的组合。
//
//  示例 1:
//
//  输入: candidates = [10,1,2,7,6,1,5], target = 8,
//  所求解集为:
//  [
//    [1, 7],
//    [1, 2, 5],
//    [2, 6],
//    [1, 1, 6]
//  ]
//
//  示例 2:
//
//  输入: candidates = [2,5,2,1,2], target = 5,
//  所求解集为:
//  [
//    [1,2,2],
//    [5]
//  ]


//  Created by 我叫城北徐公° on 2020/11/3.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int buffer[100];
static int buffer_p = 0;
static int sum = 0;

static void DFS(int* candidates,int candidatesSize, int target, int* returnSize, int* returnColumnSizes,
                int** returnArr,int index)
{
    if (sum > target)
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
    for (int i = index; i < candidatesSize; i++)
    {
        //如果第N层为当前本身，则continue
        if (candidates[i] <= target)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            sum += candidates[i];
            buffer[buffer_p++] = candidates[i];
            DFS(candidates, candidatesSize, target, returnSize, returnColumnSizes, returnArr, i + 1);
            sum -= candidates[i];
            buffer_p--;
        }
    }
}

static int compare(void* a,void* b)
{
    return *(int*)a - *(int*)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    qsort(candidates, candidatesSize, sizeof(int), compare);
    int** returnArr = (int**)malloc(sizeof(int*) * 300);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 300);
    DFS(candidates,candidatesSize,target,returnSize,*returnColumnSizes,returnArr,0);
    return returnArr;
}

int main_combinationSum2(void)
{
    //[2,5,2,1,2]
    //5
    int arr[] = {2,5,2,1,2};
    int target = 5;
    int returnSize = 0;
    int* returnColumnSizes;
    int** returnArr = combinationSum2(arr, sizeof(arr) / sizeof(arr[0]), target, &returnSize, &returnColumnSizes);
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
