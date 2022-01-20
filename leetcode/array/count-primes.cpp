//
// Created by 我叫城北徐公° on 2021/10/22.
//

//  204. 计数质数
//
//          统计所有小于非负整数 n 的质数的数量。
//
//
//
//  示例 1：
//
//  输入：n = 10
//  输出：4
//  解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
//
//  示例 2：
//
//  输入：n = 0
//  输出：0
//
//  示例 3：
//
//  输入：n = 1
//  输出：0
//
//
//
//  提示：
//
//  0 <= n <= 5 * 106


#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        int count = 0;
        vector<int> isPrimeNumber(n, 1);
        for (int i = 2; i < n; i++)
        {
            if (isPrimeNumber[i])
            {
                count++;
                for (int j = 2, x = j * i; x < n; ++j, x = j * i) isPrimeNumber[x] = 0;
            }
        }
        return count;
    }
};