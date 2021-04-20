//
// Created by 我叫城北徐公° on 2021/4/19.
//

//  684. 冗余连接
//
//
//  在本问题中, 树指的是一个连通且无环的无向图。
//
//  输入一个图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。
//
//  结果图是一个以边组成的二维数组。每一个边的元素是一对[u, v] ，满足 u < v，表示连接顶点u 和v的无向图的边。
//
//  返回一条可以删去的边，使得结果图是一个有着N个节点的树。如果有多个答案，则返回二维数组中最后出现的边。答案边 [u, v] 应满足相同的格式 u < v。
//
//  示例 1：
//
//  输入: [[1,2], [1,3], [2,3]]
//  输出: [2,3]
//  解释: 给定的无向图为:
//  1
//  / \
//  2 - 3
//
//  示例 2：
//
//  输入: [[1,2], [2,3], [3,4], [1,4], [1,5]]
//  输出: [1,4]
//  解释: 给定的无向图为:
//  5 - 1 - 2
//  |   |
//  4 - 3
//
//  注意:
//
//  输入的二维数组大小在 3 到 1000。
//  二维数组中的整数在1到N之间，其中N是输入数组的大小。
//
/**
 * 并查集
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int* cache;

static int find_parent(int x)
{
    return cache[x] == 0 ? x : find_parent(cache[x]);
}

static int merge(int x, int y)
{
    int xParent, yParent;
    if ((xParent = find_parent(x)) == (yParent = find_parent(y))) return 0;
    cache[xParent] = yParent;
    return yParent;
}

static int union_find_sets(int** edges, int edgesSize)
{
    cache = calloc(edgesSize + 1, sizeof(int));
    for (int i = 0; i < edgesSize; ++i)
    {
        int x = edges[i][0];
        int y = edges[i][1];
        if (!merge(x, y)) return i;
    }
    return 0;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize)
{
    int idx = union_find_sets(edges, edgesSize);
    *returnSize = 2;
    free(cache);
    int* res = malloc(sizeof(int) * 2);
    res[0] = fmin(edges[idx][0], edges[idx][1]);
    res[1] = fmax(edges[idx][0], edges[idx][1]);
    return res;
}