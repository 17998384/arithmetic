//
// Created by 我叫城北徐公° on 2022/6/29.
//

//  535. TinyURL 的加密与解密
//
//  TinyURL 是一种 URL 简化服务， 比如：当你输入一个 URL https://leetcode.com/problems/design-tinyurl 时，它将返回一个简化的URL http://tinyurl.com/4e9iAk 。请你设计一个类来加密与解密 TinyURL 。
//
//  加密和解密算法如何设计和运作是没有限制的，你只需要保证一个 URL 可以被加密成一个 TinyURL ，并且这个 TinyURL 可以用解密方法恢复成原本的 URL 。
//
//  实现 Solution 类：
//
//  Solution() 初始化 TinyURL 系统对象。
//  String encode(String longUrl) 返回 longUrl 对应的 TinyURL 。
//  String decode(String shortUrl) 返回 shortUrl 原本的 URL 。题目数据保证给定的 shortUrl 是由同一个系统对象加密的。
//
//
//
//  示例：
//
//  输入：url = "https://leetcode.com/problems/design-tinyurl"
//  输出："https://leetcode.com/problems/design-tinyurl"
//
//  解释：
//  Solution obj = new Solution();
//  string tiny = obj.encode(url); // 返回加密后得到的 TinyURL 。
//  string ans = obj.decode(tiny); // 返回解密后得到的原本的 URL 。
//
//
//
//  提示：
//
//  1 <= url.length <= 104
//  题目数据保证 url 是一个有效的 URL

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution1
{
public:

    Solution1()
    {
        for (char c = 'a'; c <= 'z'; c++) _randomPassword.push_back(c);
        for (char c = '0'; c <= '9'; c++) _randomPassword.push_back(c);
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        int startIdx = longUrl.find("/", 8);
        string domain = longUrl.substr(0, startIdx + 1);
        //6位随机短链
        char shortPwd[7];
        for (int i = 0; i < 6; ++i)
        {
            shortPwd[i] = _randomPassword[rand() % _randomPassword.size()];
        }
        shortPwd[6] = '\0';
        string shortUrl = domain + shortPwd;
        _map[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        auto pair = _map.find(shortUrl);
        if (pair != _map.end()) return pair->second;
        else return "";
    }

private:

    unordered_map<string, string> _map;
    vector<char> _randomPassword;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

//int main(void)
//{
//    Solution1 s;
//    string shortUrl = s.encode("https://leetcode.com/problems/design-tinyurl");
//    cout << shortUrl << endl;
//    cout << s.decode(shortUrl) << endl;
//    return 0;
//}