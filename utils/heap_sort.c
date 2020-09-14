//
//  heap_sort.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/9/14.
//  Copyright © 2020 alex. All rights reserved.
//

#include "heap_sort.h"

void compare_and_swap(int* copy,int wait_clear_up_index,int num)
{
    if (wait_clear_up_index == 0)
        return;
    do{
        int* current = &copy[wait_clear_up_index - 1];
        int* L = &copy[wait_clear_up_index * 2 - 1];
        int* R = &copy[wait_clear_up_index * 2];
        if (wait_clear_up_index * 2 - 1 < num && *current > *L)
        {
            *current ^= *L;
            *L ^= *current;
            *current ^= *L;
        }
        if (wait_clear_up_index * 2 < num && *current > *R)
        {
            *current ^= *R;
            *R ^= *current;
            *current ^= *R;
        }
        wait_clear_up_index--;
    }while(wait_clear_up_index > 0);
}

void heap_sort0(int* dest,int* copy,int num)
{
    if (num == 0)
        return;
    /*
        整理堆
     */
    compare_and_swap(copy, num / 2, num);
    int dest_pointer = 0;
    int copy_pointer = num - 1;
    if (copy_pointer == dest_pointer)
        return;
    do
    {
        //交换首尾
        int* head = &copy[0];
        int* tail = &copy[copy_pointer];
        *head ^= *tail;
        *tail ^= *head;
        *head ^= *tail;
        dest[dest_pointer++] = copy[copy_pointer];
        compare_and_swap(copy, copy_pointer / 2, copy_pointer);
        copy_pointer--;
        if (copy_pointer == 0)
            dest[num - 1] = copy[0];
    }while(copy_pointer > 0);
}

/**
    堆排序
 */
void heap_sort(int* dest,int num)
{
    if (num == 0)
        return;
    int* copy = (int*)malloc(sizeof(int) * num);
    //拷贝出副本
    memcpy(copy, dest, sizeof(int) * num);
    heap_sort0(dest,copy,num);
    free(copy);
}
