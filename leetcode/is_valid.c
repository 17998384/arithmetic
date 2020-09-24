//
//  is_valid3.c
//  arithmetic
//  有效的括号'('，')'，'{'，'}'，'['，']'
//  Created by 我叫城北徐公° on 2020/9/25.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <string.h>

static int isValid(char* s)
{
    int length = (int)strlen(s);
    if (length == 0)
        return 1;
    if (length == 1)
        return 0;
    char stack[length];
    int pointer = -1;
    int num = 0;
    while (num < length)
    {
        stack[++pointer] = s[num];
        if (pointer >= 1 && ((stack[pointer - 1] + 2 == stack[pointer]) || stack[pointer - 1] + 1 == stack[pointer]))
            pointer -= 2;
        num++;
    }
    return !(pointer >= 0);
}

int main_is_valid(void)
{
    char* s = ")(){}";
    int flag = isValid(s);
    printf("%d ",flag);
    return 0;
}
