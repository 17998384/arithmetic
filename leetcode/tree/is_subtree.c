//
// Created by 我叫城北徐公° on 2021/4/19.
//

//  572. 另一个树的子树
//
//  给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。
//
//  示例 1:
//  给定的树 s:
//
//  3
//  / \
//     4   5
//  / \
//   1   2
//
//  给定的树 t：
//
//  4
//  / \
//   1   2
//
//  返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。
//
//  示例 2:
//  给定的树 s：
//
//  3
//  / \
//     4   5
//  / \
//   1   2
//  /
//  0
//
//  给定的树 t：
//
//  4
//  / \
//   1   2
//
//  返回 false。
//
#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

static int res;

static void check_same_tree(Tree* a, Tree* b, int* flag)
{
    if (!a && !b) return;
    if ((!a && b) || (a && !b))
    {
        *flag = 0;
        return;
    }
    if (a->val != b->val)
    {
        *flag = 0;
        return;
    }
    check_same_tree(a->left, b->left, flag);
    check_same_tree(a->right, b->right, flag);
}

static void dfs(Tree* a, Tree* b)
{
    if (!a || !b) return;
    dfs(a->left, b);
    dfs(a->right, b);
    if (a->val == b->val)
    {
        int flag = 1;
        check_same_tree(a, b, &flag);
        if (flag)
        {
            res = 1;
            return;
        }

    }
}

int isSubtree(struct TreeNode* s, struct TreeNode* t)
{
    res = 0;
    dfs(s, t);
    return res;
}