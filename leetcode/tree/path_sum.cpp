//
//  path_sum.cpp
//  arithmetic
//
//  113. 路径总和 II
//
//  给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
//
//  叶子节点 是指没有子节点的节点。
//
//
//
//  示例 1：
//
//  输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//  输出：[[5,4,11,2],[5,8,4,5]]
//
//  示例 2：
//
//  输入：root = [1,2,3], targetSum = 5
//  输出：[]
//
//  示例 3：
//
//  输入：root = [1,2], targetSum = 0
//  输出：[]
//
//  Created by 我叫城北徐公° on 2021/3/17.
//  Copyright © 2021 alex. All rights reserved.
//

#include <iostream>
#include <vector>
#include "tree_node.hpp"

using namespace std;

class Solution
{
public:
    
    vector<vector<int>> res;
    
    vector<int> tmp;
    
    void dfs(TreeNode* root,int sum,int targetSum)
    {
        if (!root) return;
        sum += root->val;
        tmp.push_back(root->val);
        if (!root->left && !root->right)
        {
            if (sum == targetSum) res.push_back(tmp);
            tmp.pop_back();
            return;
        }
        dfs(root->left,sum,targetSum);
        dfs(root->right,sum,targetSum);
        tmp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        dfs(root,0,targetSum);
        return res;
    }
};
