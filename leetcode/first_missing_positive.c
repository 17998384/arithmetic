//
//  first_missing_positive.c
//  arithmetic
//
//  41.缺失的第一个正数

//  给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
//
//
//
//  示例 1:
//
//  输入: [1,2,0]
//  输出: 3
//
//  示例 2:
//
//  输入: [3,4,-1,1]
//  输出: 2
//
//  示例 3:
//
//  输入: [7,8,9,11,12]
//  输出: 1
//
//
//
//  提示：
//
//  你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。

//  Created by 我叫城北徐公° on 2020/11/4.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

static int compare(void* a,void* b)
{
    long long _long64_a = *(int*)a;
    long long _long64_b = *(int*)b;
    return (int)(_long64_a - _long64_b);
}

int firstMissingPositive(int* nums, int numsSize)
{
    if (!numsSize)
        return 1;
    qsort(nums, numsSize, sizeof(int), compare);
    int index = 0;
    while (index < numsSize && nums[index] <= 0) index++;
    if (index >= numsSize && nums[index - 1] <= 0)
        return 1;
    if (nums[index] != 1)
        return 1;
    while (index + 1 < numsSize && (nums[index] + 1 == nums[index + 1] || nums[index] == nums[index + 1])) index++;
    return nums[index] + 1;
}

int main_firstMissingPositive(void)
{
    int arr[] = {2147483647,2147483646,2147483645,3,2,1,-1,0,-2147483648};
    int index = firstMissingPositive(arr, sizeof(arr) / sizeof(arr[0]));
    printf("%d\n",index);
    return 0;
}
