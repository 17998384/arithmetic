//
//  inorder_successor.c
//  arithmetic
//
//  面试题 04.06. 后继者
//
//  设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。
//
//  如果指定节点没有对应的“下一个”节点，则返回null。
//
//  示例 1:
//
//  输入: root = [2,1,3], p = 1
//
//    2
//   / \
//  1   3
//
//  输出: 2
//
//  示例 2:
//
//  输入: root = [5,3,6,2,4,null,null,1], p = 6
//
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
//
//  输出: null
//
//
//  Created by 我叫城北徐公° on 2021/3/17.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

static void dfs(Tree* root,Tree* p,int* flag,Tree** res)
{
    if (!root) return;
    if (*flag == 2) return;
    dfs(root->left,p,flag,res);
    if (*flag == 1)
    {
        *flag = 2;
        *res = root;
        return;
    }
    if (root == p) *flag = 1;
    dfs(root->right,p,flag,res);
}

struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p)
{
    int flag = 0;
    Tree* res = NULL;
    dfs(root,p,&flag,&res);
    return res;
}
