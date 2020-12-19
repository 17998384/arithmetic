//
//  boyer_moore.c
//  arithmetic
//
//  Boyer-Moore 字符串查找算法
//
//  Created by 我叫城北徐公° on 2020/12/8.
//  Copyright © 2020 alex. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int badChar(char* src,char* target,int i,int k)
{
    char c = target[k];
    target[k] = '\0';
    char* find_str = rindex(target,src[i]);
    target[k] = c;
    return find_str != NULL ? (int)(k - (find_str - target)) : k + 1;
}

/// 制作好后缀表
/// @param target 模式串
/// @param target_len 模式串长度
/// @param good_char_cache 好模式串缓存
void pre_goods_char_cache(char* target,int target_len,int** good_char_cache)
{
    (*good_char_cache) = (int*)malloc(sizeof(int) * target_len);
    for (int i = 0; i < target_len; i++) (*good_char_cache)[i] = -1;
    for (int i = 0; i < target_len - 1; i++)
    {
        int j = i,k = 0;
        while (j >= 0 && target[j] == target[target_len - 1 - k])
        {
            (*good_char_cache)[target_len - 1 - k] = j;
            --j;
            ++k;
        }
    }
}

//BM算法
int BM(char* src,char* target)
{
    int src_len = (int)strlen(src);
    int target_len = (int)strlen(target);
    //如果源串小于待查找串，说明一定不匹配
    if (src_len < target_len) return -1;
    //初始化好后缀表
    int* good_char_cache;
    pre_goods_char_cache(target, target_len, &good_char_cache);
    //根据坏字符匹配原则
    int i,k,i_bak;
    for (i = k = target_len - 1; i < src_len;)
    {
        i_bak = i;
        while (k >= 0 && i >= 0 && src[i] == target[k]) {--i;--k;}
        if (k == -1) return i + 1;
        //匹配坏字符
        int bad_move = badChar(src,target,i,k);
        //匹配好字符
        int good_move = k == target_len - 1 ? 0 : k - good_char_cache[k + 1];
        i_bak += bad_move > good_move ? bad_move : good_move;
        i = i_bak;
        k = target_len - 1;
    }
    return -1;
}

int main_BM(void)
{
    char* src = "aabaabbbaabbbbabaaab";
    char* target = "abaa";
//    "babbbbbabb"
//     "bbab"
    char* src0 = calloc(strlen(src) + 1,sizeof(char));
    char* target0 = calloc(strlen(target) + 1,sizeof(char));
    strcpy(src0,src);
    strcpy(target0,target);
    // strcpy(str0,str);
    int res = BM(src0,target0);
    printf("%d\n", res);
    free(src0);
    free(target0);
    return 0;
}


//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//void per_goods_char_cache(char* target,int target_len,int** good_char_cache)
//{
//    (*good_char_cache) = (int*)malloc(sizeof(int) * target_len);
//    for (int i = 0; i < target_len; i++) (*good_char_cache)[i] = -1;
//    for (int i = 0; i < target_len - 1; i++)
//    {
//        int j = i,k = 0;
//        while (j >= 0 && target[j] == target[target_len - 1 - k])
//        {
//            (*good_char_cache)[target_len - 1 - k] = j;
//            --j;
//            ++k;
//        }
//    }
//}
//
//int main(void)
//{
//    int* res;
//    char* s = "cabbcab";
//    int len = strlen(s);
//    char* s0 = malloc(sizeof(char) * len + 1);
//    strcpy(s0,s);
//    per_goods_char_cache(s0,len,&res);
//    for (int i = 0; i < len; ++i)
//    {
//        printf("%d ",res[i]);
//    }
//    return 0;
//}
