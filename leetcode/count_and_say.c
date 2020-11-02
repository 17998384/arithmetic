//
//  count_and_say.c
//  arithmetic
//  38.外观数列
//  前五项如下：
//
//  1.     1
//  2.     11
//  3.     21
//  4.     1211
//  5.     111221
//  第一项是数字 1
//  描述前一项，这个数是 1 即 “ 一 个 1 ”，记作 "11"
//  描述前一项，这个数是 11 即 “ 二 个 1 ” ，记作 "21"
//  描述前一项，这个数是 21 即 “ 一 个 2 + 一 个 1 ” ，记作 "1211"
//  描述前一项，这个数是 1211 即 “ 一 个 1 + 一 个 2 + 二 个 1 ” ，记作 "111221"

//  Created by 我叫城北徐公° on 2020/11/1.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* countAndSay0(char* i_str)
{
    char* res = (char*)malloc(sizeof(char) * 5000);
    int index = 0;
    int res_index = 0;
    int i_str_len = (int)strlen(i_str);
    while (i_str[index])
    {
        if (index < i_str_len && i_str[index] != i_str[index + 1])
        {
            res[res_index++] = '1';
            res[res_index++] = i_str[index++];
            continue;
        }
        else
        {
            int count = 1;
            while (index < i_str_len && i_str[index] == i_str[index + 1]) {count++;index++;}
            res[res_index++] = count + 48;
            res[res_index++] = i_str[index++];
        }
    }
    res[res_index] = '\0';
    return res;
}

char* countAndSay(int n)
{
    if (n == 1)
        return "1";
    char* lol = "1";
    for (int i = 1; i < n; i++)
    {
        char* str = countAndSay0(lol);
        lol = str;
    }
    return lol;
}

int main_countAndSay(void)
{
    char* str = countAndSay(30);
    printf("%s\n",str);
    return 0;
}
