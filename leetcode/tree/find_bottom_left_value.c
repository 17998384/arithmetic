//
//  find_bottom_left_value.c
//  arithmetic
//
//  513. 找树左下角的值
//
//  给定一个二叉树，在树的最后一行找到最左边的值。
//
//  示例 1:
//
//  输入:
//
//      2
//     / \
//    1   3
//
//  输出:
//  1
//
//
//
//  示例 2:
//
//  输入:
//
//          1
//         / \
//        2   3
//       /   / \
//      4   5   6
//         /
//        7
//
//  输出:
//  7
//
//
//
//  注意: 您可以假设树（即给定的根节点）不为 NULL
//
//  Created by 我叫城北徐公° on 2021/3/16.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

static int maxDepth;

static void dfs(Tree* root,int curDepth,int* res)
{
    if (!root) return;
    if (!root->left && !root->right && curDepth > maxDepth)
    {
        maxDepth = curDepth;
        *res = root->val;
        return;
    }
    dfs(root->left,curDepth + 1,res);
    dfs(root->right,curDepth + 1,res);
}

int findBottomLeftValue(struct TreeNode* root)
{
    maxDepth = 0;
    int res;
    dfs(root,1,&res);
    return res;
}
