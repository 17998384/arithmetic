//
//  has_path_sum.c
//  arithmetic
//
//  112.路径总和
//
//  给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
//
//  说明: 叶子节点是指没有子节点的节点。
//
//  示例:
//  给定如下二叉树，以及目标和 sum = 22，
//
//                5
//               / \
//              4   8
//             /   / \
//            11  13  4
//           /  \      \
//          7    2      1
//
//  返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

//  Created by 我叫城北徐公° on 2020/11/26.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

int total;

int flag;

static void dfs(struct TreeNode* root, int sum)
{
    if (!root) return;
    if (flag) return;
    total += root->val;
    if (total == sum && !root->left && !root->right) flag = 1;
    dfs(root->left, sum);
    dfs(root->right, sum);
    total -= root->val;
}

int hasPathSum(struct TreeNode* root, int sum)
{
    total = 0;
    flag = 0;
    dfs(root, sum);
    return flag;
}
