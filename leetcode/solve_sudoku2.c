//
//  solve_sudoku4.c
//  arithmetic
//
//  编写一个程序，通过填充空格来解决数独问题。
//
//  一个数独的解法需遵循如下规则：
//
//      数字 1-9 在每一行只能出现一次。
//      数字 1-9 在每一列只能出现一次。
//      数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

//  ["5","3",".",".","7",".",".",".","."],
//  ["6",".",".","1","9","5",".",".","."],
//  [".","9","8",".",".",".",".","6","."],
//  ["8",".",".",".","6",".",".",".","3"],
//  ["4",".",".","8",".","3",".",".","1"],
//  ["7",".",".",".","2",".",".",".","6"],
//  [".","6",".",".",".",".","2","8","."],
//  [".",".",".","4","1","9",".",".","5"],
//  [".",".",".",".","8",".",".","7","9"]
//
//  空白格用 '.' 表示。


//  Created by 我叫城北徐公° on 2020/11/1.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int row_arr[9][9];
int col_arr[9][9];
int soduko_arr[3][3][9];
char* p[81];

static void DFS(char** board,int index,int* flag)
{
    if (index == 81)
    {
        *flag = 1;
        return;
    }
    if (*p[index] != '.')
        DFS(board, index + 1,flag);
    else
    {
        for (int i = 0; i < 9; i++)
        {
            if(!row_arr[index / 9][i] && !col_arr[index % 9][i] && !soduko_arr[index / 9 / 3][index % 9 / 3][i])
            {
                row_arr[index / 9][i] = col_arr[index % 9][i] = soduko_arr[index / 9 / 3][index % 9 / 3][i] = 1;
                *p[index] = i + 48 + 1;
                DFS(board, index + 1,flag);
                if (*flag)
                    break;
                row_arr[index / 9][i] = col_arr[index % 9][i] = soduko_arr[index / 9 / 3][index % 9 / 3][i] = 0;
                *p[index] = '.';
            }
        }
    }
}

void solveSudoku2(char** board, int boardSize, int* boardColSize)
{
    memset(row_arr, 0, sizeof(row_arr));
    memset(col_arr, 0, sizeof(col_arr));
    memset(soduko_arr, 0, sizeof(soduko_arr));
    memset(p, 0, sizeof(p));
    int count = 0;
    int index = 0;
    //prepare
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            p[count++] = &(board[i][j]);
            if (board[i][j] != '.')
            {
                index = board[i][j] - 48 - 1;
                row_arr[i][index] = col_arr[j][index] = soduko_arr[i / 3][j / 3][index] = 1;
            }
        }
    }
    int flag = 0;
    DFS(board,0,&flag);
}

int main_solveSudoku2(void)
{
    char** example = (char**)malloc(sizeof(char*) * 9);
    for (int i = 0; i < 9; i++)
    {
        example[i] = (char*)malloc(sizeof(char) * 10);
    }
    strcpy(example[0], "53..7....");
    strcpy(example[1], "6..195...");
    strcpy(example[2], ".98....6.");
    strcpy(example[3], "8...6...3");
    strcpy(example[4], "4..8.3..1");
    strcpy(example[5], "7...2...6");
    strcpy(example[6], ".6....28.");
    strcpy(example[7], "...419..5");
    strcpy(example[8], "....8..79");
    solveSudoku2(example, 9, NULL);
    for (int i = 0; i < 9; i++)
    {
        printf("%s\n",example[i]);
        free(example[i]);
    }
    free(example);
    return 0;
}
