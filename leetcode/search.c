//
//  search.c
//  arithmetic
//给你一个升序排列的整数数组 nums ，和一个整数 target 。

//  从可能反转的升序数组寻找数字。
//
//  请你在数组中搜索 target ，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

//  Created by 我叫城北徐公° on 2020/10/25.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include "dichotomy.h"

void half_search(int* nums,int start_idx,int end_idx,int target,int* num)
{
    if (start_idx > end_idx)
        return;
    if (*num != -1)
        return;
    if (start_idx == end_idx)
        *num = nums[start_idx] == target ? start_idx : -1;
    //如果是正常数组
    if (nums[end_idx] > nums[start_idx])
    {
        if (target > nums[end_idx] || target < nums[start_idx])
            return;
        *num = dichotomy(nums, start_idx, end_idx, target);
        return;
    }
    int half = (start_idx + end_idx) / 2;
    if (target == nums[half])
    {
        *num = half;
        return;
    }
    half_search(nums, start_idx, half - 1, target,num);
    half_search(nums, half + 1, end_idx, target,num);
}

int search(int* nums, int numsSize, int target){
    if (numsSize == 0)
        return -1;
    int num = -1;
    half_search(nums, 0, numsSize - 1,target,&num);
    return num;
}

int main_search(void)
{
    int nums[] = {};
    int index = search(nums, 0,1);
    printf("%d \n",index);
    return 0;
}
