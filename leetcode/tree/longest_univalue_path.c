//
//  longest_univalue_path.c
//  arithmetic
//
//  687. 最长同值路径
//
//  给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。
//
//  注意：两个节点之间的路径长度由它们之间的边数表示。
//
//  示例 1:
//
//  输入:
//
//                5
//               / \
//              4   5
//             / \   \
//            1   1   5
//
//  输出:
//
//  2
//
//  示例 2:
//
//  输入:
//
//                1
//               / \
//              4   5
//             / \   \
//            4   4   5
//
//  输出:
//
//  2
//
//  Created by 我叫城北徐公° on 2021/3/16.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

static int max;

static int dfs(Tree* root)
{
    if (!root) return 0;
    int left = dfs(root->left);
    int right = dfs(root->right);
    int tmp = 0,L = 0,R = 0;
    if (root->left && root->left->val == root->val) L = left + 1;
    if (root->right && root->right->val == root->val) R = right + 1;
    if ((L + R) > max) max = L + R;
    return fmax(L,R);
}

int longestUnivaluePath(struct TreeNode* root)
{
    max = 0;
    dfs(root);
    return max;
}
