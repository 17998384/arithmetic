//
//  find_redundant_directed_connection.c
//  arithmetic
//
//
//  685. 冗余连接 II
//
//  在本问题中，有根树指满足以下条件的有向图。该树只有一个根节点，所有其他节点都是该根节点的后继。每一个节点只有一个父节点，除了根节点没有父节点。
//
//  输入一个有向图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) // 的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。
//
//  结果图是一个以边组成的二维数组。 每一个边 的元素是一对 [u, v]，用以表示有向图中连接顶点 u 和顶点 v 的边，其中 u 是 v 的一个父节点。
//
//  返回一条能删除的边，使得剩下的图是有N个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。
//
//  示例 1:
//
//  输入: [[1,2], [1,3], [2,3]]
//  输出: [2,3]
//  解释: 给定的有向图如下:
//    1
//   / \
//  v   v
//  2-->3
//
//
//  Created by 我叫城北徐公° on 2021/1/30.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
    本题结题思路（通俗白话易懂）
    由于题目说明，这个图原本就可以组成一个树，但是由于多增加了一条边导致无法组成树（若无这条边根节点的入度一定为0），那么这条边可能会引发2种情况
    1.这条边没指向根节点，那么这条边一定指向一个除根节点之外的点，也就是说有一个点的入度一定为2，找出入度为2的点，分别尝试删除任意一条判断是否可为树
    2.这条边指向了根节点，那么一定会成环，只需要使用并查集（不懂并查集的可以百度）找到该边删除即可
 */

int find_root(int x,int* parent)
{
    return parent[x] == -1 ? x : find_root(parent[x],parent);
}

int merge(int x,int y,int* parent,int* depth)
{
    int _x = find_root(x, parent);
    int _y = find_root(y, parent);
    if (_x == _y) return 0;
    //压缩优化算法
    if (depth[_x] > depth[_y])
        parent[_y] = _x;
    else if (depth[_y] > depth[_x])
        parent[_x] = _y;
    else
    {
        parent[_x] = _y;
        depth[_y]++;
    }
    return 1;
}

void init_check_and_set(int* parent,int* depth,int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        depth[i] = 0;
    }
}

int* findRedundantDirectedConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize)
{
    //缓存
    int** buffer = calloc(edgesSize + 1, sizeof(int*));
    for (int i = 0; i <= edgesSize; i++) buffer[i] = calloc(3, sizeof(int));
    //并查集使用数组
    int* parent = calloc(edgesSize + 1, sizeof(int));
    int* depth = calloc(edgesSize + 1, sizeof(int));
    //出现环的位置
    int cycleIdx = -1;
    //入度大于1的位置
    int granOne = -1;
    
    //检查入度是否有为2的点，并记录
    for (int i = 0; i < edgesSize; i++)
    {
        int* edge = edges[i];
        //记录入度大于2的
        int* bufferInner = buffer[edge[1]];
        bufferInner[++bufferInner[0]] = i;
        if (bufferInner[0] > 1) granOne = edge[1];
    }
    
    //初始化返回结果
    *returnSize = 2;
    
    //如果是第一种情况
    if (granOne != -1)
    {
        //拿出导致入度为2的两条边
        int sideOneIdx = buffer[granOne][1];
        int sideTwoIdx = buffer[granOne][2];
        init_check_and_set(parent, depth, edgesSize + 1);
        //检查能否组成树
        for (int i = 0; i < edgesSize; i++)
        {
            //先用靠后的进行尝试
            if (i == sideTwoIdx) continue;
            //能构成环的则一定不为树
            int* edge = edges[i];
            //记录出现环的位置
            if (cycleIdx == -1 && !merge(edge[0], edge[1], parent, depth))
            {
                cycleIdx = i;
                break;
            }
        }
        if (cycleIdx == -1) return edges[sideTwoIdx];
        else return edges[sideOneIdx];
    }
    //不是第一种即是是第二种情况
    else
    {
        //初始化并查集
        init_check_and_set(parent, depth, edgesSize + 1);
        for (int i = 0; i < edgesSize; i++)
        {
            int* edge = edges[i];
            //记录出现环的位置
            if (!merge(edge[0], edge[1], parent, depth))
            {
                cycleIdx = i;
                break;
            }
        }
        return edges[cycleIdx];
    }
}
int main_findRedundantDirectedConnection(void)
{
    int arr[49][2] = {{37,30},{21,34},{10,40},{8,36},{18,10},{50,11},{13,6},{40,7},{14,38},{41,24},{32,17},{31,15},{6,27},{45,3},{30,42},{43,26},{9,4},{4,31},{1,29},{5,23},{44,19},{15,44},{49,20},{26,5},{23,50},{48,41},{47,22},{3,46},{11,16},{12,35},{34,45},{38,2},{2,32},{24,49},{35,37},{29,13},{46,48},{28,12},{7,21},{27,18},{17,39},{42,14},{20,47},{36,1},{22,9},{25,8},{39,25},{16,28},{19,43}};
    //并查集使用数组
    int parent[51];
    int depth[51];
    init_check_and_set(parent, depth, 51);
    for (int i = 0; i < 49; i++)
    {
        int* edge = arr[i];
        int res = merge(edge[0], edge[1], parent, depth);
        if (!res)
        {
            printf("the graph is cycle\n");
            exit(0);
        }
    }
    printf("the graph is no cycle\n");
    return 0;
}
