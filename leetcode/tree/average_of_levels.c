//
//  average_of_levels.c
//  arithmetic
//
//  637. 二叉树的层平均值
//
//  给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。
//
//
//
//  示例 1：
//
//  输入：
//      3
//     / \
//    9  20
//      /  \
//     15   7
//  输出：[3, 14.5, 11]
//  解释：
//  第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。
//
//
//  Created by 我叫城北徐公° on 2021/3/5.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

typedef struct list List;
typedef struct TreeNode Tree;

struct list
{
    int size;
    int capacity;
    double* data;
};

static List* new_list()
{
    List* list = calloc(1, sizeof(List));
    list->size = 0;
    list->capacity = 16;
    list->data = malloc(sizeof(double) * list->capacity);
    return list;
}

static void free_list(List* list)
{
    if (!list) return;
    free(list->data);
    free(list);
}

static void add_list(List* list,double node)
{
    if (!list) return;
    if (list->capacity - 1 == list->size)
    {
        list->capacity <<= 1;
        list->data = realloc(list->data, sizeof(double) * list->capacity);
    }
    list->data[list->size++] = node;
}

static List* bfs(Tree* root)
{
    List* list = new_list();
    if (!root) return list;
    //定义栈
    Tree* stack[12000];
    //指针，标记，深度
    int rsp = 0,rbp = 0;
    stack[rsp++] = root;
    add_list(list,root->val);
    while (rbp < rsp)
    {
        int rspBak = rsp;
        double sum = 0;
        int count = 0;
        while (rbp < rspBak)
        {
            Tree* node = stack[rbp++];
            if (node->left)
            {
                stack[rsp++] = node->left;
                sum += node->left->val;
                count++;
            }
            if (node->right)
            {
                stack[rsp++] = node->right;
                sum += node->right->val;
                count++;
            }
        }
        add_list(list,sum / count);
    }
    return list;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* averageOfLevels(struct TreeNode* root, int* returnSize)
{
    List* list = bfs(root);
    *returnSize = list->size - 1;
    return list->data;
}
