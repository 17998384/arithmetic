//
//  is_valid_sudoku.c
//  arithmetic

//  36.有效的数独

//  判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

//  数字 1-9 在每一行只能出现一次。
//  数字 1-9 在每一列只能出现一次。
//  数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

//  数独部分空格内已填入了数字，空白格用 '.' 表示。
//
//  示例 1:
//
//  输入:
//  [
//    ["5","3",".",".","7",".",".",".","."],
//    ["6",".",".","1","9","5",".",".","."],
//    [".","9","8",".",".",".",".","6","."],
//    ["8",".",".",".","6",".",".",".","3"],
//    ["4",".",".","8",".","3",".",".","1"],
//    ["7",".",".",".","2",".",".",".","6"],
//    [".","6",".",".",".",".","2","8","."],
//    [".",".",".","4","1","9",".",".","5"],
//    [".",".",".",".","8",".",".","7","9"]
//  ]
//  输出: true
//
//  示例 2:
//
//  输入:
//  [
//    ["8","3",".",".","7",".",".",".","."],
//    ["6",".",".","1","9","5",".",".","."],
//    [".","9","8",".",".",".",".","6","."],
//    ["8",".",".",".","6",".",".",".","3"],
//    ["4",".",".","8",".","3",".",".","1"],
//    ["7",".",".",".","2",".",".",".","6"],
//    [".","6",".",".",".",".","2","8","."],
//    [".",".",".","4","1","9",".",".","5"],
//    [".",".",".",".","8",".",".","7","9"]
//  ]
//  输出: false
//  解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
//       但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。


//  Created by 我叫城北徐公° on 2020/10/28.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    //创建三个map用以表示行，列，3x3的格子总数
    //行
    int row_arr[10] = {0};
    //列
    int col_arr[10] = {0};
    //3x3
    int three_arr[10] = {0};
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            //测试竖排
            if (j == 0)
            {
                for (int x = 0; x < 9; x++)
                {
                    if (board[x][i] == '.')
                        continue;
                    if (col_arr[board[x][i] - 48] != 0)
                        return 0;
                    col_arr[board[x][i] - 48] = 1;
                }
                memset(col_arr,0,sizeof(int) * 10);
            }
            //测试横排
            if (i == 0)
            {
                for (int y = 0; y < 9; y++)
                {
                    if (board[j][y] == '.')
                        continue;
                    if (row_arr[board[j][y] - 48] != 0)
                        return 0;
                    row_arr[board[j][y] - 48] = 1;
                }
                memset(row_arr,0,sizeof(int) * 10);
            }
            //测试3x3
            if (i % 3 == 0 && j % 3 == 0)
            {
                for (int k = i,k_size = i + 3; k < k_size; k++)
                {
                    for (int v = j,j_size = j + 3; v < j_size; v++)
                    {
                        if (board[k][v] == '.')
                            continue;
                        if (three_arr[board[k][v] - 48] != 0)
                            return 0;
                        three_arr[board[k][v] - 48] = 1;
                    }
                }
                memset(three_arr, 0, sizeof(int) * 10);
            }
        }
    }
    return 1;
}

int main_is_valid_sudoku(void)
{
    char** example = (char**)malloc(sizeof(char*) * 9);
    example[0] = "....5..1.";
    example[1] = ".4.3.....";
    example[2] = ".....3..1";
    example[3] = "8......2.";
    example[4] = "..2.7....";
    example[5] = ".15......";
    example[6] = ".....2...";
    example[7] = ".2.9.....";
    example[8] = "..4......";
    int result = isValidSudoku(example, 9, NULL);
    printf("%d ",result);
    return 0;
}
