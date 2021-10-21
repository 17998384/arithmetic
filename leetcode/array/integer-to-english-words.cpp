//
// Created by 我叫城北徐公° on 2021/10/20.
//

//  273. 整数转换英文表示
//
//          将非负整数 num 转换为其对应的英文表示。
//
//
//
//  示例 1：
//
//  输入：num = 123
//  输出："One Hundred Twenty Three"
//
//  示例 2：
//
//  输入：num = 12345
//  输出："Twelve Thousand Three Hundred Forty Five"
//
//  示例 3：
//
//  输入：num = 1234567
//  输出："One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
//
//  示例 4：
//
//  输入：num = 1234567891
//  输出："One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
//
//
//
//  提示：
//
//  0 <= num <= 231 - 1


#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution2
{
public:

    Solution2()
    {
        buffer = new string* [100]();
        buffer2 = new string* [4]();
    }

    ~Solution2()
    {
        for (int i = 0; i < 100; i++)
        {
            if (buffer[i]) delete buffer[i];
        }
        delete[] buffer;
        buffer = nullptr;
        for (int i = 0; i < 4; i++)
        {
            if (buffer2[i]) delete buffer2[i];
        }
        delete[] buffer2;
        buffer2 = nullptr;
    }

    string numberToWords(int num)
    {
        if (!num) return "Zero";
        vector<string*> res;
        buffer[1] = new string("One");
        buffer[2] = new string("Two");
        buffer[3] = new string("Three");
        buffer[4] = new string("Four");
        buffer[5] = new string("Five");
        buffer[6] = new string("Six");
        buffer[7] = new string("Seven");
        buffer[8] = new string("Eight");
        buffer[9] = new string("Nine");
        buffer[10] = new string("Ten");
        buffer[11] = new string("Eleven");
        buffer[12] = new string("Twelve");
        buffer[13] = new string("Thirteen");
        buffer[14] = new string("Fourteen");
        buffer[15] = new string("Fifteen");
        buffer[16] = new string("Sixteen");
        buffer[17] = new string("Seventeen");
        buffer[18] = new string("Eighteen");
        buffer[19] = new string("Nineteen");
        buffer[20] = new string("Twenty");
        buffer[30] = new string("Thirty");
        buffer[40] = new string("Forty");
        buffer[50] = new string("Fifty");
        buffer[60] = new string("Sixty");
        buffer[70] = new string("Seventy");
        buffer[80] = new string("Eighty");
        buffer[90] = new string("Ninety");

        buffer2[0] = new string("Billion");
        buffer2[1] = new string("Million");
        buffer2[2] = new string("Thousand");
        buffer2[3] = new string("Hundred");

        string strNum = to_string(num);
        if (strNum.size() >= 10)
        {
            res.push_back(buffer[strNum[0] - 48]);
            res.push_back(buffer2[0]);
            strNum = strNum.substr(1, strNum.size());
        }
        if (strNum.size() >= 7)
        {
            vector<string*> temp = calc(strNum.substr(0, strNum.size() - 6));
            for (auto& s: temp) res.push_back(s);
            if (!temp.empty()) res.push_back(buffer2[1]);
            strNum = strNum.substr(strNum.size() - 6, strNum.size());
        }
        if (strNum.size() >= 4)
        {
            vector<string*> temp = calc(strNum.substr(0, strNum.size() - 3));
            for (auto& s: temp) res.push_back(s);
            if (!temp.empty()) res.push_back(buffer2[2]);
            strNum = strNum.substr(strNum.size() - 3, strNum.size());
        }
        for (auto& s: calc(strNum))
        {
            res.push_back(s);
        }
        string resStr;
        for (int i = 0, size = res.size(); i < size; i++)
        {
            string* r = res[i];
            resStr += *r;
            if (i < size - 1) resStr += " ";
        }
        return resStr;
    }

private:

    vector<string*> calc(string x)
    {
        vector<string*> res;
        if (x.size() == 3)
        {
            if (x[0] != '0')
            {
                res.push_back(buffer[x[0] - 48]);
                res.push_back(buffer2[3]);
            }
            x = x.substr(1, x.size());
        }
        if (x.size() == 2)
        {
            int num = atoi(x.c_str());
            if (buffer[num] != nullptr) res.push_back(buffer[num]);
            else
            {
                if (buffer[num / 10 * 10])
                {
                    res.push_back(buffer[num / 10 * 10]);
                    res.push_back(buffer[num % 10]);
                }
            }
            return res;
        }
        else
        {
            res.push_back(buffer[atoi(x.c_str())]);
        }
        return res;
    }

    string** buffer;
    string** buffer2;
};