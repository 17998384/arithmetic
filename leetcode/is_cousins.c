//
//  is_cousins.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2021/2/5.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

typedef struct TreeNode Node;

static int xDepth;

static int yDepth;

static Node* xParent;

static Node* yParent;

static void dfs(Node* root,Node* parent,int x,int y,int i)
{
    if (!root) return;
    if (root->val == x)
    {
        xDepth = i;
        xParent = parent;
        return;
    }
    if (root->val == y)
    {
        yDepth = i;
        yParent = parent;
        return;
    }
    dfs(root->left,root,x,y,i + 1);
    dfs(root->right,root,x,y,i + 1);
}

int isCousins(struct TreeNode* root, int x, int y)
{
    xDepth = yDepth = -1;
    xParent = yParent = NULL;
    dfs(root,NULL,x,y,0);
    return (xDepth != -1 && yDepth != -1) && (xDepth == yDepth) && (xParent != yParent);
}
