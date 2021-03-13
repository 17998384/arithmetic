//
//  min_reorder.c
//  arithmetic
//
//  1466. 重新规划路线
//
//  n 座城市，从 0 到 n-1 编号，其间共有 n-1
//  条路线。因此，要想在两座不同城市之间旅行只有唯一一条路线可供选择（路线网形成一颗树）。去年，交通运输部决定重新规划路线，以改变交通拥堵的状况。
//
//  路线用 connections 表示，其中 connections[i] = [a, b] 表示从城市 a 到 b 的一条有向路线。
//
//  今年，城市 0 将会举办一场大型比赛，很多游客都想前往城市 0 。
//
//  请你帮助重新规划路线方向，使每个城市都可以访问城市 0 。返回需要变更方向的最小路线数。
//
//  题目数据 保证 每个城市在重新规划路线方向后都能到达城市 0 。
//
//
//  Created by 我叫城北徐公° on 2021/3/10.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//复杂版

//typedef struct adjacency_list
//{
//    int left;
//    int right;
//    int* leftData;
//    int* rightData;
//}AdjacencyList;
//
//AdjacencyList* new_AdjacencyList()
//{
//    AdjacencyList* adjacencyList = calloc(1,sizeof(AdjacencyList));
//    adjacencyList->leftData = malloc(sizeof(int) * 200);
//    adjacencyList->rightData = malloc(sizeof(int) * 200);
//    return adjacencyList;
//}
//
//void free_AdjacencyList(AdjacencyList* adjacencyList)
//{
//    free(adjacencyList->leftData);
//    free(adjacencyList->rightData);
//    free(adjacencyList);
//}
//
//static int bfs(AdjacencyList** adjacencyListArr,int n)
//{
//    int res = 0;
//    int stack[n * 2];
//    int cache[n];
//    memset(cache, 0, sizeof(int) * n);
//    int rbp,rsp;
//    rbp = rsp = 0;
//    stack[rsp++] = 0;
//    while (rbp < rsp)
//    {
//        int tmp = stack[rbp++];
//        cache[tmp] = 1;
//        AdjacencyList* tmpAdjacencyList = adjacencyListArr[tmp];
//        for (int i = 0;i < tmpAdjacencyList->right;i++)
//        {
//            int e = tmpAdjacencyList->rightData[i];
//            if (!cache[e])
//            {
//                res++;
//                stack[rsp++] = e;
//            }
//        }
//        for (int i = 0;i < tmpAdjacencyList->left;i++)
//        {
//            int e = tmpAdjacencyList->leftData[i];
//            if (!cache[e]) stack[rsp++] = e;
//        }
//    }
//    return res;
//}
//
//int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize)
//{
//    AdjacencyList** adjacencyListArr = malloc(sizeof(AdjacencyList*) * n);
//    for (int i = 0;i < n;i++) adjacencyListArr[i] = new_AdjacencyList();
//    //构建邻接表
//    for (int i = 0;i < connectionsSize;i++)
//    {
//        int* connection = connections[i];
//        int from = connection[0];
//        int to = connection[1];
//        AdjacencyList* fromAdjacencyList = adjacencyListArr[from];
//        AdjacencyList* toAdjacencyList = adjacencyListArr[to];
//        fromAdjacencyList->rightData[fromAdjacencyList->right++] = to;
//        toAdjacencyList->leftData[toAdjacencyList->left++] = from;
//    }
//    int res = bfs(adjacencyListArr,n);
//    // for (int i = 0;i < n;i++) free_AdjacencyList(adjacencyListArr[i]);
//    // free(adjacencyListArr);
//    return res;
//}


//简单版

int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize)
{
    int res = 0;
    int cache[n];
    memset(cache,0,sizeof(int) * n);
    //先把0标记为已通
    cache[0] = 1;
    int cur = 1;
    //防止数据顺序不以0开头
    while (cur < n)
    {
        for (int i = 0;i < connectionsSize;i++)
        {
            int* connection = connections[i];
            //如果已通的点指向未通的点，则需要重新规划，规划后标记为已通
            if (cache[connection[0]] == 1 && cache[connection[1]] == 0)
            {
                res++;
                cur++;
                cache[connection[1]] = 1;
            }
            //如果未通的点指向未通的点，说明不需要规划，标记为已通
            if (cache[connection[0]] == 0 && cache[connection[1]] == 1)
            {
                cur++;
                cache[connection[0]] = 1;
            }
        }
    }
    return res;
}
