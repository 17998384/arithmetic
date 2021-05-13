//
// Created by 我叫城北徐公° on 2021/5/13.
//

//  445. 两数相加 II

//  给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
//
//  你可以假设除了数字 0 之外，这两个数字都不会以零开头。
//
//
//
//  进阶：
//
//  如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
//
//
//
//  示例：
//
//  输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//  输出：7 -> 8 -> 0 -> 7


#include <iostream>
#include <vector>
#include "list_node.hpp"

using namespace std;

class Solution
{
public:

    void dfs(ListNode* head, vector<int>& v)
    {
        if (!head) return;
        dfs(head->next, v);
        v.push_back(head->val);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        vector<int> v1;
        vector<int> v2;
        dfs(l1, v1);
        dfs(l2, v2);
        bool flag = false;
        vector<int> res;
        res.resize(max(v1.size(), v2.size()));
        int i = 0;
        while (i < v1.size() || i < v2.size())
        {
            int num = 0;
            if (i < v1.size()) num += v1[i];
            if (i < v2.size()) num += v2[i];
            if (flag) num += 1;
            if (num > 9)
            {
                flag = true;
                num = num % 10;
            }
            else flag = false;
            res[i] = num;
            i++;
        }
        if (flag) res.push_back(1);
        ListNode* head = nullptr;
        for (int i = 0, size = res.size(); i < size; i++)
        {
            if (!head) head = new ListNode(res[i]);
            else
            {
                ListNode* newLNode = new ListNode(res[i]);
                newLNode->next = head;
                head = newLNode;
            }
        }
        return head;
    }
};