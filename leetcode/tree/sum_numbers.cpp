//
//  sum_numbers.cpp
//  arithmetic
//
//  129. 求根节点到叶节点数字之和
//
//  给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
//
//  每条从根节点到叶节点的路径都代表一个数字：
//
//      例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
//
//  计算从根节点到叶节点生成的 所有数字之和 。
//
//  叶节点 是指没有子节点的节点。
//
//
//
//  示例 1：
//
//  输入：root = [1,2,3]
//  输出：25
//  解释：
//  从根到叶子节点路径 1->2 代表数字 12
//  从根到叶子节点路径 1->3 代表数字 13
//  因此，数字总和 = 12 + 13 = 25
//
//
//  Created by 我叫城北徐公° on 2021/3/14.
//  Copyright © 2021 alex. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    
    int sum;
    
    void dfs(TreeNode* root,int tmpSum)
    {
        if (!root) return;
        tmpSum += root->val;
        if (!root->left && !root->right)
        {
            sum += tmpSum;
            return;
        }
        dfs(root->left,tmpSum * 10);
        dfs(root->right,tmpSum * 10);
    }
    
    int sumNumbers(TreeNode* root)
    {
        sum = 0;
        dfs(root,0);
        return sum;
    }
};
