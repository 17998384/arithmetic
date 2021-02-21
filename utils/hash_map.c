//
//  hash_map.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/10/14.
//  Copyright © 2020 alex. All rights reserved.
//

#include "hash_map.h"

/// 计算hash
/// @param hashMap map
/// @param key key
int _hash(HashMap* hashMap,void* key)
{
    int hash;
    hash = ((hash = hashMap->hash_code(key)) ^ (hash >> 16));
    return hash;
}

/*
    扩容
*/
void resize(HashMap* hashMap)
{
    int oldSize = hashMap->size;
    int newSize = oldSize * 2;
    Node** newCup = (Node**)malloc(sizeof(Node*) * newSize);
    memset(newCup, 0, sizeof(Node*) * newSize);
    //拷贝到老数组
    for (int j = 0, size = hashMap->size; j < size; j++)
    {
        Node* e = hashMap->data[j];
        hashMap->data[j] = NULL;
        if (e == NULL)
        {
            continue;
        }
        if (e->next == NULL)
        {
            newCup[e->hash & (newSize - 1)] = e;
        }
        Node* loTail = NULL;
        Node* hiTail = NULL;
        Node* loHead = NULL;
        Node* hiHead = NULL;
        Node* next;
        do
        {
            next = e->next;
            //放在高位
            if ((e->hash & oldSize) != 0)
            {
                if (hiTail == NULL)
                {
                    hiHead = e;
                }
                else
                {
                    hiTail->next = e;
                }
                hiTail = e;
            }
            else
            {
                if (loHead == NULL)
                {
                    loHead = e;
                }
                else
                {
                    loTail->next = e;
                }
                loTail = e;
            }
        } while ((e = next) != NULL);
        newCup[j + oldSize] = hiHead;
        newCup[j] = loHead;
        if (hiTail != NULL)
            hiTail->next = NULL;
        if (loTail != NULL)
            loTail->next = NULL;
    }
    free(hashMap->data);
    hashMap->data = newCup;
    hashMap->size = newSize;
}

Node* createNode(int hash, void* key, void* value, Node* next)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->hash = hash;
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}

void free_node(Node* node)
{
    if (node == NULL)
        return;
    free_node(node->next);
    node->key != NULL ? free(node->key) : NULL;
    node->value != NULL ? free(node->value) : NULL;
    free(node);
}

void free_map0(HashMap* hashMap,int is_free)
{
    for (int i = 0, size = hashMap->size; i < size; i++)
    {
        if (!is_free)
        {
            hashMap->data[i] = NULL;
            continue;
        }
        Node* e = hashMap->data[i];
        if (e != NULL && e->next == NULL)
        {
            e->key != NULL ? free(e->key) : NULL;
            e->value != NULL ? free(e->value) : NULL;
            free(e);
        }
        else
            free_node(e);
    }
}

/*
    free
*/
void free_map(HashMap* hashMap,int is_free)
{
    free_map0(hashMap,is_free);
    free(hashMap->data);
    free(hashMap);
}

/*
    get
*/
void* get(HashMap* hashMap, void* key)
{
    int hash = _hash(hashMap, key);
    int index = (hashMap->size - 1) & hash;
    Node* node = hashMap->data[index];
    if (node == NULL)
        return NULL;
    if (node->next == NULL)
        return hashMap->equals(node->key,key) ? node->value : NULL;
    Node* next;
    do
    {
        next = node->next;
        if (hashMap->equals(node->key,key))
            return node->value;
    } while ((node = next) != NULL);
    return NULL;
}

/*
    contains
*/
int contains(HashMap* hashMap, void* key)
{
    int hash = hashMap->hash_code(key);
    int index = (hashMap->size - 1) & hash;
    Node* node = hashMap->data[index];
    if (node == NULL)
        return 0;
    if (node->next == NULL)
        return hashMap->equals(node->key,key) ? 1 : 0;
    Node* next;
    do
    {
        next = node->next;
        if (hashMap->equals(node->key,key))
            return 1;
    } while ((node = next) != NULL);
    return 0;
}

/*
    新增
*/
void put(HashMap* hashMap,void* key, void* value)
{
    if (hashMap == NULL)
        return;
    if (hashMap->length == hashMap->size * 0.75)
        resize(hashMap);
    int hash = _hash(hashMap, key);
    int index = hash & (hashMap->size - 1);
    Node** nodeIndex = &hashMap->data[index];
    //如果该槽位无元素则直接插入
    if (*nodeIndex == NULL)
    {
        *nodeIndex = createNode(hash, key, value, NULL);
        hashMap->length++;
        return;
    }
    Node* e = *nodeIndex;
    Node* next = e;
    do
    {
        e = next;
        next = e->next;
        if (hashMap->equals(e->key,key))
        {
            e->value = value;
            return;
        }
    } while (next != NULL);
    e->next = createNode(hash, key, value, NULL);
    hashMap->length++;
}

/// 迭代
/// @param iter 迭代器
/// @param hashMap map
Node* iterator(Iterator* iter,HashMap* hashMap)
{
    Node* res = NULL;
    if (iter->mod_node != NULL)
    {
        res = iter->mod_node;
        iter->mod_node = iter->mod_node->next;
        return res;
    }
    for (; iter->mod < hashMap->size && !hashMap->data[iter->mod]; iter->mod++);
    iter->mod_node = iter->mod >= hashMap->size ? NULL : hashMap->data[iter->mod];
    res = iter->mod_node;
    iter->mod++;
    if (iter->mod_node != NULL) iter->mod_node = iter->mod_node->next;
    return res;
}

/*
    clean
 */
void clean(HashMap* hashMap,int is_free)
{
    free_map0(hashMap,is_free);
}

/*
    创建hashMap,需指定计算hashcode和equals函数
*/
HashMap* new_hash_map(int(*hash_code)(void*),int(*equals)(void*,void*))
{
    HashMap* hashMap = (HashMap*)malloc(sizeof(HashMap));
    hashMap->size = 16;
    hashMap->length = 0;
    hashMap->data = (Node**)malloc(sizeof(Node*) * hashMap->size);
    hashMap->hash_code = hash_code;
    hashMap->equals = equals;
    memset(hashMap->data, 0, sizeof(Node*) * hashMap->size);
    return hashMap;
}

