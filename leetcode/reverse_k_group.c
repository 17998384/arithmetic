//
//  reverse_k_group.c
//  arithmetic
//
//  25.K个一组反转链表

// 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
//
// k 是一个正整数，它的值小于或等于链表的长度。
//
// 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序
//
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 示例：
//
// 给你这个链表：1->2->3->4->5
//
// 当 k = 2 时，应当返回: 2->1->4->3->5
//
// 当 k = 3 时，应当返回: 3->2->1->4->5
//
//
//
// 说明：
//
//     你的算法只能使用常数的额外空间。
//     你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
//
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//  Created by 我叫城北徐公° on 2020/10/13.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_node.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse_k_group0(struct ListNode* one,struct ListNode* two,int* n,int k,struct ListNode** last_bak,int* tag)
{
    if (*n == k)
    {
        *last_bak = one->next;
        return one;
    }
    if (one && !two)
    {
        *tag = 0;
        return NULL;
    }
    (*n)++;
    struct ListNode* result = reverse_k_group0(two, two->next, n, k,last_bak,tag);
    if (*tag)
        two->next = one;
    return result;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if (k == 1)
        return head;
    struct ListNode** cache = (struct ListNode**)malloc(sizeof(struct ListNode*) * 200);
    memset(cache, 0, sizeof(struct ListNode*) * 200);
    int cache_index = 0;
    struct ListNode* first = head;
    struct ListNode* last = NULL;
    struct ListNode* last_bak = NULL;
    int tag = 1;
    int n = 1;
    while (first)
    {
        cache[cache_index++] = first;
        last = reverse_k_group0(first,first->next,&n,k,&last_bak,&tag);
        if (last)
            cache[cache_index++] = last;
        first = last_bak;
        last_bak = NULL;
        last = NULL;
        n = 1;
        tag = 1;
    }
    
    for (int i = 0; i < cache_index; i ++ )
    {
        printf("%d ",cache[i]->val);
    }
    for (int i = 0; i < cache_index; i += 2)
    {
        if (cache[i + 3])
            cache[i]->next = cache[i + 3];
        else if(cache[i + 2])
            cache[i]->next = cache[i + 2];
        else
        {
            if (cache[i + 1] && !cache[i + 2])
            {
                cache[i]->next = NULL;
                break;
            }
            else
                break;
        }
    }
    last = cache[1] ? cache[1] : cache[0];
    free(cache);
    return last;
}

int main_reverse_k_group(void)
{
    struct ListNode* one = (struct ListNode*)malloc(sizeof(struct ListNode));
    one->val = 4;
    one->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    one->next->val = 8;
    one->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    one->next->next->val = 4;
    one->next->next->next = NULL;
//    one->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//    one->next->next->next->val = 8;
//    one->next->next->next->next = NULL;
//    one->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//    one->next->next->next->next->val = 5;
//    one->next->next->next->next->next = NULL;
    one = reverseKGroup(one, 3);
    return 0;
}
