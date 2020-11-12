//
//  solve_sudoku.c
//  arithmetic

//  37.解数独
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

//  Created by 我叫城北徐公° on 2020/10/28.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char** board,int row,int col,int target)
{
    if (board[row][col] != '.')
        return 1;
    //检查横纵是否有重叠
    for (int i = 0; i < 9; i++)
    {
        if(board[row][i] == target || board[i][col] == target)
            return 0;
    }
    //当前横纵的3x3开头
    int col_s = (col / 3) * 3;
    int row_s = (row / 3) * 3;
    //检查当前3x3是否重叠
    for (int i = row_s,row_s_size = row_s + 3; i < row_s_size; i++)
        for (int j = col_s,col_s_size = col_s + 3; j < col_s_size ; j++)
            if (board[i][j] == target)
                return 0;
    board[row][col] = target;
    return 1;
}

/*
    获取下一个可用的数字
 */
int get_free_num(char** board,char** board_copy,int row,int col,char*** cache_arr)
{
    //当前坐标缓存
    char* current_coordinate_cache = cache_arr[row][col];
    int return_num = -1;
    for (int i = 0; i < 9; i++)
    {
        if (current_coordinate_cache[i] == 0)
        {
            return_num = i + 48 + 1;
            if (board[row][col] != '.' && board[row][col] == return_num)
                continue;
            else
            {
                current_coordinate_cache[i] = 1;
                break;
            }
        }
    }
    //如果到这步了，将下一步的缓存提前设置好（需小于8）
    return return_num;
}

/*
    还原缓存
 */
void restore_coordinate_cache(int row,int col,char*** cache_arr,char*** cache_arr_restore)
{
    //当前坐标缓存
    char* current_coordinate_cache = cache_arr[row][col];
    //当前坐标待还原缓存
    char* current_coordinate_restore_cache = cache_arr_restore[row][col];
    //还原缓存
    for (int i = 0; i < 9; i++)
    {
        current_coordinate_cache[i] = current_coordinate_restore_cache[i];
    }
}

/*
    初始化缓存
 */
void prepare_cache(char** board,char*** cache_arr,char*** cache_arr_restore,char** board_copy)
{
    //在坐标中去定位该坐标下可用的元素
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                int row = i;
                int col = j;
                //检查横纵是否有重叠
                for (int k = 0; k < 9; k++)
                {
                    //先看横排
                    if(board[row][k] != '.')
                        cache_arr[row][col][board[row][k] - 48 - 1] = 1;
                    //再看竖排
                    if (board[k][col] != '.')
                        cache_arr[row][col][board[k][col] - 48 - 1] = 1;
                }
                //当前横纵的3x3开头
                int col_s = (col / 3) * 3;
                int row_s = (row / 3) * 3;
                //检查当前3x3是否重叠
                for (int i = row_s,row_s_size = row_s + 3; i < row_s_size; i++)
                    for (int j = col_s,col_s_size = col_s + 3; j < col_s_size ; j++)
                        if (board[i][j] != '.')
                            cache_arr[row][col][board[i][j] - 48 - 1] = 1;
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        memcpy(board_copy[i], board[i], sizeof(char) * 9);
        for (int j = 0; j < 9; j++)
            memcpy(cache_arr_restore[i][j], cache_arr[i][j], sizeof(char) * 9);
    }
}

void solve_sudoku0(char** board,int row,int col,int* flag,char*** cache_arr,char*** cache_arr_restore,
                   char** board_copy)
{
    if (row == 9)
    {
        *flag = 1;
        return;
    }
    while (1)
    {
        if (*flag)
            break;
        if (board_copy[row][col] != '.')
            goto recursion_next;
        int num = get_free_num(board,board_copy, row, col,cache_arr);
        if (num == -1)
        {
            restore_coordinate_cache(row, col,cache_arr,cache_arr_restore);
            while(row >= 0)
            {
                if(row == 0 && col == 0)
                {
                    solve_sudoku0(board, row, col,flag,cache_arr,cache_arr_restore,board_copy);
                }
                if (col == 0)
                {
                    row--;
                    col = 8;
                }
                else
                    col--;
                if (board_copy[row][col] != '.')
                    continue;
                break;
            }
            board[row][col] = '.';
            solve_sudoku0(board, row, col,flag,cache_arr,cache_arr_restore,board_copy);
        }
        if(!check(board, row, col, num))
        {
            board[row][col] = '.';
            solve_sudoku0(board, row, col,flag,cache_arr,cache_arr_restore,board_copy);
        }
        else
            goto recursion_next;
    recursion_next:
        if (col == 8)
            solve_sudoku0(board, row + 1, 0,flag,cache_arr,cache_arr_restore,board_copy);
        else
            solve_sudoku0(board, row, col + 1,flag,cache_arr,cache_arr_restore,board_copy);
    }
}

void solveSudoku(char** board, int boardSize, int* boardColSize)
{
    //定义三维数组用作缓存
    char*** cache_arr = (char***)calloc(sizeof(char**), 9);
    //定义三维数组作为还原缓存
    char*** cache_arr_restore = (char***)calloc(sizeof(char**), 9);
    //board_copy
    char** board_copy = (char**)calloc(sizeof(char*),9);
    for (int i = 0 ; i < 9 ; i++)
    {
        cache_arr[i] = (char**)calloc(sizeof(char*),9);
        cache_arr_restore[i] = (char**)calloc(sizeof(char*),9);
        board_copy[i] = (char*)calloc(sizeof(char), 9);
        for (int j = 0; j < 9; j++)
        {
            cache_arr[i][j] = (char*)calloc(sizeof(char), 9);
            cache_arr_restore[i][j] = (char*)calloc(sizeof(char), 9);
        }
    }
    prepare_cache(board,cache_arr,cache_arr_restore,board_copy);
    int flag = 0;
    solve_sudoku0(board,0,0,&flag,cache_arr,cache_arr_restore,board_copy);
}

int main_solveSudoku(void)
{
    
    char** example = (char**)malloc(sizeof(char*) * 9);
    for (int i = 0; i < 9; i++)
    {
        example[i] = (char*)malloc(sizeof(char) * 10);
    }
    strcpy(example[0], "..9748...");
    strcpy(example[1], "7........");
    strcpy(example[2], ".2.1.9...");
    strcpy(example[3], "..7...24.");
    strcpy(example[4], ".64.1.59.");
    strcpy(example[5], ".98...3..");
    strcpy(example[6], "...8.3.2.");
    strcpy(example[7], "........6");
    strcpy(example[8], "...2759..");
    solveSudoku(example, 9, NULL);
    for (int i = 0; i < 9; i++)
    {
        printf("%s\n",example[i]);
        free(example[i]);
    }
    free(example);
    return 0;
}
