//
//  build_tree.c
//  arithmetic
//
//  105. 从前序与中序遍历序列构造二叉树
//
//  根据一棵树的前序遍历与中序遍历构造二叉树。
//
//  注意:
//  你可以假设树中没有重复的元素。

//  Created by 我叫城北徐公° on 2020/12/2.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

//int inorder_cache[10000];
//
//static void dfs(struct TreeNode** node,int start,int end,int* preorder_idx,int* preorder,int* inorder)
//{
//    if (start == end) return;
//    (*node) = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
//    (*node)->val = preorder[(*preorder_idx)++];
//    int i = inorder_cache[(*node)->val + 5000];
//    dfs(&(*node)->left,start,i,preorder_idx,preorder,inorder);
//    dfs(&(*node)->right,i + 1,end,preorder_idx,preorder,inorder);
//}
//
//struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
//{
//    if (!preorderSize) return NULL;
//    //创建根节点
//    struct TreeNode* root = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
//    //前序索引
//    int preorder_idx = 0;
//    //中序建立缓存
//    for (int i = 0; i < inorderSize; i++) inorder_cache[inorder[i] + 5000] = i;
//    dfs(&root,0,preorderSize,&preorder_idx,preorder,inorder);
//    return root;
//}

static short* cache;

static void dfs(struct TreeNode** node,int* preorder_idx,int* preorder,int* inorder,int inorder_start,int inorder_end)
{
    if (inorder_start > inorder_end) return;
    (*node) = calloc(1, sizeof(struct TreeNode));
    (*node)->val = preorder[(*preorder_idx)++];
    int idx = 0;
    idx = cache[(*node)->val + 5000];
    // while ((*node)->val != inorder[idx]) idx++;
    dfs(&(*node)->left, preorder_idx, preorder, inorder, inorder_start, idx - 1);
    dfs(&(*node)->right, preorder_idx, preorder, inorder, idx + 1, inorder_end);
}

static struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    if (!preorderSize) return NULL;
    struct TreeNode* root;
    int preorder_idx = 0;
    //中序索引表
    cache = calloc(10000,sizeof(short));
    for (int i = 0;i < inorderSize;i++) cache[inorder[i] + 5000] = i;
    dfs(&root, &preorder_idx, preorder, inorder, 0, inorderSize - 1);
    free(cache);
    return root;
}

int main_build_tree(void)
{
    int a[] = {1,2,2};
    int b[] = {2,1,2};
//    int a[] = {3,9,20,15,7};
//    int b[] = {9,3,15,20,7};
    struct TreeNode* root = buildTree(a, sizeof(a) / sizeof(int), b, sizeof(b) / sizeof(int));
    return 0;
}
