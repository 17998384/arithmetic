//
//  BST_sequences.cpp
//  arithmetic
//
//  面试题 04.09. 二叉搜索树序列
//
//  从左向右遍历一个数组，通过不断将其中的元素插入树中可以逐步地生成一棵二叉搜索树。给定一个由不同节点组成的二叉搜索树，输出所有可能生成此树的数组。
//
//
//
//  示例：
//  给定如下二叉树
//
//          2
//         / \
//        1   3
//
//  返回：
//
//  [
//     [2,1,3],
//     [2,3,1]
//  ]
//
//
//
//  Created by 我叫城北徐公° on 2021/3/20.
//  Copyright © 2021 alex. All rights reserved.
//

#include <iostream>
#include <vector>
#include "tree_node.hpp"

using namespace std;

class Solution {
public:

    void merge(vector<vector<int>>& res,vector<int>& buffer,vector<int>& left,int lIdx,vector<int>& right,int rIdx)
    {
        if (lIdx == left.size() && rIdx == right.size())
        {
            res.push_back(buffer);
            return;
        }
        if (lIdx < left.size())
        {
            buffer.push_back(left[lIdx]);
            merge(res,buffer,left,lIdx + 1,right,rIdx);
            buffer.pop_back();
        }
        if (rIdx < right.size())
        {
            buffer.push_back(right[rIdx]);
            merge(res,buffer,left,lIdx,right,rIdx + 1);
            buffer.pop_back();
        }
    }

    vector<vector<int>> dfs(TreeNode* root)
    {
        if (!root) return {{}};
        vector<vector<int>> left = dfs(root->left);
        vector<vector<int>> right = dfs(root->right);
        vector<vector<int>> res;
        vector<int> buffer;

        buffer.push_back(root->val);

        for (auto& lv : left)
        {
            for (auto& rv : right)
            {
                merge(res,buffer,lv,0,rv,0);
            }
        }
        return res;
    }

    vector<vector<int>> BSTSequences(TreeNode* root)
    {
        return dfs(root);
    }
};
