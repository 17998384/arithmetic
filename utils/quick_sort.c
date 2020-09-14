//
//  quick_sort.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/9/14.
//  Copyright © 2020 alex. All rights reserved.
//

#include "quick_sort.h"
#define LEFT 1
#define RIGHT 0

void quick_sort0(int* arr,int L,int R,int size)
{
    if (size <= 1)
        return;
    int L_BAK = L;
    int R_BAK = R;
    int target = RIGHT;
    int temp = *(arr + L);
    while (L != R)
    {
        switch (target)
        {
            case RIGHT:
                while (*(arr + R) >= temp && R > L) R--;
                *(arr + L) = *(arr + R);
                target = LEFT;
                break;
            case LEFT:
                while (*(arr + L) <= temp && L < R) L++;
                *(arr + R) = *(arr + L);
                target = RIGHT;
                break;
        }
    }
    *(arr + L) = temp;
    quick_sort0(arr, L_BAK, L - 1, L - L_BAK);
    quick_sort0(arr, R + 1, R_BAK, R_BAK - R);
}

void quick_sort(int* arr,int size)
{
    quick_sort0(arr, 0, size - 1, size);
}

int main(void)
{
//    int arr[] = {5,2,4,6,8,3,9,7};
    int arr[] = {-1,0,1,2,-1,-4};
    quick_sort(arr, 6);
    for (int i = 0,size = sizeof(arr)/sizeof(int); i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
