//
//  hash_map.h
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/10/14.
//  Copyright © 2020 alex. All rights reserved.
//

#ifndef hash_map_h
#define hash_map_h
#define MAP_NULL -854578421

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;
struct node
{
    int key;
    int value;
    int hash;
    Node* next;
};

typedef struct hash_map
{
    int size;
    int length;
    Node** data;
}HashMap;

/*
    扩容
*/
void resize(HashMap* hashMap);

/*
    free
*/
void free_map(HashMap* hashMap);

/*
    contains
*/
int contains(HashMap* hashMap, int key);

/*
    get
*/
int get(HashMap* hashMap, int key);

/*
    新增
*/
void put(int key, int value, HashMap* hashMap);

/*
    创建hashMap
*/
HashMap* newHashMap(void);

#endif /* hash_map_h */
