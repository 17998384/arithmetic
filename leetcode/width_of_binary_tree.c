//
//  width_of_binary_tree.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2021/2/23.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

static int bfs(Tree* root)
{
    int max = 0;
    if (!root) return max;
    Tree* stack[2000];
    unsigned long long numStack[2000];
    //指针，标记，深度
    int rsp = 0,rbp = 0;
    unsigned long long start,end,intMax = 2500000000;
    root->val = max = 1;
    stack[rsp++] = root;
    numStack[rsp] = 1;
    //bfs
    while (rbp < rsp)
    {
        int rspBak = rsp;
        start = end = -1;
        while (rbp < rspBak)
        {
            //统计每层节点，并记录当前层节点个数
            unsigned long long curVal = numStack[rbp];
            Tree* node = stack[rbp++];
            if (node->left)
            {
                numStack[rsp] = (curVal * 2) % intMax;
                if (start == -1) start = numStack[rsp];
                end = numStack[rsp];
                stack[rsp++] = node->left;
            }
            if (node->right)
            {
                numStack[rsp] = (curVal * 2) % intMax + 1;
                if (start == -1) start = numStack[rsp];
                end = numStack[rsp];
                stack[rsp++] = node->right;
            }
        }
        if (start != -1)
        {
            int width = (end - start) + 1;
            if (width > max) max = width;
        }
    }
    return max;
}

int widthOfBinaryTree(struct TreeNode* root)
{
    int width = bfs(root);
    return width;
}

