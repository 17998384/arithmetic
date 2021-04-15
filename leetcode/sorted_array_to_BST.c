//
//  sorted_array_to_BST.c
//  arithmetic

//  108. 将有序数组转换为二叉搜索树
//
//  给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
//
//  高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
//
//  示例 1：
//
//  输入：nums = [-10,-3,0,5,9]
//  输出：[0,-3,9,-10,null,5]
//  解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
//
//
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
