//
//  recover_tree.cpp
//  arithmetic
//
//  99. 恢复二叉搜索树
//
//  给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。
//
//  进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？
//
 //
//
//  示例 1：
//
//  输入：root = [1,3,null,null,2]
//  输出：[3,1,null,null,2]
//  解释：3 不能是 1 左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
//
//
//  Created by 我叫城北徐公° on 2021/4/9.
//  Copyright © 2021 alex. All rights reserved.
//

#include <iostream>
#include "tree_node.hpp"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// class Solution
// {
// public:
    
//     vector<int> v;
    
//     int idx;
    
//     void dfs(TreeNode* root)
//     {
//         if (!root) return;
//         dfs(root->left);
//         v.push_back(root->val);
//         dfs(root->right);
//     }
    
//     void dfs2(TreeNode* root)
//     {
//         if (!root) return;
//         dfs2(root->left);
//         root->val = v[idx++];
//         dfs2(root->right);
//     }
    
//     void recoverTree(TreeNode* root)
//     {
//         idx = 0;
//         dfs(root);
//         sort(v.begin(), v.end());
//         dfs2(root);
//     }
// };


class Solution
{
public:
    
    int* prev;
    int *a,*b;
    
    void dfs(TreeNode* root)
    {
        if (!root) return;
        dfs(root->left);
        if (!prev)
        {
            prev = new int;
            *prev = root->val;
        }
        else
        {
            if (root->val < *prev)
            {
                if (!a)
                {
                    a = new int;
                    b = new int;
                    *a = *prev;
                    *b = root->val;
                }
                else *b = root->val;
            }
            *prev = root->val;
        }
        dfs(root->right);
    }
    
    void dfs2(TreeNode* root)
    {
        if (!root) return;
        dfs2(root->left);
        if (root->val == *a) root->val = *b;
        else if (root->val == *b) root->val = *a;
        dfs2(root->right);
    }
    
    void recoverTree(TreeNode* root)
    {
        prev = a = b = NULL;
        dfs(root);
        dfs2(root);
        delete a;
        delete b;
        delete prev;
    }
};
