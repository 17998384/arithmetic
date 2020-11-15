//
//  is_match3.c
//  arithmetic

//  44.通配符匹配（使用递归回溯，但还是没有写出来）

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

//char* str_equals(char* src,char* dest,int dest_len)
//{
//    char* dest_0 = (char*)malloc(sizeof(char) * dest_len + 1);
//    memset(dest_0, 0, sizeof(char) * dest_len + 1);
//    strncpy(dest_0, dest, dest_len);
//    char* result = strstr(src, dest_0);
//    free(dest_0);
//    return result;
//}
//
//int isMatch(char* s, char* p)
//{
//    int s_len = (int)strlen(s);
//    int p_len = (int)strlen(p);
//    if (!s_len && !p_len)
//        return 1;
//    if (s_len && !p_len)
//        return 0;
//    int s_idx = 0;
//    int p_idx = 0;
//    while (1)
//    {
//        if (p[p_idx] == '*')
//        {
//            if (isMatch(s, p + 1))
//                return 1;
//            else
//                isMatch(s++, p + 1);
//        }
//        else if(p[p_idx] == '?')
//        {
//            if (s_idx >= s_len && p_idx < p_len)
//                return 0;
//            s_idx++;
//            p_idx++;
//        }
//        else
//        {
//            while (1)
//            {
//                int p_start = p_idx;
//                //求出*或？后面的字符串长度
//                for (int size = p_len; p_idx < size && p[p_idx] != '*' && p[p_idx] != '?'; p_idx++);
//                //查找字符串位置
//                char* new_str = str_equals(s + s_idx, p + p_start, p_idx - p_start);
//                //如果p_start的上一个不是*，那么new_str只能比s_idx多一个
//                if (p_start - 1 >= 0 && p[p_start - 1] != '*' && new_str != (s + s_idx))
//                    return 0;
//                if (new_str == NULL)
//                    return 0;
//                new_str += (p_idx - p_start);
//                if(isMatch(new_str, p + p_idx))
//                    return 1;
//                else if (p_start - 1 >= 0 && p[p_start - 1] == '*')
//                {
//                    s = new_str;
//                    p_idx = p_start;
//                }
//                else
//                    return 0;
//            }
//        }
//    }
//}
//
//int main(void)
//{
//    //"acdcb"
//    //"a*c?b"
//
//    int result = isMatch("acdcb", "a*c?b");
//    printf("%s\n",result == 1 ? "true" : "false");
//    return 0;
//}
