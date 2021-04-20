//
//  max_path_sum.c
//  arithmetic
//
//  124. 二叉树中的最大路径和
//
//  路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

//  这题说白了意思就是从一个节点到另一个节点的节点和，你只能从你的父节点开始向其他
//  任意节点都可以，然后求出最大的节点和
//
//  路径和 是路径中各节点值的总和。
//
//  给你一个二叉树的根节点 root ，返回其 最大路径和 。
//
//
//
//  示例 1：
//
//  输入：root = [1,2,3]
//  输出：6
//  解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
//
//  示例 2：
//
//  输入：root = [-10,9,20,null,null,15,7]
//  输出：42
//  解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
//
//
//
//  提示：
//
//      树中节点数目范围是 [1, 3 * 104]
//      -1000 <= Node.val <= 1000
//
//
//
//  Created by 我叫城北徐公° on 2021/3/28.
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
    int L = dfs(root->left);
    int R = dfs(root->right);
    int tmpMax = fmax(fmax(root->val + L,root->val + R),root->val);
    max = fmax(fmax(tmpMax,root->val + L + R),max);
    return tmpMax;
}

int maxPathSum(struct TreeNode* root)
{
    max = 0x80000000;
    dfs(root);
    return max;
}
