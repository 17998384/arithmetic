//
// Created by 我叫城北徐公° on 2021/4/20.
//

//  1028. 从先序遍历还原二叉树
//
//  我们从二叉树的根节点 root 开始进行深度优先搜索。
//
//  在遍历中的每个节点处，我们输出 D 条短划线（其中 D 是该节点的深度），然后输出该节点的值。（如果节点的深度为 D，则其直接子节点的深度为 D + 1。根节点的深度为 0）。
//
//  如果节点只有一个子节点，那么保证该子节点为左子节点。
//
//  给出遍历输出 S，还原树并返回其根节点 root。
//
//
//
//  示例 1：
//
//  输入："1-2--3--4-5--6--7"
//  输出：[1,2,5,3,4,6,7]
//
//  示例 2：
//
//  输入："1-2--3---4-5--6---7"
//  输出：[1,2,5,3,null,6,null,4,null,7]
//
//  示例 3：
//
//  输入："1-401--349---90--88"
//  输出：[1,401,null,349,88,90]
//
//
//
//  提示：
//
//  原始树中的节点数介于 1 和 1000 之间。
//  每个节点的值介于 1 和 10 ^ 9 之间。
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree_node.h"


typedef struct TreeNode Tree;

typedef struct pair
{
    int depth;
    int num;
    int count;
} Pair;

static Tree* new_tree(int val)
{
    Tree* tree = calloc(1, sizeof(Tree));
    tree->val = val;
    return tree;
}

Pair get_next_depth_with_val(const char* s, int* idx)
{
    Pair p;
    p.depth = 1;
    while (s[*idx] != '\0' && s[(*idx)] == '-') p.depth++, (*idx)++;
    p.count = p.depth - 1;
    //获取下一个数字
    int num = 0;
    char c;
    while (s[*idx] != '\0' && (c = s[(*idx)]) != '-')
    {
        num = num * 10 + (c - 48);
        p.count++;
        (*idx)++;
    }
    p.num = num;
    return p;
}

static void dfs(Tree** root, int depth, char* s, size_t strLen, int* strIdx)
{
    if (*strIdx >= strLen) return;
    Pair p = get_next_depth_with_val(s, strIdx);
    if (p.depth == depth) *root = new_tree(p.num);
    else
    {
        (*strIdx) -= p.count;
        return;
    }
    dfs(&(*root)->left, depth + 1, s, strLen, strIdx);
    dfs(&(*root)->right, depth + 1, s, strLen, strIdx);
}

struct TreeNode* recoverFromPreorder(char* S)
{
    size_t strLen = strlen(S);
    int strIdx = 0;
    Tree* root = NULL;
    dfs(&root, 1, S, strLen, &strIdx);
    return root;
}

int main(void)
{
    char* s = "1-401--349---90--88";
    Tree* root = recoverFromPreorder(s);
    return 0;
}