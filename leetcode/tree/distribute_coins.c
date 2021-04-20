//
//  distribute_coins.c
//  arithmetic
//
//  979. 在二叉树中分配硬币
//
//  给定一个有 N 个结点的二叉树的根结点 root，树中的每个结点上都对应有 node.val 枚硬币，并且总共有 N 枚硬币。
//
//  在一次移动中，我们可以选择两个相邻的结点，然后将一枚硬币从其中一个结点移动到另一个结点。(移动可以是从父结点到子结点，或者从子结点移动到父结点。)。
//
//  返回使每个结点上只有一枚硬币所需的移动次数。
//
//  示例 1：
//
//  输入：[3,0,0]
//  输出：2
//  解释：从树的根结点开始，我们将一枚硬币移到它的左子结点上，一枚硬币移到它的右子结点上。
//
//  Created by 我叫城北徐公° on 2021/1/17.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_node.h"

static void dfs(struct TreeNode* root,struct TreeNode* prev,int* move)
{
    if (!root) return;
    dfs(root->left,root,move);
    dfs(root->right,root,move);
    *move += abs(root->val - 1);
    if (prev) prev->val += root->val - 1;
}

int distributeCoins(struct TreeNode* root)
{
    int move = 0;
    dfs(root,NULL,&move);
    return move;
}

/** Decodes your encoded data to tree. */
extern struct TreeNode* deserialize(char* data);

int main_distributeCoins(void)
{
    char* data = calloc(20, sizeof(char));
    strcpy(data, "1,0,0,null,3");
    struct TreeNode* root = deserialize(data);
    distributeCoins(root);
    return 0;
}
typedef struct find_elements
{
    struct TreeNode* root;
    int bitmap[50000];
} FindElements;
