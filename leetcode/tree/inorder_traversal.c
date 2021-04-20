//
//  inorder_traversal.c
//  arithmetic
//
//  94.二叉树的中序遍历

//  给定一个二叉树的根节点 root ，返回它的 中序 遍历。（不允许使用递归）
//
//  Created by 我叫城北徐公° on 2020/11/24.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

static int* nums;

/// 递归版（dfs）
/// @param root 根节点
/// @param returnSize 返回大小
static void dfs(struct TreeNode* root, int* returnSize)
{
    if (!root)
        return;
    dfs(root->left, returnSize);
    nums[(*returnSize)++] = root->val;
    dfs(root->right, returnSize);
}

/// 循环版
/// @param root 根节点
/// @param returnSize 返回大小
static void loop(struct TreeNode* root, int* returnSize)
{
    long long stack[1000] = {0};
    int s_p = 0;
    struct TreeNode* node = root;
    while (node || s_p > 0)
    {
        if (node)
        {
            stack[s_p++] = (long long)node;
            node = node->left;
        }
        else
        {
            node = (struct TreeNode*)stack[--s_p];
            nums[(*returnSize)++] = node->val;
            node = node->right;
        }
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    nums = (int*)malloc(sizeof(int) * 150);
//    dfs(root, returnSize);
    loop(root, returnSize);
    return nums;
}
