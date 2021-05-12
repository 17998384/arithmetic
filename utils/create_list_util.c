//
// Created by 我叫城北徐公° on 2021/5/12.
//

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "list_node.h"

/**
 * 创建list
 * @param arr
 * @param size
 * @return
 */
struct ListNode* create_list(const int* arr, int size)
{
    if (!arr) return NULL;
    struct ListNode* head = NULL;
    struct ListNode** ptr = &head;
    for (int i = 0; i < size; ++i)
    {
        *ptr = calloc(1, sizeof(struct ListNode));
        (*ptr)->val = arr[i];
        ptr = &(*ptr)->next;
    }
    return head;
}