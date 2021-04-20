//
//  smallest_from_leaf.c
//  arithmetic
//
//  988. 从叶结点开始的最小字符串
//
//  给定一颗根结点为 root 的二叉树，树中的每一个结点都有一个从 0 到 25 的值，分别代表字母 'a' 到 'z'：值 0 代表 'a'，值 1 代表 'b'，依此类推。
//
//  找出按字典序最小的字符串，该字符串从这棵树的一个叶结点开始，到根结点结束。
//
//  （小贴士：字符串中任何较短的前缀在字典序上都是较小的：例如，在字典序上 "ab" 比 "aba" 要小。叶结点是指没有子结点的结点。）
//
//
//
//  示例 1：
//
//  输入：[0,1,2,3,4,3,4]
//  输出："dba"
//
//
//  Created by 我叫城北徐公° on 2021/3/9.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_node.h"

typedef struct TreeNode Tree;
typedef struct list List;

static char** strArr;
static long buffer[26][4500];
static int cur;

struct list
{
    int size;
    int capacity;
    char* data;
};

static List* new_list()
{
    List* list = calloc(1, sizeof(List));
    list->size = 0;
    list->capacity = 16;
    list->data = malloc(sizeof(char) * list->capacity);
    return list;
}

static void add_list(List* list,char node)
{
    if (!list) return;
    if (list->capacity - 1 == list->size)
    {
        list->capacity <<= 1;
        list->data = realloc(list->data, sizeof(char) * list->capacity);
    }
    list->data[list->size++] = node;
}

static void list_remove_last(List* list)
{
    if (!list) return;
    --list->size;
}

static void dfs(Tree* root,List* list)
{
    if (!root) return;
    if (!root->left && !root->right)
    {
        add_list(list,(char)(root->val + 97));
        char* str = malloc(sizeof(char) * list->size + 1);
        for (int i = list->size - 1,j = 0;i >= 0;i--,j++) str[j] = list->data[i];
        str[list->size] = '\0';
        strArr[cur++] = str;
        list_remove_last(list);
        return;
    }
    add_list(list,(char)(root->val + 97));
    dfs(root->left,list);
    dfs(root->right,list);
    list_remove_last(list);
}

char * smallestFromLeaf(struct TreeNode* root)
{
    cur = 0;
    strArr = malloc(sizeof(char*) * 5500);
    dfs(root,new_list());
    int minChar,idx = 0;
    for (int i = 0;i < 26;i++) buffer[i][0] = 1;
    while (cur > 0)
    {
        minChar = 200;
        for (int i = 0;i < cur;i++)
        {
            char c = strArr[i][idx];
            int cIdx = c - 97;
            if (c == '\0') return strArr[i];
            if (strArr[i][idx] < minChar)
            {
                if (minChar != 200) buffer[minChar - 97][0] = 1;
                minChar = c;
                buffer[cIdx][buffer[cIdx][0]++] = (long)strArr[i];
            }
            else if (strArr[i][idx] == minChar) buffer[cIdx][buffer[cIdx][0]++] = (long)strArr[i];
        }
        int bIdx = minChar - 97;
        cur = (int)buffer[bIdx][0] - 1;
        if (cur == 1) return (char*)buffer[bIdx][1];
        idx++;
        for (int x = 0;x < cur;x++) strArr[x] = (char*)buffer[bIdx][x + 1];
        buffer[bIdx][0] = 1;
    }
    return (char*)buffer[minChar - 97][1];
}
