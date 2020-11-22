//
//  is_balanced.c
//  arithmetic
//
//  110.平衡二叉树

//  给定一个二叉树，判断它是否是高度平衡的二叉树。O(logn)

//  一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

//  Created by 我叫城北徐公° on 2020/11/21.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tree_node.h"

static int dfs(struct TreeNode* root,int* balanced)
{
    if (!root)
        return 0;
    int l_height = dfs(root->left,balanced);
    int r_height = dfs(root->right,balanced);
    if (abs(l_height - r_height) > 1)
        *balanced = 0;
    return fmax(l_height, r_height) + 1;
}

int isBalanced(struct TreeNode* root)
{
    int balanced = 1;
    dfs(root,&balanced);
    return balanced;
}

int main_isBalanced(void)
{
    //[1,2,2,3,null,null,3,4,null,null,4]
    struct TreeNode* tree = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->left->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->left->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->left->left->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->left->left->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    int result = isBalanced(tree);
    printf("%d\n",result);
    return 0;
}
