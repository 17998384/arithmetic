//
// Created by 我叫城北徐公° on 2021/5/13.
//

//  1721. 交换链表中的节点

//  给你链表的头节点 head 和一个整数 k 。
//
//  交换 链表正数第 k 个节点和倒数第 k 个节点的值后，返回链表的头节点（链表 从 1 开始索引）。
//
//
//
//  示例 1：
//
//  输入：head = [1,2,3,4,5], k = 2
//  输出：[1,4,3,2,5]
//
//  示例 2：
//
//  输入：head = [7,9,6,6,7,8,3,0,9,5], k = 5
//  输出：[7,9,6,6,8,7,3,0,9,5]
//
//  示例 3：
//
//  输入：head = [1], k = 1
//  输出：[1]
//
//  示例 4：
//
//  输入：head = [1,2], k = 1
//  输出：[2,1]
//
//  示例 5：
//
//  输入：head = [1,2,3], k = 2
//  输出：[1,2,3]
//
//
//
//  提示：
//
//  链表中节点的数目是 n
//  1 <= k <= n <= 105
//  0 <= Node.val <= 100


#include <stdio.h>
#include "list_node.h"

typedef struct ListNode LNode;

static int calc_list_size(LNode* head)
{
    if (!head) return 0;
    int size = 0;
    LNode* slow, * fast;
    slow = fast = head;
    while (fast)
    {
        slow = slow->next;
        if (fast->next) fast = fast->next->next;
        else return size * 2 + 1;
        size++;
    }
    return size * 2;
}

struct ListNode* swapNodes(struct ListNode* head, int k)
{
    int size = calc_list_size(head);
    int last = size - k + 1;
    LNode* a, * b, * tmp = head;
    a = b = NULL;
    int i = 1;
    while (tmp)
    {
        if (i == k) a = tmp;
        if (i == last)
        {
            b = tmp;
            if (last > k) break;
        }
        tmp = tmp->next;
        i++;
    }
    if (a && b)
    {
        int tmpNum = a->val;
        a->val = b->val;
        b->val = tmpNum;
    }
    return head;
}