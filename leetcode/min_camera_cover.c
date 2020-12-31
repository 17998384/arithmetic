//
//  min_camera_cover.c
//  arithmetic
//
//  968.监控二叉树

//  给定一个二叉树，我们在树的节点上安装摄像头。
//
//  节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
//
//  计算监控树的所有节点所需的最小摄像头数量。

//  Created by 我叫城北徐公° on 2020/12/31.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

static void dfs(struct TreeNode* root,struct TreeNode* prev,int* res)
{
    if(!root) return;
    dfs(root->left,root,res);
    dfs(root->right,root,res);
    if((root->left && !root->left->val) || (root->right && !root->right->val))
    {
        //当前节点标为1
        root->val = 1;
        //上一个节点可以被监控到，但只是可以被监控到而已，标为2
        if(prev) prev->val = 2;
        (*res)++;
    }
    if(!root->val && !prev && ((root->left && root->left->val == 2) || (root->right && root->right->val == 2) || (!root->left && !root->right))) (*res)++;
}

int minCameraCover(struct TreeNode* root)
{
    int res = 0;
    dfs(root,NULL,&res);
    return res;
}
