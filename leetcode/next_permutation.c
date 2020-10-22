//
//  next_permutation.c
//  arithmetic
//  实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

//  如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
//
//  必须原地修改，只允许使用额外常数空间。
//
//  以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
//  1,2,3 → 1,3,2
//  3,2,1 → 1,2,3
//  1,1,5 → 1,5,1

//  Created by 我叫城北徐公° on 2020/10/21.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int compare(void* a,void* b)
{
    return (*(int*)a) - (*(int*)b);
}

void swap(int* a,int* b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void nextPermutation(int* nums, int numsSize){
    if (numsSize == 0 || numsSize == 1)
        return;
    int arr[100];
    memset(arr,0,sizeof(int) * 100);
    for (int i = numsSize - 1; i > 0; i--)
    {
        arr[nums[i]] = i;
        if (nums[i - 1] < nums[i])
        {
            for (int j = nums[i - 1] + 1; j < 100 ; j++)
            {
                if (arr[j] && nums[i] != nums[arr[j]])
                {
                    swap(&nums[i], &nums[arr[j]]);
                    break;
                }
            }
            swap(&nums[i], &nums[i - 1]);
            qsort(nums + i, numsSize - i, sizeof(int), compare);
            goto loop;
        }
    }
    qsort(nums, numsSize, sizeof(int), compare);
loop:
    SEGV_NOOP;
}

int main_next_permutation(void)
{
    //            0 1 2  3 4 5 6 7 8 9 10 11
    int arr[] = {1,20,26,1,15,29,4,29,10,9,21,7,27,11,21,5,9,7,27,16,17,3,6,5,16,23,29,14,28,21,2,29,3,29,0,18,28,5,10,9,6,23,8,25,26,21,1,5,29,28,14,8,1,20,13,10};
    nextPermutation(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
