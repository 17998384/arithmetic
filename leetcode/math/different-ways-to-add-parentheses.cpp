//
// Created by 我叫城北徐公° on 2022/7/1.
//

//  241. 为运算表达式设计优先级
//
//          给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 按任意顺序 返回答案。
//
//  生成的测试用例满足其对应输出值符合 32 位整数范围，不同结果的数量不超过 104 。
//
//
//
//  示例 1：
//
//  输入：expression = "2-1-1"
//  输出：[0,2]
//  解释：
//  ((2-1)-1) = 0
//  (2-(1-1)) = 2
//
//  示例 2：
//
//  输入：expression = "2*3-4*5"
//  输出：[-34,-14,-10,-10,10]
//  解释：
//  (2*(3-(4*5))) = -34 true
//  (((2*3)-4)*5) = 10  true

//  ((2*3)-(4*5)) = -14 true

//  (2*((3-4)*5)) = -10 true
//  ((2*(3-4))*5) = -10
//
//
//
//  提示：
//
//  1 <= expression.length <= 20
//  expression 由数字和算符 '+'、'-' 和 '*' 组成。
//  输入表达式中的所有整数值在范围 [0, 99]

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> nums;
        vector<char> symbols;

        int tmpNum = 0;
        bool modifyNum = false;
        for (char c: expression)
        {
            if (c >= '0' && c <= '9')
            {
                tmpNum = tmpNum * 10 + (c - 48);
                modifyNum = true;
            }
            else
            {
                if (modifyNum)
                {
                    nums.push_back(tmpNum);
                    tmpNum = 0;
                    modifyNum = false;
                }
                symbols.push_back(c);
            }
        }
        if (modifyNum) nums.push_back(tmpNum);
        vector<int> res = this->dfs(nums, symbols, 0, nums.size() - 1);
        return res;
    }

private:

    vector<int> dfs(vector<int>& nums, vector<char>& symbols, int start, int end)
    {
        //终止条件
        if (start >= end)
        {
            vector<int> v;
            v.push_back(nums[start]);
            return v;
        }

        vector<int> res;
        for (int i = start; i < end; i++)
        {
            vector<int> left = dfs(nums, symbols, start, i);
            vector<int> right = dfs(nums, symbols, i + 1, end);
            char symbol = symbols[i];
            for (auto& l: left)
            {
                for (auto& r: right) res.push_back(this->calc(l, r, symbol));
            }
        }
        return res;
    }

    int calc(int a, int b, char symbol)
    {
        switch (symbol)
        {
            case '*' :
            {
                return a * b;
            }
            case '-' :
            {
                return a - b;
            }
            case '+':
            {
                return a + b;
            }
            default :
                return 0;
        }
    }

};

//int main(void)
//{
//    Solution s;
//    vector<int> res = s.diffWaysToCompute("2*3-4*5-5*6");
//    for (auto& n: res) cout << n << endl;
//    return 0;
//}