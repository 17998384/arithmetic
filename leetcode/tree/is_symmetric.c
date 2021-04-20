//
//  is_symmetric.c
//  arithmetic
//
//  剑指 Offer 28. 对称的二叉树
//
//  请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
//
//  Created by 我叫城北徐公° on 2020/12/3.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

static void dfs(struct TreeNode* root,struct TreeNode* root2,int* flag)
{
    if(!root && !root2) return;
    if(!root || !root2)
    {
        *flag = 0;
        return;
    }
    if (root->val != root2->val)
    {
        *flag = 0;
        return;
    }
    dfs(root->left,root2->right,flag);
    dfs(root->right,root2->left,flag);
}

int isSymmetric(struct TreeNode* root)
{
    if(!root) return 1;
    int flag = 1;
    dfs(root,root,&flag);
    return flag;
}
