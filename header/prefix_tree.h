//
// Created by 我叫城北徐公° on 2022/1/13.
//

#ifndef ARITHMETIC_PREFIX_TREE_H
#define ARITHMETIC_PREFIX_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;
typedef struct prefix_tree PrefixTree;

struct node
{
    Node** children;

    int ref;

    void (* destroy_node)(Node* node, int childrenSize);
};

struct prefix_tree
{

    Node* root;

    int childrenSize;

    /**
     * 添加元素
     */
    void (* insert_element)(PrefixTree*, const char*);

    /**
     * 查询元素
     * @return
     */
    int (* query_element)(PrefixTree*, const char*);

    /**
     * 删除元素
     */
    void (* delete_element)(PrefixTree*, const char*);

    /**
     * 销毁前缀树
     */
    void (* destroy_prefix_tree)(PrefixTree*);
};

static Node* new_node(int num);

#ifdef __cplusplus
extern "C" {

#endif

/**
* 创建前缀树
*/
PrefixTree* create_prefix_tree(int childrenSize);

#ifdef __cplusplus

}
#endif

#endif //ARITHMETIC_PREFIX_TREE_H
