//
//  kth_largest.c
//  arithmetic
//
//  剑指offer 54. 二叉搜索树的第k大节点

//  给定一棵二叉搜索树，请找出其中第k大的节点。
//
//
//
//  示例 1:
//
//  输入: root = [3,1,4,null,2], k = 1
//     3
//    / \
//   1   4
//    \
//     2
//  输出: 4
//
//  示例 2:
//
//  输入: root = [5,3,6,2,4,null,null,1], k = 3
//         5
//        / \
//       3   6
//      / \
//     2   4
//    /
//   1
//  输出: 4
//
//
//
//  限制：
//
//  1 ≤ k ≤ 二叉搜索树元素个数


//  Created by 我叫城北徐公° on 2020/11/24.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

int count = 0;

int val;

static void dfs(struct TreeNode* root,int k)
{
    if (!root)
        return;
    dfs(root->right,k);
    if(++count == k)
    {
        val = root->val;
        return;
    }
    dfs(root->left,k);
}

int kthLargest(struct TreeNode* root, int k)
{
    count = 0;
    val = 0;
    dfs(root,k);
    return val;
}
