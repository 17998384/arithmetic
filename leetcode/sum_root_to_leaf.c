//
//  sum_root_to_leaf.c
//  arithmetic
//
//  1022. 从根到叶的二进制数之和
//
//  给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。例如，如果路径为 0 -> 1 -> 1 -> 0
// -> 1，那么它表示二进制数 01101，也就是 13 。
//
//  对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。
//
//  返回这些数字之和。题目数据保证答案是一个 32 位 整数。
//
//
//  Created by 我叫城北徐公° on 2020/11/28.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"
#include "my_lib.h"

static char buffer[2000];
static int idx;

static void dfs(struct TreeNode* root,int* res_p)
{
    if (!root) return;
    buffer[idx++] = root->val + 48;
    dfs(root->left, res_p);
    dfs(root->right, res_p);
    //叶子节点
    if (!root->left && !root->right)
    {
        buffer[idx] = '\0';
        (*res_p) += binary_to_int(buffer);
    }
    idx--;
}

int sumRootToLeaf(struct TreeNode* root)
{
    int res = 0;
    idx = 0;
    dfs(root,&res);
    return res;
}
