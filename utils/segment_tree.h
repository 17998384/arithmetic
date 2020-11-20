//
//  segment_tree.h
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/11/19.
//  Copyright © 2020 alex. All rights reserved.
//

#ifndef segment_tree_h
#define segment_tree_h

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

/*
    节点
 */
struct node
{
    int L;
    int R;
    Node* l_child;
    Node* r_child;
    int sum;
};

/*
    线段树结构体
 */
typedef struct segmentTree
{
    Node* root;
}SegmentTree;

/// 创建线段树
/// @param arr 数组
/// @param arr_size 数组长度
SegmentTree* create_segment_tree(int* arr,int arr_size);

/// 获取范围的和
/// @param start start
/// @param end end
int get_scope_sum(SegmentTree* segmentTree,int start,int end);

/// dfs遍历
/// @param root 线段树根节点
void dfs_segmentTree(Node* root);

/// dfs释放线段树节点
/// @param root 根结点
void dfs_free_segmentTree(Node* root);

#endif /* segment_tree_h */
