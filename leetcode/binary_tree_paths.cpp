//
//  binary_tree_paths.cpp
//  arithmetic
//
//  257. 二叉树的所有路径
//
//  给定一个二叉树，返回所有从根节点到叶子节点的路径。
//
//  说明: 叶子节点是指没有子节点的节点。
//
//  示例:
//
//  输入:
//
//     1
//   /   \
//  2     3
//   \
//    5
//
//  输出: ["1->2->5", "1->3"]
//
//  解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
//
//
//  Created by 我叫城北徐公° on 2021/3/14.
//  Copyright © 2021 alex. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "tree_node.hpp"

using namespace std;

class Solution {
public:
    
    vector<string> res;
    vector<int> v;
    
    void dfs(TreeNode* root)
    {
        if (!root) return;
        v.push_back(root->val);
        if (!root->left && !root->right)
        {
            string s;
            for (int i = 0,size = v.size();i < size;i++)
            {
                s.append(to_string(v[i]));
                if (i != size - 1) s.append("->");
            }
            res.push_back(s);
            v.pop_back();
            return;
        }
        dfs(root->left);
        dfs(root->right);
        v.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root)
    {
        dfs(root);
        return res;
    }
};
