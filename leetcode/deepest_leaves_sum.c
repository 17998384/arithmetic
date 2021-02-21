//
//  deepest_leaves_sum.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2021/2/21.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"
#include "hash_map.h"

typedef struct TreeNode Tree;

static void dfs(Tree* root,int depth,int* maxDepth,int* buffer)
{
    if (!root) return;
    buffer[depth] += root->val;
    *maxDepth = depth > *maxDepth ? depth : *maxDepth;
    dfs(root->left,depth + 1,maxDepth,buffer);
    dfs(root->right,depth + 1,maxDepth,buffer);
}

int deepestLeavesSum(struct TreeNode* root)
{
    int buffer[1000] = {0};
    int maxDepth = -1;
    dfs(root,1,&maxDepth,buffer);
    return buffer[maxDepth];
}


//hashMap版
//int hash_code(void* key)
//{
//    return *(int*)key;
//}
//
//int equals(void* a,void* b)
//{
//    return *(int*)a == *(int*)b;
//}
//
//typedef struct TreeNode Tree;
//
//static void dfs(Tree* root,int k,int* res,HashMap* map)
//{
//    if (!root || *res) return;
//    dfs(root->left,k,res,map);
//    int difference = k - root->val;
//    // printf("%d\n",difference);
//    if (get(map,&difference)) *res = 1;
//    put(map,&root->val,&root->val);
//    dfs(root->right,k,res,map);
//}
//
//int findTarget(struct TreeNode* root, int k)
//{
//    int res = 0;
//    HashMap* map = new_hash_map(hash_code,equals);
//    dfs(root,k,&res,map);
//    free_map(map,0);
//    return res;
//}
