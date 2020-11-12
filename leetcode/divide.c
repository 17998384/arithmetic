//
//  divide.c
//  arithmetic
//

//  29.两数相除

// 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

// 返回被除数 dividend 除以除数 divisor 得到的商。
//
// 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

//  Created by 我叫城北徐公° on 2020/10/15.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int divide(int dividend, int divisor){
    if(dividend == -2147483648 && divisor == -1)
        return 2147483647;
    if (dividend == -2147483648 && divisor == 1)
        return -2147483648;
    unsigned int a = dividend == -2147483648 ? 2147483648 : abs(dividend) ;
    unsigned int b = divisor == -2147483648 ? 2147483648 : abs(divisor);
    if (a < b)
        return 0;
    unsigned int remainder = 0;
    int max_bit = 0;
    int div = 0;
    //获取最高位
    unsigned int a_bak = a;
    while (a_bak != 0) {
        a_bak = a_bak >> 1;
        max_bit++;
    }
    while (max_bit != 0) {
        int bit_num = (a >> (max_bit - 1)) & 1;
        int bit_num_remainder_sum = bit_num + remainder;
        remainder = bit_num_remainder_sum >= b ? bit_num_remainder_sum - b : bit_num_remainder_sum;
        div |= bit_num_remainder_sum >= b ? 1 : 0;
        remainder <<= 1;
        if (max_bit == 1)
            break;
        div <<= 1;
        max_bit--;
    }
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        div = -div;
    return div;
}

int main_divide(void)
{
    //-2147483648
    //-1109186033
    int result = divide(-2147483648, -1109186033);
    printf("%d ",result);
    return 0;
}
