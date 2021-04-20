//
//  insert_into_BST.c
//  arithmetic
//
//  701. 二叉搜索树中的插入操作
//
//  给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。
//
//  注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。
//
//  Created by 我叫城北徐公° on 2021/1/12.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

static struct TreeNode* new_node(int val)
{
    struct TreeNode* node = calloc(1,sizeof(struct TreeNode));
    node->val = val;
    return node;
}

static void dfs(struct TreeNode** root,int val)
{
    if (!(*root))
    {
        (*root) = new_node(val);
        return;
    }
    if (val < (*root)->val) dfs(&(*root)->left,val);
    else dfs(&(*root)->right,val);
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val)
{
    dfs(&root,val);
    return root;
}
