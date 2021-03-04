//
//  min_diffIn_BST.c
//  arithmetic
//
//  783. 二叉搜索树节点最小距离
//
//  给定一个二叉搜索树的根节点 root，返回树中任意两节点的差的最小值。
//
//  Created by 我叫城北徐公° on 2021/2/25.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

int min,lastNum;

static void dfs(Tree* root)
{
    if (!root) return;
    dfs(root->left);
    if (lastNum != 0x80000000) min = min < (root->val - lastNum) ? min : root->val - lastNum;
    lastNum = root->val;
    dfs(root->right);
}

int minDiffInBST(struct TreeNode* root)
{
    min = 0x7FFFFFFF;
    lastNum = 0x80000000;
    dfs(root);
    return min;
}
