//
//  letter_combinations.c
//  arithmetic
//
//  17.电话号码的字母组合
//
//  Created by 我叫城北徐公° on 2020/9/22.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cache[10];
char** returned;
//数字长度
int digits_len;
//队列
char list[1000];
//队列指针
int list_p = 0;


/*
 广度优先遍历，组成队列
 */
void BFS(char* digits,int digits_index,int digits_max_index,int* returned_index)
{
    
    if (digits_index == digits_max_index - 1)
    {
        for (int i = 1,size = cache[digits[digits_index] - 48][0] - 47; i < size; i++)
        {
            returned[*returned_index] = (char*)malloc(sizeof(char) * digits_len + 1);
            for (int j = 0; j < digits_len - 1; j++)
            {
                returned[*returned_index][j] = list[j];
            }
            returned[*returned_index][digits_len - 1] = cache[digits[digits_index] - 48][i];
            returned[*returned_index][digits_len] = '\0';
            (*returned_index)++;
        }
        return;
    }
    int current_cache_index = digits[digits_index] - 48;
    for (int i = 1,size = cache[current_cache_index][0] - 47; i < size; i++)
    {
        list[digits_index] = cache[current_cache_index][i];
        BFS(digits, digits_index + 1,digits_max_index,returned_index);
    }
}

char* str_handler(char* source,char target)
{
    int len = strlen(source);
    int index = 0;
    int size = 0;
    while (source[index])
    {
        if (source[index] != target)
        {
            size++;
        }
        index++;
    }
    char* copy = (char*)malloc(sizeof(char) * size + 1);
    size = index = 0;
    while (source[index])
    {
        if (source[index] != target)
        {
            copy[size++] = source[index];
        }
        index++;
    }
    copy[size] = '\0';
    return copy;
}

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
char** letterCombinations(char * digits, int* returnSize)
{
    if (digits == NULL || strlen(digits) == 0)
    {*returnSize = 0;return NULL;}
    cache[0] = "";
    cache[1] = "";
    cache[2] = "3abc";
    cache[3] = "3def";
    cache[4] = "3ghi";
    cache[5] = "3jkl";
    cache[6] = "3mno";
    cache[7] = "4pqrs";
    cache[8] = "3tuv";
    cache[9] = "4wxyz";
    digits = str_handler(digits,'1');
    //数字长度
    digits_len = strlen(digits);
    //最终数组长度
    float final_len = 1;
    {
        for (int i = 0; i < digits_len; i++)
        {
            final_len *= cache[digits[i] - 48][0] - 48;
        }
        //返回指针数组
        returned = (char**)malloc(sizeof(char*) * final_len);
        *returnSize = (int)final_len;
    }
    int returned_index = 0;
    BFS(digits,0,digits_len,&returned_index);
    return returned;
}

int main_letter_combinations(void)
{
    int size;
    char** returned = letterCombinations("234", &size);
    for (int i = 0; i < size; i++)
    {
        char* tmp = returned[i];
        printf("%s ",tmp);
    }
    return 0;
}
