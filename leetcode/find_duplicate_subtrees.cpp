//
//  find_duplicate_subtrees.cpp
//  arithmetic
//
//  652. 寻找重复的子树
//
//  给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
//
//  两棵树重复是指它们具有相同的结构以及相同的结点值。
//
//  示例 1：
//
//          1
//         / \
//        2   3
//       /   / \
//      4   2   4
//         /
//        4
//
//  下面是两个重复的子树：
//
//        2
//       /
//      4
//
//  和
//
//      4
//
//  因此，你需要以列表的形式返回上述重复子树的根结点。
//
//
//  Created by 我叫城北徐公° on 2021/3/25.
//  Copyright © 2021 alex. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include "tree_node.hpp"

using namespace std;

class Solution
{
public:
    
    unordered_map<string,int> uMap;
    
    vector<TreeNode*> res;
    
    string dfs(TreeNode* root)
    {
        if (!root) return "$";
        string s = to_string(root->val) + " " +dfs(root->left) + " " + dfs(root->right);
        if (uMap[s] == 1) res.push_back(root);
        uMap[s]++;
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        dfs(root);
        return res;
    }
};
