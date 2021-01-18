//
//  find_elements_create.c
//  arithmetic
//
//  1261. 在受污染的二叉树中查找元素
//
//  给出一个满足下述规则的二叉树：
//
//  root.val == 0
//  如果 treeNode.val == x 且 treeNode.left != null，那么 treeNode.left.val == 2 * x + 1
//  如果 treeNode.val == x 且 treeNode.right != null，那么 treeNode.right.val == 2 * x + 2
//
//  现在这个二叉树受到「污染」，所有的 treeNode.val 都变成了 -1。
//
//  请你先还原二叉树，然后实现 FindElements 类：
//
//  FindElements(TreeNode* root) 用受污染的二叉树初始化对象，你需要先把它还原。
//  bool find(int target) 判断目标值 target 是否存在于还原后的二叉树中并返回结果。
//
//  Created by 我叫城北徐公° on 2021/1/18.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

typedef struct find_elements
{
    struct TreeNode* root;
    int* bitmap;
    int cur_size;
}FindElements;

static void dfs(struct TreeNode* root,int val,FindElements* findElements)
{
    if (!root) return;
    root->val = val;
    int remainder = val / 32;
    if (remainder >= findElements->cur_size)
    {
        findElements->bitmap = realloc(findElements->bitmap,sizeof(int) * remainder << 1);
        findElements->cur_size = remainder << 1;
    }
    unsigned int bit = 1;
    findElements->bitmap[remainder] |= (bit << (val % 32));
    dfs(root->left,val * 2 + 1,findElements);
    dfs(root->right,val * 2 + 2,findElements);
}

static void dfs_free(struct TreeNode* root)
{
    if (!root) return;
    dfs_free(root->left);
    dfs_free(root->right);
    free(root);
}

FindElements* findElementsCreate(struct TreeNode* root)
{
    FindElements* findElements = malloc(sizeof(FindElements));
    findElements->root = root;
    findElements->cur_size = 512;
    findElements->bitmap = calloc(findElements->cur_size,sizeof(int));
    dfs(root,0,findElements);
    return findElements;
}

bool findElementsFind(FindElements* obj, int target)
{
    unsigned int bit = 1;
    return obj->bitmap[target / 32] & (bit << (target % 32));
}

void findElementsFree(FindElements* obj)
{
    dfs_free(obj->root);
    free(obj->bitmap);
    free(obj);
}
