//
//  min_distance.c
//  arithmetic
//
//  72.编辑距离
//
//  给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
//
//  你可以对一个单词进行如下三种操作：
//
//      插入一个字符
//      删除一个字符
//      替换一个字符
//
//
//
//  示例 1：
//
//  输入：word1 = "horse", word2 = "ros"
//  输出：3
//  解释：
//  horse -> rorse (将 'h' 替换为 'r')
//  rorse -> rose (删除 'r')
//  rose -> ros (删除 'e')
    
//  Created by 我叫城北徐公° on 2020/12/15.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MIN(x,y) (x) > (y) ? (y) : (x)

int minDistance(char * word1, char * word2)
{
    int word1_len = (int)strlen(word1);
    int word2_len = (int)strlen(word2);
    int dp[word1_len + 1][word2_len + 1];
    dp[0][0] = 0;
    for (int i = 1; i <= word1_len; ++i) dp[i][0] = i;
    for (int i = 1; i <= word2_len; ++i) dp[0][i] = i;
    for (int i = 1; i <= word1_len; ++i)
    {
        for (int j = 1; j <= word2_len; ++j)
        {
            if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = (MIN(MIN(dp[i - 1][j],dp[i][j - 1]),dp[i - 1][j - 1])) + 1;
        }
    }
    return dp[word1_len][word2_len];
}

int main_minDistance(void)
{
    int move = minDistance("horse","ros");
    printf("%d\n", move);
    return 0;
}
