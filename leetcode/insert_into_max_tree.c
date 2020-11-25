//
//  insertInto_max_tree.c
//  arithmetic
//
//  998. 最大二叉树 II
//
//  最大树定义：一个树，其中每个节点的值都大于其子树中的任何其他值。
//
//  给出最大树的根节点 root。
//
//  就像之前的问题那样，给定的树是从表 A（root = Construct(A)）递归地使用下述 Construct(A) 例程构造的：
//
//      如果 A 为空，返回 null
//      否则，令 A[i] 作为 A 的最大元素。创建一个值为 A[i] 的根节点 root
//      root 的左子树将被构建为 Construct([A[0], A[1], ..., A[i-1]])
//      root 的右子树将被构建为 Construct([A[i+1], A[i+2], ..., A[A.length - 1]])
//      返回 root
//
//  请注意，我们没有直接给定 A，只有一个根节点 root = Construct(A).
//
//  假设 B 是 A 的副本，并附加值 val。保证 B 中的值是不同的。
//
//  返回 Construct(B)。

//  Created by 我叫城北徐公° on 2020/11/24.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

static int* nums;

int numsSize = 0;

int max = -1000;

int max_idx;

static void dfs_iter(struct TreeNode* root)
{
    if (!root)
        return;
    dfs_iter(root->left);
    if (max < root->val)
    {
        max = root->val;
        max_idx = numsSize;
    }
    nums[numsSize++] = root->val;
    dfs_iter(root->right);
}

static void dfs(int* nums,int start,int end,struct TreeNode** root)
{
    if (start > end)
        return;
    //找最大数
    int max = nums[start];
    int max_idx = start;
    for (int i = start; i <= end; i++)
    {
        if (max < nums[i])
        {
            max = nums[i];
            max_idx = i;
        }
    }
    (*root) = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    (*root)->val = max;
    dfs(nums, start, max_idx - 1, &(*root)->left);
    dfs(nums, max_idx + 1, end, &(*root)->right);
}

struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val)
{
    if (!root)
        return NULL;
    if (val > root->val)
    {
        struct TreeNode* newRoot = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
        newRoot->val = val;
        newRoot->left = root;
        return newRoot;
    }
    nums = (int*)malloc(sizeof(int) * 110);
    dfs_iter(root);
    nums[numsSize++] = val;
    struct TreeNode* right;
    dfs(nums, max_idx + 1, numsSize - 1, &right);
    root->right = right;
    return root;
}
