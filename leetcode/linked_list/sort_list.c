//
// Created by 我叫城北徐公° on 2021/5/12.
//

//  148. 排序链表

//  给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
//
//  进阶：
//
//  你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
//
//
//
//  示例 1：
//
//  输入：head = [4,2,1,3]
//  输出：[1,2,3,4]
//
//  示例 2：
//
//  输入：head = [-1,5,3,4,0]
//  输出：[-1,0,3,4,5]
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
//  链表中节点的数目在范围 [0, 5 * 104] 内
//  -105 <= Node.val <= 105


#include <stdio.h>
#include "list_node.h"

typedef struct ListNode LNode;

static LNode* merge(LNode* left, LNode* right)
{
    LNode* head = NULL;
    LNode** headPtr = &head;
    while (left || right)
    {
        if (!left)
        {
            *headPtr = right;
            right = right->next;
        }
        else if (!right)
        {
            *headPtr = left;
            left = left->next;
        }
        else
        {
            if (left->val > right->val)
            {
                *headPtr = right;
                right = right->next;
            }
            else
            {
                *headPtr = left;
                left = left->next;
            }
        }
        headPtr = &(*headPtr)->next;
    }
    return head;
}

static LNode* fast_slow_ptr(LNode* head)
{
    LNode* slow, * fast, * prev = NULL;
    slow = fast = head;
    while (fast)
    {
        if (!prev) prev = slow;
        else prev = prev->next;
        slow = slow->next;
        if (fast->next) fast = fast->next->next;
        else break;
    }
    if (prev) prev->next = NULL;
    return slow;
}

static LNode* list_merge_sort(LNode* left, LNode* right)
{
    if (!left || !right) return left ? left : right;
    LNode* resL = list_merge_sort(left, fast_slow_ptr(left));
    LNode* resR = list_merge_sort(right, fast_slow_ptr(right));
    return merge(resL, resR);
}

struct ListNode* sortList(struct ListNode* head)
{
    return list_merge_sort(head, fast_slow_ptr(head));
}
