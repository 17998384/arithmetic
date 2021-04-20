//
//  print_tree.c
//  arithmetic
//
//  655. 输出二叉树
//
//  示例 1:
//
//  输入:
//       1
//      /
//     2
//  输出:
//  [["", "1", ""],
//   ["2", "", ""]]
//
//
//  示例 2:
//
//  输入:
//       1
//      / \
//     2   3
//      \
//       4
//  输出:
//  [["", "", "", "1", "", "", ""],
//   ["", "2", "", "", "", "3", ""],
//   ["", "", "4", "", "", "", ""]]
//
//
//
//  Created by 我叫城北徐公° on 2021/3/5.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "tree_node.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct TreeNode Tree;

static void get_depth(Tree* root,int* maxDepth,int curDepth)
{
    if (!root) return;
    if (curDepth > *maxDepth) *maxDepth = curDepth;
    get_depth(root->left,maxDepth,curDepth + 1);
    get_depth(root->right,maxDepth,curDepth + 1);
}

static void dfs(Tree* root,int start,int end,int depth,char*** matrix)
{
    if (!root) return;
    int half = (start + end) / 2;
    char* num = calloc(10,sizeof(char));
    itoa(root->val,num,10);
    matrix[depth][half] = num;
    dfs(root->left,start,half - 1,depth + 1,matrix);
    dfs(root->right,half + 1,end,depth + 1,matrix);
}

char *** printTree(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    int maxDepth = -1;
    get_depth(root,&maxDepth,1);
    *returnSize = maxDepth;
    //树中所有节点个数
    int count = (1 << maxDepth) - 1;
    //准备矩阵
    char*** matrix = malloc(sizeof(char**) * maxDepth);
    *returnColumnSizes = malloc(sizeof(int) * maxDepth);
    char* emptyStr = calloc(1,1);
    for (int i = 0;i < maxDepth;i++)
    {
        matrix[i] = malloc(sizeof(char**) * count);
        for (int j = 0;j < count;j++) matrix[i][j] = emptyStr;
        (*returnColumnSizes)[i] = count;
    }
    dfs(root,0,count - 1,0,matrix);
    return matrix;
}
