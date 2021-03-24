//
//  largest_values.cpp
//  arithmetic
//
//  515. 在每个树行中找最大值
//
//  您需要在二叉树的每一行中找到最大的值。
//
//  示例：
//
//  输入:
//
//            1
//           / \
//          3   2
//         / \   \
//        5   3   9
//
//  输出: [1, 3, 9]
//
//
//  Created by 我叫城北徐公° on 2021/3/24.
//  Copyright © 2021 alex. All rights reserved.
//

#include <iostream>
#include <queue>
#include "tree_node.hpp"

using namespace std;

class Solution {
public:
    
    typedef struct TreeNode Tree;
    
    static vector<int> bfs(Tree* root)
    {
        vector<int> res;
        if (!root) return res;
        queue<Tree*> q;
        q.push(root);
        while (!q.empty())
        {
            int start,size,max;
            start = 0;
            size = q.size();
            max = 0x80000000;
            while (start < size)
            {
                Tree* tree = q.front();
                q.pop();
                if (tree->val > max) max = tree->val;
                if (tree->left) q.push(tree->left);
                if (tree->right) q.push(tree->right);
                start++;
            }
            res.push_back(max);
        }
        return res;
    }

    vector<int> largestValues(TreeNode* root)
    {
        return bfs(root);
    }
};
