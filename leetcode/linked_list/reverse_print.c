//
// Created by 我叫城北徐公° on 2021/5/21.
//

//  剑指 Offer 06. 从尾到头打印链表

//  输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
//
//
//
//  示例 1：
//
//  输入：head = [1,3,2]
//  输出：[2,3,1]
//
//
//
//  限制：
//
//  0 <= 链表长度 <= 10000


#include <stdio.h>
#include <stdlib.h>
#include "list_node.h"

typedef struct ListNode LNode;

static int* dfs(LNode* head, int* count)
{
    if (!head) return NULL;
    (*count)++;
    if (!head->next)
    {
        int* res = malloc((*count) * sizeof(int));
        *count = 0;
        res[(*count)++] = head->val;
        return res;
    }
    int* res = dfs(head->next, count);
    if (res) res[(*count)++] = head->val;
    return res;
}

int* reversePrint(struct ListNode* head, int* returnSize)
{
    int count = 0;
    int* res = dfs(head, &count);
    *returnSize = count;
    return res;
}