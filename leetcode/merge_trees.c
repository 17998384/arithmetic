//
//  merge_trees.c
//  arithmetic
//
//  617. 合并二叉树

// 给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

//  你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

//  Created by 我叫城北徐公° on 2021/1/3.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

static void dfs(struct TreeNode* t1, struct TreeNode* t2, struct TreeNode** root)
{
    if (!t1 && !t2) return;
    if (t1 && t2)
    {
        t1->val += t2->val;
        *root = t1;
    }
    else if (t1 && !t2) *root = t1;
    else *root = t2;
    dfs(t1 ? t1->left : NULL, t2 ? t2->left : NULL,&(*root)->left);
    dfs(t1 ? t1->right : NULL, t2 ? t2->right : NULL,&(*root)->right);
}

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2)
{
    struct TreeNode* root = NULL;
    dfs(t1,t2,&root);
    return root;
}
