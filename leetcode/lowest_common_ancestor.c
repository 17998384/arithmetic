//
//  lowest_common_ancestor.c
//  arithmetic
//
//  面试题 04.08. 首个共同祖先
//
//  设计并实现一个算法，找出二叉树中某两个节点的第一个共同祖先。不得将其他的节点存储在另外的数据结构中。注意：这不一定是二叉搜索树。
//
//  例如，给定如下二叉树: root = [3,5,1,6,2,0,8,null,null,7,4]
//
//      3
//     / \
//    5   1
//   / \ / \
//  6  2 0  8
//    / \
//   7   4
//
//  示例 1:
//
//  输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
//  输出: 3
//  解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
//
//  Created by 我叫城北徐公° on 2021/2/3.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Node;

static Node* dfs(Node* root,Node* p,Node* q)
{
    if (!root) return NULL;
    if (root->val == p->val || root->val == q->val) return root;
    Node* left = dfs(root->left,p,q);
    Node* right = dfs(root->right,p,q);
    if (left && right) return root;
    return left ? left : right;
}

void check_dfs(struct TreeNode* root,int val,int* flag)
{
    if (!root || *flag) return;
    if (root->val == val)
    {
        *flag = 1;
        return;
    }
    check_dfs(root->left,val,flag);
    check_dfs(root->right,val,flag);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    /*
        性能优化，若只dfs 其中一个节点就可找到另一节点，则大可不必dfs所有
    */
    int flag = 0;
    //检查p中是否包含q
    check_dfs(p,q->val,&flag);
    if (flag) return p;
    flag = 0;
    //检查q中是否包含p
    check_dfs(q,p->val,&flag);
    if (flag) return q;
    return dfs(root,p,q);
}
