//
//  max_depth2.c
//  arithmetic
//
//  104. 二叉树的最大深度
//
//  给定一个二叉树，找出其最大深度。
//
//  二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
//
//  说明: 叶子节点是指没有子节点的节点。
//
//  示例：
//  给定二叉树 [3,9,20,null,null,15,7]，
//
//      3
//     / \
//    9  20
//      /  \
//     15   7
//
//  返回它的最大深度 3 。
//
//
//  Created by 我叫城北徐公° on 2021/3/17.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Tree;
    
static int maxDepth1;

static void dfs(Tree* root,int curDepth)
{
    if (!root) return;
    if (curDepth > maxDepth1) maxDepth1 = curDepth;
    dfs(root->left,curDepth + 1);
    dfs(root->right,curDepth + 1);
}

int maxDepth2(struct TreeNode* root)
{
    maxDepth1 = 0;
    dfs(root,1);
    return maxDepth1;
}
