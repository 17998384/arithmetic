//
//  three_num2.c
//  arithmetic
//  三数之和标准版
//  Created by 我叫城北徐公° on 2020/9/14.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int compare(void* a,void* b)
{
    return *(int*)a - *(int*)b;
}

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
    qsort(nums, numsSize, sizeof(int),compare);
    int** return_array = (int**)malloc(sizeof(int*) * 16384);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 16384);
    int left = 0;
    int right = 0;
    for (int i = 0; i < numsSize - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        if(nums[i] > 0)
            break;
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

int main(void)
{
    int nums[] = {-2,-2,-1,0,1,2};
    int return_size;
    int* returnColumnSizes;
    int** return_array = threeSum(nums, 6, &return_size, &returnColumnSizes);
    for (int i = 0; i < return_size; i++)
    {
        printf("%d %d %d \n",return_array[i][0],return_array[i][1],return_array[i][2]);
    }
    return 0;
}
