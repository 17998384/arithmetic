//
//  search_range.c
//  arithmetic
//  给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

//  你的算法时间复杂度必须是 O(log n) 级别。
//
//  如果数组中不存在目标值，返回 [-1, -1]。
//
//  示例 1:
//
//  输入: nums = [5,7,7,8,8,10], target = 8
//  输出: [3,4]

//  Created by 我叫城北徐公° on 2020/10/26.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "dichotomy.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int* return_nums = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    return_nums[0] = -1;
    return_nums[1] = -1;
    if (numsSize == 0)
        return return_nums;
    int index = dichotomy(nums, 0, numsSize - 1, target);
    if (index == -1)
        return return_nums;
    int left = index;
    int right = index;
    int flag = 0;
    while(left >= 0 && right <= numsSize - 1)
    {
        if(left > 0 && (nums[left] == nums[left - 1]))
            {left--;flag = 1;}
        if(right < numsSize - 1 && (nums[right] == nums[right + 1]))
            {right++;flag = 1;}
        if(!flag)
            break;
        flag = 0;
    }
    return_nums[0] = left;
    return_nums[1] = right;
    return return_nums;
}

int main_search_range(void)
{
    int nums[] = {2,2};
    int return_size;
    int* return_nums = searchRange(nums, sizeof(nums)/sizeof(nums[0]), 2, &return_size);
    printf("%d %d\n",return_nums[0],return_nums[1]);
    free(return_nums);
    return 0;
}
