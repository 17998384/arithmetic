//
//  max_ancestor_diff.c
//  arithmetic
//
//  1026. 节点与其祖先之间的最大差值
//
//  给定二叉树的根节点 root，找出存在于 不同 节点 A 和 B 之间的最大值 V，其中 V = |A.val - B.val|，且 A 是 B 的祖先。
//
//  （如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先）
//
//
//  Created by 我叫城北徐公° on 2021/2/26.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

/*
    第一种解法
 */

// static int resMax;

// static void dfs(Tree* root,int min,int max)
// {
//     if (!root) return;
//     if (root->val > max) max = root->val;
//     if (root->val < min) min = root->val;
//     int tmp = abs(max - min);
//     if (tmp > resMax) resMax = tmp;
//     dfs(root->left,min,max);
//     dfs(root->right,min,max);
// }

// int maxAncestorDiff(struct TreeNode* root)
// {
//     resMax = 0x8FFFFFFF;
//     dfs(root->left,root->val,root->val);
//     dfs(root->right,root->val,root->val);
//     return resMax;
// }

/*
 第二种解法
 */

static int max;

static int* new_array(int a,int b)
{
    int* arr = malloc(sizeof(int) * 2);
    arr[0] = a;
    arr[1] = b;
    return arr;
}

static int* dfs(Tree* root)
{
    if (!root) return NULL;
    int* left = dfs(root->left);
    int* right = dfs(root->right);
    int t_min = root->val,t_max = root->val;
    if (left)
    {
        int _0 = abs(left[0] - root->val),_1 = abs(left[1] - root->val);
        max = max > _0 ? max : _0;
        max = max > _1 ? max : _1;
        t_min = t_min < left[0] ? t_min : left[0];
        t_max = t_max > left[1] ? t_max : left[1];
        free(left);
    }
    if (right)
    {
        int _0 = abs(right[0] - root->val),_1 = abs(right[1] - root->val);
        max = max > _0 ? max : _0;
        max = max > _1 ? max : _1;
        t_min = t_min < right[0] ? t_min : right[0];
        t_max = t_max > right[1] ? t_max : right[1];
        free(right);
    }
    return new_array(t_min,t_max);
}

int maxAncestorDiff(struct TreeNode* root)
{
    max = 0x8FFFFFFF;
    int* res = dfs(root);
    free(res);
    return max;
}
