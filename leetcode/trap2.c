//
//  trap2.c
//  arithmetic
//

//  42.接雨水,改良版
//  给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
//
//
//
//  示例 1：
//
//  输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
//  输出：6
//  解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接6个单位的雨水（蓝色部分表示雨水）。
//
//  示例 2：
//
//  输入：height = [4,2,0,3,2,5]
//  输出：9
//  Created by 我叫城北徐公° on 2020/11/5.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int trap2(int* height, int heightSize)
{
    if (!heightSize)
        return 0;
    int* left_max;
    int* right_max;
    left_max = (int*)malloc(sizeof(int) * heightSize);
    right_max = (int*)malloc(sizeof(int) * heightSize);
    int max = 0;
    int sum = 0;
    for (int i = 0; i < heightSize; i++)
    {
        max = max > height[i] ? max : height[i];
        left_max[i] = max;
    }
    max = 0;
    for (int i = heightSize - 1; i >= 0; i--)
    {
        max = max > height[i] ? max : height[i];
        right_max[i] = max;
    }
    for (int i = 0; i < heightSize; i++)
    {
        sum += (left_max[i] > right_max[i] ? right_max[i] : left_max[i]) - height[i];
    }
    free(left_max);
    free(right_max);
    return sum;
}

int main_trap2(void)
{
    int arr[] = {10527};
    int sum = trap2(arr, sizeof(arr) / sizeof(arr[0]));
    printf("%d\n",sum);
    return 0;
}
