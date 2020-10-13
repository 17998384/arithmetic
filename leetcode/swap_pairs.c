//
//  swap_pairs.c
//  arithmetic
//  给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//  你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//  Created by 我叫城北徐公° on 2020/10/12.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "list_node.h"

struct ListNode* swapPairs(struct ListNode* head){
    if (!head)
        return NULL;
    if (!head->next)
        return head;
    struct ListNode* current = head;
    struct ListNode* tmp_current = head;
    struct ListNode* next = head->next;
    struct ListNode* prev;
    struct ListNode* return_node = next;
    while (current && next)
    {
        prev = current;
        current->next = next->next;
        next->next = tmp_current;
        current = current->next;
        if (!current)
        {
            next = NULL;
            break;
        }
        next = current->next;
        tmp_current = current;
        if (!next)
            prev->next = tmp_current;
        else
            prev->next = next;
    }
    return return_node;
}

int main_swap_pairs(void)
{
    struct ListNode* one = (struct ListNode*)malloc(sizeof(struct ListNode));
    one->val = 1;
    one->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    one->next->val = 2;
    one->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    one->next->next->val = 3;
    one->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    one->next->next->next->val = 4;
    one->next->next->next->next = NULL;
    one = swapPairs(one);
    printf("\n");
    return 0;
}
