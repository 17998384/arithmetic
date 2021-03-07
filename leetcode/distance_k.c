//
//  distance_k.c
//  arithmetic
//
//  863. 二叉树中所有距离为 K 的结点
//
//  给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 K 。
//
//  返回到目标结点 target 距离为 K 的所有结点的值的列表。 答案可以以任何顺序返回。
//
//  Created by 我叫城北徐公° on 2021/3/7.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

typedef struct TreeNode Tree;
typedef struct list List;

static char* cache;

struct list
{
    int size;
    int capacity;
    int* data;
};

static List* new_list()
{
    List* list = calloc(1, sizeof(List));
    list->size = 0;
    list->capacity = 16;
    list->data = malloc(sizeof(int) * list->capacity);
    return list;
}

static void add_list(List* list,int node)
{
    if (!list) return;
    if (list->capacity - 1 == list->size)
    {
        list->capacity <<= 1;
        list->data = realloc(list->data, sizeof(int) * list->capacity);
    }
    list->data[list->size++] = node;
}

static void calc_dfs(Tree* root,int target,int depth,int K,List* list)
{
    if (!root || K < 0) return;
    if (depth == K && root->val != target && !cache[root->val]) add_list(list,root->val);
    //遍历过的需要标记，否则会导致重复计算
    cache[root->val] = 1;
    calc_dfs(root->left,target,depth + 1,K,list);
    calc_dfs(root->right,target,depth + 1,K,list);
}

static void dfs(Tree* root,int target,int* K,int* flag,List* list)
{
    if (!root) return;
    if (root->val == target)
    {
        //如果K为0，说明范围是0，只需要添加它本身即可
        if (!*K)
        {
            add_list(list,root->val);
        }
        //否则计算该节点下所有子节点是否有满足条件的
        else calc_dfs(root,target,0,*K,list);
        //标记
        *flag = 1;
        return;
    }
    
    //触发标记后不再继续递归
    if (!*flag) dfs(root->left,target,K,flag,list);
    if (!*flag) dfs(root->right,target,K,flag,list);
    
    //开始寻找每个上级节点，然后进行计算，直到根节点
    if (*flag)
    {
        calc_dfs(root,target,0,*K - 1,list);
        (*K)--;
    }
}

int* distanceK(struct TreeNode* root, struct TreeNode* target, int K, int* returnSize)
{
    List* list = new_list();
    cache = calloc(1001,sizeof(char));
    int flag = 0;
    dfs(root,target->val,&K,&flag,list);
    free(cache);
    *returnSize = list->size;
    return list->data;
}
