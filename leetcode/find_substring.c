//
//  find_substring.c
//  arithmetic
//
//  30. 串联所有单词的子串

//  给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
//
//  注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

//  Created by 我叫城北徐公° on 2020/10/18.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "hash_map.h"

static int equals(void* a,void* b)
{
    return !strcmp((char*)a, (char*)b);
}

static int hashCode(void* key)
{
    unsigned int max = 0xFFFFFFFF;
    long long h = 0;
    char* str = (char*)key;
    int str_len = (int)strlen(str);
    if (h == 0 && str_len > 0) {
        for (int i = 0 ; i < str_len; i++) {
            h = 31 * h + str[i];
            h &= max;
        }
    }
    return (int)h;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    //初始化
    *returnSize = 0;
    if (!wordsSize)
        return NULL;
    const int word_size = (int)strlen(words[0]);
    const int str_len = (int)strlen(s);
    if (!wordsSize)
        return NULL;
    if (!str_len)
        return NULL;
    //使用map
    HashMap* hashMap = newHashMap(hashCode,equals);
    //标记数组
    int* const flag_array = (int*)malloc(sizeof(int) * wordsSize * 2);
    //标记比较数组
    int* const flag_array_cmp = flag_array + wordsSize;
    memset(flag_array, 0 , sizeof(int) * wordsSize * 2);
    //返回数组
    int* const return_array = (int*)malloc(sizeof(int) * 100);
    for (int i = 0,j = 0; i < wordsSize; i++)
    {
        if (strlen(words[i]) != word_size)
        {
            free_map(hashMap,1);
            return NULL;
        }
        int* c =(int*)get(hashMap, words[i]);
        if (c != NULL)
        {
            flag_array[*c]++;
            continue;
        }
        int* tmp_j = (int*)malloc(sizeof(int));
        *tmp_j = j;
        put(hashMap,words[i],tmp_j);
        flag_array[j++] = 1;
    }
//    for (int i = 0; i < 4; i++)
//    {
//        printf("%d ",flag_array[i]);
//    }
//    printf("\n");
    char* tmp_cmp_str = (char*)malloc(sizeof(char) * word_size + 1);
    memset(tmp_cmp_str, 0, sizeof(char) * word_size + 1);
    for (int i = 0; i < str_len; i++)
    {
        strncpy(tmp_cmp_str, s + i, sizeof(char) * word_size);
        int* c = (int*)get(hashMap, tmp_cmp_str);
        if (c == NULL)
            continue;
        flag_array_cmp[*c]++;
        for (int j = 1,f = i + word_size; j < wordsSize; j++,f += word_size)
        {
            strncpy(tmp_cmp_str, s + f, sizeof(char) * word_size);
            c = (int*)get(hashMap, tmp_cmp_str);
            if (c == NULL)
                goto loop;
            if (flag_array_cmp[*c] == flag_array[*c])
                goto loop;
            flag_array_cmp[*c]++;
        }
        return_array[(*returnSize)++] = i;
        memset(flag_array_cmp, 0 , sizeof(int) * wordsSize);
        continue;
    loop:
        memset(flag_array_cmp, 0 , sizeof(int) * wordsSize);
        BUS_NOOP;
    }
    free(flag_array);
    free(tmp_cmp_str);
    free_map(hashMap,1);
    return return_array;
}

int main_find_substring(void)
{
    //"wordgoodgoodgoodbestword"
    //["word","good","best","good"]
    //"lingmindraboofooowingdingbarrwingmonkeypoundcake"
    //["fooo","barr","wing","ding","wing"]

    //"bcabbcaabbccacacbabccacaababcbb"
    //["c","b","a","c","a","a","a","b","c"]

    char* str = "bcabbcaabbccacacbabccacaababcbb";
    //["abc","def","ghi"]
    char** str_arr = (char**)malloc(sizeof(char*) * 9);
    str_arr[0] = "c";
    str_arr[1] = "b";
    str_arr[2] = "a";
    str_arr[3] = "c";
    str_arr[4] = "a";
    str_arr[5] = "a";
    str_arr[6] = "a";
    str_arr[7] = "b";
    str_arr[8] = "c";
    int returnSize;
    int* returnArray = findSubstring(str, str_arr, 9, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ",returnArray[i]);
    }
    return 0;
}
