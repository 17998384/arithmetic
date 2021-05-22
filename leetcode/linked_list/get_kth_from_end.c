//
// Created by 我叫城北徐公° on 2021/5/22.
//

//  剑指 Offer 22. 链表中倒数第k个节点

//  输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
//
//  例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。
//
//
//
//  示例：
//
//  给定一个链表: 1->2->3->4->5, 和 k = 2.
//
//  返回链表 4->5.


#include <stdio.h>
#include "list_node.h"

typedef struct ListNode LNode;

/*
 * 第一种解法，时间复杂度O(n)
 */

//static LNode* dfs(LNode* head, int* count, int k)
//{
//    if (!head) return NULL;
//    if (!head->next)
//    {
//        (*count)++;
//        if (*count == k) return head;
//        return NULL;
//    }
//    LNode* res = dfs(head->next, count, k);
//    (*count)++;
//    if (res) return res;
//    if (*count == k) return head;
//    return NULL;
//}

//struct ListNode* getKthFromEnd(struct ListNode* head, int k)
//{
//    int count = 0;
//    return dfs(head, &count, k);
//}

struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    LNode* fast = head;
    for (int i = 0; i < k && fast; i++, fast = fast->next);
    while (fast)
    {
        head = head->next;
        fast = fast->next;
    }
    return head;
}