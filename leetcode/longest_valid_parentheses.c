//
//  longest_valid_parentheses.c
//  arithmetic
//
//  给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
//
//  示例 1:
//
//  输入: "(()"
//  输出: 2
//  解释: 最长有效括号子串为 "()"
//
//  示例 2:
//
//  输入: ")()())"
//  输出: 4
//  解释: 最长有效括号子串为 "()()"


//  Created by 我叫城北徐公° on 2020/10/21.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int longestValidParentheses(char * s){
    int str_len = (int)strlen(s);
    if (!str_len)
        return 0;
    int stack[str_len];
    int stack_p = 0;
    char flag_array[str_len];
    memset(flag_array, 0, sizeof(char) * str_len);
    int sum_len = 0;
    int tmp_sum_len = 0;
    int flag = 1;
    for (int i = 0; i < str_len; i++)
    {
        flag_array[i] = 1;
        stack[stack_p] = s[i];
        //匹配到了
        if (stack_p > 0 && stack[stack_p] - stack[stack_p - 1] == 1)
        {
            //pop
            stack_p -= 2;
            flag = i;
            flag_array[flag] = 0;
            while (!flag_array[flag]) flag--;
            flag_array[flag] = 0;
        }
        //push
        stack_p++;
    }
    for (int i = 0; i < str_len; i++)
    {
        if (flag_array[i])
        {
            sum_len = tmp_sum_len > sum_len ? tmp_sum_len : sum_len;
            tmp_sum_len = 0;
        }
        else
            tmp_sum_len++;
    }
    return tmp_sum_len > sum_len ? tmp_sum_len : sum_len;
}

int main_longest_valid_parentheses(void)
{
    int len = longestValidParentheses("(()");
    printf("%d\n",len);
    return 0;
}
