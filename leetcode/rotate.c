//
//  rotate.c
//  arithmetic
//
//  48.旋转图像

//  给定一个 n × n 的二维矩阵表示一个图像。
//
//  将图像顺时针旋转 90 度。
//
//  说明：
//
//  你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
//
//  示例 1:
//
//  给定 matrix =
//  [
//    [1,2,3],
//    [4,5,6],
//    [7,8,9]
//  ],
//
//  原地旋转输入矩阵，使其变为:
//  [
//    [7,4,1],
//    [8,5,2],
//    [9,6,3]
//  ]
//
//  示例 2:
//
//  给定 matrix =
//  [
//    [ 5, 1, 9,11],
//    [ 2, 4, 8,10],
//    [13, 3, 6, 7],
//    [15,14,12,16]
//  ],
//
//  原地旋转输入矩阵，使其变为:
//  [
//    [15,13, 2, 5],
//    [14, 3, 4, 1],
//    [12, 6, 8, 9],
//    [16, 7,10,11]
//  ]


//  Created by 我叫城北徐公° on 2020/11/20.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

static void swap(int* a,int* b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    //[0][0] - [matrixSize - 1][matrixSize - 1]对角线交换
    for (int x = 0; x < matrixSize; x++)
    {
        for (int y = 0; y < matrixSize; y++)
        {
            if (x <= y)
                continue;
            swap(&matrix[x][y], &matrix[y][x]);
        }
    }
    //左右交换
    int half = matrixSize / 2;
    for (int x = 0; x < matrixSize; x++)
    {
        for (int y = 0; y < half; y++)
        {
            swap(&matrix[x][y], &matrix[x][matrixSize - 1 - y]);
        }
    }
//    for (int x = 0; x < matrixSize; x++)
//    {
//        for (int y = 0; y < matrixSize; y++)
//        {
//            printf("%d ",matrix[x][y]);
//        }
//        printf("\n");
//    }
}

int main_rotate(void)
{
    int size = 4;
    int count = 1;
    int** arr = (int**)malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = (int*)malloc(sizeof(int*) * size);
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = count++;
        }
    }
    rotate(arr, size, NULL);
    return 0;
}
