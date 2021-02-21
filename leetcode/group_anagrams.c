//
//  group_anagrams.c
//  arithmetic
//
//  49.字母异位词分组

//  给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
//
//  示例:
//
//  输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
//  输出:
//  [
//    ["ate","eat","tea"],
//    ["nat","tan"],
//    ["bat"]
//  ]
//
//  说明：
//
//      所有输入均为小写字母。
//      不考虑答案输出的顺序。


//  Created by 我叫城北徐公° on 2020/11/20.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "hash_map.h"

static int equals(void* a,void* b)
{
    return (*(int*)a) == (*(int*)b);
}

static int hashCode(void* a)
{
    return *((int*)a);
}

static int str_hashCode(char* key)
{
    long long hash = 0;
    while (*key)
    {
        hash += pow(*key, 4);
        key++;
    }
    hash ^= hash >> 16;
    return (int)hash;
}

typedef struct list
{
    int size;
    char** arr;
}List;

List* newList()
{
    List* list = malloc(sizeof(List));
    list->size = 0;
    list->arr = (char**)malloc(sizeof(char*) * 10);
    return list;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    char*** res = (char***)malloc(sizeof(char**) * strsSize);
    *returnSize = 0;
    int* cache[1000] = {0};
    int cache_idx = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
    HashMap* map = new_hash_map(hashCode, equals);
    for (int i = 0; i < strsSize; i++)
    {
        //计算hash
        int* hash = (int*)malloc(sizeof(int));
        *hash = str_hashCode(strs[i]);
        List* value = (List*)get(map, hash);
        if (value == NULL)
        {
            cache[cache_idx++] = hash;
            value = newList();
            value->arr[value->size++] = strs[i];
            put(map, hash, value);
        }
        else
        {
            free(hash);
            value->arr[value->size++] = strs[i];
        }
    }
    for (int i = 0; i < cache_idx; i++)
    {
        List* value = (List*)get(map, cache[i]);
        res[i] = value->arr;
        (*returnColumnSizes)[i] = value->size;
        (*returnSize)++;
    }
    free_map(map, 1);
    return res;
}

int main_groupAnagrams(void)
{
    //["rig","rat","jul","dry","goo","art","imp","dud","gos"]
    char** strs = (char**)malloc(sizeof(char*) * 9);
    strs[0] = "rig";
    strs[1] = "rat";
    strs[2] = "jul";
    strs[3] = "dry";
    strs[4] = "goo";
    strs[5] = "art";
    strs[6] = "imp";
    strs[7] = "dud";
    strs[8] = "gos";
    int returnSize;
    int* returnColumnSizes;
    char*** res = groupAnagrams(strs, 9, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%s ",res[i][j]);
        }
        printf("\n");
    }
//    //
//    printf("%d %d\n",str_hashCode("gos"),str_hashCode("dry"));
    return 0;
}
