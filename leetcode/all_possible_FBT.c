//
//  all_possible_FBT.c
//  arithmetic
//
//  894. 所有可能的满二叉树
//
//  满二叉树是一类二叉树，其中每个结点恰好有 0 或 2 个子结点。
//
//  返回包含 N 个结点的所有可能满二叉树的列表。 答案的每个元素都是一个可能树的根结点。
//
//  答案中每个树的每个结点都必须有 node.val=0。
//
//  你可以按任何顺序返回树的最终列表。
//
//  Created by 我叫城北徐公° on 2021/1/13.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

typedef struct leetcode_list LeetcodeList;

struct leetcode_list
{
    struct TreeNode** element;
    int max_size;
    int cur_size;
    void(*leetcode_list_add)(LeetcodeList*,struct TreeNode*);
    void(*leetcode_list_resize)(LeetcodeList*);
};

static void leetcode_list_add(LeetcodeList* leetcodeList,struct TreeNode* node)
{
    if (leetcodeList->cur_size > leetcodeList->max_size - 1) leetcodeList->leetcode_list_resize(leetcodeList);
    leetcodeList->element[leetcodeList->cur_size++] = node;
}

static void leetcode_list_resize(LeetcodeList* leetcodeList,struct TreeNode* node)
{
    leetcodeList->element = realloc(leetcodeList->element, sizeof(struct TreeNode*) * leetcodeList->max_size << 1);
    leetcodeList->max_size <<= 1;
}

LeetcodeList* new_leetcode_list()
{
    LeetcodeList* leetcodeList = malloc(sizeof(LeetcodeList));
    leetcodeList->cur_size = 0;
    leetcodeList->max_size = 1 << 4;
    leetcodeList->element = malloc(sizeof(struct TreeNode*) * leetcodeList->max_size);
    leetcodeList->leetcode_list_add = leetcode_list_add;
    leetcodeList->leetcode_list_resize = leetcode_list_resize;
    return leetcodeList;
}

static struct TreeNode* new_node()
{
    struct TreeNode* node = calloc(1,sizeof(struct TreeNode));
    return node;
}

static LeetcodeList* dfs(int N)
{
    if (N == 1)
    {
        LeetcodeList* leetcodeList = new_leetcode_list();
        leetcodeList->leetcode_list_add(leetcodeList,new_node());
        return leetcodeList;
    }
    LeetcodeList* res = new_leetcode_list();
    for (int i = 1; i < N; i += 2)
    {
        LeetcodeList* left = dfs(i);
        LeetcodeList* right = dfs(N - 1 - i);
        for (int j = 0; j < left->cur_size; j++)
        {
            for (int k = 0; k < right->cur_size; k++)
            {
                struct TreeNode* root = new_node();
                root->left = left->element[j];
                root->right = right->element[k];
                res->leetcode_list_add(res,root);
            }
        }
    }
    return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** allPossibleFBT(int N, int* returnSize)
{
    *returnSize = 0;
    //N是偶数一定不行
    if (N % 2 == 0) return NULL;
    LeetcodeList* res = dfs(N);
    *returnSize = res->cur_size;
    return res->element;
}

int main_allPossibleFBT(void)
{
    int returnSize;
    allPossibleFBT(11, &returnSize);
    return 0;
}
