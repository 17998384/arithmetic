//
//  tree_node.h
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/11/22.
//  Copyright © 2020 alex. All rights reserved.
//

#ifndef tree_node_h
#define tree_node_h

#ifdef __cplusplus

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
    {}
};

#else

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

#endif

#endif /* tree_node_h */
