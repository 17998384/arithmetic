//
// Created by 我叫城北徐公° on 2021/5/22.
//

//  剑指 Offer 24. 反转链表

//  定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
//
//
//
//  示例:
//
//  输入: 1->2->3->4->5->NULL
//          输出: 5->4->3->2->1->NULL
//
//
//
//          限制：
//
//  0 <= 节点个数 <= 5000

#include <stdio.h>
#include "list_node.h"

typedef struct ListNode LNode;

struct ListNode* reverseList2(struct ListNode* head)
{
    if (!head) return NULL;
    if (!head->next) return head;
    LNode* next = head->next;
    head->next = NULL;
    LNode* res = reverseList2(next);
    if (next) next->next = head;
    return res;
}