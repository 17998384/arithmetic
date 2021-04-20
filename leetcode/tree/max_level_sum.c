//
//  max_level_sum.c
//  arithmetic
//
//  1161. 最大层内元素和
//
//  给你一个二叉树的根节点 root。设根节点位于二叉树的第 1 层，而根节点的子节点位于第 2 层，依此类推。
//
//  请你找出层内元素之和 最大 的那几层（可能只有一层）的层号，并返回其中 最小 的那个。
//
//
//
//  示例 1：
//
//  输入：root = [1,7,0,7,-8,null,null]
//  输出：2
//  解释：
//  第 1 层各元素之和为 1，
//  第 2 层各元素之和为 7 + 0 = 7，
//  第 3 层各元素之和为 7 + -8 = -1，
//  所以我们返回第 2 层的层号，它的层内元素之和最大。
//
//  示例 2：
//
//  输入：root = [989,null,10250,98693,-89388,null,null,null,-32127]
//  输出：2
//
//
//  Created by 我叫城北徐公° on 2021/3/24.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

static int bfs(Tree* root)
{
    int max = 0x80000000;
    int tier = 1;
    int rbp,rsp,curTier;
    rbp = rsp = curTier = 0;
    Tree* stack[10000];
    stack[rsp++] = root;
    while (rbp < rsp)
    {
        int rspBak = rsp;
        int sum = 0;
        while (rbp < rspBak)
        {
            Tree* tree = stack[rbp++];
            sum += tree->val;
            if (tree->left) stack[rsp++] = tree->left;
            if (tree->right) stack[rsp++] = tree->right;
        }
        curTier++;
        // printf("tier : %d,sum : %d\n",curTier,sum);
        if (sum > max)
        {
            max = sum;
            tier = curTier;
        }
    }
    return tier;
}

int maxLevelSum(struct TreeNode* root)
{
    return bfs(root);
}
