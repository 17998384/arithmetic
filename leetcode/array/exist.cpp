//
// Created by 我叫城北徐公° on 2021/8/29.
//

//  79. 单词搜索
//
//          给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
//
//  单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
//
//
//
//  示例 1：
//
//  输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
//  输出：true
//
//  示例 2：
//
//  输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
//  输出：true
//
//  示例 3：
//
//  输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
//  输出：false
//
//
//
//  提示：
//
//  m == board.length
//          n = board[i].length
//  1 <= m, n <= 6
//  1 <= word.length <= 15
//  board 和 word 仅由大小写英文字母组成
//
//
//
//  进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        bool exists = false;
        int rowMaxSize = board.size();
        int colMaxSize = board[0].size();
        cache = new bool* [rowMaxSize]();
        for (int i = 0, size = board.size(); i < size; i++) cache[i] = new bool[colMaxSize]();
        int strIdx = 0;
        for (int row = 0; row < rowMaxSize; row++)
        {
            for (int col = 0; col <= colMaxSize; col++)
            {
                strIdx = 0;
                recall(board, col, row, exists, word, strIdx);
                if (exists) break;
                exists = false;
            }
        }
        for (int i = 0, size = board.size(); i < size; i++) delete[] cache[i];
        delete[] cache;
        return exists;
    }

private:

    bool** cache;

    void recall(vector<vector<char>>& board, int col, int row, bool& exists, string& word, int& strIdx)
    {
        if (exists) return;
        if (strIdx >= word.length())
        {
            exists = true;
            return;
        }
        if (row >= board.size() || row < 0 || col < 0 || col >= board[0].size()) return;
        if (cache[row][col]) return;
        if (board[row][col] != word[strIdx]) return;
        cache[row][col] = true;
        strIdx++;
        recall(board, col + 1, row, exists, word, strIdx);
        recall(board, col, row - 1, exists, word, strIdx);
        recall(board, col, row + 1, exists, word, strIdx);
        recall(board, col - 1, row, exists, word, strIdx);
        cache[row][col] = false;
        strIdx--;
    }
};

int main_exist(void)
{
    Solution s;
    vector<vector<char>> board = {{'C', 'A', 'A'},
                                  {'A', 'A', 'A'},
                                  {'B', 'C', 'D'}};
    string str = "AAB";
    bool res = s.exist(board, str);
    cout << res << endl;
    return 0;
}