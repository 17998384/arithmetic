//
//  find_second_minimum_value.c
//  arithmetic
//
//  671. 二叉树中第二小的节点
//
//  给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。
//
//  更正式地说，root.val = min(root.left.val, root.right.val) 总成立。
//
//  给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。
//
//
//  Created by 我叫城北徐公° on 2021/2/23.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"


typedef struct TreeNode Tree;

static int min;
static int secondMin;

static void dfs(Tree* root)
{
    if (!root) return;
    if (root->val == min)
    {
        if (root->left && (root->left->val != root->right->val))
        {
            int tmpSecondMin = root->left->val > root->right->val ? root->left->val : root->right->val;
            if (secondMin == -1) secondMin = tmpSecondMin;
            else secondMin = secondMin < tmpSecondMin ? secondMin : tmpSecondMin;
        }
    }
    dfs(root->left);
    dfs(root->right);
}

int findSecondMinimumValue(struct TreeNode* root)
{
    if (!root) return -1;
    min = root->val;
    secondMin = -1;
    dfs(root);
    return secondMin;
}
