//
//  segment_tree.c
//  arithmetic
//
//  线段树
//
//  Created by 我叫城北徐公° on 2020/11/19.
//  Copyright © 2020 alex. All rights reserved.
//

#include "segment_tree.h"

void create_segment_tree0(Node** node, int start, int end, int* arr)
{
    *node = (Node*) calloc(1, sizeof(Node));
    if (start == end)
    {
        (*node)->sum = arr[start];
        (*node)->L = start;
        (*node)->R = end;
        return;
    }
    int half = (start + end) / 2;
    create_segment_tree0(&(*node)->l_child, start, half, arr);
    create_segment_tree0(&(*node)->r_child, half + 1, end, arr);
    (*node)->sum = (*node)->l_child->sum + (*node)->r_child->sum;
    (*node)->L = start;
    (*node)->R = end;
}

int get_scope_sum0(Node* node, int start, int end)
{
    if (!node)
        return 0;
    if (node->L == start && node->R == end)
        return node->sum;
    int l_sum = 0;
    int r_sum = 0;
    if (start <= node->l_child->R)
        l_sum = get_scope_sum0(node->l_child, start, node->l_child->R);
    if (end >= node->r_child->L)
        r_sum = get_scope_sum0(node->r_child, node->r_child->L, end);
    return l_sum + r_sum;
}

/// 创建线段树
/// @param arr 数组
/// @param arr_size 数组长度
SegmentTree* create_segment_tree(int* arr, int arr_size)
{
    Node* root;
    create_segment_tree0(&root, 0, arr_size - 1, arr);
    SegmentTree* segmentTree = (SegmentTree*) malloc(sizeof(SegmentTree));
    segmentTree->root = root;
    return segmentTree;
}

/// 获取范围的和
/// @param start start
/// @param end end
int get_scope_sum(SegmentTree* segmentTree, int start, int end)
{
    return get_scope_sum0(segmentTree->root, start, end);
}

/// dfs遍历
/// @param root 线段树根节点
void dfs_segmentTree(Node* root)
{
    if (!root)
        return;
    printf("L -> %d,R -> %d,sum -> %d\n", root->L, root->R, root->sum);
    dfs_segmentTree(root->l_child);
    dfs_segmentTree(root->r_child);
}

/// dfs释放线段树节点
/// @param root 根结点
void dfs_free_segmentTree(Node* root)
{
    if (!root)
        return;
    dfs_free_segmentTree(root->l_child);
    dfs_free_segmentTree(root->r_child);
    free(root);
}

//int main(void)
//{
//    int arr[] = {1,3,5,7,9,11};
//    SegmentTree* segmentTree = create_segment_tree(arr, sizeof(arr) / sizeof(arr[0]));
//    dfs_segmentTree(segmentTree->root);
////    int sum = get_scope_sum(segmentTree, 2, 3);
////    printf("%d\n",sum);
//    dfs_free_segmentTree(segmentTree->root);
//    free(segmentTree);
//    return 0;
//}
