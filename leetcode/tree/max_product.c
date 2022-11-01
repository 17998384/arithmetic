//
//  max_product.c
//  arithmetic
//
//  1339.分裂二叉树的最大乘积
//
//  给你一棵二叉树，它的根为 root 。请你删除 1 条边，使二叉树分裂成两棵子树，且它们子树和的乘积尽可能大。
//
//  由于答案可能会很大，请你将结果对 10^9 + 7 取模后再返回。
//
//  Created by 我叫城北徐公° on 2021/1/5.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "tree_node.h"

static long total;
static long max;

long calc_dfs(struct TreeNode* root)
{
    if (!root) return 0L;
    long L = calc_dfs(root->left);
    long R = calc_dfs(root->right);
    long sum = L + R + root->val;
    return sum;
}

static long dfs(struct TreeNode* root)
{
    if (!root) return 0L;
    long L = dfs(root->left);
    long R = dfs(root->right);
    long sum = L + R + root->val;
    long product = (total - sum) * sum;
    max = product > max ? product : max;
    return sum;
}

static int maxProduct(struct TreeNode* root)
{
    max = 0;
    total = calc_dfs(root);
    dfs(root);
    return max % (long)(pow(10,9) + 7);
}

