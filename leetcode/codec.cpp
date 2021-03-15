//
//  codec.cpp
//  arithmetic
//
//  449. 序列化和反序列化二叉搜索树
//
//  序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。
//
//  设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。
//    您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。
//
//  编码的字符串应尽可能紧凑。
//
//
//
//  示例 1：
//
//  输入：root = [2,1,3]
//  输出：[2,1,3]
//
//  示例 2：
//
//  输入：root = []
//  输出：[]
//
//
//  Created by 我叫城北徐公° on 2021/3/16.
//  Copyright © 2021 alex. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include "tree_node.hpp"

using namespace std;

class Codec
{
public:
    
    void bfs(TreeNode* root,string& s)
    {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        s += (to_string(root->val) + " ");
        while (!q.empty())
        {
            TreeNode* tmp = q.front();
            q.pop();
            if (!tmp->left) s += "# ";
            else
            {
                s += (to_string(tmp->left->val) + " ");
                q.push(tmp->left);
            }
            if (!tmp->right) s += "# ";
            else
            {
                s += (to_string(tmp->right->val) + " ");
                q.push(tmp->right);
            }
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        string s;
        bfs(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        if (!data.size()) return NULL;
        int strIdx = 0,size = data.size();
        int tmpCount = 0;
        TreeNode* root;
        queue<TreeNode*> q;
        //先构建root...
        while (data[strIdx] != ' ') tmpCount = (10 * tmpCount + (data[strIdx++] - 48));
        strIdx++;
        root = new TreeNode(tmpCount);
        q.push(root);
        tmpCount = 0;
        while (strIdx < size && !q.empty())
        {
            TreeNode* tmp = q.front();
            q.pop();
            if (data[strIdx] != '#')
            {
                while (data[strIdx] != ' ') tmpCount = (10 * tmpCount + (data[strIdx++] - 48));
                tmp->left = new TreeNode(tmpCount);
                q.push(tmp->left);
                tmpCount = 0;
                strIdx++;
            }
            else strIdx += 2;
            if (data[strIdx] != '#')
            {
                while (data[strIdx] != ' ') tmpCount = (10 * tmpCount + (data[strIdx++] - 48));
                tmp->right = new TreeNode(tmpCount);
                q.push(tmp->right);
                tmpCount = 0;
                strIdx++;
            }
            else strIdx += 2;
        }
        return root;
    }
};
