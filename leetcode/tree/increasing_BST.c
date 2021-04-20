//
//  increasing_BST.c
//  arithmetic
//
//  897.递增顺序查找树
//
//  给你一个树，请你 按中序遍历 重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点。
//
//
//
//  示例 ：
//
//  输入：[5,3,6,2,4,null,8,1,null,null,null,7,9]
//
//         5
//        / \
//      3    6
//     / \    \
//    2   4    8
//   /        / \
//  1        7   9
//
//  输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
//
//   1
//    \
//     2
//      \
//       3
//        \
//         4
//          \
//           5
//            \
//             6
//              \
//               7
//                \
//                 8
//                  \
//                   9
//
    
//
//  Created by 我叫城北徐公° on 2020/11/24.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

struct TreeNode* head;

struct TreeNode** temp;

static void dfs(struct TreeNode* root)
{
    if (!root)
        return;
    dfs(root->left);
    *temp = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    (*temp)->val = root->val;
    temp = &((*temp)->right);
    dfs(root->right);
}

struct TreeNode* increasingBST(struct TreeNode* root)
{
    head = NULL;
    temp = &head;
    dfs(root);
    return head;
}
