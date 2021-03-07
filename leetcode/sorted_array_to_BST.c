//
//  sorted_array_to_BST.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2021/3/7.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

static Tree* new_tree(int val)
{
    Tree* tree = calloc(1,sizeof(Tree));
    tree->val = val;
    return tree;
}

static void dfs(Tree** root,int start,int end,int* nums)
{
    if (start > end) return;
    int half = (start + end) / 2;
    *root = new_tree(nums[half]);
    dfs(&(*root)->left,start,half - 1,nums);
    dfs(&(*root)->right,half + 1,end,nums);
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    Tree* root = NULL;
    dfs(&root,0,numsSize - 1,nums);
    return root;
}
