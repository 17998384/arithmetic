//
// Created by 我叫城北徐公° on 2021/5/21.
//

//  面试题 02.01. 移除重复节点

//  编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
//
//  示例1:
//
//  输入：[1, 2, 3, 3, 2, 1]
//  输出：[1, 2, 3]
//
//  示例2:
//
//  输入：[1, 1, 1, 1, 2]
//  输出：[1, 2]
//
//  提示：
//
//  链表长度在[0, 20000]范围内。
//  链表元素在[0, 20000]范围内。
//
//  进阶：
//
//  如果不得使用临时缓冲区，该怎么解决？（无解，只能双重for循环，不要想着用啥技巧，没技巧）


#include <stdio.h>
#include <stdlib.h>
#include "list_node.h"

typedef struct ListNode LNode;

struct ListNode* removeDuplicateNodes(struct ListNode* head)
{
    char cache[20001] = {0};
    LNode** headPtr = &head;
    while (*headPtr)
    {
        LNode* cur = (*headPtr);
        if (cache[cur->val])
        {
            LNode* next = cur->next;
            free(cur);
            *headPtr = next;
        }
        else
        {
            cache[cur->val] = 1;
            headPtr = &(*headPtr)->next;
        }
    }
    return head;
}