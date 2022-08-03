//
//  prune_tree.c
//  arithmetic
//
//  814.二叉树剪枝
//
//  给定二叉树根结点 root ，此外树的每个结点的值要么是 0，要么是 1。
//
//  返回移除了所有不包含 1 的子树的原二叉树。
//
//  ( 节点 X 的子树为 X 本身，以及所有 X 的后代。)
//
//  示例1:
//  输入: [1,null,0,0,1]
//  输出: [1,null,0,null,1]
//
//  解释:
//  只有红色节点满足条件“所有不包含 1 的子树”。
//  右图为返回的答案。

//  Created by 我叫城北徐公° on 2020/11/26.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

static int dfs(struct TreeNode* root)
{
    if (!root) return 0;
    int L = dfs(root->left);
    int R = dfs(root->right);
    if (!L) root->left = NULL;
    if (!R) root->right = NULL;
    return root->val | L | R;
}

static void dfs_iter(struct TreeNode* root)
{
    if (!root) return;
    printf("%d ",root->val);
    dfs_iter(root->left);
    dfs_iter(root->right);
}

static struct TreeNode* pruneTree(struct TreeNode* root)
{
    dfs(root);
    if (!root->left && !root->right && !root->val) return NULL;
    return root;
}

int main_pruneTree(void)
{
    //[1,null,0,0,1]
    struct TreeNode* A = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    A->val = 1;
//    A->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
//    A->left->val = 4;
    A->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    A->right->val = 0;
    A->right->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    A->right->left->val = 0;
    A->right->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    A->right->right->val = 1;
    A = pruneTree(A);
    dfs_iter(A);
    return 0;
}
