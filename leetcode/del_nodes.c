//
//  del_nodes.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/11/30.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_node.h"

static char my_cache[1001] = {0};
static char my_cache2[1001] = {0};
struct TreeNode** nodes;

static void dfs(struct TreeNode* root,struct TreeNode* father,int* returnSize)
{
    if (!root) return;
    //如果是被删节点
    if (my_cache[root->val])
    {
        if (father && father->left == root) father->left = NULL;
        else if (father && father->right == root) father->right = NULL;
        if (root->left && !my_cache[root->left->val]) my_cache2[root->left->val] = 1;
        if (root->right && !my_cache[root->right->val]) my_cache2[root->right->val] = 1;
    }
    if (my_cache2[root->val]) nodes[(*returnSize)++] = root;
    dfs(root->left, root, returnSize);
    dfs(root->right, root, returnSize);
}

struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize)
{
    *returnSize = 0;
    memset(my_cache,0,sizeof(char) * 1001);
    memset(my_cache2,0,sizeof(char) * 1001);
    //缓存做标记
    for (int i = 0; i < to_deleteSize; i++) my_cache[to_delete[i]] = 1;
    nodes = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 500);
    if (root && !my_cache[root->val]) my_cache2[root->val] = 1;
    //dfs
    dfs(root,NULL, returnSize);
    return nodes;
}

int main_delNodes(void)
{
    struct TreeNode* A = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    A->val = 1;
    A->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    A->left->val = 2;
    A->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    A->right->val = 3;
    A->left->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    A->left->left->val = 4;
    A->left->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    A->left->right->val = 5;
    A->right->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    A->right->left->val = 6;
    A->right->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    A->right->right->val = 7;
    int arr[] = {1};
    int returnSize;
    delNodes(A, arr, 1, &returnSize);
}
