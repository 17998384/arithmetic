//
//  build_tree.cpp
//  arithmetic
//
//  106. 从中序与后序遍历序列构造二叉树
//
//  根据一棵树的中序遍历与后序遍历构造二叉树。
//
//  注意:
//  你可以假设树中没有重复的元素。
//
//  例如，给出
//
//  中序遍历 inorder = [9,3,15,20,7]
//  后序遍历 postorder = [9,15,7,20,3]
//
//  返回如下的二叉树：
//
//      3
//     / \
//    9  20
//      /  \
//     15   7
//
//
//  Created by 我叫城北徐公° on 2021/3/24.
//  Copyright © 2021 alex. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    
    unordered_map<int,int> uMap;
    
    void dfs(TreeNode** root,int inorderStart,int inorderEnd
             ,vector<int>& postorder,int* postIdx)
    {
        if (inorderStart > inorderEnd) return;
        *root = new TreeNode(postorder.at((*postIdx)--));
        auto findPair = uMap.find((*root)->val);
        dfs(&(*root)->right,findPair->second + 1,inorderEnd,postorder,postIdx);
        dfs(&(*root)->left,inorderStart,findPair->second - 1,postorder,postIdx);
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        //将中序遍历的放入缓存
        int i = 0;
        for (auto e : inorder) uMap.insert(pair<int,int>(e,i++));
        TreeNode* root = NULL;
        i = inorder.size() - 1;
        dfs(&root,0,i,postorder,&i);
        return root;
    }
};
