//
//  construct_from_pre_post.c
//  arithmetic
//
//  889. 根据前序和后序遍历构造二叉树
//
//  返回与给定的前序和后序遍历匹配的任何二叉树。
//
//   pre 和 post 遍历中的值是不同的正整数。
//
//
//
//  示例：
//
//  输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
//  输出：[1,2,3,4,5,6,7]
//
//
//  Created by 我叫城北徐公° on 2021/2/16.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

static int* buffer = NULL;

typedef struct TreeNode Node;

static Node* new_node(int val)
{
    Node* node = calloc(1,sizeof(Node));
    node->val = val;
    return node;
}

static void dfs(int size,int* pre,int* preIdx,int* post,int postBegin,int postEnd,Node** root)
{
    if (*preIdx >= size || postBegin > postEnd) return;
    *root = new_node(pre[(*preIdx)++]);
    if (postBegin == postEnd) return;
    
    int idx = buffer[pre[*preIdx]];
    int prev = (*preIdx) - 1;
    dfs(size,pre,preIdx,post,postBegin,idx,&(*root)->left);
    dfs(size,pre,preIdx,post,idx + 1,buffer[pre[prev]] - 1,&(*root)->right);
}

struct TreeNode* constructFromPrePost(int* pre, int preSize, int* post, int postSize)
{
    if (!preSize) return NULL;
    Node* root = NULL;
    buffer = malloc(sizeof(int) * (preSize + postSize + 1));
    //计算缓存
    for (int i = 0;i < preSize;i++) buffer[post[i]] = i;
    int preIdx = 0;
    dfs(preSize,pre,&preIdx,post,0,postSize - 1,&root);
    free(buffer);
    return root;
}

int main_constructFromPrePost(void)
{
    int pre[] = {1,2,4,5,3,6,7};
    int post[] = {4,5,2,6,7,3,1};
    Node* root = constructFromPrePost(pre, sizeof(pre) / sizeof(pre[0]), post, sizeof(post) / sizeof(post[0]));
    return 0;
}
