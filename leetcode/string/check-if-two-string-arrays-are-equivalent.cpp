//
// Created by 我叫城北徐公° on 2022/11/1.
//

//  1662. 检查两个字符串数组是否相等
//          给你两个字符串数组 word1 和 word2 。如果两个数组表示的字符串相同，返回 true ；否则，返回 false 。
//
//  数组表示的字符串 是由数组中的所有元素 按顺序 连接形成的字符串。
//
//
//
//  示例 1：
//
//  输入：word1 = ["ab", "c"], word2 = ["a", "bc"]
//  输出：true
//  解释：
//  word1 表示的字符串为 "ab" + "c" -> "abc"
//  word2 表示的字符串为 "a" + "bc" -> "abc"
//  两个字符串相同，返回 true
//  示例 2：
//
//  输入：word1 = ["a", "cb"], word2 = ["ab", "c"]
//  输出：false
//  示例 3：
//
//  输入：word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
//  输出：true
//
//
//  提示：
//
//  1 <= word1.length, word2.length <= 103
//  1 <= word1[i].length, word2[i].length <= 103
//  1 <= sum(word1[i].length), sum(word2[i].length) <= 103
//  word1[i] 和 word2[i] 由小写字母组成

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
    {
        if (word1.size() > 0 && word2.size() > 0 && word1[0][0] != word2[0][0]) return false;
        string s1;
        string s2;
        for (auto& s: word1) s1 += s;
        for (auto& s: word2) s2 += s;
        return s1 == s2;
    }
};