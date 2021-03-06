//
//  check_sub_tree.c
//  arithmetic
//
//  面试题 04.10. 检查子树
//
//  检查子树。你有两棵非常大的二叉树：T1，有几万个节点；T2，有几万个节点。设计一个算法，判断 T2 是否为 T1 的子树。
//
//  如果 T1 有这么一个节点 n，其子树与 T2 一模一样，则 T2 为 T1 的子树，也就是说，从节点 n 处把树砍断，得到的树与 T2 完全相同。
//
//  注意：此题相对书上原题略有改动。
//
//  示例1:
//
//   输入：t1 = [1, 2, 3], t2 = [2]
//   输出：true
//
//
//  Created by 我叫城北徐公° on 2021/3/5.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

int res;

static void dfs2(Tree* t1,Tree* t2,int* flag)
{
    if (!t1 && !t2) return;
    else if (t1->val == t2->val)
    {
        dfs2(t1->left,t2->left,flag);
        dfs2(t1->right,t2->right,flag);
    }
    else *flag = 0;
}

static void dfs1(Tree* t1,Tree* t2)
{
    if (!t1 || !t2) return;
    if (t1->val == t2->val)
    {
        int flag = 1;
        dfs2(t1,t2,&flag);
        if (flag)
        {
            res = 1;
            return;
        }
    }
    dfs1(t1->left,t2);
    dfs1(t1->right,t2);
}

int checkSubTree(struct TreeNode* t1, struct TreeNode* t2)
{
    res = 0;
    if (!t2) return 1;
    if (!t1 && t2) return 0;
    dfs1(t1,t2);
    return res;
}
