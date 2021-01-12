//
//  btree_game_winning_move.c
//  arithmetic
//
//  1145.二叉树着色游戏
//
//  有两位极客玩家参与了一场「二叉树着色」的游戏。游戏中，给出二叉树的根节点 root，树上总共有 n 个节点，且 n 为奇数，其中每个节点上的值从 1 到 n 各不相同。
//
//
//
//  游戏从「一号」玩家开始（「一号」玩家为红色，「二号」玩家为蓝色），最开始时，
//
//  「一号」玩家从 [1, n] 中取一个值 x（1 <= x <= n）；
//
//  「二号」玩家也从 [1, n] 中取一个值 y（1 <= y <= n）且 y != x。
//
//  「一号」玩家给值为 x 的节点染上红色，而「二号」玩家给值为 y 的节点染上蓝色。
//
//
//
//  之后两位玩家轮流进行操作，每一回合，玩家选择一个他之前涂好颜色的节点，将所选节点一个 未着色 的邻节点（即左右子节点、或父节点）进行染色。
//
//  如果当前玩家无法找到这样的节点来染色时，他的回合就会被跳过。
//
//  若两个玩家都没有可以染色的节点时，游戏结束。着色节点最多的那位玩家获得胜利 ✌️。
//
//
//
//  现在，假设你是「二号」玩家，根据所给出的输入，假如存在一个 y 值可以确保你赢得这场游戏，则返回 true；若无法获胜，就请返回 false。
//
//
//
//  示例：
//
//  输入：root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
//  输出：True
//  解释：第二个玩家可以选择值为 2 的节点。
//
//
//  Created by 我叫城北徐公° on 2021/1/12.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

static void dfs2(struct TreeNode* root,struct TreeNode* compare,int* res)
{
    if (!root) return;
    (*res)++;
    if (root->left != compare) dfs2(root->left,compare,res);
    if (root->right != compare) dfs2(root->right,compare,res);
}

static void dfs(struct TreeNode* root,struct TreeNode* father,int x,int n,int* res)
{
    if (!root) return;
    if (root->val == x)
    {
        int F,L,R;
        F = L = R = 0;
        if (father)
        {
            dfs2(root,root,&F);
            F = n - F;
        }
        if (root->left) dfs2(root->left,root,&L);
        if (root->right) dfs2(root->right,root,&R);
        if (F > n - F || L > n - L || R > n - R) *res = 1;
        else *res = 0;
        // printf("F : %d,L : %d,R : %d\n",F,L,R);
        return;
    }
    dfs(root->left,root,x,n,res);
    dfs(root->right,root,x,n,res);
}

int btreeGameWinningMove(struct TreeNode* root, int n, int x)
{
    int res = 0;
    dfs(root,NULL,x,n,&res);
    return res;
}
