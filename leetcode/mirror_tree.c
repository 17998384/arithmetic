//
//  mirror_tree.c
//  arithmetic
//
//  剑指 Offer 27. 二叉树的镜像
//
//  请完成一个函数，输入一个二叉树，该函数输出它的镜像。
//
//  例如输入：
//
//       4
//     /   \
//    2     7
//   / \   / \
//  1   3 6   9
//  镜像输出：
//
//       4
//     /   \
//    7     2
//   / \   / \
//  9   6 3   1
//
//
//
//  示例 1：
//
//  输入：root = [4,2,7,1,3,6,9]
//  输出：[4,7,2,9,6,3,1]
//
//
//
//  限制：
//
//  0 <= 节点个数 <= 1000
//
//  Created by 我叫城北徐公° on 2021/3/17.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

static void dfs(Tree* root)
{
    if (!root) return;
    Tree* tmp;
    tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    dfs(root->left);
    dfs(root->right);
}

struct TreeNode* mirrorTree(struct TreeNode* root)
{
    dfs(root);
    return root;
}
