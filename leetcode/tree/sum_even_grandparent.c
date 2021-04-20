//
//  sum_even_grandparent.c
//  arithmetic
//
//  1315. 祖父节点值为偶数的节点和
//
//  给你一棵二叉树，请你返回满足以下条件的所有节点的值之和：
//
//      该节点的祖父节点的值为偶数。（一个节点的祖父节点是指该节点的父节点的父节点。）
//
//  如果不存在祖父节点值为偶数的节点，那么返回 0 。
//
//
//  Created by 我叫城北徐公° on 2021/2/3.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

//思路：若当前节点为偶数，则加上孙子节点的和
int get_sum(struct TreeNode* node)
{
    int sum = 0;
    if (node)
    {
        if (node->left) sum += node->left->val;
        if (node->right) sum += node->right->val;
    }
    return sum;
}

static void dfs(struct TreeNode* root,int* sum)
{
    if (!root) return;
    /*
        binary 00010
                   |
            该位为0一定是偶数
    */
    if (!(root->val & 1))
    {
        (*sum) += get_sum(root->left);
        (*sum) += get_sum(root->right);
    }
    /*
        保证孙子节点不为NULL才继续
    */
    if (root->left && (root->left->left || root->left->right)) dfs(root->left,sum);
    if (root->right && (root->right->left || root->right->right)) dfs(root->right,sum);
}

int sumEvenGrandparent(struct TreeNode* root)
{
    int sum = 0;
    dfs(root,&sum);
    return sum;
}
