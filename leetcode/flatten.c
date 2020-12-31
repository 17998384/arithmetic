//
//  flatten.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/12/31.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

struct TreeNode* prev;

static void dfs(struct TreeNode* root)
{
    if(!root) return;
    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;
    if(!prev) prev = root;
    else
    {
        prev->right = root;
        prev->left = NULL;
        prev = root;
    }
    dfs(left);
    dfs(right);
}

void flatten(struct TreeNode* root)
{
    prev = NULL;
    dfs(root);
}

int main(void)
{
    //[1,2,2,3,null,null,3,4,null,null,4]
    struct TreeNode* tree = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->val = 1;
    tree->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->left->val = 2;
    tree->left->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->left->left->val = 3;
    tree->left->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->left->right->val = 4;
    tree->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->right->val = 5;
//    tree->right->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
//    tree->right->left->val = 6;
    tree->right->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->right->right->val = 6;
    flatten(tree);
}
