//
//  trap.c
//  arithmetic

//  42.接雨水
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

int trap(int* height, int heightSize)
{
    if (!heightSize)
        return 0;
    int* L = height;
    int* R = height + heightSize - 1;
    int prev_height = 0;
    int max_height = 0;
    int sum = 0;
    while (L < R)
    {
        if (*L == 0)
        {
            L++;
            continue;
        }
        if (*R == 0)
        {
            R--;
            continue;
        }
        int current_height = *L > *R ? *R : *L;
        if (current_height <= max_height)
            goto loop;
        prev_height = max_height;
        max_height = current_height;
        for (int j = L - height,size = R - height; j < size; j++)
        {
            if (height[j] == current_height)
                continue;
            int element = height[j];
            if (element < prev_height)
                element += (prev_height - element);
            element = current_height - element;
            sum += element > 0 ? element : 0;
        }
    loop:
        *L > *R ? R-- : L++;
    }
    return sum;
}

int main_trap(void)
{
    int arr[] = {10527,6186,2907};
    int sum = trap(arr, sizeof(arr) / sizeof(arr[0]));
    //23
    printf("%d\n",sum);
    return 0;
}
