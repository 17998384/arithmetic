//
//  tree_serialize.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2021/1/2.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_node.h"

#define DEBUG 0
#define LIST_SIZE 20000
#define SERIALIZE_STR_SIZE 80000

struct TreeNode* new_tree_node(int val)
{
    struct TreeNode* node = calloc(1, sizeof(struct TreeNode));
    node->val = val;
    return node;
}

/*
    整数转字符串
 */
static char* itoa(int num,char* str,int radix,int* str_idx)
{
    char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";//索引表
    unsigned unum;//存放要转换的整数的绝对值,转换的整数可能是负数
    int i=0,j,k;//i用来指示设置字符串相应位，转换之后i其实就是字符串的长度；转换后顺序是逆序的，有正负的情况，k用来指示调整顺序的开始位置;j用来指示调整顺序时的交换。
 
    //获取要转换的整数的绝对值
    if(radix==10&&num<0)//要转换成十进制数并且是负数
    {
        unum=(unsigned)-num;//将num的绝对值赋给unum
        str[i++]='-';//在字符串最前面设置为'-'号，并且索引加1
    }
    else unum=(unsigned)num;//若是num为正，直接赋值给unum
 
    //转换部分，注意转换后是逆序的
    do
    {
        str[i++]=index[unum%(unsigned)radix];//取unum的最后一位，并设置为str对应位，指示索引加1
        unum/=radix;//unum去掉最后一位
 
    }while(unum);//直至unum为0退出循环
 
    str[i]='\0';//在字符串最后添加'\0'字符，c语言字符串以'\0'结束。
 
    //将顺序调整过来
    if(str[0]=='-') k=1;//如果是负数，符号不用调整，从符号后面开始调整
    else k=0;//不是负数，全部都要调整
 
    char temp;//临时变量，交换两个值时用到
    for(j=k;j<=(i-1)/2;j++)//头尾一一对称交换，i其实就是字符串的长度，索引最大值比长度少1
    {
        temp=str[j];//头部赋值给临时变量
        str[j]=str[i-1+k-j];//尾部赋值给头部
        str[i-1+k-j]=temp;//将临时变量的值(其实就是之前的头部值)赋给尾部
    }
    (*str_idx) += i;
    return str;//返回转换后的字符串
}

/// bfs
/// @param root 跟节点
/// @param serialize_str 序列化字符串
/// @param serialize_str_idx 序列化字符串索引
/// @param depth 树的最大深度
static void bfs(struct TreeNode* root,char* serialize_str,int* serialize_str_idx,int depth)
{
    struct TreeNode* list[LIST_SIZE] = {0};
    //p1,前指针，p2后指针
    int p1 = 0,p2 = 0,cur_depth = 1;
    list[p2++] = root;
    while(p1 < p2)
    {
        //备份的p2指针
        int p3 = p2;
        while(p1 < p3)
        {
            //可能为NULL
            struct TreeNode* tmp = list[p1++];
            if (tmp)
            {
                itoa(tmp->val, serialize_str + *serialize_str_idx, 10, serialize_str_idx);
                serialize_str[(*serialize_str_idx)++] = ',';
                //小于最大深度
                if (cur_depth < depth)
                {
                    list[p2++] = tmp->left;
                    list[p2++] = tmp->right;
                }
            }
            //否则拼接一个null
            else
            {
                strcat(serialize_str, "null");
                (*serialize_str_idx) += 4;
                serialize_str[(*serialize_str_idx)++] = ',';
            }
        }
        cur_depth++;
    }
    //去掉最后一个','
    serialize_str[--(*serialize_str_idx)] = '\0';
}

static void dfs(struct TreeNode* root,int* max_depth,int tmp)
{
    if (!root) return;
    if (tmp > *max_depth) *max_depth = tmp;
    dfs(root->left, max_depth, tmp + 1);
    dfs(root->right, max_depth, tmp + 1);
}

/** Encodes a tree to a single string. */
/// 序列化（序列化成前序遍历和中序遍历，求出该树）
/// @param root 根节点
char* serialize(struct TreeNode* root)
{
    if (!root) return "";
    //求出树的最大深度
    int depth = 0;
    dfs(root,&depth,1);
    char* serialize_str = calloc(SERIALIZE_STR_SIZE, sizeof(char));
    int serialize_str_idx = 0;
    bfs(root, serialize_str, &serialize_str_idx, depth);
    if (DEBUG) printf("%s\n",serialize_str);
    return serialize_str;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data)
{
    if (!strlen(data)) return NULL;
    //根节点
    char* tmp = strtok(data, ",");
    struct TreeNode** list[LIST_SIZE] = {0};
    struct TreeNode* root = new_tree_node(atoi(tmp));
    int p1 = 0,p2 = 0;
    list[p2++] = &root;
    while (p1 < p2)
    {
        //备份p2的指针
        int p3 = p2;
        while (p1 < p3)
        {
            struct TreeNode** tmp = list[p1++];
            char* L = strtok(NULL, ",");
            char* R = strtok(NULL, ",");
            if (!L || !R) return root;
            (*tmp)->left = (*L == 'n') ? NULL : new_tree_node(atoi(L));
            (*tmp)->right = (*R == 'n') ? NULL : new_tree_node(atoi(R));
            if ((*tmp)->left) list[p2++] = &(*tmp)->left;
            if ((*tmp)->right) list[p2++] = &(*tmp)->right;
        }
    }
    return root;
}

int main_tree_serialize(void)
{
    //[1,2,2,3,null,null,3,4,null,null,4]
    struct TreeNode* tree = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->val = 1;
    tree->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->left->val = 2;
    tree->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->right->val = 3;
    tree->right->left = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->right->left->val = 4;
    tree->right->right = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    tree->right->right->val = 5;
    char* s = serialize(tree);
    printf("%s\n",s);
    struct TreeNode* root = deserialize(s);
    printf("%p\n",root);
    return 0;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
