//
//  remove_leaf_nodes.c
//  arithmetic
//
//  1325. 删除给定值的叶子节点

//  给你一棵以 root 为根的二叉树和一个整数 target ，请你删除所有值为 target 的 叶子节点 。
//
//  注意，一旦删除值为 target 的叶子节点，它的父节点就可能变成叶子节点；如果新叶子节点的值恰好也是 target ，那么这个节点也应该被删除。
//
//  也就是说，你需要重复此过程直到不能继续删除。
//
//
//
//  示例 1：
//
//  输入：root = [1,2,3,2,null,2,4], target = 2
//  输出：[1,null,3,null,4]
//  解释：
//  上面左边的图中，绿色节点为叶子节点，且它们的值与 target 相同（同为 2 ），它们会被删除，得到中间的图。
//  有一个新的节点变成了叶子节点且它的值与 target 相同，所以将再次进行删除，从而得到最右边的图。
//
//
//
//  Created by 我叫城北徐公° on 2021/3/14.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

static void dfs(Tree** root,int target)
{
    if (!(*root)) return;
    if (!(*root)->left && !(*root)->right)
    {
        if ((*root)->val == target) (*root) = NULL;
        return;
    }
    dfs(&(*root)->left,target);
    dfs(&(*root)->right,target);
    if (!(*root)->left && !(*root)->right)
    {
        if ((*root)->val == target) (*root) = NULL;
    }
}

struct TreeNode* removeLeafNodes(struct TreeNode* root, int target)
{
    dfs(&root,target);
    return root;
}
