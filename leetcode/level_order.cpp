//
//  level_order.cpp
//  arithmetic
//
//
//  102. 二叉树的层序遍历
//  给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
//
//
//
//  示例：
//  二叉树：[3,9,20,null,null,15,7],
//
//      3
//     / \
//    9  20
//      /  \
//     15   7
//
//  返回其层序遍历结果：
//
//  [
//    [3],
//    [9,20],
//    [15,7]
//  ]
//
//  Created by 我叫城北徐公° on 2021/3/13.
//  Copyright © 2021 alex. All rights reserved.
//

#include <iostream>
#include <vector>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    
    vector<vector<int>> bfs(TreeNode* root)
    {
        vector<vector<int>> res;
        if (!root) return res;
        TreeNode* stack[2000];
        int rbp,rsp;
        rbp = rsp = 0;
        stack[rsp++] = root;
        while (rbp < rsp)
        {
            int rspBak = rsp;
            vector<int> v;
            while (rbp < rspBak)
            {
                TreeNode* t = stack[rbp++];
                v.push_back(t->val);
                if (t->left) stack[rsp++] = t->left;
                if (t->right) stack[rsp++] = t->right;
            }
            res.push_back(v);
        }
        return res;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        return bfs(root);
    }
};
