//
//  my_lib.h
//  arithmetic
//
//  我的库函数
//
//  Created by 我叫城北徐公° on 2020/11/1.
//  Copyright © 2020 alex. All rights reserved.
//

#ifndef my_lib_h
#define my_lib_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    整数转字符串
 */
char* itoa(int num,char* str,int radix);

/*
    十进制转二进制
    使用后记得调用free()
 */
char* dec_to_binary(char* dec_num);

#endif /* my_lib_h */
