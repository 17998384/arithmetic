//
// Created by 我叫城北徐公° on 2021/9/9.
//

//  84. 柱状图中最大的矩形
//
//          给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
//
//  求在该柱状图中，能够勾勒出来的矩形的最大面积。
//
//
//
//  示例 1:
//
//  输入：heights = [2,1,5,6,2,3]
//  输出：10
//  解释：最大的矩形为图中红色区域，面积为 10
//
//  示例 2：
//
//  输入： heights = [2,4]
//  输出： 4
//
//
//
//  提示：
//
//  1 <= heights.length <=105
//  0 <= heights[i] <= 104


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        //单调栈
        stack<pair<int, int>> stack;
        int area = 0;
        for (int i = 0, size = heights.size(); i < size; i++)
        {
            int height = i;
            while (!stack.empty() && stack.top().second > heights[i])
            {
                pair<int, int>& top = stack.top();
                height = top.first;
                area = max(top.second * (i - height), area);
                stack.pop();
            }
            stack.push(pair<int, int>{height, heights[i]});
        }
        int i = heights.size();
        while (!stack.empty())
        {
            pair<int, int>& top = stack.top();
            int height = top.first;
            area = max(top.second * (i - height), area);
            stack.pop();
        }
        return area;
    }
};

int main_largestRectangleArea(void)
{
    stack<int> stack;
    vector<int> nums = {0, 2, 2, 2, 1, 4, 8, 8};
    Solution s;
    int area = s.largestRectangleArea(nums);
    cout << area << endl;
    return 0;
}