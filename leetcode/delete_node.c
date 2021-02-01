//
//  delete_node.c
//  arithmetic
//
//  450. 删除二叉搜索树中的节点
//
//  给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
//
//  一般来说，删除节点可分为两个步骤：
//
//      首先找到需要删除的节点；
//      如果找到了，删除它。
//
//  说明： 要求算法时间复杂度为 O(h)，h 为树的高度。
//
//  示例:
//
//  root = [5,3,6,2,4,null,7]
//  key = 3
//
//      5
//     / \
//    3   6
//   / \   \
//  2   4   7
//
//  给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
//
//  一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
//
//      5
//     / \
//    4   6
//   /     \
//  2       7
//
//  另一个正确答案是 [5,2,6,null,4,null,7]。
//
//      5
//     / \
//    2   6
//     \   \
//      4   7
//
//
//  Created by 我叫城北徐公° on 2021/2/1.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

#define LEFT 1
#define RIGHT -1

int dfs2(struct TreeNode** root_p,struct TreeNode* parent,struct TreeNode* oldParent,int direction)
{
    struct TreeNode* root = *root_p;
    //递归找到最左边的
    if (direction == LEFT && !root->right)
    {
        int res = root->val;
        //节点上移
        if (root->left) (*root_p) = root->left;
        else if (parent != oldParent) parent->right = NULL;
        else parent->left = NULL;
        return res;
    }
    //递归找到最右边的
    else if (direction == RIGHT && !root->left)
    {
        int res = root->val;
        //节点上移
        if (root->right) (*root_p) = root->right;
        else if (parent != oldParent) parent->left = NULL;
        else parent->right = NULL;
        return res;
    }
    else
    {
        if (direction == LEFT) return dfs2(&root->right,root,oldParent,direction);
        else return dfs2(&root->left,root,oldParent,direction);
    }
}

void dfs(struct TreeNode* root,struct TreeNode** parent,int key)
{
    if (!root) return;
    if (root->val == key)
    {
        if (root->right) root->val = dfs2(&root->right,root,root,RIGHT);
        else if (root->left) root->val = dfs2(&root->left,root,root,LEFT);
        //是它自己，且左右都无节点，说明它自己需要清掉
        else (*parent) = NULL;
        return;
    }
    dfs(root->left,&root->left,key);
    dfs(root->right,&root->right,key);
}

struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
    dfs(root,&root,key);
    return root;
}
