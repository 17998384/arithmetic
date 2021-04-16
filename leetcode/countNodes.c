//
// Created by 我叫城北徐公° on 2021/4/16.
//

//  222. 完全二叉树的节点个数
//
//  给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
//
//  完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。
//
//
//
//  示例 1：
//
//  输入：root = [1,2,3,4,5,6]
//  输出：6
//
//  示例 2：
//
//  输入：root = []
//  输出：0
//
//  示例 3：
//
//  输入：root = [1]
//  输出：1
//
//
//
//  提示：
//
//  树中节点的数目范围是[0, 5 * 104]
//  0 <= Node.val <= 5 * 104
//  题目数据保证输入的树是 完全二叉树
//
//
//
//  进阶：遍历树来统计节点是一种时间复杂度为 O(n) 的简单解决方案。你可以设计一个更快的算法吗？


#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

static Tree* new_tree(int val)
{
    Tree* tree = calloc(1, sizeof(Tree));
    tree->val = val;
    return tree;
}

static int get_depth(Tree* root, int start)
{
    if (!root) return start;
    int l = get_depth(root->left, start + 1);
    int r = get_depth(root->right, start + 1);
    return l > r ? l : r;
}

int countNodes(struct TreeNode* root)
{
    if (!root) return 0;
    int l = get_depth(root->left, 0);
    int r = get_depth(root->right, 0);
    //如果左大于右，说明右子树是满的，统计左子树就好，否则左子树是满的，统计右子树
    int nodeCount = l > r ? countNodes(root->left) : countNodes(root->right);
    int d =  l > r ? r : l;
    //如果左大于右，说明右子树是满的，计算出结果就好，否则左子树是满的；再加上之前计算的（左/右）子树结果，加上父节点1个，得到结果
    //计算满二叉树的数量公式（2 ^ depth - 1) => if (depth == 0) 0 : (1 << depth - 1)
    return (d ? ((1 << d) - 1) : 0) + nodeCount + 1;
}

int main(void)
{
    Tree* root = new_tree(1);
    root->left = new_tree(2);
    root->right = new_tree(3);
    Tree* rootLeft = root->left;
    rootLeft->left = new_tree(4);
    rootLeft->right = new_tree(5);
    root->right->left = new_tree(6);
    int count = countNodes(root);
    printf("%d\n", count);
    return 0;
}