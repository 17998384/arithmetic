//
// Created by 我叫城北徐公° on 2021/5/13.
//

//  234. 回文链表

//  请判断一个链表是否为回文链表。
//
//  示例 1:
//
//  输入: 1->2
//  输出: false
//
//  示例 2:
//
//  输入: 1->2->2->1
//  输出: true
//
//  进阶：
//  你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？


#include <stdio.h>
#include "list_node.h"

typedef struct ListNode LNode;

/**
 * 快慢指针分割并计算大小
 * @param head
 * @return
 */
static LNode* fast_slow_ptr_split_and_calc_size(LNode* head, int* size)
{
    LNode* slow, * fast, * prev = NULL;
    int i;
    slow = fast = head;
    *size = i = 0;
    while (fast)
    {
        if (!prev) prev = slow;
        else prev = prev->next;
        slow = slow->next;
        if (fast->next) fast = fast->next->next;
        else
        {
            *size = (i << 1) + 1;
            break;
        }
        i++;
    }
    if (prev) prev->next = NULL;
    if (!*size) *size = i << 1;
    return slow;
}

static LNode* dfs(LNode* left, LNode** right, int* isOdd, int* isPalindrome)
{
    if (!left || !*isPalindrome) return NULL;
    if (!left->next)
    {
        if (*isOdd)
        {
            *isOdd = 0;
            return NULL;
        }
        return left;
    }
    LNode* res = dfs(left->next, right, isOdd, isPalindrome);
    if (res)
    {
        if (res->val != (*right)->val) *isPalindrome = 0;
        *right = (*right)->next;
    }
    return left;
}

int linkedListIsPalindrome(struct ListNode* head)
{
    int size = 0;
    LNode* right = fast_slow_ptr_split_and_calc_size(head, &size);
    LNode leftSentry;
    leftSentry.next = head;
    int res = 1;
    int isOdd = (size % 2 != 0);
    dfs(&leftSentry, &right, &isOdd, &res);
    return res;
}
