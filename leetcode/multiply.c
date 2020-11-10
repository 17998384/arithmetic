//
//  multiply2.c
//  arithmetic
//
//  43.字符串相乘
//  给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//
//  示例 1:
//
//  输入: num1 = "2", num2 = "3"
//  输出: "6"
//
//  示例 2:
//
//  输入: num1 = "123", num2 = "456"
//  输出: "56088"
//
//  说明：
//
//      num1 和 num2 的长度小于110。
//      num1 和 num2 只包含数字 0-9。
//      num1 和 num2 均不以零开头，除非是数字 0 本身。
//      不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
//
//
//  Created by 我叫城北徐公° on 2020/11/5.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void num_add(int* arr,int bit,int num)
{
    int scale = 0;
    do
    {
        scale = 0;
        int sum = arr[bit] + num;
        if (sum > 9)
            scale = sum / 10;
        arr[bit--] = sum % 10;
        num = sum / 10;
    }while (scale && bit >= 0);
}

char * multiply(char * num1, char * num2)
{
    int bit,str1_len = (int)strlen(num1),str2_len = (int)strlen(num2);
    int arr[str1_len + str2_len];
    memset(arr, 0, sizeof(int) * (str1_len + str2_len));
    for (int i = str1_len - 1; i >= 0; i--) {
        // (str1_len + str2_len - 1) - (str1_len - 1 - i) => str2_len + i
        bit = str2_len + i;
        for (int j = str2_len - 1; j >= 0; j--) {
            int a = num1[i] - '0';
            int b = num2[j] - '0';
            int mul = a * b;
            num_add(arr, bit, mul);
            bit--;
        }
    }
    char* result = (char*)malloc(sizeof(char) * (str1_len + str2_len) + 1);
    int flag = 1;
    int j = 0;
    for (int i = 0,size = str1_len + str2_len; i < size; i++)
    {
        if (flag && arr[i] == 0)
            continue;
        flag = 0;
        result[j] = arr[i] + '0';
        j++;
    }
    if (flag)
    {
        result[0] = '0';
        result[1] = '\0';
    }
    else
        result[j] = '\0';
    return result;
}

int main_multiply(void)
{
    char* result = multiply("0", "0");
    printf("%s\n",result);
    return 0;
}
