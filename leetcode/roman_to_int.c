//
//  roman_to_int.c
//  arithmetic

//  13.罗马转整型数字

//  Created by 我叫城北徐公° on 2020/9/14.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int romanToInt(char * s){
    int str_length = (int)strlen(s);
    int buffer[26];
    buffer['I' - 65] = 1;
    buffer['V' - 65] = 5;
    buffer['X' - 65] = 10;
    buffer['L' - 65] = 50;
    buffer['C' - 65] = 100;
    buffer['D' - 65] = 500;
    buffer['M' - 65] = 1000;
    int num = 0,last = buffer[s[str_length - 1] - 65];
    for (int i = str_length - 1; i >= 0; i--)
    {
        int current = buffer[s[i] - 65];
        if (current < last)
        {
            num -= current;
        }
        else
        {
            num += current;
        }
        last = current;
    }
    return num;
}
