//
//  merge_k_lists.c
//  arithmetic
//
//  合并K个生序链表
//
//  Created by 我叫城北徐公° on 2020/10/12.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

static int compare(void* a,void* b)
{
    return *((int*)a) - *((int*)b);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (listsSize == 0)
        return NULL;
    int* array = (int*)malloc(sizeof(int) * 10000);
    int current_index = 0;
    for (int i = 0; i < listsSize; i++)
    {
        struct ListNode* first = lists[i];
        while (first)
        {
            array[current_index++] = first->val;
            first = first->next;
        }
    }
    if (current_index == 0)
        return NULL;
    qsort(array, current_index, sizeof(int), compare);
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tmp = head;
    struct ListNode* prev;
    for (int i = 0; i < current_index; i++)
    {
        tmp->val = array[i];
        tmp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next = NULL;
    return head;
}

void eg1()
{
    struct ListNode* one = (struct ListNode*)malloc(sizeof(struct ListNode));
    one->val = 1;
    one->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    one->next->val = 3;
    one->next->next = NULL;
    struct ListNode* two = (struct ListNode*)malloc(sizeof(struct ListNode));
    two->val = 1;
    two->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    two->next->val = 2;
    two->next->next = NULL;
    struct ListNode** param = (struct ListNode**)malloc(sizeof(struct ListNode*) * 2);
    param[0] = one;
    param[1] = two;
    struct ListNode* result = mergeKLists(param, 2);
}

void eg2()
{
    struct ListNode** param = (struct ListNode**)malloc(sizeof(struct ListNode*) * 1);
    param[0] = NULL;
    struct ListNode* result = mergeKLists(param, 1);
    printf("\n");
}

int main_merge_k_lists(void)
{
    eg2();
    printf("\n");
}
