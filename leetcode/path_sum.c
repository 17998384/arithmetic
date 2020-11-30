//
//  path_sum.c
//  arithmetic
//
//  面试题04.12 求和路径
//
//  给定一棵二叉树，其中每个节点都含有一个整数数值
//   (该值或正或负)。设计一个算法，打印节点数值总和等于某个给定值的所有路径的数量。注意，路径不一定非得从二叉树的根节点或叶节点
//    开始或结束，但是其方向必须向下(只能从父节点指向子节点方向)。
//
//  示例:
//  给定如下二叉树，以及目标和 sum = 22，
//
//                5
//               / \
//              4   8
//             /   / \
//            11  13  4
//           /  \    / \
//          7    2  5   1
//
//  返回:
//
//  3
//  解释：和为 22 的路径有：[5,4,11,2], [5,8,4,5], [4,11,7]

//  Created by 我叫城北徐公° on 2020/11/27.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

static int total;

static int num;

static void dfs2(struct TreeNode* root,int sum)
{
    if (!root) return;
    total += root->val;
    if (total == sum) num++;
    dfs2(root->left,sum);
    dfs2(root->right,sum);
    total -= root->val;
}

static void dfs(struct TreeNode* root,int sum)
{
    if (!root) return;
    total = 0;
    dfs2(root,sum);
    dfs(root->left,sum);
    dfs(root->right,sum);
}

int pathSum(struct TreeNode* root, int sum)
{
    num = 0;
    dfs(root,sum);
    return num;
}
