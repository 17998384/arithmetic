//
//  skip_list.h
//  arithmetic
//  
//  Created by 我叫城北徐公° on 2020/12/5.
//  Copyright © 2020 alex. All rights reserved.
//

#ifndef skip_list_h
#define skip_list_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct skip_list_node SkipListNode;

struct skip_list_node
{
    int data;
    SkipListNode** next;
};

typedef struct skip_list
{
    int max_level;
    int cur_level;
    int size;
    SkipListNode* head;
}SkipList;

/// newNode
/// @param data 数据
/// @param level 当前等级
SkipListNode* newSkipListNode(int data,int level);

/// 添加
/// @param skipList 跳跃表
/// @param val 添加值
void add(SkipList* skipList,int val);

/// 搜索
/// @paramskipList  跳跃表
/// @param val 要搜索的值
/// @return 返回搜索到的节点
static SkipListNode* search(SkipList* skipList,int val);

/// 删除
/// @param skipList 跳跃表
/// @param val 要删除的值
void del(SkipList* skipList,int val);

/// 清空
/// @param skipList 跳跃表
static void clean(SkipList* skipList);

/// 获取等级
/// @param maxLevel 跳跃表最大的深度
int getLevel(int maxLevel);

#endif /* skip_list_h */
