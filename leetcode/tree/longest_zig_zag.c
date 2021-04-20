//
//  longest_zig_zag.c
//  arithmetic
//
//  1372. 二叉树中的最长交错路径

//  第一种解法（类似于DP）

//给你一棵以 root 为根的二叉树，二叉树中的交错路径定义如下：
//
//  选择二叉树中 任意 节点和一个方向（左或者右）。
//  如果前进方向为右，那么移动到当前节点的的右子节点，否则移动到它的左子节点。
//  改变前进方向：左变右或者右变左。
//  重复第二步和第三步，直到你在树中无法继续移动。
//
//  交错路径的长度定义为：访问过的节点数目 - 1（单个节点的路径长度为 0 ）。
//
//  请你返回给定树中最长 交错路径 的长度。
//
//  Created by 我叫城北徐公° on 2021/1/6.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree_node.h"

#define L -1
#define R 1
#define BUFFER_SIZE 10000000

struct Result
{
    int left;
    int right;
};
static int max;
static struct Result* res_buffer[10000000];

static void max_dfs(struct TreeNode* root,int* direction,int* cur)
{
    if (!root) return;
    int idx = ((unsigned long)root) % BUFFER_SIZE;
    if (*direction == L)
    {
        if (res_buffer[idx])
        {
            (*cur) += res_buffer[idx]->left;
            res_buffer[idx] = NULL;
            return;
        }
        if (!root->left) return;
        *direction = -*(direction);
        (*cur)++;
        max_dfs(root->left, direction, cur);
    }
    else
    {
        if (res_buffer[idx])
        {
            (*cur) += res_buffer[idx]->right;
            res_buffer[idx] = NULL;
            return;
        }
        if (!root->right) return;
        *direction = -*(direction);
        (*cur)++;
        max_dfs(root->right, direction, cur);
    }
}

static void dfs(struct TreeNode* root,int* direction)
{
    if (!root) return;
    dfs(root->left,direction);
    dfs(root->right,direction);
    int cur = 0;
    struct Result* res = calloc(1, sizeof(struct Result));
    *direction = L;
    max_dfs(root, direction,&cur);
    max = cur > max ? cur : max;
    res->left = cur;
    cur = 0;
    *direction = R;
    max_dfs(root, direction,&cur);
    max = cur > max ? cur : max;
    res->right = cur;
    int idx = ((unsigned long)root) % BUFFER_SIZE;
    res_buffer[idx] = res;
}

int longestZigZag(struct TreeNode* root)
{
    max = 0;
    int direction;
    dfs(root, &direction);
    res_buffer[(unsigned long)root % 10000000] = NULL;
    return max;
}
