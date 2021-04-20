//
//  kth_smallest.c
//  arithmetic
//
//  230. 二叉搜索树中第K小的元素
//
//  给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
//
//  说明：
//  你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
//
//  示例 1:
//
//  输入: root = [3,1,4,null,2], k = 1
//     3
//    / \
//   1   4
//    \
//     2
//  输出: 1
//
//
//  Created by 我叫城北徐公° on 2021/2/2.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

static void dfs(struct TreeNode* root,int k,int* idx,int* val)
{
    if (!root) return;
    dfs(root->left,k,idx,val);
    if (*idx == k && *idx != -1)
    {
        *val = root->val;
        *idx = -1;
        return;
    }
    if (*idx != -1) (*idx)++;
    dfs(root->right,k,idx,val);
}

int kthSmallest(struct TreeNode* root, int k)
{
    int idx = 1,res = 0;
    dfs(root,k,&idx,&res);
    return res;
}
