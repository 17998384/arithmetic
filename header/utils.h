//
//  my_lib.h
//  arithmetic
//
//  我的库函数
//
//  Created by 我叫城北徐公° on 2020/11/1.
//  Copyright © 2020 alex. All rights reserved.
//

#define utils_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
    整数转字符串
 */
char* itoa(int num,char* str,int radix);

/*
    十进制转二进制
    使用后记得调用free()
 */
char* dec_to_binary(char* dec_num);

/*
    字符串替换函数，支持规则
 */
char * strreplace(char const * const original,
                  char const * const pattern, char const * const replacement);

/// 字符串替换函数
/// @param src 原字符串
/// @param from 想更换掉的字符串
/// @param to 更换成该字符串
char *strreplace2(const char *src, const char *from, const char *to);

/// 二进制转整数
/// @param str 二进制字符串
int binary_to_int(char* str);

/// 求两个数字的最大公约数
/// @param a 
/// @param b
int gcd(int a,int b);

#ifdef __cplusplus
}
#endif
