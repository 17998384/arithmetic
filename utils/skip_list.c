//
//  skip_list.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/12/5.
//  Copyright © 2020 alex. All rights reserved.
//

#include "skip_list.h"

SkipListNode* newSkipListNode(int data,int level)
{
    SkipListNode* skipListNode = calloc(1,sizeof(SkipListNode));
    skipListNode->data = data;
    skipListNode->next = calloc(level, sizeof(SkipListNode*));
    return skipListNode;
}

void add(SkipList* skipList,int val)
{
    int level = getLevel(skipList->max_level);
    //创建新节点
    SkipListNode* newNode = newSkipListNode(val, level + 1);
    //头节点
    for (; level >= 0; --level)
    {
        SkipListNode* tmp = skipList->head;
        while (tmp->next[level] && tmp->next[level]->data < val) tmp = tmp->next[level];
        newNode->next[level] = tmp->next[level];
        tmp->next[level] = newNode;
    }
    if (level >skipList->cur_level) skipList->cur_level = level;
    skipList->size++;
}

static SkipListNode* search(SkipList* skipList,int val)
{
    //从最高深度找
    int level = skipList->cur_level;
    SkipListNode* tmp = NULL;
    int flag = 1;
    for (; level >= 0; --level)
    {
        if (flag) tmp = skipList->head;
        while (tmp->next[level] && tmp->next[level]->data < val) {tmp = tmp->next[level];flag = 0;}
        if (tmp->next[level] && tmp->next[level]->data == val) return tmp->next[level];
    }
    return NULL;
}

void del(SkipList* skipList,int val)
{
    int level = skipList->cur_level;
    SkipListNode* tmp = NULL;
    SkipListNode* target = NULL;
    int flag = 1;
    for (; level >= 0; --level)
    {
        if (flag) tmp = skipList->head;
        while (tmp->next[level] && tmp->next[level]->data < val) {tmp = tmp->next[level];flag = 0;}
        if (tmp->next[level] && tmp->next[level]->data == val)
        {
            target = tmp->next[level];
            tmp->next[level] = target->next[level];
        }
    }
    free(target);
}

static void dfs_free(SkipListNode* skipListNode)
{
    if (!skipListNode) return;
    dfs_free(skipListNode->next[0]);
    free(skipListNode->next);
    free(skipListNode);
}

static void clean(SkipList* skipList)
{
    dfs_free(skipList->head);
    free(skipList);
}

int getLevel(int maxLevel)
{
    int level = 0;
    while (level < maxLevel - 1 && rand() % 2 == 0) level++;
    return level;
}

//int main(void)
//{
//    SkipList* skipList = (SkipList*)calloc(1, sizeof(SkipList));
//    skipList->max_level = 16;
//    skipList->size = 0;
//    skipList->head = newSkipListNode(-1, 16);
//    for (int i = 0; i < 8; i++) add(skipList, i);
//    SkipListNode* node = search(skipList, 6);
//    del(skipList, 6);
//    SkipListNode* node2 = search(skipList, 6);
////    printf("node->data : %d,node2->data : %d\n",node ? node->data : -1,node2 ? node2->data : -1);
//    printf("node2->data : %d\n",node2 ? node2->data : -1);
//    clean(skipList);
//    return 0;
//}
