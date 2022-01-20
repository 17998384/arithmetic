//
// Created by 我叫城北徐公° on 2021/10/22.
//

//  200. 岛屿数量
//
//          给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
//
//  岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
//
//  此外，你可以假设该网格的四条边均被水包围。
//
//
//
//  示例 1：
//
//  输入：grid = [
//  ['1','1','1','1','0'],
//  ['1','1','0','1','0'],
//  ['1','1','0','0','0'],
//  ['0','0','0','0','0']
//  ]
//  输出：1
//
//  示例 2：
//
//  输入：grid = [
//  ['1','1','0','0','0'],
//  ['1','1','0','0','0'],
//  ['0','0','1','0','0'],
//  ['0','0','0','1','1']
//  ]
//  输出：3
//
//
//
//  提示：
//
//  m == grid.length
//          n == grid[i].length
//  1 <= m, n <= 300
//  grid[i][j] 的值为 '0' 或 '1'

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int count = 0;
        for (int i = 0, size = grid.size(); i < size; i++)
        {
            for (int j = 0, jSize = grid[i].size(); j < jSize; j++)
            {
                if (grid[i][j] == 'X' || grid[i][j] == '0') continue;
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j, 2);
                }
            }
        }
        return count;
    }

private:

    void dfs(vector<vector<char>>& grid, int row, int col, int direction)
    {
        if (row >= grid.size() || row < 0 || col >= grid[0].size() || col < 0 || grid[row][col] == '0' ||
            grid[row][col] == 'X')
            return;
        grid[row][col] = 'X';
        if (direction != 2) dfs(grid, row - 1, col, 0);
        if (direction != 3) dfs(grid, row, col - 1, 1);
        if (direction != 0) dfs(grid, row + 1, col, 2);
        if (direction != 1) dfs(grid, row, col + 1, 3);
    }
};

