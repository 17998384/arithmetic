//
// Created by 我叫城北徐公° on 2021/9/23.
//

//  130. 被围绕的区域
//          给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
//
//
//
//  示例 1：
//
//  输入：board =[
//  ["X","X","X","X"],
//  ["X","O","O","X"],
//  ["X","X","O","X"],
//  ["X","O","X","X"]]
//  输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
//  解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
//
//  示例 2：
//
//  输入：board = [["X"]]
//          输出：[["X"]]
//
//
//
//  提示：
//
//  m == board.length
//          n == board[i].length
//  1 <= m, n <= 200
//  board[i][j] 为 'X' 或 'O'


#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void solve(vector<vector<char>>& board)
    {
        if (board.size() <= 2) return;
        int rowSize = board.size();
        int colSize = board[0].size();
        for (int i = 0; i < colSize; i++)
        {
            if (board[0][i] == 'O')
            {
                board[0][i] = '0';
                dfs(board, 0 + 1, i, 2);
            }
            if (board[rowSize - 1][i] == 'O')
            {
                board[rowSize - 1][i] = '0';
                dfs(board, rowSize - 2, i, 0);
            }
        }
        for (int i = 0; i < rowSize; i++)
        {
            if (board[i][0] == 'O')
            {
                board[i][0] = '0';
                dfs(board, i, 0 + 1, 3);
            }
            if (board[i][colSize - 1] == 'O')
            {
                board[i][colSize - 1] = '0';
                dfs(board, i, colSize - 2, 1);
            }
        }
        for (auto& v: board)
        {
            for (auto& num: v)
            {
                if (num == '0') num = 'O';
                else num = 'X';
            }
        }
    }

private:

    void dfs(vector<vector<char>>& board, int row, int col, int direction)
    {
        if (row >= board.size() - 1 || row < 1 || col >= board[0].size() - 1 || col < 1 || board[row][col] == 'X' ||
            board[row][col] == '0')
            return;
        board[row][col] = '0';
        if (direction != 2) dfs(board, row - 1, col, 0);
        if (direction != 3) dfs(board, row, col - 1, 1);
        if (direction != 0) dfs(board, row + 1, col, 2);
        if (direction != 1) dfs(board, row, col + 1, 3);
    }
};

