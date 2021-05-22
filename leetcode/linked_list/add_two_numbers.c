//
// Created by 我叫城北徐公° on 2021/5/21.
//

//  面试题 02.05. 链表求和

//  给定两个用链表表示的整数，每个节点包含一个数位。
//
//  这些数位是反向存放的，也就是个位排在链表首部。
//
//  编写函数对这两个整数求和，并用链表形式返回结果。
//
//
//
//  示例：
//
//  输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
//  输出：2 -> 1 -> 9，即912
//
//          进阶：思考一下，假设这些数位是正向存放的，又该如何解决呢?
//
//  示例：
//
//  输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
//  输出：9 -> 1 -> 2，即912

#include <stdio.h>
#include <stdlib.h>
#include "list_node.h"

typedef struct ListNode LNode;

static LNode* new_node(int val)
{
    LNode* newNode = calloc(1, sizeof(LNode));
    newNode->val = val;
    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    LNode* res = NULL;
    LNode** resPtr = &res;
    int bit = 0;
    while (l1 || l2)
    {
        int sum = 0;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        if (bit) sum++;
        if (sum > 9) bit = 1;
        else bit = 0;
        *resPtr = new_node(sum % 10);
        resPtr = &(*resPtr)->next;
    }
    if (bit) *resPtr = new_node(1);
    return res;
}