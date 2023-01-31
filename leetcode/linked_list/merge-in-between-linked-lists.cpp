//
// Created by 我叫城北徐公° on 2023/1/31.
//

//  1669. 合并两个链表

//  给你两个链表list1 和list2，它们包含的元素分别为n 个和m 个。
//
//  请你将list1中下标从 a 到 b 的全部节点都删除，并将list2接在被删除节点的位置。
//
//  下图中蓝色边和节点展示了操作后的结果：
//
//  请你返回结果链表的头指针。
//
//
//
//  示例 1：
//
//  输入：list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
//  输出：[0,1,2,1000000,1000001,1000002,5]
//  解释：我们删除 list1 中下标为 3 和 4 的两个节点，并将 list2 接在该位置。上图中蓝色的边和节点为答案链表。
//
//  示例 2：
//
//  输入：list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
//  输出：[0,1,1000000,1000001,1000002,1000003,1000004,6]
//  解释：上图中蓝色的边和节点为答案链表。
//
//
//
//  提示：
//
//  3 <= list1.length <= 104
//  1 <= a <= b < list1.length - 1
//  1 <= list2.length <= 104

#include <iostream>
#include "list_node.h"

using namespace std;

class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *res = list1, *list1Head, *list1Tail, *list2Head = list2, *list2TailSlow = list2, *list2TailFast = list2;
        while (list2TailFast)
        {
            list2TailSlow = list2TailFast->next;
            if (list2TailSlow == NULL)
            {
                list2TailSlow = list2TailFast;
                break;
            }
            list2TailFast = list2TailSlow->next;
        }
        for (int i = 0; list1; i++, list1 = list1->next)
        {
            if (i == a - 1) list1Head = list1;
            else if (i == b) list1Tail = list1->next;
        }
        list1Head->next = list2Head;
        list2TailSlow->next = list1Tail;
        return res;
    }
};