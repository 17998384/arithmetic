//
//  search_BST.c
//  arithmetic
//
//  700. 二叉搜索树中的搜索
//
//  给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。
//
//  例如，
//
//  给定二叉搜索树:
//
//          4
//         / \
//        2   7
//       / \
//      1   3
//
//  和值: 2
//
//
//  Created by 我叫城北徐公° on 2021/3/8.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

static void dfs(Tree* root,int val,Tree** res)
{
    if (!root) return;
    if (root->val == val)
    {
        *res = root;
        return;
    }
    if (root->val > val) dfs(root->left,val,res);
    if (root->val < val) dfs(root->right,val,res);
}

struct TreeNode* searchBST(struct TreeNode* root, int val)
{
    Tree* res = NULL;
    dfs(root,val,&res);
    return res;
}
