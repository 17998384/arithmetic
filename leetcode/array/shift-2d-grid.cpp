//
// Created by 我叫城北徐公° on 2022/7/20.
//

//  1260. 二维网格迁移
//
//          给你一个 m 行 n 列的二维网格 grid 和一个整数 k。你需要将 grid 迁移 k 次。
//
//  每次「迁移」操作将会引发下述活动：
//
//  位于 grid[i][j] 的元素将会移动到 grid[i][j + 1]。
//  位于 grid[i][n - 1] 的元素将会移动到 grid[i + 1][0]。
//  位于 grid[m - 1][n - 1] 的元素将会移动到 grid[0][0]。
//
//  请你返回 k 次迁移操作后最终得到的 二维网格。
//
//
//
//  示例 1：
//
//  输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
//  输出：[[9,1,2],[3,4,5],[6,7,8]]
//
//  示例 2：
//
//  输入：grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
//  输出：[[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
//
//  示例 3：
//
//  输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
//  输出：[[1,2,3],[4,5,6],[7,8,9]]
//
//
//
//  提示：
//
//  m == grid.length
//          n == grid[i].length
//  1 <= m <= 50
//  1 <= n <= 50
//  -1000 <= grid[i][j] <= 1000
//  0 <= k <= 100


#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        int rowSize = grid.size();
        int colSize = grid[0].size();

        k = k % (rowSize * colSize);

        int moveRow = k / colSize;
        int moveCol = k % colSize;

        vector<vector<int>> res(rowSize);
        for (auto& r: res) r = vector<int>(colSize);

        for (auto& i: grid)
        {
            for (auto& j: i)
            {
                res[moveRow][moveCol++] = j;
                if (moveCol >= colSize)
                {
                    moveCol = 0;
                    moveRow++;
                }
                if (moveRow >= rowSize) moveRow = 0;
            }
        }
        return res;
    }
};

//int main(void)
//{
//    vector<vector<int>> r = {{1, 2},
//                             {3, 4}};
//    Solution s;
//    vector<vector<int>> res = s.shiftGrid(r, 2);
//    for (auto& r: res)
//    {
//        for (auto& n: r)
//        {
//            cout << n << endl;
//        }
//    }
//    return 0;
//}