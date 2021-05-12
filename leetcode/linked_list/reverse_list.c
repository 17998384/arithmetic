//
// Created by 我叫城北徐公° on 2021/5/12.
//

//  206. 反转链表
//
//  给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
//
//
//
//  示例 1：
//
//  输入：head = [1,2,3,4,5]
//  输出：[5,4,3,2,1]
//
//  示例 2：
//
//  输入：head = [1,2]
//  输出：[2,1]
//
//  示例 3：
//
//  输入：head = []
//  输出：[]
//
//
//
//  提示：
//
//  链表中节点的数目范围是 [0, 5000]
//  -5000 <= Node.val <= 5000
//
//
//
//  进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？


#include <stdio.h>
#include "list_node.h"

typedef struct ListNode LNode;

static LNode* reverse_list0(LNode* head, LNode** res)
{
    if (!head) return NULL;
    if (!head->next)
    {
        *res = head;
        return head;
    }
    LNode* r = reverse_list0(head->next, res);
    if (r) r->next = head;
    return head;
}

struct ListNode* reverseList(struct ListNode* head)
{
    if (!head) return NULL;
    LNode* res = NULL;
    reverse_list0(head, &res);
    head->next = NULL;
    return res;
}