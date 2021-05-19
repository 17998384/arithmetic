//
// Created by 我叫城北徐公° on 2021/5/10.
//

//  109. 有序链表转换二叉搜索树

//  给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
//
//  本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
//
//  示例:
//
//  给定的有序链表： [-10, -3, 0, 5, 9],
//
//  一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
//
//  0
//  / \
//     -3   9
//  /   /
//  -10  5



#include <iostream>
#include <vector>
#include "list_node.h"
#include "tree_node.h"

using namespace std;

class Solution
{
public:

    void build_tree(TreeNode** root, vector<int>& v, int start, int end)
    {
        if (start > end) return;
        int half = (start + end) / 2;
        *root = new TreeNode(v[half]);
        build_tree(&(*root)->left, v, start, half - 1);
        build_tree(&(*root)->right, v, half + 1, end);
    }

    TreeNode* sortedListToBST(ListNode* head)
    {
        vector<int> v;
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }
        TreeNode* root = NULL;
        build_tree(&root, v, 0, v.size() - 1);
        return root;
    }
};