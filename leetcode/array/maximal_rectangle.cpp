//
// Created by 我叫城北徐公° on 2021/9/10.
//

//  85. 最大矩形
//
//          给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
//
//
//
//  示例 1：
//
//  输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
//  输出：6
//  解释：最大矩形如上图所示。
//
//  示例 2：
//
//  输入：matrix = []
//  输出：0
//
//  示例 3：
//
//  输入：matrix = [["0"]]
//          输出：0
//
//  示例 4：
//
//  输入：matrix = [["1"]]
//          输出：1
//
//  示例 5：
//
//  输入：matrix = [["0","0"]]
//          输出：0
//
//
//
//  提示：
//
//  rows == matrix.length
//          cols == matrix[0].length
//  0 <= row, cols <= 200
//  matrix[i][j] 为 '0' 或 '1'



#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int area = 0;
        for (int i = 0, size = matrix.size(); i < size; ++i)
        {
            //将当前层的值计算
            if (i >= 1)
                for (int j = 0, jSize = matrix[i].size(); j < jSize; j++)
                {
                    matrix[0][j] += matrix[i][j] - '0';
                    if (matrix[i][j] == '0') matrix[0][j] = 0;
                }
            else for (char& j: matrix[0]) j -= '0';
            calcMaxArea(matrix[0], area);
        }
        return area;
    }

private:

    void calcMaxArea(vector<char>& matrix, int& area)
    {
        stack<pair<int, int>> stack;
        for (int i = 0, size = matrix.size(); i < size; ++i)
        {
            int height = i;
            while (!stack.empty() && stack.top().second > matrix[i])
            {
                pair<int, int>& p = stack.top();
                area = max((i - p.first) * p.second, area);
                height = p.first;
                stack.pop();
            }
            stack.push(pair<int, int>{height, matrix[i]});
        }
        int i = matrix.size();
        while (!stack.empty())
        {
            pair<int, int>& p = stack.top();
            area = max((i - p.first) * p.second, area);
            stack.pop();
        }
    }
};

int main_maximalRectangle(void)
{
//    vector<vector<char>> res = {{'1', '1', '1', '1', '0'},
//                                {'1', '1', '1', '1', '1'},
//                                {'1', '1', '1', '1', '1'},
//                                {'1', '0', '0', '1', '0'}};
    vector<vector<char>> res = {{'0', '1'},
                                {'1', '0'}};

    //[["0","1"],["1","0"]]
    Solution s;
    int area = s.maximalRectangle(res);
    cout << area << endl;
    return 0;
}