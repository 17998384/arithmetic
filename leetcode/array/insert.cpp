//
// Created by 我叫城北徐公° on 2021/4/25.
//

//  57. 插入区间

//  给你一个 无重叠的 ，按照区间起始端点排序的区间列表。
//
//  在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
//
//
//
//  示例 1：
//
//  输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
//  输出：[[1,5],[6,9]]
//
//  示例 2：
//
//  输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
//  输出：[[1,2],[3,10],[12,16]]
//  解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
//
//  示例 3：
//
//  输入：intervals = [], newInterval = [5,7]
//  输出：[[5,7]]
//
//  示例 4：
//
//  输入：intervals = [[1,5]], newInterval = [2,3]
//  输出：[[1,5]]
//
//  示例 5：
//
//  输入：intervals = [[1,5]], newInterval = [2,7]
//  输出：[[1,7]]
//
//
//
//  提示：
//
//  0 <= intervals.length <= 104
//  intervals[i].length == 2
//  0 <= intervals[i][0] <= intervals[i][1] <= 105
//  intervals 根据 intervals[i][0] 按 升序 排列
//          newInterval.length == 2
//  0 <= newInterval[0] <= newInterval[1] <= 105

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        if (intervals.empty())
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        int x = newInterval[0];
        int y = newInterval[1];

        //x > intervals[max][1]
        if (x > intervals[intervals.size() - 1][1])
        {
            intervals.push_back(newInterval);
            return intervals;
        }

        //y < intervals[0][0]
        if (y < intervals[0][0])
        {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        vector<vector<int>> res;
        int compareIdx = 0, beforeIntervalsSize = intervals.size();
        for (int i = 0, size = intervals.size(); i < size; ++i)
        {
            if (x <= intervals[i][0])
            {
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }
        }
        if (beforeIntervalsSize == intervals.size()) intervals.push_back(newInterval);
        res.push_back(intervals[0]);
        for (int i = 1, size = intervals.size(); i < size; ++i)
        {
            vector<int>& waitCompare = intervals[i];
            vector<int>& compare = res[compareIdx];
            int min, max;
            if (waitCompare[0] > compare[1])
            {
                res.push_back(waitCompare);
            }
            else
            {
                min = std::min(compare[0], waitCompare[0]);
                max = std::max(compare[1], waitCompare[1]);
                compare[0] = min;
                compare[1] = max;
            }
            compareIdx = (int) res.size() - 1;
        }
        return res;
    }
};