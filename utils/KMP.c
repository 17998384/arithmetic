//
// Created by 我叫城北徐公° on 2022/8/15.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int* get_next(char* patternStr)
{
    int strLen = strlen(patternStr);
    if (strLen == 0)
    {
        return NULL;
    }
    char* p = patternStr;
    int* next = malloc(sizeof(int) * strLen);
    memset(next, 0, sizeof(int) * strLen);
    int j = 0, k = -1;
    next[0] = k;
    while (j < strLen)
    {
        if (k == -1 || p[j] == p[k])
        {
            //假设index[0] == index [5]，那么我们应当认为index[6]在匹配失败时跳到index [1]
            next[++j] = ++k;
        }
        else
        {
            k = next[k];
        }
    }
    return next;
}

int kmp(char* targetStr, char* patternStr)
{
    int targetStrLen = strlen(targetStr);
    int patternStrLen = strlen(patternStr);
    if (targetStrLen == 0 && patternStrLen == 0)
    {
        return 1;
    }
    int* next = get_next(patternStr);
    if (!next)
    {
        return 1;
    }
    int i = 0, j = 0;
    while (i < targetStrLen)
    {
        if (targetStr[i] != patternStr[j])
        {
            j = next[j];
            if (j == -1)
            {
                i++;
                j = 0;
            }
        }
        else
        {
            i++;
            j++;
        }
    }
    free(next);
    if (j >= patternStrLen)
    {
        return 1;
    }
    return 0;
}

int main_kmp(void)
{
    char* s1 = "aaaaaaaaaaaaaaaaas";
    char* s2 = "as";
    int r = kmp(s1, s2);
    printf("%d\n", r);
//    int* next = get_next(s2);
//    int len = strlen(s2);
//    for (int i = 0; i < len; i++)
//    {
//        printf("%d ", next[i]);
//    }
//    free(next);
    return 0;
}