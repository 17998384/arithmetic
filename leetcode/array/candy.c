//
// Created by 我叫城北徐公° on 2021/9/26.
//

//  135. 分发糖果
//
//          老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
//
//  你需要按照以下要求，帮助老师给这些孩子分发糖果：
//
//  每个孩子至少分配到 1 个糖果。
//  评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。
//
//  那么这样下来，老师至少需要准备多少颗糖果呢？
//
//
//
//  示例 1：
//
//  输入：[1,0,2]
//  输出：5
//  解释：你可以分别给这三个孩子分发 2、1、2 颗糖果。
//
//  示例 2：
//
//  输入：[1,2,2]
//  输出：4
//  解释：你可以分别给这三个孩子分发 1、2、1 颗糖果。
//  第三个孩子只得到 1 颗糖果，这已满足上述两个条件。


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x, y) (x) > (y) ? (x) : (y)

//第一种解法
//static int candy(int* ratings, int ratingsSize)
//{
//    if (ratingsSize == 0) return 0;
//    int buffer[ratingsSize];
//
//    for (int i = 0; i < ratingsSize; i++)
//    {
//
//        if (i > 0 && ratings[i] > ratings[i - 1]) buffer[i] = buffer[i - 1] + 1;
//        else if (i > 0 && ratings[i - 1] > ratings[i])
//        {
//            int tmp = i;
//            buffer[i] = 1;
//            while (tmp > 0 && ratings[tmp - 1] > ratings[tmp])
//            {
//                if (tmp - 1 > 0 && ratings[tmp - 2] < ratings[tmp - 1])
//                    buffer[tmp - 1] = (MAX(buffer[tmp - 2], buffer[tmp])) + 1;
//                else buffer[tmp - 1] = buffer[tmp] + 1;
//                tmp--;
//            }
//        }
//        else buffer[i] = 1;
//
//    }
//    int sum = 0;
//    for (int i = 0; i < ratingsSize; i++) sum += buffer[i];
//    return sum;
//}

//第二种解法，改进版
static int candy(int* ratings, int ratingsSize)
{
    if (ratingsSize == 0) return 0;
    int buffer[ratingsSize];

    for (int i = 0; i < ratingsSize; i++)
    {
        if (i > 0 && ratings[i - 1] < ratings[i]) buffer[i] = buffer[i - 1] + 1;
        else buffer[i] = 1;
    }

    int sum = 0;

    for (int i = ratingsSize - 1; i >= 1; i--)
    {
        if (i < ratingsSize && ratings[i - 1] > ratings[i]) buffer[i - 1] = MAX(buffer[i] + 1, buffer[i - 1]);
        sum += buffer[i];
    }

    sum += buffer[0];
    return sum;
}


int main_candy(void)
{
    int arr[] = {1, 2, 1};
    int sum = candy(arr, sizeof(arr) / sizeof(arr[0]));
    printf("%d\n", sum);
    return 0;
}