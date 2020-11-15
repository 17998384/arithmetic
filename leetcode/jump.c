//
//  jump.c
//  arithmetic
//
//  45.跳跃游戏II

//  给定一个非负整数数组，你最初位于数组的第一个位置。
//
//  数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
//  你的目标是使用最少的跳跃次数到达数组的最后一个位置。
//
//  示例:
//
//  输入: [2,3,1,1,4]
//  输出: 2
//  解释: 跳到最后一个位置的最小跳跃数是 2。
//       从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
//
//  说明:
//
//  假设你总是可以到达数组的最后一个位置。


//  Created by 我叫城北徐公° on 2020/11/15.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <string.h>
//#define MIN(x,y) (x) > (y) ? (y) : (x)


/// dp解法，然而效率没有贪心算法高
/// @param nums 数组
/// @param numsSize 数组长度
//int jump(int* nums, int numsSize)
//{
//    int dp[numsSize];
//    memset(dp, 1,sizeof(int) * numsSize);
//    //动态规划
//    dp[0] = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        for (int j = i + 1; (j <= i + nums[i]) && j < numsSize; j++)
//        {
//            dp[j] = MIN(dp[i] + 1, dp[j]);
//            if (j == numsSize - 1)
//                goto loop;
//        }
//    }
//loop:
//    return dp[numsSize - 1];
//}
//
//int main(void)
//{
//    int arr[] = {10,9,8,7,6,5,4,3,2,1,0};
//    int min = jump(arr, sizeof(arr) / sizeof(arr[0]));
//    printf("%d\n",min);
//    return 0;
//}
