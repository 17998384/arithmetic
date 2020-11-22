//
//  list_of_depth.c
//  arithmetic
//  04.03   面试题 04.03. 特定深度节点链表
//
//给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表（比如，若一棵树的深度为 D，则会创建出 D 个链表）。返回一个包含所有深度的链表的数组。
//
//
//
//示例：
//
//输入：[1,2,3,4,5,null,7,8]
//
//        1
//       /  \
//      2    3
//     / \    \
//    4   5    7
//   /
//  8
//
//输出：[[1],[2,3],[4,5,7],[8]]

//  Created by 我叫城北徐公° on 2020/11/22.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "list_node.h"
#include "tree_node.h"

static struct ListNode* newListNode(int val)
{
    struct ListNode* node = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    node->val = val;
    return node;
}

struct ListNode** bfs(struct TreeNode* tree, int* returnSize)
{
    struct ListNode** res = (struct ListNode**)calloc(1000, sizeof(struct ListNode*));
    struct TreeNode** list = (struct TreeNode**)calloc(1000, sizeof(struct TreeNode*));
    int start = 0;
    int end = 1;
    int end_0 = 1;
    list[start] = tree;
    res[*returnSize] = newListNode(tree->val);
    while (1)
    {
        while (start != end)
        {
            (*returnSize)++;
            struct ListNode** head = &res[*returnSize];
            struct TreeNode* treeNode = list[start];
            if (treeNode->left)
            {
                list[end_0++] = treeNode->left;
                (*head) = newListNode(treeNode->left->val);
//                printf("list address :%p,list val :%d,list next address :%p\n",*head,(*head)->val,(*head)->next);
                head = &((*head)->next);
            }
            if (treeNode->right)
            {
                list[end_0++] = treeNode->right;
                (*head) = newListNode(treeNode->right->val);
//                printf("list address :%p,list val :%d,list next address :%p\n",*head,(*head)->val,(*head)->next);
                head = &((*head)->next);
            }
            start++;
        }
        if (end == end_0)
            break;
        end = end_0;
    }
    free(list);
    return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** listOfDepth(struct TreeNode* tree, int* returnSize)
{
    *returnSize = 0;
    if (!tree)
        return NULL;
    return bfs(tree, returnSize);
}

int main_listOfDepth(void)
{
    //[1,2,2,3,null,null,3,4,null,null,4]
    struct TreeNode* tree = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->left->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->left->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->left->left->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->right->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    int returnSize;
    struct ListNode** listNode = listOfDepth(tree, &returnSize);
    return 0;
}
