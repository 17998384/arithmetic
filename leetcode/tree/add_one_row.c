//
//  add_one_row.c
//  arithmetic
//
//  623. 在二叉树中增加一行
//
//  给定一个二叉树，根节点为第1层，深度为 1。在其第 d 层追加一行值为 v 的节点。
//
//  添加规则：给定一个深度值 d （正整数），针对深度为 d-1 层的每一非空节点 N，为 N 创建两个值为 v 的左子树和右子树。
//
//  将 N 原先的左子树，连接为新节点 v 的左子树；将 N 原先的右子树，连接为新节点 v 的右子树。
//
//  如果 d 的值为 1，深度 d - 1 不存在，则创建一个新的根节点 v，原先的整棵树将作为 v 的左子树。
//
//  示例 1:
//
//  输入:
//  二叉树如下所示:
//         4
//       /   \
//      2     6
//     / \   /
//    3   1 5
//
//  v = 1
//
//  d = 2
//
//  输出:
//         4
//        / \
//       1   1
//      /     \
//     2       6
//    / \     /
//   3   1   5
//
//
//  Created by 我叫城北徐公° on 2021/3/14.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

static Tree* new_tree(int val)
{
    Tree* tree = calloc(1, sizeof(Tree));
    tree->val = val;
    return tree;
}

static Tree* bfs(Tree* root, int val, int depth)
{
    if (depth == 1)
    {
        Tree* newRoot = new_tree(val);
        newRoot->left = root;
        return newRoot;
    }
    Tree* stack[8000];
    int rbp, rsp, curDepth;
    rbp = rsp = 0;
    stack[rsp++] = root;
    curDepth = 2;
    while (rbp < rsp)
    {
        int rspBak = rsp;
        while (rbp < rspBak)
        {
            Tree* tmpTree = stack[rbp++];
            Tree* oldLeft = tmpTree->left;
            Tree* oldRight = tmpTree->right;
            if (curDepth == depth)
            {
                tmpTree->left = new_tree(val);
                tmpTree->right = new_tree(val);
                tmpTree->left->left = oldLeft;
                tmpTree->right->right = oldRight;
            }
            else
            {
                if (oldLeft) stack[rsp++] = oldLeft;
                if (oldRight) stack[rsp++] = oldRight;
            }
        }
        if (curDepth == depth) return root;
        curDepth++;
    }
    return root;
}

struct TreeNode* addOneRow(struct TreeNode* root, int val, int depth)
{
    return bfs(root, val, depth);
}