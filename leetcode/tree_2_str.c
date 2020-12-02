//
//  tree_2_str.c
//  arithmetic
//
//  606.根据二叉树创建字符串
//
//  你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
//
//  空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
//
//  示例 1:
//
//  输入: 二叉树: [1,2,3,4]
//         1
//       /   \
//      2     3
//     /
//    4
//
//  输出: "1(2(4))(3)"
//
//  解释: 原本将是“1(2(4)())(3())”，
//  在你省略所有不必要的空括号对之后，
//  它将是“1(2(4))(3)”。
//
//  TMD,这个shi一样的题目描述……
//
//  题目的意思是子节点需要用()来包裹。举例来说，二叉树
//    [root,left,right]，则转换为root(left)(right)。如果只有left为空节点，则输出root()(right)；如果只有right为空节点则可以忽略右节点的
//  ()，输出为root(left)。
//
//
//  Created by 我叫城北徐公° on 2020/11/30.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "my_lib.h"
#include "tree_node.h"

static void dfs(struct TreeNode* t,struct TreeNode* root,struct TreeNode* parent,char* str,int* str_idx)
{
    if (!t)
    {
        if (parent->right != NULL)
        {
            str[(*str_idx)++] = '(';
            str[(*str_idx)++] = ')';
        }
        return;
    }
    if (t != root)
    {
        str[(*str_idx)++] = '(';
        itoa(t->val, str + (*str_idx), 10);
    }
    dfs(t->left,root,t,str,str_idx);
    dfs(t->right,root,t,str,str_idx);
    if (t != root) str[(*str_idx)++] = ')';
}

char * tree2str(struct TreeNode* t)
{
    if (!t) return "";
    
    char* str = (char*)malloc(sizeof(char) * 100000);
    int str_idx = 0;
    itoa(t->val, str, 10);
    dfs(t,t,NULL,str,&str_idx);
    str[str_idx] = '\0';
    return str;
}
