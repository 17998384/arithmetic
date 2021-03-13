//
//  range_sum_BST.c
//  arithmetic
//
//  938. 二叉搜索树的范围和

//  给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之间的所有结点的值的和。
//
//  输入：root = [10,5,15,3,7,null,18], low = 7, high = 15
//  输出：32

//  Created by 我叫城北徐公° on 2021/3/11.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

static void dfs(Tree* root,int low,int high,int* sum)
{
    if (!root) return;
    if (root->val >= low) dfs(root->left,low,high,sum);
    if (root->val >= low && root->val <= high) (*sum) += root->val;
    if (root->val <= high) dfs(root->right,low,high,sum);
}

int rangeSumBST(struct TreeNode* root, int low, int high)
{
    int sum = 0;
    dfs(root,low,high,&sum);
    return sum;
}
