//
//  bst_iterator.c
//  arithmetic
//
//  173. 二叉搜索树迭代器
//
//  实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。
//
//  调用 next() 将返回二叉搜索树中的下一个最小的数。
//
//
//
//  示例：
//
//  BSTIterator iterator = new BSTIterator(root);
//  iterator.next();    // 返回 3
//  iterator.next();    // 返回 7
//  iterator.hasNext(); // 返回 true
//  iterator.next();    // 返回 9
//  iterator.hasNext(); // 返回 true
//  iterator.next();    // 返回 15
//  iterator.hasNext(); // 返回 true
//  iterator.next();    // 返回 20
//  iterator.hasNext(); // 返回 false
//
//
//
//  提示：
//
//      next() 和 hasNext() 操作的时间复杂度是 O(1)，并使用 O(h) 内存，其中 h 是树的高度。
//      你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 中至少存在一个下一个最小的数。
//
//
//
//  Created by 我叫城北徐公° on 2021/3/7.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

typedef struct bst_iterator
{
    Tree** stack;
    int rbp;
} BSTIterator;

static void get_tree_depth(Tree* root,int* maxDepth,int curDepth)
{
    if (!root) return;
    if (curDepth > *maxDepth) *maxDepth = curDepth;
    get_tree_depth(root->left,maxDepth,curDepth + 1);
    get_tree_depth(root->right,maxDepth,curDepth + 1);
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root)
{
    int maxDepth = 0;
    get_tree_depth(root,&maxDepth,1);
    BSTIterator* bstIterator = malloc(sizeof(BSTIterator));
    bstIterator->stack = malloc(sizeof(Tree*) * maxDepth);
    bstIterator->rbp = 0;
    while (root)
    {
        bstIterator->stack[bstIterator->rbp++] = root;
        root = root->left;
    }
    return bstIterator;
}

int bSTIteratorNext(BSTIterator* obj)
{
    Tree* tree = obj->stack[--obj->rbp];
    int res = tree->val;
    if (tree->right)
    {
        tree = tree->right;
        while (tree)
        {
            obj->stack[obj->rbp++] = tree;
            tree = tree->left;
        }
    }
    return res;
}

int bSTIteratorHasNext(BSTIterator* obj)
{
    if (obj->rbp == 0) return 0;
    return 1;
}

void bSTIteratorFree(BSTIterator* obj)
{
    free(obj->stack);
    free(obj);
}

