//
// Created by 我叫城北徐公° on 2022/2/7.
//

//  240. 搜索二维矩阵 II
//
//  编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
//
//  每行的元素从左到右升序排列。
//  每列的元素从上到下升序排列。
//
//
//
//  示例 1：
//
//  输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
//  输出：true
//
//  示例 2：
//
//  输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
//  输出：false
//
//
//
//  提示：
//
//  m == matrix.length
//          n == matrix[i].length
//  1 <= n, m <= 300
//  -109 <= matrix[i][j] <= 109
//  每行的所有元素从左到右升序排列
//          每列的所有元素从上到下升序排列
//  -109 <= target <= 109



#include <iostream>
#include <vector>

using namespace std;

//class Solution
//{
//public:
//
//    bool searchMatrix(vector<vector<int>>& matrix, int target)
//    {
//        for (auto& m: matrix)
//        {
//            if (m[0] > target) return false;
//            int idx = dichotomy(m.data(), 0, m.size() - 1, target);
//            if (idx != -1) return true;
//        }
//        return false;
//    }
//
//private:
//
//    int dichotomy(int* arr, int begin, int end, int target)
//    {
//        if (begin > end) return -1;
//        int half = (begin + end) / 2;
//        if (target > arr[half]) return dichotomy(arr, half + 1, end, target);
//        else if (target < arr[half]) return dichotomy(arr, begin, half - 1, target);
//        else return half;
//    }
//};

class Solution
{
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int x = 0, y = matrix[0].size() - 1;
        while (x < matrix.size() && y >= 0)
        {
            if (target > matrix[x][y]) x++;
            else if (matrix[x][y] == target) return true;
            else y--;
        }
        return false;
    }

};

//int main(void)
//{
//    vector<vector<int>> v = {{1,  3,  5,  7,  9},
//                             {2,  4,  6,  8,  10},
//                             {11, 13, 15, 17, 19},
//                             {12, 14, 16, 18, 20},
//                             {21, 22, 23, 24, 25}};
//    Solution s;
//    bool res = s.searchMatrix(v, 13);
//    cout << res << endl;
//    return 0;
//}
