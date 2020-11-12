//
//  int_to_roman.c
//  arithmetic

//  12.整数转罗马数字

//  Created by 我叫城北徐公° on 2020/9/14.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void four_and_nine_handler(char* str,int* bit_point,int num,char a,char b,char c)
{
    if (num == 4)
    {
        str[(*bit_point)++] = a;
        str[(*bit_point)++] = b;
        return;
    }
    if (num == 9)
    {
        str[(*bit_point)++] = a;
        str[(*bit_point)++] = c;
    }
}

void single_handler(char* str,int* bit_point,int num,char a,char b,char c)
{
    if (num == 4 || num == 9)
    {
        four_and_nine_handler(str,bit_point,num,a,b,c);
        return;
    }
    if (num < 5)
    {
        for (int i = 0; i < num; i++)
        {
            str[(*bit_point)++] = a;
        }
    }
    if (num >= 5)
    {
        str[(*bit_point)++] = b;
        for (int i = 0; i < num - 5; i++)
        {
            str[(*bit_point)++] = a;
        }
    }
}

char* int_to_roman0(int num)
{
    char* str = (char*)malloc(sizeof(char)*20);
    //个位
    const int unit = num % 10;
    //十位
    const int decade = num / 10 % 10;
    //百位
    const int hundred = num / 100 % 10;
    //千位
    const int thousand = num / 1000;
    //字符串位数
    int bit_point = 0;
    //千位
    if (thousand != 0)
    {
        for (int i = 0; i < thousand; i++)
        {
            str[bit_point++] = 'M';
        }
    }
    //百位
    if (hundred != 0)
    {
        single_handler(str,&bit_point,hundred,'C','D','M');
    }
    //十位
    if (decade != 0)
    {
        single_handler(str,&bit_point,decade,'X','L','C');
    }
    //个位
    if (unit != 0)
    {
        single_handler(str,&bit_point,unit,'I','V','X');
    }
    str[bit_point] = '\0';
    return str;
}

char * intToRoman(int num){
    return int_to_roman0(num);
}
