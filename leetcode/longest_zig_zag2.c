//
//  longest_zig_zag2.c
//  arithmetic
//
//  1372. 二叉树中的最长交错路径

//  第一种解法（dfs优化版）

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
#include <stdlib.h>
#include <string.h>
#include "tree_node.h"

#define MAX(x,y) (x) > (y) ? (x) : (y)

//整体思路就是以当前元素希望要的边去计算其左子树与右子树返回的长度（比较抽象，需自行领会）

static int dfs(struct TreeNode* root,int* max,int isLeft)
{
    if (!root) return 0;
    int L = dfs(root->left,max,0);
    int R = dfs(root->right,max,1);
    int more_than = MAX(L,R);
    *max = more_than > *max ? more_than : *max;
    if (isLeft) return L + 1;
    else return R + 1;
}

int longestZigZag2(struct TreeNode* root)
{
    int max = 0;
    dfs(root,&max,0);
    return max;
}
