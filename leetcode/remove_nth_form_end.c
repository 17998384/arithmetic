//
//  remove_nth_form_end.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/9/24.
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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int half = 1;
    int all = 1;
    struct ListNode* current = head;
    struct ListNode* half_node = head;
    //求出中位节点与总结点数量
    while(current->next != NULL)
    {
        half_node = half_node->next;
        current = current->next;
        half++;
        all++;
        if(current->next == NULL)
        {
            break;
        }
        current = current->next;
        all++;
    }
    if (all == 1)
    {
        return NULL;
    }
    if (all == n)
    {
        return head->next;
    }
    int current_num = all - n + 1;
    //如果大于一半
    if(current_num > half)
    {
        for(int i = half; i < current_num - 1 ;i++)
        {
            half_node = half_node->next;
        }
        struct ListNode* target_next = half_node->next->next;
        half_node->next = target_next;
    }
    else
    {
        half_node = head;
        for(int i = 1; i < current_num - 1 ;i++)
        {
            half_node = half_node->next;
        }
        struct ListNode* target_next = half_node->next->next;
        half_node->next = target_next;
    }
    return head;
}
int main(void)
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    struct ListNode* current = head;
    for (int i = 2; i < 4; i++)
    {
        struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = i;
        current->next = tmp;
        current = tmp;
    }
    current->next = NULL;
    struct ListNode* target = removeNthFromEnd(head, 1);
    while (target)
    {
        printf("%d ",target->val);
        struct ListNode* prev = target;
        target = target->next;
        free(prev);
    }
    return 0;
}
