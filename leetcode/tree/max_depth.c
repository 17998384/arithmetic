//
//  max_depth.c
//  arithmetic
//
//  559. N 叉树的最大深度
//
//  给定一个 N 叉树，找到其最大深度。
//
//  最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
//
//  N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。
//
//
//
//  示例 1：
//
//  输入：root = [1,null,3,2,4,null,5,6]
//  输出：3
//

//  Created by 我叫城北徐公° on 2021/3/6.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

typedef struct Node Node;

void get_max_depth(Node* root,int* maxDepth,int depth)
{
    if (!root) return;
    if (depth > *maxDepth) *maxDepth = depth;
    for (int i = 0;i < root->numChildren;i++)
    {
        get_max_depth(root->children[i],maxDepth,depth + 1);
    }
}

int maxDepth(struct Node* root)
{
    int max = 0;
    get_max_depth(root,&max,1);
    return max;
}
