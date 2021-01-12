//
//  CBT_Inserter.c
//  arithmetic
//
//  919.完全二叉树插入器
//
//
//  完全二叉树是每一层（除最后一层外）都是完全填充（即，节点数达到最大）的，并且所有的节点都尽可能地集中在左侧。
//
//  设计一个用完全二叉树初始化的数据结构 CBTInserter，它支持以下几种操作：
//
//      CBTInserter(TreeNode root) 使用头节点为 root 的给定树初始化该数据结构；
//      CBTInserter.insert(int v)  向树中插入一个新节点，节点类型为 TreeNode，值为 v //    。使树保持完全二叉树的状态，并返回插入的新节点的父节点的值；
//      CBTInserter.get_root() 将返回树的头节点。
//
//
//
//  示例 1：
//
//  输入：inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
//  输出：[null,1,[1,2]]
//
//  示例 2：
//
//  输入：inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
//  输出：[null,3,4,[1,2,3,4,5,6,7,8]]
//
//  Created by 我叫城北徐公° on 2021/1/12.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

#define BUFFER_SIZE 15000

typedef struct CBT_inserter
{
    struct TreeNode** buffer;
    int cur;
} CBTInserter;

struct TreeNode* new_node(int val)
{
    struct TreeNode* new_node = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    new_node->val = val;
    return new_node;
}

static void bfs(struct TreeNode* root,CBTInserter* cbtInserter)
{
    if (!root)
    {
        cbtInserter->buffer[0] = NULL;
        return;
    }
    struct TreeNode* stack[1000];
    int p1 = 0,p2 = 0;
    stack[p2++] = root;
    while (p1 != p2)
    {
        struct TreeNode* cur = stack[p1++];
        cbtInserter->buffer[cbtInserter->cur++] = cur;
        if (cur->left) stack[p2++] = cur->left;
        if (cur->right) stack[p2++] = cur->right;
    }
}

CBTInserter* cBTInserterCreate(struct TreeNode* root)
{
    CBTInserter* cbtInserter = (CBTInserter*)malloc(sizeof(CBTInserter));
    cbtInserter->cur = 1;
    //初始化数组
    cbtInserter->buffer = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * BUFFER_SIZE);
    bfs(root,cbtInserter);
    return cbtInserter;
}

int cBTInserterInsert(CBTInserter* obj, int v)
{
    int cur = obj->cur;
    int father = cur / 2;
    obj->buffer[obj->cur++] = new_node(v);
    //检验左右
    int isL = cur % 2 == 0 ? 1 : 0;
    if (father > 0)
    {
        if (isL) obj->buffer[father]->left = obj->buffer[cur];
        else obj->buffer[father]->right = obj->buffer[cur];
    }
    return father > 0 ? obj->buffer[father]->val : obj->buffer[1]->val;
}

struct TreeNode* cBTInserterGet_root(CBTInserter* obj)
{
    return obj->buffer[1];
}

void cBTInserterFree(CBTInserter* obj)
{
    printf("call free\n");
    free(obj->buffer);
}

/**
 * Your CBTInserter struct will be instantiated and called as such:
 * CBTInserter* obj = cBTInserterCreate(root);
 * int param_1 = cBTInserterInsert(obj, v);
 
 * struct TreeNode* param_2 = cBTInserterGet_root(obj);
 
 * cBTInserterFree(obj);
*/
