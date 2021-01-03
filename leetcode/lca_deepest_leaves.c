//
//  lca_deepest_leaves.c
//  arithmetic
//
//  1123. 最深叶节点的最近公共祖先

//  给你一个有根节点的二叉树，找到它最深的叶节点的最近公共祖先。
//
//  回想一下：
//
//      叶节点 是二叉树中没有子节点的节点
//      树的根节点的 深度 为 0，如果某一节点的深度为 d，那它的子节点的深度就是 d+1
//      如果我们假定 A 是一组节点 S 的 最近公共祖先，S 中的每个节点都在以 A 为根节点的子树中，且 A 的深度达到此条件下可能的最大值。
//
//
//  Created by 我叫城北徐公° on 2021/1/3.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

#define DEBUG 0

static int depth;

static struct TreeNode* father;

void depth_dfs0(struct TreeNode* root,int cur_depth)
{
    if (!root) return;
    if (cur_depth > depth) depth = cur_depth;
    depth_dfs0(root->left, cur_depth + 1);
    depth_dfs0(root->right, cur_depth + 1);
}

int depth_dfs(struct TreeNode* root)
{
    depth = 0;
    depth_dfs0(root,1);
    return depth;
}

static void dfs(struct TreeNode* root)
{
    if (!root) return;
    depth = 0;
    int l_depth = depth_dfs(root->left);
    int r_depth = depth_dfs(root->right);
    if (DEBUG) printf("l_depth -> %d,r_depth -> %d\n",l_depth,r_depth);
    if (l_depth == r_depth)
    {
        father = root;
        return;
    }
    if (l_depth >= r_depth) dfs(root->left);
    else dfs(root->right);
}

struct TreeNode* lcaDeepestLeaves(struct TreeNode* root)
{
    father = NULL;
    dfs(root);
    return father;
}
