//
//  is_balanced2.c
//  arithmetic
//

//  面试题 04.04. 检查平衡性
//
//  实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。
//
//  示例 1:
//
//  给定二叉树 [3,9,20,null,null,15,7]
//      3
//     / \
//    9  20
//      /  \
//     15   7
//  返回 true 。
//
//  示例 2:
//
//  给定二叉树 [1,2,2,3,3,null,null,4,4]
//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4
//  返回 false 。
//
//
//  Created by 我叫城北徐公° on 2021/3/14.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

static int dfs(Tree* root,int* res)
{
    if (!root || !*res) return 0;
    int leftFlag = dfs(root->left,res);
    int rightFlag = dfs(root->right,res);
    if (abs(leftFlag - rightFlag) > 1)
    {
        *res = 0;
        return 0;
    }
    return fmax(leftFlag,rightFlag) + 1;
}

static int isBalanced(struct TreeNode* root)
{
    int res = 1;
    dfs(root,&res);
    return res;
}
