//
// Created by 我叫城北徐公° on 2021/5/10.
//

//  86. 分隔链表

//  给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
//
//  你应当 保留 两个分区中每个节点的初始相对位置。
//
//
//
//  示例 1：
//
//  输入：head = [1,4,3,2,5,2], x = 3
//  输出：[1,2,2,4,3,5]
//
//  示例 2：
//
//  输入：head = [2,1], x = 2
//  输出：[1,2]
//
//
//
//  提示：
//
//  链表中节点的数目在范围 [0, 200] 内
//  -100 <= Node.val <= 100
//  -200 <= x <= 200


#include <stdio.h>
#include "list_node.h"

typedef struct ListNode LNode;

struct ListNode* partition(struct ListNode* head, int x)
{
    if (!head) return NULL;
    LNode* left, * right, * leftIter, * rightIter;
    left = right = leftIter = rightIter = NULL;
    while (head)
    {
        if (head->val < x)
        {
            if (leftIter)
            {
                leftIter->next = head;
                leftIter = leftIter->next;
            }
            else
            {
                left = leftIter = head;
            }
        }
        else
        {
            if (rightIter)
            {
                rightIter->next = head;
                rightIter = rightIter->next;
            }
            else
            {
                right = rightIter = head;
            }
        }
        head = head->next;
    }
    if (rightIter) rightIter->next = NULL;
    if (left)
    {
        leftIter->next = right;
        return left;
    }
    else return right;
}
