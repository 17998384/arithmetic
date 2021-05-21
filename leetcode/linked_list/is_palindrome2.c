//
// Created by 我叫城北徐公° on 2021/5/21.
//

//  面试题 02.06. 回文链表

//  编写一个函数，检查输入的链表是否是回文的。
//
//
//
//  示例 1：
//
//  输入： 1->2
//  输出： false
//
//          示例 2：
//
//  输入： 1->2->2->1
//  输出： true
//
//
//
//  进阶：
//  你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？


#include <stdio.h>
#include <list_node.h>

typedef struct ListNode LNode;

static void dfs(LNode* head, LNode** compare, LNode* fast, int* flag)
{
    if (!*flag) return;
    if (!fast)
    {
        *compare = head;
        return;
    }
    if (!fast->next)
    {
        *compare = head->next;
        return;
    }
    fast = fast->next->next;
    dfs(head->next, compare, fast, flag);
    if (head->val != (*compare)->val) *flag = 0;
    if (*compare) (*compare) = (*compare)->next;
}

int isPalindrome2(struct ListNode* head)
{
    LNode* compare = NULL;
    int flag = 1;
    dfs(head, &compare, head, &flag);
    return flag;
}