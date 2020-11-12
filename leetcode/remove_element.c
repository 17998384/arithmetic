//
//  remove_element.c
//  arithmetic
//
//  27.移除元素

//  Created by 我叫城北徐公° on 2020/10/13.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>

int removeElement(int* nums, int numsSize,int val){
    int count = 0;
    int point = 0;
    for(int i = 0;i < numsSize;i++)
    {
        if((nums[i] != val))
        {
            nums[point++] = nums[i];
            count++;
        }
    }
    return count;
}

int main_remove_element(void)
{
    int arr[] = {3,2,2,3};
    int num = removeElement(arr, sizeof(arr) / sizeof(int),3);
    for (int i = 0; i < num; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
