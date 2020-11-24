//
//  construct_maximum_binary_tree.c
//  arithmetic
//
//  654.最大二叉树
//
//  给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：
//
//      二叉树的根是数组中的最大元素。
//      左子树是通过数组中最大值左边部分构造出的最大二叉树。
//      右子树是通过数组中最大值右边部分构造出的最大二叉树。
//
//  通过给定的数组构建最大二叉树，并且输出这个树的根节点。
//
//
//
//  示例 ：
//
//  输入：[3,2,1,6,0,5]
//  输出：返回下面这棵树的根节点：
//
//        6
//      /   \
//     3     5
//      \    /
//       2  0
//         \
//          1

//  Created by 我叫城北徐公° on 2020/11/24.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

static void dfs_iter(struct TreeNode* root)
{
    if (!root)
        return;
    dfs_iter(root->left);
    printf("%d ",root->val);
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

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize)
{
    struct TreeNode* root;
    dfs(nums, 0, numsSize - 1, &root);
    return root;
}

int main_constructMaximumBinaryTree(void)
{
    int arr[] = {3,2,1,6,0,5};
    struct TreeNode* root = constructMaximumBinaryTree(arr, sizeof(arr)/sizeof(arr[0]));
    dfs_iter(root);
    return 0;
}
