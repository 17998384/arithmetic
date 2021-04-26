//
// Created by 我叫城北徐公° on 2021/4/26.
//

//66. 加一

//  给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
//
//  最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//
//  你可以假设除了整数 0 之外，这个整数不会以零开头。
//
//
//
//  示例 1：
//
//  输入：digits = [1,2,3]
//  输出：[1,2,4]
//  解释：输入数组表示数字 123。
//
//  示例 2：
//
//  输入：digits = [4,3,2,1]
//  输出：[4,3,2,2]
//  解释：输入数组表示数字 4321。
//
//  示例 3：
//
//  输入：digits = [0]
//  输出：[1]
//
//
//
//  提示：
//
//  1 <= digits.length <= 100
//  0 <= digits[i] <= 9

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int* res = malloc(sizeof(int) * (digitsSize + 1));
    res[0] = 0;
    memcpy(res + 1, digits, digitsSize * sizeof(int));
    free(digits);
    digits = res;
    int carry = 1;
    for (int i = digitsSize; i >= 0; --i)
    {
        int tmp = digits[i];
        if (carry) ++tmp;
        if (tmp < 10) carry = 0;
        else carry = 1;
        digits[i] = tmp % 10;
    }
    if (digits[0])
    {
        *returnSize = digitsSize + 1;
        return digits;
    }
        //ptr + 1
    else
    {
        *returnSize = digitsSize;
        return digits + 1;
    }
}