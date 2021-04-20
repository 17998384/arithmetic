//
//  diameter_of_binary_tree.c
//  arithmetic
//
//  543. 二叉树的直径
//
//  给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
//
//
//
//  示例 :
//  给定二叉树
//
//            1
//           / \
//          2   3
//         / \
//        4   5
//
//  返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
//
//  Created by 我叫城北徐公° on 2021/2/21.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

static int dfs(Tree* root,int* maxLength)
{
    if (!root) return 0;
    int leftDepth = dfs(root->left,maxLength);
    int rightDepth = dfs(root->right,maxLength);
    int sum = leftDepth + rightDepth;
    *maxLength = *maxLength > sum ? *maxLength : sum;
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    int maxLength = 0;
    dfs(root,&maxLength);
    return maxLength;
}
