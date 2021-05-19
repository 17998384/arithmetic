//
// Created by 我叫城北徐公° on 2021/4/16.
//

//  508. 出现次数最多的子树元素和
//
//  给你一个二叉树的根结点，请你找出出现次数最多的子树元素和。一个结点的「子树元素和」定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
//
//  你需要返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。
//
//
//
//  示例 1：
//  输入:
//
//     5
//   /   \
//  2    -3
//
//  返回 [2, -3, 4]，所有的值均只出现一次，以任意顺序返回所有值。
//
//  示例 2：
//  输入：
//
//  5
//  /  \
//  2   -5
//
//  返回 [2]，只有 2 出现两次，-5 只出现 1 次。
//
//
//
//  提示： 假设任意子树元素和均可以用 32 位有符号整数表示。
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include "tree_node.h"

using namespace std;

class Solution
{
public:

    unordered_map<int, int> uMap;
    vector<int> res;
    int maxCount;

    int dfs(TreeNode* root)
    {
        if (!root) return 0;
        int L = dfs(root->left);
        int R = dfs(root->right);
        int sum = root->val + L + R;
        auto finder = uMap.find(sum);
        int tmp;
        if (finder == uMap.end()) tmp = uMap[sum] = 1;
        else tmp = ++finder->second;
        //检查是否大于
        if (tmp > maxCount)
        {
            res.clear();
            maxCount = tmp;
            res.push_back(sum);
        }
        else if (tmp == maxCount) res.push_back(sum);
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root)
    {
        maxCount = 0;
        dfs(root);
        return res;
    }
};