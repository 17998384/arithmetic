//
//  is_match.c
//  arithmetic
//

//  44.通配符匹配

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

//  Created by 我叫城北徐公° on 2020/11/11.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//int isMatch0(char* s, char* p,int s_len,int p_len)
//{
//    int flag = 1;
//    int s_index = 0;
//    int p_index = 0;
//    while (p_index < p_len)
//    {
//        switch (p[p_index])
//        {
//            case '*':
//            {
//                p_index++;
//                if (p_index >= p_len)
//                {
//                    flag = 1;
//                    goto loop;
//                }
//                int tmp = 0;
//                while (p[p_index] == '*'|| p[p_index] == '?')
//                {
//                    if (p[p_index] == '?')
//                        tmp++;
//                    p_index++;
//                }
//                int s_index_bak = s_index;
//                while (s_index < s_len && s[s_index] != p[p_index]) s_index++;
//                if ((s_index - s_index_bak) < tmp)
//                {
//                    flag = 0;
//                    goto loop;
//                }
//                if (p_index == p_len && p[p_index - 1] == '*')
//                {
//                    flag = 1;
//                    goto loop;
//                }
//                if (s[s_index] != p[p_index])
//                {
//                    flag = 0;
//                    goto loop;
//                }
//                s_index++;
//                p_index++;
//                flag = 1;
//                break;
//            }
//            case '?':
//            {
//                ++s_index;
//                ++p_index;
//            }
//            default:
//            {
//                if (s_index >= s_len || p_index >= p_len)
//                {
//                    if (s_index >= s_len)
//                    {
//                        while (p_index < p_len)
//                        {
//                            if (p[p_index++] != '*')
//                            {
//                                flag = 0;
//                                goto loop;
//                            }
//                        }
//                        flag = 1;
//                        goto loop;
//                    }
//                    flag = 0;
//                    goto loop;
//                }
//                if (s[s_index] != p[p_index])
//                {
//                    if (p[p_index] == '*')
//                    {
//                        s_index++;
//                        break;
//                    }
//                    else if (p[p_index] == '?')
//                        break;
//                    else
//                    {
//                        flag = 0;
//                        goto loop;
//                    }
//                }
//                s_index++;
//                p_index++;
//                flag = 1;
//                break;
//            }
//        }
//    }
//    if (s_index < s_len)
//        flag = 0;
//loop:
//    return flag;
//}
//
//int isMatch(char* s, char* p)
//{
//    int s_len = (int)strlen(s);
//    int p_len = (int)strlen(p);
//    if (p_len == 0 && s_len == 0)
//        return 1;
//    if (p_len == 0 && s_len > 0)
//        return 0;
//    if (p_len == 1 && p[0] == '?' && s_len == 1)
//        return 1;
//    if (s_len == 0 && p_len > 0)
//    {
//        int p_index = 0;
//        while (p_index < p_len)
//        {
//            if (p[p_index++] != '*')
//                return 0;
//        }
//        return 1;
//    }
//    int result_1 = isMatch0(s, p, s_len, p_len);
//    //invert_str
//    for (int i = 0,j = s_len - 1; i < s_len / 2; i++,j--)
//    {
//        s[i] ^= s[j];
//        s[j] ^= s[i];
//        s[i] ^= s[j];
//    }
//    for (int i = 0,j = p_len - 1; i < p_len / 2; i++,j--)
//    {
//        p[i] ^= p[j];
//        p[j] ^= p[i];
//        p[i] ^= p[j];
//    }
//    int result_2 = isMatch0(s, p, s_len, p_len);
//    return result_1 | result_2;
//}

//int main(void)
//{
////    //"mississippi"
////    //"m??*ss*?i*pi"
////
////    //"aab"
////    //"c*a*b"
////    char* str1 = (char*)malloc(sizeof(char) * 200);
////    char* str2 = (char*)malloc(sizeof(char) * 200);
////    strcpy(str1, "fg");
////    strcpy(str2, "???");
////    int result = isMatch(str1,str2);
////    printf("%d\n",result);
//    return 0;
//}
