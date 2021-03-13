//
//  postorder_traversal.c
//  arithmetic
//
//  145. 二叉树的后序遍历
//
//  给定一个二叉树，返回它的 后序 遍历。
//
//  示例:
//
//  输入: [1,null,2,3]
//     1
//      \
//       2
//      /
//     3
//
//  输出: [3,2,1]
//
//  进阶: 递归算法很简单，你可以通过迭代算法完成吗？
//
//  Created by 我叫城北徐公° on 2021/3/11.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

static int* bfs(Tree* root,int* returnSize)
{
    if (!root) return NULL;
    Tree* stack[1000];
    int rbp;
    rbp = 0;
    stack[rbp++] = root;
    int* res = malloc(sizeof(int) * 1000);
    while (rbp > 0)
    {
        Tree* tmp = stack[rbp - 1];
        if (tmp->left)
        {
            stack[rbp++] = tmp->left;
            tmp->left = NULL;
            continue;
        }
        if (tmp->right)
        {
            stack[rbp++] = tmp->right;
            tmp->right = NULL;
            continue;
        }
        res[(*returnSize)++] = tmp->val;
        rbp--;
    }
    return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    return bfs(root,returnSize);
}
