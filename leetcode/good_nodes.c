//
//  good_nodes.c
//  arithmetic
//
//  1448. 统计二叉树中好节点的数目
//
//  给你一棵根为 root 的二叉树，请你返回二叉树中好节点的数目。
//
//  「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。
//
//
//
//  示例 1：
//
//  输入：root = [3,1,4,3,null,1,5]
//  输出：4
//  解释：图中蓝色节点为好节点。
//  根节点 (3) 永远是个好节点。
//  节点 4 -> (3,4) 是路径中的最大值。
//  节点 5 -> (3,4,5) 是路径中的最大值。
//  节点 3 -> (3,1,3) 是路径中的最大值。
//
//
//  Created by 我叫城北徐公° on 2021/3/17.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

static int count;

static void dfs(Tree* root,int max)
{
    if (!root) return;
    if (root->val >= max)
    {
        count++;
        max = root->val;
    }
    dfs(root->left,max);
    dfs(root->right,max);
}

int goodNodes(struct TreeNode* root)
{
    count = 0;
    if (!root) return count;
    dfs(root,root->val);
    return count;
}
