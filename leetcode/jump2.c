//
//  jump2.c
//  arithmetic
//
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
#define MAX(a,b) ((a) > (b) ? (a) : (b))

/// 贪心算法
/// @param nums 数组
/// @param numsSize 数组长度
int jump2(int* nums, int numsSize)
{
    if (numsSize == 1)
        return 0;
    //当前，当前结束位置，最大可达位置，跳跃次数
    int current,current_end,max,step;
    current = current_end = max = step = 0;
    while (current < numsSize)
    {
        //求当前这个位置可以走的最大索引
        max = MAX(max, nums[current] + current);
        //如果已经走到了当前可以走的最大索引，则跳一步，并更新下一次可走的最大值
        if (current == current_end)
        {
            step++;
            current_end = max;
        }
        //如果当前结束位置已经是末尾，说明可以结束了
        if (current_end == numsSize - 1)
            break;
        current++;
    }
    return step;
}

int main_jump2(void)
{
    int arr[] = {2,3,1,1,4};
    int min = jump2(arr, sizeof(arr) / sizeof(arr[0]));
    printf("%d\n",min);
    return 0;
}
