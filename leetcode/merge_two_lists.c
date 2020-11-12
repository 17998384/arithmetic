//
//  merge_two_lists.c
//  arithmetic

//  21.合并两个有序链表

//  Created by 我叫城北徐公° on 2020/9/25.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    struct ListNode* return_node = NULL;
    struct ListNode* curret_node = NULL;
    while (1)
    {
        if (p1 == NULL && p2 == NULL)
            break;
        struct ListNode* tmp = NULL;
        if (p1 != NULL && p2 != NULL)
        {
            if (p1->val < p2->val)
            {
                tmp = p1;
                p1 = p1->next;
            }
            else
            {
                tmp = p2;
                p2 = p2->next;
            }
            
        }
        else if (p1 != NULL && p2 == NULL)
        {
            tmp = p1;
            p1 = NULL;
            goto loop;
        }
        else if (p1 == NULL && p2 != NULL)
        {
            tmp = p2;
            p2 = NULL;
            goto loop;
        }
        else{}
    loop:
        if (return_node == NULL)
        {
            return_node = tmp;
            curret_node = return_node;
        }
        else
        {
            curret_node->next = tmp;
            curret_node = tmp;
        }
    }
    return return_node;
}

int main_merge_two_lists(void)
{
    struct ListNode* one = (struct ListNode*)malloc(sizeof(struct ListNode));
    one->val = 1;
    one->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    one->next->val = 2;
    one->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    one->next->next->val = 4;
    one->next->next->next = NULL;
    struct ListNode* two = (struct ListNode*)malloc(sizeof(struct ListNode));
    two->val = 1;
    two->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    two->next->val = 3;
    two->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    two->next->next->val = 4;
    two->next->next->next = NULL;
    struct ListNode* result = mergeTwoLists(one, two);
    while (result)
    {
        printf("%d ",result->val);
        result = result->next;
    }
    return 0;
}
