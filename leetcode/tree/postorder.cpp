//
//  postorder.cpp
//  arithmetic
//
//  590. N 叉树的后序遍历
//
//  给定一个 N 叉树，返回其节点值的 后序遍历 。
//
//  N 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。
//
//
//
//  进阶：
//
//  递归法很简单，你可以使用迭代法完成此题吗?
//
//
//
//  示例 1：
//
//  输入：root = [1,null,3,2,4,null,5,6]
//  输出：[5,6,3,2,4,1]
//
//
//  Created by 我叫城北徐公° on 2021/3/13.
//  Copyright © 2021 alex. All rights reserved.
//

#include "node.hpp"

class Solution {
public:
    
    vector<int> bfs(Node* root)
    {
        vector<int> res;
        if (!root) return res;
        int rbp = 0;
        Node* stack[3000];
        stack[rbp++] = root;
        while (rbp > 0)
        {
            Node* n = stack[rbp - 1];
            vector<Node*>& v = n->children;
            if (v.size() > 0)
            {
                stack[rbp++] = v[0];
                v.erase(v.begin());
                continue;
            }
            res.push_back(n->val);
            rbp--;
        }
        return res;
    }
    
    vector<int> postorder(Node* root)
    {
        return bfs(root);
    }
};
