//
//  str_str.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/10/14.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_map.h"

static int equals(void* a,void* b)
{
    return (*(char*)a) == (*(char*)b);
}

static int hashCode(void* a)
{
    return *((char*)a);
}

/*
    计算next数组
*/
int* get_next_array(char* needle,int target_len)
{
    int* next = (int*)malloc(sizeof(int) * strlen(needle));
    int i = 1;
    next[0] = 0;
    //创建map
    HashMap* hash_nap = newHashMap(hashCode, equals);
    while (needle[i])
    {
        int* value = (int*)get(hash_nap, needle + i);
        if (value == NULL)
            next[i] = i;
        else
            next[i] = i - *value;
        int* i_p = (int*)malloc(sizeof(int));
        *i_p = i;
        put(hash_nap,needle + i,i_p);
        i++;
    }
    for (int i = 0; i < target_len; i++)
    {
        printf("%d ",next[i]);
    }
    free_map(hash_nap);
    return next;
}

int strStr(char * haystack, char * needle)
{
    int haystack_len = (int)strlen(haystack);
    int needle_len = (int)strlen(needle);
    if (!needle_len)
        return -1;
    if (!haystack_len)
        return -1;
    //KMP算法
    int* next = get_next_array(needle,needle_len);
    int p1 = 0;
    int p2 = 0;
    int p1_bak = 0;
    int flag = 0;
    while (p1 < haystack_len && p2 < needle_len)
    {
        if (p2 == needle_len)
        {
            flag = p1_bak;
            break;
        }
        if (haystack[p1] == needle[p2])
        {
            p1++;
            p2++;
            continue;
        }
        if(p2 == 0)
            p1 = p1_bak + 1;
        else
            p1 = p1_bak + (next[p2 - 1] == 0 ? 1 : next[p2 - 1]);
        p1_bak = p1;
        p2 = 0;
    }
    return p2 == needle_len ? flag = p1_bak : -1;
}

int main_str_str(void)
{
    //"ababcaababcaabc"
    //"ababcaabc"

    //ababababc
    //ababababababababc
    
    //abcdabcdb
    //abcdabcdabcdb
    
    //"mississippi"
    //"issip"
    
    char* str = "abcdabcdb";
    int result = strStr("abcdabcdabcdb", str);
    printf("%d ",result);
    
    return 0;
}
