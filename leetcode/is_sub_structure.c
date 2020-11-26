//
//  is_sub_structure.c
//  arithmetic
//
//  剑指 Offer 26. 树的子结构
//
//  输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
//
//  B是A的子结构， 即 A中有出现和B相同的结构和节点值。
//
//  例如:
//  给定的树 A:
//
//       3
//      / \
//     4   5
//    / \
//   1   2
//  给定的树 B：
//
//     4
//    /
//   1
//  返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。
//
//  示例 1：
//
//  输入：A = [1,2,3], B = [3,1]
//  输出：false
//
//  示例 2：
//
//  输入：A = [3,4,5,1,2], B = [4,1]
//  输出：true
//
//  限制：
//
//  0 <= 节点个数 <= 10000

//  Created by 我叫城北徐公° on 2020/11/26.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

static int dfs(struct TreeNode* A,struct TreeNode* B)
{
    if (!A && !B) return 1;
    if (!A && B) return 0;
    if (A && !B) return 1;
    if (A->val != B->val) return 0;
    return dfs(A->left, B->left) && dfs(A->right, B->right);
}

int isSubStructure(struct TreeNode* A, struct TreeNode* B)
{
    int result = 0;
    if (A && B)
    {
        if (A->val == B->val) result = dfs(A, B);
        if (!result) result = isSubStructure(A->left, B);
        if (!result) result = isSubStructure(A->right, B);
    }
    return result;
}


int main_isSubStructure(void)
{
    //[3,4,5,1,2]   [4,1]
    struct TreeNode* A = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    A->val = 3;
    A->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    A->left->val = 4;
    A->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    A->right->val = 5;
    A->left->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    A->left->left->val = 1;
    A->left->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    A->left->right->val = 2;
    struct TreeNode* B = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    B->val = 4;
    B->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    B->left->val = 1;
    int result = isSubStructure(A, B);
    printf("%d\n",result);
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
    return 0;
}
