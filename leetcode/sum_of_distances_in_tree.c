//
//  sum_of_distances_in_tree.c
//  arithmetic
//
//  834. 树中距离之和
//
//  给定一个无向、连通的树。树中有 N 个标记为 0...N-1 的节点以及 N-1 条边 。
//
//  第 i 条边连接节点 edges[i][0] 和 edges[i][1] 。
//
//  返回一个表示节点 i 与其他所有节点距离之和的列表 ans。
//
//  示例 1:
//
//  输入: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
//  输出: [8,12,6,10,10,10]
//  解释:
//  如下为给定的树的示意图：
//    0
//   / \
1//    2
//     /|\
//    3 4 5
//
//  我们可以计算出 dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
//  也就是 1 + 1 + 2 + 2 + 2 = 8。 因此，answer[0] = 8，以此类推。
//
//  Created by 我叫城北徐公° on 2021/2/27.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//其实题解里面说的还是比较抽象，不容易理解，只能说抓住一个点，自己去理解
//本质就是：
//第一遍dfs假定以节点0为根节点，后序遍历求每个节点的子节点部分的距离和与
//子节点数量，（以例题为例，0的所有子节点距离和就是8，1则为0，2则为3；0的
//子节点数量是5，1则为0，2则为3，剩下的以此类推，使用后序遍历可以类似于DP的
//操作，免去不少计算）
//第二遍dfs假定以节点0为根节点，前序遍历获取每个节点父节点部分的距离和，相加就是总距离和
//
//第二遍dfs不好理解，主要是寻找关系，以例题为例，假如寻找2的父节点，相当于把2当作父节点，而子节点只有0和1，原先0到0是0，
//0到1 是1，现在2 是根节点了，那么2到1就是0到1 加1，2到0就是0 到0 加 1，后面就靠自己领悟吧

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct list List;

static List** graph;        //图
static int* distance;       //距离
static int* nodeNum;        //节点数量

struct list
{
    int size;
    int capacity;
    int* data;
};

static List* new_list()
{
    List* list = calloc(1, sizeof(List));
    list->size = 0;
    list->capacity = 16;
    list->data = malloc(sizeof(int) * list->capacity);
    return list;
}

static void free_list(List* list)
{
    if (!list) return;
    free(list->data);
    free(list);
}

static void add_list(List* list,int node)
{
    if (!list) return;
    if (list->capacity - 1 == list->size)
    {
        list->capacity <<= 1;
        list->data = realloc(list->data, sizeof(int) * list->capacity);
    }
    list->data[list->size++] = node;
}

static void dfs1(int root,int parent)
{
    List* list = graph[root];
    for (int i = 0,size = list->size;i < size;i++)
    {
        if (list->data[i] == parent) continue;
        //后序遍历
        dfs1(list->data[i],root);
        nodeNum[root] += (nodeNum[list->data[i]] + 1);
        distance[root] += (distance[list->data[i]] + nodeNum[list->data[i]] + 1);
    }
}

static void dfs2(int N,int root,int parent)
{
    List* list = graph[root];
    for (int i = 0,size = list->size;i < size;i++)
    {
        //前序遍历
        int tmpNodeNum = N - 1 - nodeNum[root];
        if (tmpNodeNum > 0 && nodeNum[root] != -1)
        {
            int tmpDistance = distance[parent] - (distance[root] + nodeNum[root] + 1);
            distance[root] += (tmpDistance + tmpNodeNum);
            nodeNum[root] = -1;
        }
        if (list->data[i] == parent) continue;
        dfs2(N,list->data[i],root);
    }
}
 
int* sumOfDistancesInTree(int N, int** edges, int edgesSize, int* edgesColSize, int* returnSize)
{
    *returnSize = N;
    if (!N) return NULL;
    graph = malloc(sizeof(List*) * N);
    distance = calloc(N,sizeof(int));
    nodeNum = calloc(N,sizeof(int));
    for (int i = 0;i < N;i++) graph[i] = new_list();
    for (int i = 0;i < edgesSize;i++)
    {
        int* edge = edges[i];
        add_list(graph[edge[0]],edge[1]);
        add_list(graph[edge[1]],edge[0]);
    }
    dfs1(0,-1);
    dfs2(N,0,-1);
    // for (int i = 0;i < N ;i++)
    // {
    //     printf("%d %d\n",distance[i],nodeNum[i]);
    // }
    return distance;
}
