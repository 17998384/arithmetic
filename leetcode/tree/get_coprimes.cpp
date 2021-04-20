//
//  get_coprimes.cpp
//  arithmetic
//
//  1766. 互质树（困难）
//
//  给你一个 n 个节点的树（也就是一个无环连通无向图），节点编号从 0 到 n - 1 ，且恰好有 n - 1 条边，每个节点有一个值。树的 根节点 为 0 号点。
//
//  给你一个整数数组 nums 和一个二维数组 edges 来表示这棵树。nums[i] 表示第 i 个点的值，edges[j] = [uj, vj] 表示节点 uj 和节点 vj 在树中有一条边。
//
//  当 gcd(x, y) == 1 ，我们称两个数 x 和 y 是 互质的 ，其中 gcd(x, y) 是 x 和 y 的 最大公约数 。
//
//  从节点 i 到 根 最短路径上的点都是节点 i 的祖先节点。一个节点 不是 它自己的祖先节点。
//
//  请你返回一个大小为 n 的数组 ans ，其中 ans[i]是离节点 i 最近的祖先节点且满足 nums[i] 和 nums[ans[i]] 是 互质的 // ，如果不存在这样的祖先节点，ans[i] 为 -1 。
//
//
//
//  示例 1：
//
//  输入：nums = [2,3,3,2], edges = [[0,1],[1,2],[1,3]]
//  输出：[-1,0,0,1]
//  解释：上图中，每个节点的值在括号中表示。
//  - 节点 0 没有互质祖先。
//  - 节点 1 只有一个祖先节点 0 。它们的值是互质的（gcd(2,3) == 1）。
//  - 节点 2 有两个祖先节点，分别是节点 1 和节点 0 。节点 1 的值与它的值不是互质的（gcd(3,3) == 3）但节点 0 的值是互质的(gcd(2,3) ==
//    1)，所以节点 0 是最近的符合要求的祖先节点。
//  - 节点 3 有两个祖先节点，分别是节点 1 和节点 0 。它与节点 1 互质（gcd(3,2) == 1），所以节点 1 是离它最近的符合要求的祖先节点。
//
//  示例 2：
//
//  输入：nums = [5,6,10,2,3,6,15], edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
//  输出：[-1,0,-1,0,0,0,-1]
//
//
//
//  提示：
//
//      nums.length == n
//      1 <= nums[i] <= 50
//      1 <= n <= 105
//      edges.length == n - 1
//      edges[j].length == 2
//      0 <= uj, vj < n
//      uj != vj
//
//  Created by 我叫城北徐公° on 2021/3/28.
//  Copyright © 2021 alex. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include "utils.h"

using namespace std;

class Solution
{
public:
    
    vector<int> res;
    vector<vector<int>> Graph;
    int visit[51];
    int numsOrder[51];
    set<int> cache;
    
    void dfs(int val,vector<int>& nums,int parent,int order)
    {
        bool flag = true;
        int maxOrder = -1;
        int curN = nums.at(val);
        //比较，不断使用排序最大并且符合条件的覆盖res中的祖先节点
        for (auto n : cache)
        {
            if (numsOrder[n] > maxOrder && gcd(n,curN) == 1)
            {
                maxOrder = numsOrder[n];
                res[val] = visit[n];
                flag = false;
            }
        }
        if (flag) res[val] = -1;
        //记录最后一次的父节点
        int lastVisit,lastNumsOrder,n = curN;
        lastVisit = visit[n],lastNumsOrder = numsOrder[n],visit[n] = val;
        cache.insert(n);
        //记录节点遍历的顺序
        numsOrder[n] = order;
        for (auto n : Graph[val]) if (n != parent) dfs(n,nums,val,order + 1);
        //收尾工作
        visit[n] = lastVisit,numsOrder[n] = lastNumsOrder;
        if (lastVisit == -1) cache.erase(cache.find(n));
    }
    
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges)
    {
        Graph.resize(nums.size());
        res.resize(nums.size());
        for (auto edge : edges)
        {
            int first = edge.at(0);
            int second = edge.at(1);
            Graph[first].push_back(second);
            Graph[second].push_back(first);
        }
        for (int i = 1;i < 51;i++) visit[i] = -1;
        memset(numsOrder,0,51 * sizeof(int));
        dfs(0,nums,-1,0);
        return res;
    }
};
