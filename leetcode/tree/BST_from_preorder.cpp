//
//  BST_from_preorder.cpp
//  arithmetic
//
//  1008. 前序遍历构造二叉搜索树
//
//  返回与给定前序遍历 preorder 相匹配的二叉搜索树（binary search tree）的根结点。
//
//  (回想一下，二叉搜索树是二叉树的一种，其每个节点都满足以下规则，对于 node.left 的任何后代，值总 < node.val，而 node.right 的任何后代，值总 >
// node.val。此外，前序遍历首先显示节点 node 的值，然后遍历 node.left，接着遍历 node.right。）
//
//  题目保证，对于给定的测试用例，总能找到满足要求的二叉搜索树。
//
//
//
//  示例：
//
//  输入：[8,5,1,7,10,12]
//  输出：[8,5,10,1,7,null,12]
//
//  Created by 我叫城北徐公° on 2021/3/16.
//  Copyright © 2021 alex. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include "tree_node.h"

using namespace std;

//两种做法

// class Solution {
// public:
    
//     //先转中序，再继续组合    时间复杂度O(nlogn + logn)
//     unordered_map<int,int> midMap;
    
//     void dfs(TreeNode** root,vector<int> pre,int* preIdx,int midStart,int midEnd)
//     {
//         if (midStart > midEnd) return;
//         int e = pre[(*preIdx)++];
//         (*root) = new TreeNode(e);
//         auto pair = midMap.find(e);
//         dfs(&(*root)->left,pre,preIdx,midStart,pair->second - 1);
//         dfs(&(*root)->right,pre,preIdx,pair->second + 1,midEnd);
//     }
    
//     TreeNode* bstFromPreorder(vector<int>& preorder)
//     {
//         const int preorderSize = preorder.size();
//         if (!preorderSize) return NULL;
//         int* midorder = new int[preorderSize];
//         memcpy(midorder,preorder.data(),sizeof(int) * preorderSize);
//         sort(midorder,midorder + preorderSize);
//         for (int i = 0;i < preorderSize;i++)
//         {
//             midMap.insert(pair<int,int> (midorder[i],i));
//         }
//         TreeNode* root;
//         int preIdx = 0;
//         dfs(&root,preorder,&preIdx,0,preorderSize - 1);
//         delete[] midorder;
//         return root;
//     }
// };

class Solution
{
public:
    //利用 （低 高） 范围差做 （一遍DFS搞定），时间复杂度O(logn);
    void dfs(vector<int> v,int* cur,int low,int high,TreeNode** root)
    {
        *root = new TreeNode(v[(*cur)++]);
        if (*cur >= v.size()) return;
        if (v[*cur] < (*root)->val)
        {
            dfs(v,cur,low,(*root)->val,&(*root)->left);
        }
        if (*cur >= v.size()) return;
        if (v[*cur] > (*root)->val && v[*cur] <= high)
        {
            dfs(v,cur,(*root)->val,high,&(*root)->right);
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        if (!preorder.size()) return NULL;
        TreeNode* root;
        int cur = 0;
        dfs(preorder,&cur,INT_MIN,INT_MAX,&root);
        return root;
    }
};
