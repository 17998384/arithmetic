//
//  is_same_tree.c
//  arithmetic
//
//  100. 相同的树
//
//  如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
//
//  示例 1:
//
//  输入:       1         1
//            / \       / \
//           2   3     2   3
//
//          [1,2,3],   [1,2,3]
//
//  输出: true
//
//  示例 2:
//
//  输入:      1          1
//            /           \
//           2             2
//
//          [1,2],     [1,null,2]
//
//  输出: false
//
//  Created by 我叫城北徐公° on 2021/1/17.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

static void dfs(struct TreeNode* p, struct TreeNode* q,int* isSame)
{
    if (!*isSame) return;
    if (!p && !q) return;
    if ((p && !q) || (!p && q))
    {
        *isSame = 0;
        return;
    }
    if (p->val != q->val)
    {
        *isSame = 0;
        return;
    }
    dfs(p->left,q->left,isSame);
    dfs(p->right,q->right,isSame);
}

int isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    int res = 1;
    dfs(p,q,&res);
    return res;
}
