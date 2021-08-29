//
// Created by 我叫城北徐公° on 2021/7/13.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string>& recall(string& base)
    {
        recall0(base, 0);
        return res;
    }

private:
    vector<string> res;


    void recall0(string& base, int idx)
    {
        if (idx >= base.size())
        {
            res.push_back(base);
            return;
        }
        for (int i = idx, size = base.size(); i < size; ++i)
        {
            swap(base.at(i), base.at(idx));
            recall0(base, idx + 1);
            swap(base.at(i), base.at(idx));
        }
    }

};

int main_recall(void)
{
    Solution s;
    string str = "abc";
    vector<string>& res = s.recall(str);
    for (string& s : res)
    {
        cout << s << endl;
    }
    return 0;
}