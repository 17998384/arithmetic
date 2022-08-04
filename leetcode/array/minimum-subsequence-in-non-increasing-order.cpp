//
// Created by 我叫城北徐公° on 2022/8/4.
//

#include <iostream>
#include <vector>

using namespace std;

static bool compare(int a, int b)
{
    return a > b;
}

class Solution
{
public:
    vector<int> minSubsequence(vector<int>& nums)
    {
        sort(nums.begin(), nums.end(), compare);
        vector<int> res;
        int sum = 0;
        int sum1 = 0;
        for (auto& n: nums) sum += n;
        for (int i = 0; i < nums.size(); i++)
        {
            int n = nums[i];
            sum1 += n;
            sum -= n;
            if (sum1 > sum)
            {
                for (int j = 0; j <= i; j++) res.push_back(nums[j]);
                return res;
            }
        }
        return res;
    }
};
