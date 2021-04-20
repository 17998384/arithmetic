//
//  min_depth.c
//  arithmetic
//
//  111. 二叉树的最小深度
//
//  给定一个二叉树，找出其最小深度。
//
//  最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//
//  说明：叶子节点是指没有子节点的节点。
//
//
//
//  示例 1：
//
//  输入：root = [3,9,20,null,null,15,7]
//  输出：2
//
//  示例 2：
//
//  输入：root = [2,null,3,null,4,null,5,null,6]
//  输出：5
//
//
//  Created by 我叫城北徐公° on 2021/3/13.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

static void dfs(Tree* root,int depth,int* min)
{
    if (!root) return;
    if (!root->left && !root->right)
    {
        if (depth < *min) *min = depth;
        return;
    }
    dfs(root->left,depth + 1,min);
    dfs(root->right,depth + 1,min);
}

int minDepth(struct TreeNode* root)
{
    if (!root) return 0;
    int min = 0x7FFFFFFF;
    dfs(root,1,&min);
    return min;
}
