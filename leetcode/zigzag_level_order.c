//
//  zigzag_level_order.c
//  arithmetic
//
//  103.二叉树的锯齿形层次遍历
//
//  给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
//
//  例如：
//  给定二叉树 [3,9,20,null,null,15,7],
//
//      3
//     / \
//    9  20
//      /  \
//     15   7
//
//  返回锯齿形层次遍历如下：
//
//  [
//    [3],
//    [20,9],
//    [15,7]
//  ]
//
//  Created by 我叫城北徐公° on 2020/11/25.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

static int** bfs(struct TreeNode* tree, int* returnSize,int** returnColumnSizes)
{
    int** res = (int**)malloc(sizeof(int*) * 1000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
    struct TreeNode** list = (struct TreeNode**)calloc(1000, sizeof(struct TreeNode*));
    int start = 0;
    int end = 1;
    int end_0 = 1;
    list[start] = tree;
    res[*returnSize] = (int*)calloc(1, sizeof(int));
    res[*returnSize][0] = tree->val;
    (*returnColumnSizes)[0] = 1;
    while (1)
    {
        int idx = 0;
        (*returnSize)++;
        res[*returnSize] = (int*)calloc(1000, sizeof(int));
        while (start != end)
        {
            int* arr = res[*returnSize];
            struct TreeNode* treeNode = list[start];
            if (treeNode->left)
            {
                list[end_0++] = treeNode->left;
                arr[idx++] = treeNode->left->val;
            }
            if (treeNode->right)
            {
                list[end_0++] = treeNode->right;
                arr[idx++] = treeNode->right->val;
            }
            start++;
        }
        (*returnColumnSizes)[(*returnSize)] = idx;
        //2的倍数，反转
        if (idx > 0 && *returnSize % 2 != 0)
        {
            for (int i = 0,last = idx - 1,size = (idx - 1) / 2 ; i <= size ; i++,last--)
            {
                if (i == last)
                    continue;
                res[*returnSize][i] ^= res[*returnSize][last];
                res[*returnSize][last] ^= res[*returnSize][i];
                res[*returnSize][i] ^= res[*returnSize][last];
            }
        }
        if (end == end_0)
            break;
        end = end_0;
    }
    free(list);
    return res;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    if (!root)
        return NULL;
    return bfs(root, returnSize, returnColumnSizes);
}

int main_zigzagLevelOrder(void)
{
    //[1,2,2,3,null,null,3,4,null,null,4]
    struct TreeNode* tree = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->val = 1;
    tree->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->left->val = 2;
//    tree->left->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
//    tree->left->left->val = 4;
//    tree->left->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
//    tree->left->right->val = 5;
//    tree->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
//    tree->right->val = 3;
//    tree->right->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
//    tree->right->left->val = 6;
//    tree->right->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
//    tree->right->right->val = 7;
    int returnSize;
    int* returnColumnSizes;
    int** num = zigzagLevelOrder(tree, &returnSize,&returnColumnSizes);
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d ",num[i][j]);
        }
        printf("\n");
    }
    return 0;
}

