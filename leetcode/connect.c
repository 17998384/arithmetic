//
//  connect.c
//  arithmetic
//
//  116. 填充每个节点的下一个右侧节点指针
//
//  给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
//
//  struct Node {
//    int val;
//    Node *left;
//    Node *right;
//    Node *next;
//  }
//
//  填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
//
//  初始状态下，所有 next 指针都被设置为 NULL。
//
//
//
//  进阶：
//
//      你只能使用常量级额外空间。
//      使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
//

//  Created by 我叫城北徐公° on 2021/2/24.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>

struct Node {
  int val;
  struct Node *left;
  struct Node *right;
  struct Node *next;
};

typedef struct Node Node;

//bfs版本

static void bfs(Node* root)
{
    if (!root) return;
    Node* stack[5000];
    //指针，标记
    int rsp = 0,rbp = 0;
    stack[rsp++] = root;
    //bfs
    while (rbp < rsp)
    {
        int rspBak = rsp;
        Node* lastRight = NULL;
        while (rbp < rspBak)
        {
            Node* node = stack[rbp++];
            if (!node->left) continue;
            if (lastRight) lastRight->next = node->left;
            node->left->next = node->right;
            stack[rsp++] = node->left;
            stack[rsp++] = node->right;
            lastRight = node->right;
        }
    }
    
}

#define LEFT 1
#define RIGHT -1

static void dfs(Node* parent,Node* root,int isLeft)
{
    if (!root) return;
    if (isLeft == LEFT && parent) root->next = parent->right;
    if (isLeft == RIGHT && parent && parent->next) root->next = parent->next->left;
    dfs(root,root->left,LEFT);
    dfs(root,root->right,RIGHT);
}

Node* leetcode_connect(Node* root)
{
    // bfs(root);
    // dfs(NULL,root,LEFT);
    return root;
}
