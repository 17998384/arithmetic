//
//  generate_parenthesis.c
//  arithmetic
//

//  22.括号生成

//  数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
//
//
//
//  示例：
//
//  输入：n = 3
//  输出：[
//         "((()))",
//         "(()())",
//         "(())()",
//         "()(())",
//         "()()()"
//       ]

//  Created by 我叫城北徐公° on 2020/10/10.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateParenthesis0(int l_count,int r_count,int n,int current_index,int* returnSize,char* tmp,char** result)
{
    if (l_count > n || r_count > n)
        return;
    if (l_count == n && r_count == n)
    {
        char* str = (char*)malloc(sizeof(char) * n * 2 + 1);
        memcpy(str, tmp, sizeof(char) * n * 2);
        str[n * 2] = '\0';
        result[(*returnSize)++] = str;
        return;
    }
    if (l_count >= r_count)
    {
        tmp[current_index] = '(';
        generateParenthesis0(l_count + 1, r_count, n, current_index + 1, returnSize,tmp,result);
        tmp[current_index] = ')';
        generateParenthesis0(l_count, r_count + 1, n, current_index + 1, returnSize,tmp,result);
    }
}

char** generateParenthesis(int n,int* returnSize)
{
    char** result = (char**)malloc(sizeof(char*) * 100);
    char tmp[n * 2];
    generateParenthesis0(0, 0, n, 0, returnSize, tmp, result);
    return result;
}

int main_generate_parent_hesis(void)
{
    int size = 0;
    char** result = generateParenthesis(6, &size);
    for (int i = 0; i < size; i++)
    {
        printf("%s ",result[i]);
    }
    return 0;
}
