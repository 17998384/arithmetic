//
//  is_match3.c
//  arithmetic

//  44.通配符匹配（最终版，回溯解决）

//  给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
//
//  '?' 可以匹配任何单个字符。
//  '*' 可以匹配任意字符串（包括空字符串）。
//
//  两个字符串完全匹配才算匹配成功。
//
//  说明:
//
//      s 可能为空，且只包含从 a-z 的小写字母。
//      p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
//
//  示例 1:
//
//  输入:
//  s = "aa"
//  p = "a"
//  输出: false
//  解释: "a" 无法匹配 "aa" 整个字符串。
//
//  示例 2:
//
//  输入:
//  s = "aa"
//  p = "*"
//  输出: true
//  解释: '*' 可以匹配任意字符串。
//
//  示例 3:
//
//  输入:
//  s = "cb"
//  p = "?a"
//  输出: false
//  解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
//
//  示例 4:
//
//  输入:
//  s = "adceb"
//  p = "*a*b"
//  输出: true
//  解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
//
//  示例 5:
//
//  输入:
//  s = "acdcb"
//  p = "a*c?b"
//  输出: false

//  Created by 我叫城北徐公° on 2020/11/12.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isMatch(char* s,char* p)
{
    int s_idx = 0;
    int p_idx = 0;
    int s_len = (int)strlen(s);
    int p_len = (int)strlen(p);
    //回溯位置
    int back = 0;
    int star = -1;
    while (s_idx < s_len)
    {
        if (s[s_idx] == p[p_idx] || p[p_idx] == '?')
        {
            s_idx++;
            p_idx++;
            continue;
        }
        if (p[p_idx] == '*')
        {
            //记录星星和当前字符串的位置，方便回溯
            star = p_idx++;
            back = s_idx;
            continue;
        }
        //回溯
        //说明匹配失败了，如果没星星则直接失败，否则星星吃掉一个字符
        if (star != -1)
        {
            s_idx = ++back;
            p_idx = star + 1;
            continue;
        }
        //没星星也匹配失败就是失败
        return 0;
    }
    //如果p串和s串全部匹配完，但是p串还有剩余，则必须都是星星才可以
    while (p[p_idx] == '*') p_idx++;
    return p_idx == p_len;
}

int main_is_match(void)
{
    //"acdcb"
    //"a*c?b"

    int result = isMatch("aa", "*");
    printf("%s\n",result == 1 ? "true" : "false");
    return 0;
}
