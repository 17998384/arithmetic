//
// Created by 我叫城北徐公° on 2021/4/23.
//

//  56. 合并区间
//
//  以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
//
//
//
//  示例 1：
//
//  输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
//  输出：[[1,6],[8,10],[15,18]]
//  解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
//
//  示例 2：
//
//  输入：intervals = [[1,4],[4,5]]
//  输出：[[1,5]]
//  解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
//
//
//
//  提示：
//
//  1 <= intervals.length <= 104
//  intervals[i].length == 2
//  0 <= starti <= endi <= 104
//
//
#include <iostream>
#include <vector>

using namespace std;

static bool compare(const vector<int>& v1, const vector<int>& v2)
{
    return v1[0] < v2[0];
}

class Solution
{
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), compare);
//        for (auto& v : intervals) cout << v[0] << " " << v[1] << endl;
        //将0号放入
        res.push_back(intervals[0]);
        if (intervals.size() == 1) return res;
        int compareIdx = 0;
        for (int i = 1, size = intervals.size(); i < size; i++)
        {
            //([0] -> x,[1] -> y)
            vector<int>& compare = res[compareIdx];
            //([0] -> x1,[1] -> y1)
            vector<int>& waitCompare = intervals[i];
            //拆分
            if (waitCompare[0] > compare[1])
            {
                res.push_back(waitCompare);
            }
            else
            {
                compare[0] = min(compare[0], waitCompare[0]);
                compare[1] = max(compare[1], waitCompare[1]);
            }
            compareIdx = (int) res.size() - 1;
        }
        return res;
    }
};