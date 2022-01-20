//
// Created by 我叫城北徐公° on 2022/1/13.
//

#include "prefix_tree.h"
#include <unistd.h>

static void destroy_node(Node* node, int childrenSize)
{
    for (int i = 0; i < childrenSize; ++i)
    {
        Node* destroyNode = node->children[i];
        if (destroyNode) destroy_node(destroyNode, childrenSize);
    }
    free(node->children);
    free(node);
}

static Node* new_node(int num)
{
    Node* node = malloc(sizeof(Node));
    node->children = calloc(num, sizeof(Node*));
    node->ref = 0;
    node->destroy_node = destroy_node;
    return node;
}

void insert_element(PrefixTree* prefixTree, const char* str)
{
    size_t len, idx;
    idx = 0, len = strlen(str);
    Node** curNode = &prefixTree->root;
    while (idx < len)
    {
        curNode = &((*curNode)->children[str[idx] - 97]);
        if (!*curNode) *curNode = new_node(prefixTree->childrenSize);
        ++(*curNode)->ref;
        idx++;
    }
}

int query_element(PrefixTree* prefixTree, const char* str)
{
    size_t len, idx;
    idx = 0, len = strlen(str);
    Node** curNode = &prefixTree->root;
    while (idx < len)
    {
        curNode = &((*curNode)->children[str[idx] - 97]);
        if (!*curNode) return 0;
        idx++;
    }
    return (*curNode)->ref;
}

void delete_element(PrefixTree* prefixTree, const char* str)
{
    size_t len, idx;
    idx = 0, len = strlen(str);
    Node** curNode = &prefixTree->root;
    while (idx < len && *curNode)
    {
        curNode = &((*curNode)->children[str[idx] - 97]);
        if (!*curNode) return;
        else if ((*curNode)->ref == 1)
        {
            destroy_node((*curNode), 26);
            *curNode = NULL;
        }
        else --(*curNode)->ref;
        idx++;
    }
}

void destroy_prefix_tree(PrefixTree* prefixTree)
{
    prefixTree->root->destroy_node(prefixTree->root, prefixTree->childrenSize);
    free(prefixTree);
}

PrefixTree* create_prefix_tree(int childrenSize)
{
    PrefixTree* prefixTree = malloc(sizeof(PrefixTree));
    prefixTree->childrenSize = childrenSize;
    prefixTree->insert_element = insert_element;
    prefixTree->query_element = query_element;
    prefixTree->delete_element = delete_element;
    prefixTree->destroy_prefix_tree = destroy_prefix_tree;
    prefixTree->root = new_node(childrenSize);
    return prefixTree;
}

//int main(void)
//{
//    PrefixTree* prefixTree = create_prefix_tree(26);
//    int res[4];
//    prefixTree->insert_element(prefixTree, "abcde");
////    prefixTree->insert_element(prefixTree, "abc");
////    prefixTree->insert_element(prefixTree, "ab");
////    prefixTree->insert_element(prefixTree, "a");
////    prefixTree->delete_element(prefixTree, "abcde");
//    res[0] = prefixTree->query_element(prefixTree, "abcde");
//    res[1] = prefixTree->query_element(prefixTree, "abc");
//    res[2] = prefixTree->query_element(prefixTree, "a");
//    res[3] = prefixTree->query_element(prefixTree, "x");
//    for (int i = 0; i < 4; i++)
//    {
//        printf("%d\n", res[i]);
//    }
//    prefixTree->destroy_prefix_tree(prefixTree);
//    return 0;
//}