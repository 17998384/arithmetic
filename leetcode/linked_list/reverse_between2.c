//
// Created by 我叫城北徐公° on 2021/5/10.
//

//  92. 反转链表 II

//  给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
//
//
//
//  示例 1：
//
//  输入：head = [1,2,3,4,5], left = 2, right = 4
//  输出：[1,4,3,2,5]
//
//  示例 2：
//
//  输入：head = [5], left = 1, right = 1
//  输出：[5]
//
//
//
//  提示：
//
//  链表中节点数目为 n
//  1 <= n <= 500
//  -500 <= Node.val <= 500
//  1 <= left <= right <= n



#include <stdio.h>
#include "list_node.h"

typedef struct ListNode LNode;

static LNode* dfs(int idx, LNode* head, int right, LNode** newHead, LNode** afterRightLNode)
{
    if (!head) return NULL;
    if (idx == right)
    {
        *afterRightLNode = head->next;
        *newHead = head;
        return head;
    }
    LNode* tmp = dfs(idx + 1, head->next, right, newHead, afterRightLNode);
    if (tmp) tmp->next = head;
    return head;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
{
    if (!head) return NULL;
    LNode* resHead = NULL;
    LNode* tmp = head;
    LNode* afterRightLNode = NULL;
    if (left != 1) resHead = head;
    int idx = 1;
    while (tmp)
    {
        if (idx == left)
        {
            LNode* newHead = NULL;
            dfs(idx, tmp, right, &newHead, &afterRightLNode);
            if (!resHead) resHead = newHead;
            else
            {
                LNode* _tmp = head;
                int tmpIdx = 1;
                while (tmpIdx < left)
                {
                    if (tmpIdx + 1 == left)
                    {
                        _tmp->next = newHead;
                        break;
                    }
                    _tmp = _tmp->next;
                    tmpIdx++;
                }
            }
            tmp->next = afterRightLNode;
            break;
        }
        tmp = tmp->next;
        idx++;
    }
    return resHead;
}
