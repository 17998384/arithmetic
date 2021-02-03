//
//  trim_BST.c
//  arithmetic
//
//  669. 修剪二叉搜索树
//
//  给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 //  high。通过修剪二叉搜索树，使得所有节点的值在  [low,high]中。修剪树不应该改变保留在树中的元素的相对结构（即，如果没有被移除，原有的父代子代关系都应当保留）。 可以证明，存在唯一的答案。
//
//  所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。
//
//
//
//  示例 1：
//
//  输入：root = [1,0,2], low = 1, high = 2
//  输出：[1,null,2]
//
//
//  Created by 我叫城北徐公° on 2021/2/4.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Node;

static Node* find_match(Node* root,int isGreater,int low,int high)
{
    if (!root) return NULL;
    if (isGreater)
    {
        if (root->val >= low)
        {
            if (root->val <= high) return root;
            else return find_match(root->left,!isGreater,low,high);
        }
        return find_match(root->right,isGreater,low,high);
    }
    else
    {
        if (root->val <= high)
        {
            if (root->val >= low) return root;
            else return find_match(root->right,!isGreater,low,high);
        }
        return find_match(root->left,isGreater,low,high);
    }
}

static void dfs(Node** root,int low,int high)
{
    if (!(*root)) return;
    if ((*root) && (*root)->val > high) *root = find_match((*root)->left,0,low,high);
    if ((*root) && (*root)->val < low) *root = find_match((*root)->right,1,low,high);
    if (!(*root)) return;
    dfs(&(*root)->left,low,high);
    dfs(&(*root)->right,low,high);
}

struct TreeNode* trimBST(struct TreeNode* root, int low, int high)
{
    dfs(&root,low,high);
    return root;
}
