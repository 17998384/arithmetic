//
// Created by 我叫城北徐公° on 2022/6/23.
//

//  289. 生命游戏
//
//          根据 百度百科 ， 生命游戏 ，简称为 生命 ，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。
//
//  给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态： 1 即为 活细胞 （live），或 0 即为 死细胞 （dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
//
//  如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
//  如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
//  如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
//  如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
//
//  下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。给你 m x n 网格面板 board 的当前状态，返回下一个状态。
//
//
//
//  示例 1：
//
//  输入：board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
//  输出：[[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
//
//  示例 2：
//
//  输入：board = [[1,1],[1,0]]
//  输出：[[1,1],[1,1]]
//
//
//
//  提示：
//
//  m == board.length
//          n == board[i].length
//  1 <= m, n <= 25
//  board[i][j] 为 0 或 1
//
//
//
//  进阶：
//
//  你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
//  本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？


#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int rowSize = board.size();
        int colSize = board[0].size();
        vector<vector<int>> copy(rowSize);
        for (int i = 0; i < rowSize; i++)
        {
            copy[i].resize(colSize);
            std::copy(board[i].begin(), board[i].end(), copy[i].begin());
        }
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                int liveNum = this->verify_live_num(copy, i, j, rowSize, colSize);
                if (copy[i][j] != 0)
                {
                    if (liveNum < 2) board[i][j] = 0;
                    else if (liveNum > 3) board[i][j] = 0;
                    else;
                }
                else
                {
                    if (liveNum == 3) board[i][j] = 1;
                }
            }
        }
    }

private:

    int verify_live_num(vector<vector<int>>& board, int curRow, int curCol, int rowSize, int colSize)
    {
        /*
         * 八个方位
         */
        int num = 0;
        //左上方
        if (curRow - 1 >= 0 && curCol - 1 >= 0 && board[curRow - 1][curCol - 1] != 0) num++;
        //上方
        if (curRow - 1 >= 0 && board[curRow - 1][curCol] != 0) num++;
        //右上方
        if (curRow - 1 >= 0 && curCol + 1 < colSize && board[curRow - 1][curCol + 1] != 0) num++;
        //左边
        if (curCol - 1 >= 0 && board[curRow][curCol - 1] != 0) num++;
        //右边
        if (curCol + 1 < colSize && board[curRow][curCol + 1] != 0) num++;
        //左下方
        if (curRow + 1 < rowSize && curCol - 1 >= 0 && board[curRow + 1][curCol - 1] != 0) num++;
        //下方
        if (curRow + 1 < rowSize && board[curRow + 1][curCol] != 0) num++;
        //右下方
        if (curRow + 1 < rowSize && curCol + 1 < colSize && board[curRow + 1][curCol + 1] != 0) num++;
        return num;
    }
};

int main_game_of_life(void)
{
    Solution s;
    vector<vector<int>> res = {{1, 1},
                               {1, 0}};
    s.gameOfLife(res);
    return 0;
}