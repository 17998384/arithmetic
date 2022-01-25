//
// Created by 我叫城北徐公° on 2022/1/24.
//

//  215. 数组中的第K个最大元素

//  给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
//
//  请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//
//
//
//  示例 1:
//
//  输入: [3,2,1,5,6,4] 和 k = 2
//  输出: 5
//
//  示例 2:
//
//  输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//  输出: 4
//
//
//
//  提示：
//
//  1 <= k <= nums.length <= 104
//  -104 <= nums[i] <= 104


#define MINUS_ONE(x) (x - 1)

#include <stdio.h>

typedef struct heap_sort
{
    int* nums;
    int size;
} HeapSort;

static void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int pop_top(HeapSort* heapSort)
{
    int size = heapSort->size;
    if (size == 0) return 0;
    if (size == 1) return heapSort->nums[0];
    for (int ptr = size / 2; ptr > 0; ptr--)
    {
        int* a = &heapSort->nums[MINUS_ONE(ptr)];
        int* b;
        if (ptr * 2 + 1 <= size)
        {
            b = &heapSort->nums[MINUS_ONE(ptr * 2 + 1)];
            if (*a < *b) swap(a, b);
        }
        b = &heapSort->nums[MINUS_ONE(ptr * 2)];
        if (*a < *b) swap(a, b);
    }
    int res = heapSort->nums[0];
    swap(&heapSort->nums[0], &heapSort->nums[size - 1]);
    --heapSort->size;
    return res;
}

int find_kth_largest(int* nums, int numsSize, int k)
{
    int res = 0;
    HeapSort heapSort;
    heapSort.nums = nums;
    heapSort.size = numsSize;
    for (int i = 0; i < k; ++i) res = pop_top(&heapSort);
    return res;
}

