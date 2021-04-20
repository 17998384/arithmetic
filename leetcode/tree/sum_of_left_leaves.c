//
//  sum_of_left_leaves.c
//  arithmetic
//
//  404. 左叶子之和
//
//  计算给定二叉树的所有左叶子之和。
//
//  示例：
//
//      3
//     / \
//    9  20
//      /  \
//     15   7
//
//  在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
//
//

//  Created by 我叫城北徐公° on 2021/2/2.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

static void dfs(struct TreeNode* root,int* sum)
{
    if (!root) return;
    if (root->left && !root->left->left && !root->left->right) *sum += root->left->val;
    dfs(root->left,sum);
    dfs(root->right,sum);
}

int sumOfLeftLeaves(struct TreeNode* root)
{
    int sum = 0;
    dfs(root,&sum);
    return sum;
}
