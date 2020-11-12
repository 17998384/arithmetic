//
//  remove_duplicates.c
//  arithmetic

//  26.删除排序数组中的重复项
//
//  Created by 我叫城北徐公° on 2020/10/13.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int count = (numsSize == 0) ? 0 : 1;
    int point = 1;
    for(int i = 0;i < numsSize;i++)
    {
        if(i > 0 && (nums[i] != nums[i - 1]))
        {
            nums[point++] = nums[i];
            count++;
        }
    }
    return count;
}

int main_remove_duplicates(void)
{
    int arr[] = {1,1,1,1,1,2,2,2,2,2,2};
    int num = removeDuplicates(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < num; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
