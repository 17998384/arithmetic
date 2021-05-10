//
// Created by 我叫城北徐公° on 2021/5/8.
//

//  61. 旋转链表
//
//  给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
//
//
//
//  示例 1：
//
//  输入：head = [1,2,3,4,5], k = 2
//  输出：[4,5,1,2,3]
//
//  示例 2：
//
//  输入：head = [0,1,2], k = 4
//  输出：[2,0,1]
//
//
//
//  提示：
//
//  链表中节点的数目在范围 [0, 500] 内
//  -100 <= Node.val <= 100
//  0 <= k <= 2 * 109
//

#include <stdio.h>
#include "list_node.h"


typedef struct ListNode LNode;

struct ListNode* rotateRight(struct ListNode* head, int k)
{
    LNode* resHead = head;
    LNode* tail;
    LNode* tmp;
    tmp = tail = head;
    int linkedListSize = 0;
    while (tmp)
    {
        tail = tmp;
        linkedListSize++;
        tmp = tmp->next;
    }
    if (!linkedListSize) return resHead;
    int moveIdx = linkedListSize - (k % linkedListSize);
    int movePrevIdx = moveIdx - 1;
    if (movePrevIdx < 0) return resHead;

    // printf("moveIdx : %d,movePrevIdx : %d\n",moveIdx,movePrevIdx);

    tmp = resHead;
    int idx = 0;
    while (idx < linkedListSize)
    {

        if (idx == movePrevIdx)
        {
            LNode* next = tmp->next;
            tmp->next = NULL;
            tmp = next;
            idx++;
            continue;
        }
        else if (idx == moveIdx)
        {
            resHead = tmp;
            tail->next = head;
            break;
        }
        tmp = tmp->next;
        idx++;
    }
    return resHead;
}
