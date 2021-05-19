//
// Created by 我叫城北徐公° on 2021/5/12.
//

//  143. 重排链表

//  给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
//  将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
//
//  你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//
//  示例 1:
//
//  给定链表 1->2->3->4, 重新排列为 1->4->2->3.
//
//  示例 2:
//
//  给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

#include <iostream>
#include <vector>
#include "list_node.h"

using namespace std;

class Solution
{
public:

    vector<ListNode*> v;

    void reorderList(ListNode* head)
    {
        while (head)
        {
            v.push_back(head);
            ListNode* next = head->next;
            head->next = nullptr;
            head = next;
        }
        int start = 0;
        int end = v.size() - 1;
        while (start < end)
        {
            v[start]->next = v[end];
            if (start + 1 < end) v[end]->next = v[start + 1];
            start++;
            end--;
        }

    }
};