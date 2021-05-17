//
// Created by 我叫城北徐公° on 2021/5/14.
//

//  725. 分隔链表

//  给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。
//
//  每部分的长度应该尽可能的相等: 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。
//
//  这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。
//
//  返回一个符合上述规则的链表的列表。
//
//  举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ]
//
//  示例 1：
//
//  输入:
//  root = [1, 2, 3], k = 5
//  输出: [[1],[2],[3],[],[]]
//  解释:
//  输入输出各部分都应该是链表，而不是数组。
//  例如, 输入的结点 root 的 val= 1, root.next.val = 2, \root.next.next.val = 3, 且 root.next.next.next = null。
//  第一个输出 output[0] 是 output[0].val = 1, output[0].next = null。
//  最后一个元素 output[4] 为 null, 它代表了最后一个部分为空链表。
//
//  示例 2：
//
//  输入:
//  root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
//  输出: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
//  解释:
//  输入被分成了几个连续的部分，并且每部分的长度相差不超过1.前面部分的长度大于等于后面部分的长度。
//
//
//
//  提示:
//
//  root 的长度范围： [0, 1000].
//  输入的每个节点的大小范围：[0, 999].
//  k 的取值范围： [1, 50].

#include <stdio.h>
#include <stdlib.h>
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

struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize)
{
    int size = calc_list_size(root);
    int* buffer = calloc(k, sizeof(int));
    if (k >= size)
    {
        for (int i = 0; i < size; i++) buffer[i] = 1;
    }
    else
    {
        int slot = size / k;
        int remain = size % k;
        for (int i = 0, j = 0; i < k; i++, j++)
        {
            buffer[i] = slot;
            if (j < remain) buffer[i]++;
        }
    }
    LNode** res = calloc(k, sizeof(LNode*));
    *returnSize = k;
    LNode* next = NULL;
    for (int i = 0; i < k; i++)
    {
        res[i] = root;
        for (int j = 0, bSize = buffer[i]; j < bSize; ++j)
        {
            if (j == bSize - 1)
            {
                next = root->next;
                root->next = NULL;
                root = next;
            }
            else root = root->next;
        }
    }
    free(buffer);
    return res;
}