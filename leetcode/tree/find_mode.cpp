//
// Created by 我叫城北徐公° on 2021/4/16.
//

//  501. 二叉搜索树中的众数
//
//  给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
//
//  假定 BST 有如下定义：
//
//  结点左子树中所含结点的值小于等于当前结点的值
//          结点右子树中所含结点的值大于等于当前结点的值
//  左子树和右子树都是二叉搜索树
//
//          例如：
//  给定 BST [1,null,2,2],
//
//      1
//       \
//        2
//       /
//      2
//
//  返回[2].
//
//  提示：如果众数超过1个，不需考虑输出顺序
//
//          进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
//
//

#include <iostream>
#include <vector>
#include "tree_node.h"

using namespace std;

class Solution
{
public:

    vector<int> res;

    int maxCount;
    int count;
    int* prev;

    void dfs(TreeNode* root)
    {
        if (!root) return;
        dfs(root->left);
        if (prev == NULL)
        {
            prev = new int;
            *prev = root->val;
            maxCount = count = 1;
            res.push_back(root->val);
        }
        else
        {
            if (*prev != root->val)
            {
                count = 1;
                if (count == maxCount) res.push_back(root->val);
            }
            else
            {
                count++;
                if (count > maxCount)
                {
                    res.clear();
                    res.push_back(root->val);
                    maxCount = count;
                }
                else if (count == maxCount) res.push_back(root->val);
            }
            *prev = root->val;
        }
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root)
    {
        maxCount = maxCount = 0;
        prev = NULL;
        dfs(root);
        return res;
    }
};