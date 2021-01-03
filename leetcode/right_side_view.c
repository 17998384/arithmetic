//
//  right_side_view.c
//  arithmetic
//
//  199. 二叉树的右视图
//
//  给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
//
//  示例:
//
//  输入: [1,2,3,null,5,null,4]
//  输出: [1, 3, 4]
//  解释:
//
//     1            <---
//   /   \
//  2     3         <---
//   \     \
//    5     4       <---
//
//  Created by 我叫城北徐公° on 2021/1/3.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

#define LIST_SIZE 1000
#define ARRAY_SIZE 200
#define DEBUG 0

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static int* bfs(struct TreeNode* root,int* returnSize)
{
    if (!root) return NULL;
    struct TreeNode* list[LIST_SIZE] = {0};
    int* res = malloc(sizeof(int) * ARRAY_SIZE);
    //p1,前指针，p2后指针
    int p1 = 0,p2 = 0;
    list[p2++] = root;
    while(p1 < p2)
    {
        //备份的p2指针
        int p3 = p2;
        if (DEBUG) printf("p1 -> %d,p3 -> %d\n",p1,p3);
        while(p1 < p3)
        {
            struct TreeNode* tmp = list[p1++];
            if ((p1 - 1) == (p3 - 1)) res[(*returnSize)++] = tmp->val;
            if (tmp->left) list[p2++] = tmp->left;
            if (tmp->right) list[p2++] = tmp->right;
        }
    }
    return res;
}

int* rightSideView(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    return bfs(root,returnSize);
}
