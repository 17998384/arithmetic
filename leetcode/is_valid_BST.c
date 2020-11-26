//
//  is_valid_BST.c
//  arithmetic
//
//  面试题 04.05. 合法二叉搜索树
//
//  实现一个函数，检查一棵二叉树是否为二叉搜索树。
//  示例 1:
//
//  输入:
//      2
//     / \
//    1   3
//  输出: true
//
//  示例 2:
//
//  输入:
//      5
//     / \
//    1   4
//       / \
//      3   6
//  输出: false
//  解释: 输入为: [5,1,4,null,null,3,6]。
//       根节点的值为 5 ，但是其右子节点值为 4 。
//
//  Created by 我叫城北徐公° on 2020/11/26.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

static int current;

static void dfs(struct TreeNode* root,int* valid)
{
    if (!root) return;
    if (!*valid) return;
    dfs(root->left, valid);
    if (current == -1) current = root->val;
    else
    {
        if (root->val <= current)
            *valid = 0;
        current = root->val;
    }
    dfs(root->right, valid);
}

int isValidBST(struct TreeNode* root)
{
    int valid = 1;
    current = -1;
    dfs(root, &valid);
    return valid;
}
