//
// Created by 我叫城北徐公° on 2021/9/23.
//

//  188. 买卖股票的最佳时机 IV
//
//  给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
//
//  设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
//
//  注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//
//
//
//  示例 1：
//
//  输入：k = 2, prices = [2,4,1]
//  输出：2
//  解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
//
//  示例 2：
//
//  输入：k = 2, prices = [3,2,6,5,0,3]
//  输出：7
//  解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
//  随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
//
//
//
//  提示：
//
//  0 <= k <= 100
//  0 <= prices.length <= 1000
//  0 <= prices[i] <= 1000

#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int>& prices)
    {
        if (prices.size() == 0) return 0;
        int* dp = new int[k * 2 + 1];
        dp[0] = 0;
        for (int i = 1, size = 2 * k + 1; i < size; i++)
        {
            if (i % 2 != 0) dp[i] = -prices[0];
            else dp[i] = 0;
        }
        for (int i = 1, size = prices.size(); i < size; i++)
        {
            for (int j = 1, sizeJ = 2 * k + 1; j < sizeJ; j++)
            {
                dp[j] = max(dp[j - 1] - prices[i], dp[j]);
                j++;
                dp[j] = max(dp[j], dp[j - 1] + prices[i]);
            }
        }
        int max = 0;
        for (int i = 0, size = 2 * k + 1; i < size; i += 2) max = std::max(max, dp[i]);
        delete[] dp;
        return max;
    }
};
