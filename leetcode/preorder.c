//
//  preorder.c
//  arithmetic
//
//  589.N叉树的前序遍历（不允许使用递归）
//
//  Created by 我叫城北徐公° on 2020/11/23.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int* nums;

/// 递归版（dfs）
/// @param root node节点
/// @param returnSize 返回元素大小
static void dfs(struct Node* root, int* returnSize)
{
    if (!root)
        return;
    nums[(*returnSize)++] = root->val;
    for (int i = 0; i < root->numChildren; i++)
    {
        dfs(root->children[i], returnSize);
    }
}


/// 循环版
/// @param root node节点
/// @param returnSize 返回元素大小
void loop(struct Node* root, int* returnSize)
{
    long long stack[1000] = {0};
    int s_p = 0;
    struct Node* node;
    int i = 0,target = 0;
    stack[s_p++] = (long long)root;
    stack[s_p++] = i;
    while (s_p != 0)
    {
        //pop
        i = (int)stack[--s_p];
        node = (struct Node*)stack[--s_p];
        if (s_p >= target)
        {
            nums[(*returnSize)++] = node->val;
            target += 2;
        }
        //并判断i长度
        if (i < node->numChildren)
        {
            //push，将其本身再次push到栈中，并将i+1
            stack[s_p++] = (long long)node;
            stack[s_p++] = i + 1;
            //将子节点push进去
            stack[s_p++] = (long long)node->children[i];
            stack[s_p++] = 0;
            continue;
        }
        else
            target -= 2;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* _preorder(struct Node* root, int* returnSize)
{
    *returnSize = 0;
    if(!root)
        return NULL;
    nums = (int*)malloc(sizeof(int) * 1000);
    //dfs
    dfs(root, returnSize);
    //循环
    loop(root, returnSize);
    return nums;
}

int main_preorder(void)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = 1;
    node->numChildren = 2;
    node->children = (struct Node**)malloc(sizeof(struct Node*) * 2);
    node->children[0] = (struct Node*)calloc(1, sizeof(struct Node));
    node->children[1] = (struct Node*)calloc(1, sizeof(struct Node));
    node->children[0]->val = 2;
    node->children[1]->val = 3;
    int returnSize;
    _preorder(node, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ",nums[i]);
    }
    return 0;
}

