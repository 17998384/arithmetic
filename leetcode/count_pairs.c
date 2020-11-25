//
//  count_pairs.c
//  arithmetic
//
//  1530.好叶子节点对的数量
//
//  给你二叉树的根节点 root 和一个整数 distance 。
//
//  如果二叉树中两个 叶 节点之间的 最短路径长度 小于或者等于 distance ，那它们就可以构成一组 好叶子节点对 。
//
//  返回树中 好叶子节点对的数量 。

//
//  Created by 我叫城北徐公° on 2020/11/25.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree_node.h"

struct TreeNode* stack[1024];

int stack_p;

static void dfs2(struct TreeNode* root,struct TreeNode* wait_compare_node,int* current_trace,int distance,int* count)
{
    if (!root)
        return;
    (*current_trace)++;
    if (*current_trace > distance)
    {
        (*current_trace)--;
        return;
    }
    if (root->left != wait_compare_node) dfs2(root->left,wait_compare_node,current_trace,distance,count);
    if (!root->left && !root->right)
        (*count)++;
    if (root->right != wait_compare_node) dfs2(root->right,wait_compare_node,current_trace,distance,count);
    (*current_trace)--;
}

static void handler(int distance,int* count)
{
    //拷贝一个新的栈
    struct TreeNode* tmp_stack[stack_p];
    memcpy(tmp_stack, stack, sizeof(struct TreeNode*) * stack_p);
    int tmp_stack_p = stack_p;
    struct TreeNode* wait_compare_node = tmp_stack[--tmp_stack_p];
    struct TreeNode* tmp_node = NULL;
    int current_trace = 0;
    int trace = 0;
    while (tmp_stack_p > 0)
    {
        tmp_node = tmp_stack[--tmp_stack_p];
        dfs2(tmp_node, wait_compare_node, &current_trace, distance,count);
        current_trace = ++trace;
        wait_compare_node = tmp_node;
    }
    
}

static void dfs(struct TreeNode* root,int distance,int* count)
{
    if (!root)
        return;
    stack[stack_p++] = root;
    dfs(root->left,distance,count);
    if (!root->left && !root->right)
        handler(distance,count);
    dfs(root->right,distance,count);
    --stack_p;
}

int countPairs(struct TreeNode* root, int distance)
{
    stack_p = 0;
    int count = 0;
    dfs(root, distance,&count);
    return count / 2;
}

int main_countPairs(void)
{
    struct TreeNode* tree = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->val = 1;
    tree->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->left->val = 2;
    tree->left->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->left->left->val = 4;
    tree->left->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->left->right->val = 5;
    tree->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->right->val = 3;
    tree->right->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->right->left->val = 6;
    tree->right->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->right->right->val = 7;
    int sum = countPairs(tree, 4);
    printf("%d\n",sum);
    return 0;
}
