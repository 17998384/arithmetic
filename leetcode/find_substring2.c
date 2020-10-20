//
//  find_substring2.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/10/20.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
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
static int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
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
            free_map(hashMap);
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
        char* tmp_str = (char*)malloc(sizeof(char) * word_size + 1);
        strcpy(tmp_str, words[i]);
        put(hashMap,tmp_str,tmp_j);
        flag_array[j++] = 1;
    }
    int sum_w = 0;
    for (int i = 0; i < wordsSize; i++)
        sum_w += words[i][0];
//    for (int i = 0; i < 4; i++)
//    {
//        printf("%d ",flag_array[i]);
//    }
//    printf("\n");
    char* tmp_cmp_str = (char*)malloc(sizeof(char) * word_size + 1);
    memset(tmp_cmp_str, 0, sizeof(char) * word_size + 1);
    for (int k = 0;; k++)
    {
        int flag = 1;
        int sum_s = 0;
        for (int i = 0,t_k = k; i < wordsSize; i++,t_k += word_size)
        {
            if (t_k >= str_len)
            {flag = 0;break;}
            sum_s += s[t_k];
        }
        if (!flag)
            break;
        if (sum_s != sum_w)
            continue;
        for (int j = 0,f = k; j < wordsSize; j++,f += word_size)
        {
            strncpy(tmp_cmp_str, s + f, sizeof(char) * word_size);
            int* c = (int*)get(hashMap, tmp_cmp_str);
            if (c == NULL)
                goto loop;
            if (flag_array_cmp[*c] == flag_array[*c])
                goto loop;
            flag_array_cmp[*c]++;
        }
        return_array[(*returnSize)++] = k;
        memset(flag_array_cmp, 0 , sizeof(int) * wordsSize);
        continue;
    loop:
        memset(flag_array_cmp, 0 , sizeof(int) * wordsSize);
        BUS_NOOP;
    }
    free(flag_array);
    free(tmp_cmp_str);
    free_map(hashMap);
    return return_array;
}

int main_find_substring2(void)
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
