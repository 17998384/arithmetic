//
//  three_sum.c
//  arithmetic

//  15.三数之和垃圾版

//
//  Created by 我叫城北徐公° on 2020/9/14.
//  Copyright © 2020 alex. All rights reserved.
//

#include "heap_sort.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize < 3)
    {
        return NULL;
    }
    //堆排序
    heap_sort(nums, numsSize);
    //qsort(nums, numsSize, sizeof(int),compare);
    int** return_array = (int**)malloc(sizeof(int*) * 16384);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 16384);
    int left = 0;
    int right = 0;
    for (int i = 0; i < numsSize - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        left = i + 1;
        right = numsSize - 1;
        //目标值
        int target = -nums[i];
        while (left < right)
        {
            if (nums[right] < 0)
            {
                break;
            }
            if (target < (nums[left] + nums[right]))
            {
                right--;
                continue;
            }
            else if (target > (nums[left] + nums[right]))
            {
                left++;
                continue;
            }
            return_array[*returnSize] = (int*)malloc(sizeof(int) * 3);
            return_array[*returnSize][0] = nums[i];
            return_array[*returnSize][1] = nums[left];
            return_array[*returnSize][2] = nums[right];
            (*returnColumnSizes)[*returnSize] = 3;
            (*returnSize)++;
            while (left < right && nums[left] == nums[++left]);
            while (left < right && nums[right] == nums[--right]);
        }
    }
    return return_array;
}

int main_threeSum(void)
{
    int nums[] = {-2,-2,-1,0,1,2};
    int return_size;
    threeSum(nums, 6, &return_size, NULL);
    return 0;
}
