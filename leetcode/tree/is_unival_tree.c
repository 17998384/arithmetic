//
//  is_unival_tree.c
//  arithmetic
//
//  965. 单值二叉树
//
//  如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
//
//  只有给定的树是单值二叉树时，才返回 true；否则返回 false。
//
//
//
//  示例 1：
//
//  输入：[1,1,1,1,1,null,1]
//  输出：true
//
//
//  Created by 我叫城北徐公° on 2021/2/2.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

static int dfs(struct TreeNode* root,int lastVal)
{
    if (!root) return 1;
    if (root->val ^ lastVal) return 0;
    return dfs(root->left,root->val) && dfs(root->right,root->val);
}

int isUnivalTree(struct TreeNode* root)
{
    return dfs(root,root->val);
}
