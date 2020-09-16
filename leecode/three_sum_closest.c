//
//  three_sum_closest.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/9/16.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int three_sum_closest_compare(void* a,void* b)
{
    return *(int*)a - *(int*)b;
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    qsort(nums, numsSize, sizeof(int), three_sum_closest_compare);
    int L,R;
    int target_num = nums[0] + nums[1] + nums[numsSize - 1];
    int difference_value = (int)abs(target_num - target);
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        L = i + 1;
        R = numsSize - 1;
        while (L < R)
        {
            sum = nums[i] + nums[L] + nums[R];
            int difference_value0 = (int)abs(sum - target);
            if (difference_value0 == 0)
            {
                target_num = target;
                goto loop;
            }
            if (difference_value0 <= difference_value)
            {
                difference_value = difference_value0;
                target_num = sum;
            }
            (sum - target) > 0 ? R-- : L++;
        }
    }
loop:
    return target_num;
}

int main(void)
{
    int arr[] = {0,2,1,-3,-1};
    int target = threeSumClosest(arr, sizeof(arr)/sizeof(int), 1);
    printf("%d\n",target);
    return 0;
}
