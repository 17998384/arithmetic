//
//  is_complete_tree.c
//  arithmetic
//
//  958. 二叉树的完全性检验
//
//  给定一个二叉树，确定它是否是一个完全二叉树。
//
//  百度百科中对完全二叉树的定义如下：
//
//  若设二叉树的深度为 h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，第 h 层所有的结点都连续集中在最左边，这就是完全二叉树。（注：第 h // 层可能包含 1~ 2h 个节点。）
//
//
//  Created by 我叫城北徐公° on 2021/2/21.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Node;

static int bfs(Node* root)
{
    if (!root) return 1;
    //定义栈
    Node* stack[300];
    int depthNodeCount[101] = {0};
    depthNodeCount[1] = 1;
    //指针，标记，深度
    int rsp = 0,rbp = 0,flag = 1,depth = 0;
    stack[rsp++] = root;
    
    //bfs
    /*
        统计该层节点的时候，若出现空节点，则标记，若该层后面还有节点，说明一定不是满二叉树
    */
    while (rbp < rsp)
    {
        depth++;
        int rspBak = rsp;
        while (rbp < rspBak)
        {
            //统计每层节点，并记录当前层节点个数
            Node* node = stack[rbp++];
            if (node->left && !flag) return 0;
            else if (node->left)
            {
                stack[rsp++] = node->left;
                depthNodeCount[depth + 1]++;
            }
            else flag = 0;
            if (node->right && !flag) return 0;
            else if (node->right)
            {
                stack[rsp++] = node->right;
                depthNodeCount[depth + 1]++;
            }
            else flag = 0;
        }
        flag = 1;
        //上一层树节点是否最大？不是则不满足
        if (depth > 2 && depthNodeCount[depth - 1] != (1 << (depth - 2))) return 0;
    }
    return flag;
}

int isCompleteTree(struct TreeNode* root)
{
    return bfs(root);
}

//优化版


//typedef struct TreeNode Node;
//
//int bfs(Node* root)
//{
//    if (!root) return 1;
//    //定义栈
//    Node* stack[300];
//    //栈指针
//    int rsp = 0,rbp = 0;
//    stack[rsp++] = root;
//
//    //bfs
//    /*
//        统计该层节点的时候，若出现空节点且该层后面还有节点，说明一定不是满二叉树
//    */
//    while (rbp < rsp)
//    {
//        Node* node = stack[rbp++];
//        if (node->left) stack[rsp++] = node->left;
//        else
//        {
//            if (node->right) return 0;
//            while (rbp < rsp && (node = stack[rbp++])) if (node->left || node->right) return 0;
//        }
//        if (node->right) stack[rsp++] = node->right;
//        else while (rbp < rsp && (node = stack[rbp++])) if (node->left || node->right) return 0;
//    }
//    return 1;
//}
//
//bool isCompleteTree(struct TreeNode* root)
//{
//    return bfs(root);
//}
