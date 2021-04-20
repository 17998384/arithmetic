//
//  flip_equiv.c
//  arithmetic
//
//  951. 翻转等价二叉树
//
//  我们可以为二叉树 T 定义一个翻转操作，如下所示：选择任意节点，然后交换它的左子树和右子树。
//
//  只要经过一定次数的翻转操作后，能使 X 等于 Y，我们就称二叉树 X 翻转等价于二叉树 Y。
//
//  编写一个判断两个二叉树是否是翻转等价的函数。这些树由根节点 root1 和 root2 给出。
//
//
//
//  示例：
//
//  输入：root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
//  输出：true
//  解释：我们翻转值为 1，3 以及 5 的三个节点。
//  Flipped Trees Diagram
//
//
//
//  提示：
//
//      每棵树最多有 100 个节点。
//      每棵树中的每个值都是唯一的、在 [0, 99] 范围内的整数。
//
//
//  Created by 我叫城北徐公° on 2021/3/24.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

static void dfs(Tree* root1,Tree* root2,int* flag)
{
    if (!root1 && !root2) return;
    if ((root1 && !root2) || (!root1 && root2) || root1->val != root2->val)
    {
        *flag = 0;
        return;
    }
    int tab = 0;
    if ((root1->left || root2->left) && ((root1->left && !root2->left) || (!root1->left && root2->left) || root1->left->val != root2->left->val)) tab = 1;
    dfs(root1->left,tab ? root2->right : root2->left,flag);
    dfs(root1->right,tab ? root2->left : root2->right,flag);
}

int flipEquiv(struct TreeNode* root1, struct TreeNode* root2)
{
    int flag = 1;
    dfs(root1,root2,&flag);
    return flag;
}
