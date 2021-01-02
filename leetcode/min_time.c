//
//  min_time.c
//  arithmetic
//
//  1443. 收集树上所有苹果的最少时间
//
//  给你一棵有 n 个节点的无向树，节点编号为 0 到 n-1 ，它们中有一些节点有苹果。通过树上的一条边，需要花费 1 秒钟。你从 节点 0 出发，请你返回最少需要多少秒，可以收集到所有苹果，并回到节点 0 。
//
//  无向树的边由 edges 给出，其中 edges[i] = [fromi, toi] ，表示有一条边连接 from 和 toi 。除此以外，还有一个布尔数组 hasApple ，其中 hasApple[i] = true 代表节点 i 有一个苹果，否则，节点 i 没有苹果。
//
//  Created by 我叫城北徐公° on 2021/1/1.
//  Copyright © 2021 alex. All rights reserved.
//

#define SIDE 18
#include <stdio.h>
#include <stdlib.h>

static void dfs(int root,int prev, int* hasApple,int* res,int** buffer)
{
    if (root == -1) return;
    for (int i = 0; i < SIDE; i++)
    {
        int* child = buffer[root];
        dfs(child[i], root, hasApple, res, buffer);
    }
    if (hasApple[root] && prev != -1) hasApple[prev] = 1;
    if (hasApple[root] && prev != -1) (*res) += 2;
}

int* my_malloc()
{
    int* mem = malloc(sizeof(int) * SIDE);
    for (int i = 0; i < SIDE; i++)
    {
        mem[i] = -1;
    }
    return mem;
}

int minTime(int n, int** edges, int edgesSize, int* edgesColSize, int* hasApple, int hasAppleSize)
{
    //使用数组做
    int** buffer = calloc(n, sizeof(int*));
    int* visit = calloc(n,sizeof(int));
    visit[0] = 1;
    for (int i = 0; i < edgesSize; i++)
    {
        //int edge[2]
        int* edge = edges[i];
        //无连通，调换位置
        if (!visit[edge[0]])
        {
            edge[0] ^= edge[1];
            edge[1] ^= edge[0];
            edge[0] ^= edge[1];
        }
        if (!buffer[edge[0]]) buffer[edge[0]] = my_malloc();
        for (int j = 0; j < SIDE; j++)
        {
            if (buffer[edge[0]][j] != -1) continue;
            buffer[edge[0]][j] = edge[1];
            if (!buffer[edge[1]]) buffer[edge[1]] = my_malloc();
            visit[edge[1]] = 1;
            break;
        }
    }
    int res = 0;
    dfs(0, -1, hasApple, &res, buffer);
    for (int i = 0;i < n;i++) if (buffer[i]) free(buffer[i]);
    free(buffer);
    free(visit);
    return res;
    //    for (int i = 0; i < n; i++)
    //    {
    //        int* tmp = buffer[i];
    //        if (tmp)
    //        {
    //            printf("head -> %d : ",i);
    //            for (int j = 0; j < 10; j++)
    //            {
    //                printf("%d ",tmp[j]);
    //            }
    //            printf("\n");
    //        }
    //    }
    //    return 0;
}
