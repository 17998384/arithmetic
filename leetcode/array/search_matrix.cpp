//
// Created by 我叫城北徐公° on 2021/8/29.
//

//  74. 搜索二维矩阵
//
//          编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
//
//  每行中的整数从左到右按升序排列。
//  每行的第一个整数大于前一行的最后一个整数。
//
//
//
//  示例 1：
//
//  输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
//  输出：true
//
//  示例 2：
//
//  输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
//  输出：false
//
//
//
//  提示：
//
//  m == matrix.length
//          n == matrix[i].length
//  1 <= m, n <= 100
//  -104 <= matrix[i][j], target <= 104



#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        map<int, vector<int>*> map;
        for (vector<int>& item: matrix) map[item[0]] = &item;
        vector<int> keys;
        for (auto& entry: map) keys.push_back(entry.first);
        int find = dichotomy_scope(keys, target, 0, keys.size() - 1);
        if (find == -1) return false;
        vector<int>* findVector = map[find];
        return (find = dichotomy_scope(*findVector, target, 0, findVector->size() - 1)) != -1 && find == target;
    }

private:
    int dichotomy_scope(vector<int>& v, int target, int start, int end)
    {
        if (end < start) return -1;
        if (end == start && target >= v[start]) return v[start];
        int halfIdx = (start + end) / 2;
        if (target == v[halfIdx]) return v[halfIdx];
        if (target < v[halfIdx]) return dichotomy_scope(v, target, start, halfIdx - 1);
        else
        {
            if (end - halfIdx > 0 && target < v[halfIdx + 1]) return v[halfIdx];
            return dichotomy_scope(v, target, halfIdx + 1, end);
        }
    }
};
