//
//  subtree_with_all_deepest.c
//  arithmetic
//
//  865.具有所有最深节点的最小子树
//
//  给定一个根为 root 的二叉树，每个节点的深度是 该节点到根的最短距离 。
//
//  如果一个节点在 整个树 的任意节点之间具有最大的深度，则该节点是 最深的 。
//
//  一个节点的 子树 是该节点加上它的所有后代的集合。
//
//  返回能满足 以该节点为根的子树中包含所有最深的节点 这一条件的具有最大深度的节点。
//
//  （通俗点说，就是找到最深的所有节点，然后取他们的公共节点；如果最深的节点只有一个，那就是他自己）
//
//  注意：本题与力扣 1123 重复：https://leetcode-cn.com/problems/lowest-common-ancestor-of-deepest-leaves/

//  Created by 我叫城北徐公° on 2020/11/27.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

typedef struct my_tree_node
{
    struct TreeNode* current;
    struct my_tree_node* father;
}MyTreeNode;

//栈
static MyTreeNode* stack[500];

static int stack_p;

static int max_depth;

static MyTreeNode* newMyTreeNode(struct TreeNode* root,MyTreeNode* father)
{
    MyTreeNode* myTreeNode = (MyTreeNode*)calloc(1,sizeof(MyTreeNode));
    myTreeNode->current = root;
    myTreeNode->father = father;
    return myTreeNode;
}

static void dfs(struct TreeNode* root,struct my_tree_node* father,int* depth)
{
    if (!root) return;
    //包装一个自己的结构体
    (*depth)++;
    father = newMyTreeNode(root, father);
    dfs(root->left, father,depth);
    dfs(root->right, father,depth);
    if (*depth > max_depth)
    {
        stack_p = 0;
        stack[stack_p++] = father;
        max_depth = *depth;
    }
    else if (*depth == max_depth)
        stack[stack_p++] = father;
    (*depth)--;
}

static struct TreeNode* handler()
{
    //如果当前长度只有一个的话，那说明就是他自己
    if (stack_p == 1) return stack[0]->current;
    //找出它们公共的父节点，判断是否一致，一致则返回该节点，否则再次向上寻找
    int begin = 0;
    int end = 0;
    struct TreeNode* res = NULL;
    while (!res)
    {
        struct TreeNode* father = NULL;
        end = stack_p;
        int flag = 1;
        for (int i = begin; i < end; i++)
        {
            stack[stack_p++] = stack[i]->father;
            if (!father)
            {
                father = stack[i]->father->current;
                continue;
            }
            //如果出现父亲不相同，则判定失误
            if (father->val != stack[i]->father->current->val)
                flag = 0;
            father = stack[i]->father->current;
        }
        if (flag)
            res = father;
        begin = end;
    }
    return res;
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root)
{
    stack_p = 0;
    max_depth = 0;
    int depth = 0;
    dfs(root, NULL, &depth);
    //检测遍历
//    for (int i = 0; i < stack_p; i++)
//    {
//        printf("current node val : %d ,current father val : %d"
//               ,stack[i]->current->val,stack[i]->father != NULL ? stack[i]->father->current->val : 0);
//    }
    return handler();
}
