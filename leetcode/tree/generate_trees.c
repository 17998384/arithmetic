//
//  generate_trees.c
//  arithmetic
//
//  95. 不同的二叉搜索树 II

//  给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

//  Created by 我叫城北徐公° on 2021/2/19.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

typedef struct list
{
    int size;
    int capacity;
    Tree** trees;
}List;

List* new_list()
{
    List* list = calloc(1, sizeof(List));
    list->capacity = 16;
    list->trees = malloc(sizeof(Tree*) * list->capacity);
    list->size = 0;
    return list;
}

void free_list(List* list)
{
    if (!list) return;
    free(list->trees);
    free(list);
}

void add_list(List* list,Tree* tree)
{
    if (!list) return;
    if (list->capacity - 1 == list->size)
    {
        list->capacity <<= 1;
        list->trees = realloc(list->trees, sizeof(Tree*) * list->capacity);
    }
    list->trees[list->size++] = tree;
}

static Tree* new_tree(int val)
{
    Tree* tree = calloc(1,sizeof(Tree));
    tree->val = val;
    return tree;
}

 void copy_tree(Tree* root,Tree** _root)
 {
     if (!root) return;
     *_root = new_tree(root->val);
     copy_tree(root->left,&(*_root)->left);
     copy_tree(root->right,&(*_root)->right);
 }

static List* dfs(int start,int end,int size)
{
    List* list = new_list();
    if (start > size || end < 1 || start > end)
    {
        add_list(list, NULL);
        return list;
    }
    for (int i = start;i <= end;i++)
    {
        Tree* tree;
        List* left = dfs(start,i - 1,size);
        List* right = dfs(i + 1,end,size);
        for (int a = 0; a < left->size; a++)
        {
            for (int b = 0; b < right->size; b++)
            {
                tree = new_tree(i);
                tree->left = left->trees[a];
                tree->right = right->trees[b];
                add_list(list, tree);
            }
        }
        free_list(left);
        free_list(right);
    }
    return list;
}

struct TreeNode** generateTrees(int n, int* returnSize)
{
    *returnSize = 0;
    if (!n) return NULL;
    List* list = dfs(1,n,n);
    Tree** res = malloc(sizeof(Tree*) * list->size);
    for (int i = 0,size = list->size;i < size;i++) res[i] = list->trees[i];
    *returnSize = list->size;
    free_list(list);
    return res;
}

void main_generateTrees(void)
{
    int returnSize;
    Tree** res = generateTrees(8, &returnSize);
}
