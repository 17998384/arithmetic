//
//  trie.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/12/6.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//前缀树，利用二维数组模拟树

const int MAX_NODE = 100000;
const int CHAR_SIZE = 26;


static int nodes[MAX_NODE][CHAR_SIZE] = {0};
static int color[MAX_NODE] = {0};
static int k = 1;

static void add(char* s)
{
    int len = (int)strlen(s);
    if (len == 0) return;
    //默认从根节点添加
    int p = 0;
    for (int i = 0; i < len; ++i)
    {
        int c = s[i] - 97;
        while (nodes[p][c]) p = nodes[p][c];
        nodes[p][c] = k;
        p = k;
        ++k;
    }
    color[p] = 1;
}

static char* find(char* s)
{
    int len = (int)strlen(s);
    //从根节点寻找
    int p = 0;
    for (int i = 0; i < len; ++i)
    {
        int c = s[i] - 97;
        if (!nodes[p][c]) return "NO FIND";
        p = nodes[p][c];
    }
    return color[p] == 1 ? "IS FIND" : "NO FIND";
}

int main_tric(void)
{
    int add_count;
    int find_count;
    printf("请输入要插入的字符串数量:\n");
    scanf("%d",&add_count);
    printf("请输入要查找的字符串数量:\n");
    scanf("%d",&find_count);
    printf("add_count -> %d,find_count -> %d\n", add_count,find_count);
    getchar();
    printf("请循环输入要插入的字符串:\n");
    for (int i = 0; i < add_count; ++i)
    {
        char* s = (char*)calloc(20,sizeof(char));
        gets(s);
        add(s);
    }
    printf("输入完毕\n");
    printf("请循环输入要查找的字符串:\n");
    for (int i = 0; i < find_count; ++i)
    {
        char* s = (char*)calloc(20,sizeof(char));
        gets(s);
        char* result = find(s);
        printf("字符串%s找到结果为:%s\n", s,result);
    }
    return 0;
}
