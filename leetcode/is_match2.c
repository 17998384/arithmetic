//
//  is_match2.c
//  arithmetic
//

//  44.通配符匹配（失败的垃圾版）

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

//int isMatch(char* s, char* p)
//{
//    int s_len = (int)strlen(s);
////    int p_len = (int)strlen(p);
//    int s_idx = 0;
//    int p_idx = 0;
//    int flag = 1;
//    while (1)
//    {
//        if (p[p_idx] == '*')
//        {
//            p_idx++;
//            continue;
//        }
//        else if(p[p_idx] == '?')
//        {
//            p_idx++;
//            s_idx++;
//            continue;
//        }
//        else
//        {
//            int p_start = p_idx;
//            while (p[p_idx] != '\0' && p[p_idx] != '*' && p[p_idx] != '?') p_idx++ ;
//            if (p[p_idx] != '\0' && p[p_idx] == '*')
//            {
//                int tmp = 0;
//                for (int i = s_idx,j = p_start; i < s_len && j < p_idx; i++,j++)
//                {
//                    if (tmp == p_idx - p_start)
//                    {
//                        s_idx = i - j + p_start;
//                        tmp = 0;
//                        j = p_start;
//                    }
//                    if (s[i] == p[j])
//                        tmp++;
//                }
//            }
//            else
//            {
//                int tmp = 0;
//                for (; s_idx < s_len && p_start < p_idx; s_idx++,p_start++)
//                {
//                    if (tmp == p_idx - p_start)
//                        break;
//                    if (s[s_idx] == p[p_start])
//                        tmp++;
//                }
//                if (tmp != p_idx - p_start)
//                {
//                    flag = 0;
//                    break;
//                }
//            }
//        }
//    }
//    return 1;
//}
//
//int main(void)
//{
//    isMatch("abcabczzzde", "*abc???de*");
//}
