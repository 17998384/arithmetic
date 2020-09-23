//
//  four_sum.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/9/23.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


static int compare(void* a,void* b)
{
    return *(int*)a - *(int*)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize < 4)
    {
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int),compare);
    int** return_array = (int**)malloc(sizeof(int*) * 16384);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 16384);
    int left = 0;
    int right = 0;
    for (int i = 0; i < numsSize - 3; i++)
    {
        if(target < 0 && nums[i] > 0)
        {
            continue;
        }
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        for(int j = i + 1 ; j < numsSize - 2 ; j++)
        {
            if (j > 1 && nums[j] == nums[j - 1] && j - i != 1)
            {
                continue;
            }
            left = j + 1;
            right = numsSize - 1;
            if(nums[i] + nums[j] > target && nums[left] > 0)
            {
                break;
            }
            //目标值
            int target0 = target - (nums[i] + nums[j]);
            while (left < right)
            {
                if (target0 < (nums[left] + nums[right]))
                {
                    right--;
                    continue;
                }
                else if (target0 > (nums[left] + nums[right]))
                {
                    left++;
                    continue;
                }
                return_array[*returnSize] = (int*)malloc(sizeof(int) * 4);
                return_array[*returnSize][0] = nums[i];
                return_array[*returnSize][1] = nums[j];
                return_array[*returnSize][2] = nums[left];
                return_array[*returnSize][3] = nums[right];
                (*returnColumnSizes)[*returnSize] = 4;
                (*returnSize)++;
                while (left < right && nums[left] == nums[++left]);
                while (left < right && nums[right] == nums[--right]);
            }
        }
    }
        
    return return_array;
}

int main_four_sum(void)
{
    int nums[] = {1,0,-1,0,-2,2};
    int return_size;
    int* returnColumnSizes;
    int** return_array = fourSum(nums, 6, 0, &return_size, &returnColumnSizes);
    for (int i = 0; i < return_size; i++)
    {
        printf("%d %d %d %d \n",return_array[i][0],return_array[i][1],return_array[i][2],return_array[i][3]);
    }
    return 0;
}
