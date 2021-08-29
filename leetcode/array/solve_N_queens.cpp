//
// Created by 我叫城北徐公° on 2021/8/29.
//

//  51. N 皇后
//
//  n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
//
//  给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
//
//  每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
//
//
//
//  示例 1：
//
//  输入：n = 4
//  输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//  解释：如上图所示，4 皇后问题存在两个不同的解法。
//
//  示例 2：
//
//  输入：n = 1
//  输出：[["Q"]]
//
//
//
//  提示：
//
//  1 <= n <= 9
//  皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。


#include <string>
#include <vector>

using namespace std;

class Solution
{
public:

    vector<vector<string>> solveNQueens(int n)
    {
        rowCache = new bool[n]();
        colCache = new bool[n]();
        cache = new bool* [n]();
        for (int i = 0; i < n; i++) cache[i] = new bool[n]();
        vector<vector<string>> res;
        recall(res, n, 0);
        delete[] rowCache;
        delete[] colCache;
        for (int i = 0; i < n; i++) delete[] cache[i];
        delete[] cache;
        return res;
    }

private:

    bool* rowCache;
    bool* colCache;
    bool** cache;

    bool check(int row, int col, int n)
    {
        if (rowCache[row] || colCache[col]) return true;
        //找两条斜线是否已有元素
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) if (cache[i][j]) return true;
        for (int i = row, j = col; i < n && j < n; i++, j++) if (cache[i][j]) return true;
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) if (cache[i][j]) return true;
        for (int i = row, j = col; i < n && j >= 0; i++, j--) if (cache[i][j]) return true;
        return false;
    }

    void recall(vector<vector<string>>& res, int n, int cur)
    {
        if (cur == n)
        {
            vector<string> v;
            v.resize(n);
            for (int i = 0; i < n; i++)
            {
                char arr[n + 1];
                for (int j = 0; j < n; j++)
                {
                    if (cache[i][j]) arr[j] = 'Q';
                    else arr[j] = '.';
                }
                arr[n] = '\0';
                v[i] = string(arr);
            }
            res.push_back(v);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (check(cur, i, n)) continue;
            rowCache[cur] = true;
            colCache[i] = true;
            cache[cur][i] = true;
            recall(res, n, cur + 1);
            rowCache[cur] = false;
            colCache[i] = false;
            cache[cur][i] = false;
        }
    }
};
