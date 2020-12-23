//
//  can_partition.c
//  arithmetic
//
//  416.分割等和子集

//  给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
//  注意:
//
//      每个数组中的元素不会超过 100
//      数组的大小不会超过 200
//
//  示例 1:
//
//  输入: [1, 5, 11, 5]
//
//  输出: true
//
//  解释: 数组可以分割成 [1, 5, 5] 和 [11].
//
//  Created by 我叫城北徐公° on 2020/12/19.
//  Copyright © 2020 alex. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#define MAX(x,y) (x) > (y) ? (x) : (y)

int canPartition(int* nums, int numsSize)
{
    //求出总大小
    int sum = 0;
    for (int i = 0; i < numsSize; ++i) sum += nums[i];
    //不能整除一定不能分
    if (sum % 2 != 0) return 0;
    int half = sum / 2;
    int dp[half + 1];
    memset(dp,0,sizeof(dp));
    //初始化第一行dp
    for (int i = 1; i <= half; ++i)
    {
        if (i >= nums[0]) dp[i] = nums[0];
        else dp[i] = 0;
    }
    for (int i = 1; i < numsSize; ++i)
    {
        for (int j = 1; j <= half; ++j)
        {
            //如果当前数字满足和，则判断
            if (j >= nums[i]) dp[j] = (MAX(dp[j], dp[j - nums[i]] + nums[i]));
        }
    }
    return dp[half] == half;
}

int main_canPartition(void)
{
    int nums[] = {1,2,3,4,5,1,2,2,5};
    int res = canPartition(nums,sizeof(nums) / sizeof(int));
    printf("%d\n", res);
    return 0;
}
