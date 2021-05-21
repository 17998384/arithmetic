//
// Created by 我叫城北徐公° on 2021/5/20.
//

//  1669. 合并两个链表

//  给你两个链表 list1 和 list2 ，它们包含的元素分别为 n 个和 m 个。
//
//  请你将 list1 中第 a 个节点到第 b 个节点删除，并将list2 接在被删除节点的位置。
//
//  下图中蓝色边和节点展示了操作后的结果：
//
//  请你返回结果链表的头指针。
//
//
//
//  示例 1：
//
//  输入：list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
//  输出：[0,1,2,1000000,1000001,1000002,5]
//  解释：我们删除 list1 中第三和第四个节点，并将 list2 接在该位置。上图中蓝色的边和节点为答案链表。
//
//  示例 2：
//
//  输入：list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
//  输出：[0,1,1000000,1000001,1000002,1000003,1000004,6]
//  解释：上图中蓝色的边和节点为答案链表。
//
//
//
//  提示：
//
//  3 <= list1.length <= 104
//  1 <= a <= b < list1.length - 1
//  1 <= list2.length <= 104


#include <stdio.h>
#include "list_node.h"

typedef struct ListNode LNode;

static LNode* get_list_tail(LNode* head)
{
    LNode* fast, * slow;
    slow = fast = head;
    while (fast)
    {
        slow = slow->next;
        if (fast->next)
        {
            if (!fast->next->next) return fast->next;
            fast = fast->next->next;
        }
        else return fast;
    }
    return NULL;
}

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2)
{
    int i = 0;
    LNode* tmp, * start, * end;
    tmp = list1, start = end = NULL;
    while (tmp)
    {
        if (i == a - 1) start = tmp;
        if (i == b + 1)
        {
            end = tmp;
            break;
        }
        i++;
        tmp = tmp->next;
    }
    if (start)
    {
        LNode* list2Tail = get_list_tail(list2);
        start->next = list2;
        list2Tail->next = end;
    }
    return list1;
}