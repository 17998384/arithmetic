//
//  tree_node.hpp
//  arithmetic
//
//  Created by 我叫城北徐公° on 2021/3/14.
//  Copyright © 2021 alex. All rights reserved.
//

#ifndef tree_node_h
#define tree_node_h

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif /* tree_node_h */
