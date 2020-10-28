//
//  search_insert.c
//  arithmetic
//  给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

//  你可以假设数组中无重复元素。
//
//  示例 1:
//
//  输入: [1,3,5,6], 5
//  输出: 2

//  示例 2:
//
//  输入: [1,3,5,6], 2
//  输出: 1


//  Created by 我叫城北徐公° on 2020/10/27.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>

int dichotomy_0(int* nums,int start_idx,int end_idx,int target,int* last_half)
{
    if (start_idx > end_idx)
    {
        
        return -1;
    }
    int half_idx = (start_idx + end_idx) / 2;
    *last_half = half_idx;
    if (target == nums[half_idx])
        return half_idx;
    else if (target > nums[half_idx])
        return dichotomy_0(nums,half_idx + 1,end_idx,target,last_half);
    else
        return dichotomy_0(nums,start_idx,half_idx - 1,target,last_half);
}

int searchInsert(int* nums, int numsSize, int target)
{
    if (!numsSize)
        return -1;
    int last_half;
    int index = dichotomy_0(nums, 0, numsSize - 1, target, &last_half);
    if (index != -1)
        return index;
    for (; last_half >= 0; last_half--)
    {
        if (nums[last_half] < target)
        {
            return last_half + 1;
        }
    }
    return 0;
}

int main_search_insert(void)
{
    int arr[] = {1};
    int index = searchInsert(arr, sizeof(arr) / sizeof(arr[0]), -1);
    printf("%d ",index);
    return 0;
}
