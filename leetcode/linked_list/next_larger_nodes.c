//
// Created by 我叫城北徐公° on 2021/5/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "list_node.h"
#include "utils.h"

typedef struct ListNode LNode;

//static int search_next_larger(LNode* head, int cur)
//{
//    while (head)
//    {
//        if (head->val > cur) return head->val;
//        head = head->next;
//    }
//    return 0;
//}
//
//int* nextLargerNodes(struct ListNode* head, int* returnSize)
//{
//    int* res = malloc(sizeof(int) * 10000);
//    int idx = 0;
//    while (head)
//    {
//        res[idx++] = search_next_larger(head->next, head->val);
//        head = head->next;
//    }
//    *returnSize = idx;
//    return res;
//}

typedef struct ListNode LNode;

static int max;

static int dfs(LNode* root, int* idx, int** arr, int* returnSize)
{
    if (!root)
    {
        *returnSize = (*idx);
        *arr = malloc(sizeof(int) * (*idx));
        (*idx)--;
        (*arr)[*idx] = 0;
        return -1;
    }
    (*idx)++;
    int r = dfs(root->next, idx, arr, returnSize);
    if (r != -1)
    {
        if (r > root->val) (*arr)[(*idx)] = root->val;
        else (*arr)[(*idx)] = max;
        (*idx)--;
    }
    return root->val;
}

int* nextLargerNodes(struct ListNode* head, int* returnSize)
{
    max = 0x80000000;
    int idx = -1;
    int* arr;
    //制作一个傀儡头
    LNode puppet;
    puppet.next = head;
    dfs(&puppet, &idx, &arr, returnSize);
    return arr;
}
