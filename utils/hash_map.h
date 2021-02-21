//
//  hash_map.h
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/10/14.
//  Copyright © 2020 alex. All rights reserved.
//

#ifndef hash_map_h
#define hash_map_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;
struct node
{
    void* key;
    void* value;
    int hash;
    Node* next;
};

typedef struct hash_map
{
    int size;
    int length;
    Node** data;
    int(*hash_code)(void*);
    int(*equals)(void*,void*);
}HashMap;

typedef struct iterator
{
    //用于map遍历指针位置
    int mod;
    Node* mod_node;
}Iterator;

/*
    扩容
*/
void resize(HashMap* hashMap);

/*
    free
*/
void free_map(HashMap* hashMap,int is_free);

/*
    contains
*/
int contains(HashMap* hashMap, void* key);

/*
    get
*/
void* get(HashMap* hashMap, void* key);

/*
    新增
*/
void put(HashMap* hashMap,void* key, void* value);

/// 迭代
/// @param iteraotr 迭代器
/// @param hashMap map
Node* iterator(Iterator* iteraotr,HashMap* hashMap);

/*
    clean
 */
void clean(HashMap* hashMap,int is_free);

/*
    创建hashMap,需指定计算hashcode和equals函数
*/
HashMap* new_hash_map(int(*hash_code)(void*),int(*equals)(void*,void*));

#endif /* hash_map_h */
