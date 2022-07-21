//
// Created by 我叫城北徐公° on 2022/7/21.
//

//  814. 二叉树剪枝
//
//          给你二叉树的根结点 root ，此外树的每个结点的值要么是 0 ，要么是 1 。
//
//  返回移除了所有不包含 1 的子树的原二叉树。
//
//  节点 node 的子树为 node 本身加上所有 node 的后代。
//
//
//
//  示例 1：
//
//  输入：root = [1,null,0,0,1]
//  输出：[1,null,0,null,1]
//  解释：
//  只有红色节点满足条件“所有不包含 1 的子树”。 右图为返回的答案。
//
//  示例 2：
//
//  输入：root = [1,0,1,0,0,0,1]
//  输出：[1,null,1,null,1]
//
//  示例 3：
//
//  输入：root = [1,1,0,1,1,0,1,0]
//  输出：[1,1,0,1,1,null,1]
//
//
//
//  提示：
//
//  树中节点的数目在范围 [1, 200] 内
//  Node.val 为 0 或 1



#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode TreeNode;

static int dfs(TreeNode* treeNode)
{
    if (!treeNode) return 0;
    int a = dfs(treeNode->left);
    int b = dfs(treeNode->right);
    if (!a) treeNode->left = NULL;
    if (!b) treeNode->right = NULL;
    return a + b + treeNode->val;
}

struct TreeNode* pruneTree(struct TreeNode* root)
{
    int res = dfs(root);
    if (res == 0) return NULL;
    return root;
}