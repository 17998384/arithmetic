//
//  get_all_elements.cpp
//  arithmetic
//
//
//  1305. 两棵二叉搜索树中的所有元素
//
//  给你 root1 和 root2 这两棵二叉搜索树。
//
//  请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.
//
//
//
//  示例 1：
//
//  输入：root1 = [2,1,4], root2 = [1,0,3]
//  输出：[0,1,1,2,3,4]
//
//  示例 2：
//
//  输入：root1 = [0,-10,10], root2 = [5,1,7,0,2]
//  输出：[-10,0,0,1,2,5,7,10]
//
//  示例 3：
//
//  输入：root1 = [], root2 = [5,1,7,0,2]
//  输出：[0,1,2,5,7]
//
//  Created by 我叫城北徐公° on 2021/3/24.
//  Copyright © 2021 alex. All rights reserved.
//

#include <iostream>
#include <vector>
#include "tree_node.hpp"

using namespace std;

class Solution
{
public:

    vector<int> res;

    void dfs(TreeNode* root,vector<int>& v)
    {
        if (!root) return;
        dfs(root->left,v);
        v.push_back(root->val);
        dfs(root->right,v);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int> v1;
        vector<int> v2;
        dfs(root1,v1);
        dfs(root2,v2);
        bool v1Empty,v2Empty;
        // 1 2 4
        // 0 1 3
        int i = 0,j = 0;
        while (!(v1Empty = (i >= v1.size())) | !(v2Empty = (j >= v2.size())))
        {
            if (!v1Empty && !v2Empty)
            {
                int a = v1.at(i);
                int b = v2.at(j);
                if (a >= b) res.push_back(v2.at(j++));
                else res.push_back(v1.at(i++));
            }
            else if (!v1Empty) res.push_back(v1.at(i++));
            else res.push_back(v2.at(j++));
        }
        return res;
    }
};
