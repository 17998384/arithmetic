//
// Created by 我叫城北徐公° on 2021/10/22.
//

//  212. 单词搜索 II
//
//  给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。
//
//  单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
//
//
//
//  示例 1：
//
//  输入：board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
//  输出：["eat","oath"]
//
//  示例 2：
//
//  输入：board = [["a","b"],["c","d"]], words = ["abcb"]
//  输出：[]
//
//
//
//  提示：
//
//  m == board.length
//          n == board[i].length
//  1 <= m, n <= 12
//  board[i][j] 是一个小写英文字母
//  1 <= words.length <= 3 * 104
//  1 <= words[i].length <= 10
//  words[i] 由小写英文字母组成
//          words 中的所有字符串互不相同
//
//

#include <vector>
#include <string>
#include <iostream>
#include <set>
#include "prefix_tree.h"

using namespace std;

class SolutionWord
{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        prefixTree = create_prefix_tree(26);
        set<char> firstLetter;
        wordsCache = new set<string>;
        resSet = new set<string>;
        res = new vector<string>;
        for (const auto& word: words)
        {
            prefixTree->insert_element(prefixTree, word.c_str());
            if (!word.empty())
            {
                firstLetter.insert(word[0]);
                wordsCache->insert(word);
            }
        }

        bool** cache = new bool* [board.size()];
        for (int i = 0, size = board.size(); i < size; ++i) cache[i] = new bool[board[i].size()]();

        for (int i = 0, size = board.size(); i < size; i++)
        {
            for (int j = 0, jSize = board[i].size(); j < jSize; ++j)
            {
                if (firstLetter.find(board[i][j]) != firstLetter.end())
                {
                    is_match(board, i, j, cache);
                }
            }
        }
        for (const auto& word: *resSet) res->push_back(word);

        for (int i = 0, size = board.size(); i < size; ++i) delete[] cache[i];

        delete[] cache;
        return *res;
    }

    ~SolutionWord()
    {
        if (prefixTree) prefixTree->destroy_prefix_tree(prefixTree);
        if (resSet) delete resSet;
        if (wordsCache) delete wordsCache;
        if (res) delete res;
    }

private:

    PrefixTree* prefixTree;

    set<string>* wordsCache;

    set<string>* resSet;

    vector<string>* res;

    void is_match(vector<vector<char>>& board, int row, int col,
                  bool** cache)
    {
        string tmp;
        dfs(board, row, col, 0, cache, tmp);
        dfs(board, row, col, 1, cache, tmp);
        dfs(board, row, col, 2, cache, tmp);
        dfs(board, row, col, 3, cache, tmp);
    }

    void dfs(vector<vector<char>>& board, int row, int col, int direction, bool** cache,
             string& tmp)
    {
        if (row >= board.size() || row < 0 || col >= board[0].size() || col < 0 || cache[row][col]) return;

        tmp.push_back(board[row][col]);
        cache[row][col] = true;
        int ref = prefixTree->query_element(prefixTree, tmp.c_str());
        switch (ref)
        {
            case 0:
                goto loop;
//            case 1:
//            {
//                resSet->insert(tmp);
//                prefixTree->delete_element(prefixTree, tmp.c_str());
//                goto loop;
//            }
            default:
            {
                if (wordsCache->find(tmp) != wordsCache->end())
                {
                    if (resSet->find(tmp) == resSet->end())
                    {
                        prefixTree->delete_element(prefixTree, tmp.c_str());
                        resSet->insert(tmp);
                    }
                }
                break;
            }
        }
        if (direction != 2) dfs(board, row - 1, col, 0, cache, tmp);
        if (direction != 3) dfs(board, row, col - 1, 1, cache, tmp);
        if (direction != 0) dfs(board, row + 1, col, 2, cache, tmp);
        if (direction != 1) dfs(board, row, col + 1, 3, cache, tmp);
        loop:
        cache[row][col] = false;
        tmp.pop_back();
    }
};

int main_word_search_ii(void)
{
//    vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
//                                  {'e', 't', 'a', 'e'},
//                                  {'i', 'h', 'k', 'r'},
//                                  {'i', 'f', 'l', 'v'}};
//    vector<string> words = {"oath", "pea", "eat", "iifl"};
//    vector<vector<char>> board = {{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
//                                  {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
//                                  {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
//                                  {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
//                                  {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
//                                  {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
//                                  {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
//                                  {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
//                                  {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
//                                  {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
//                                  {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
//                                  {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}};
//    vector<string> words = {"lllllll", "fffffff", "ssss", "s", "rr", "xxxx", "ttt", "eee", "ppppppp", "iiiiiiiii",
//                            "xxxxxxxxxx", "pppppp", "xxxxxx", "yy", "jj", "ccc", "zzz", "ffffffff", "r", "mmmmmmmmm",
//                            "tttttttt", "mm", "ttttt", "qqqqqqqqqq", "z", "aaaaaaaa", "nnnnnnnnn", "v", "g", "ddddddd",
//                            "eeeeeeeee", "aaaaaaa", "ee", "n", "kkkkkkkkk", "ff", "qq", "vvvvv", "kkkk", "e", "nnn",
//                            "ooo", "kkkkk", "o", "ooooooo", "jjj", "lll", "ssssssss", "mmmm", "qqqqq", "gggggg",
//                            "rrrrrrrrrr", "iiii", "bbbbbbbbb", "aaaaaa", "hhhh", "qqq", "zzzzzzzzz", "xxxxxxxxx", "ww",
//                            "iiiiiii", "pp", "vvvvvvvvvv", "eeeee", "nnnnnnn", "nnnnnn", "nn", "nnnnnnnn", "wwwwwwww",
//                            "vvvvvvvv", "fffffffff", "aaa", "p", "ddd", "ppppppppp", "fffff", "aaaaaaaaa", "oooooooo",
//                            "jjjj", "xxx", "zz", "hhhhh", "uuuuu", "f", "ddddddddd", "zzzzzz", "cccccc", "kkkkkk",
//                            "bbbbbbbb", "hhhhhhhhhh", "uuuuuuu", "cccccccccc", "jjjjj", "gg", "ppp", "ccccccccc",
//                            "rrrrrr", "c", "cccccccc", "yyyyy", "uuuu", "jjjjjjjj", "bb", "hhh", "l", "u", "yyyyyy",
//                            "vvv", "mmm", "ffffff", "eeeeeee", "qqqqqqq", "zzzzzzzzzz", "ggg", "zzzzzzz", "dddddddddd",
//                            "jjjjjjj", "bbbbb", "ttttttt", "dddddddd", "wwwwwww", "vvvvvv", "iii", "ttttttttt",
//                            "ggggggg", "xx", "oooooo", "cc", "rrrr", "qqqq", "sssssss", "oooo", "lllllllll", "ii",
//                            "tttttttttt", "uuuuuu", "kkkkkkkk", "wwwwwwwwww", "pppppppppp", "uuuuuuuu", "yyyyyyy",
//                            "cccc", "ggggg", "ddddd", "llllllllll", "tttt", "pppppppp", "rrrrrrr", "nnnn", "x", "yyy",
//                            "iiiiiiiiii", "iiiiii", "llll", "nnnnnnnnnn", "aaaaaaaaaa", "eeeeeeeeee", "m", "uuu",
//                            "rrrrrrrr", "h", "b", "vvvvvvv", "ll", "vv", "mmmmmmm", "zzzzz", "uu", "ccccccc", "xxxxxxx",
//                            "ss", "eeeeeeee", "llllllll", "eeee", "y", "ppppp", "qqqqqq", "mmmmmm", "gggg", "yyyyyyyyy",
//                            "jjjjjj", "rrrrr", "a", "bbbb", "ssssss", "sss", "ooooo", "ffffffffff", "kkk", "xxxxxxxx",
//                            "wwwwwwwww", "w", "iiiiiiii", "ffff", "dddddd", "bbbbbb", "uuuuuuuuu", "kkkkkkk",
//                            "gggggggggg", "qqqqqqqq", "vvvvvvvvv", "bbbbbbbbbb", "nnnnn", "tt", "wwww", "iiiii",
//                            "hhhhhhh", "zzzzzzzz", "ssssssssss", "j", "fff", "bbbbbbb", "aaaa", "mmmmmmmmmm",
//                            "jjjjjjjjjj", "sssss", "yyyyyyyy", "hh", "q", "rrrrrrrrr", "mmmmmmmm", "wwwww", "www",
//                            "rrr", "lllll", "uuuuuuuuuu", "oo", "jjjjjjjjj", "dddd", "pppp", "hhhhhhhhh", "kk",
//                            "gggggggg", "xxxxx", "vvvv", "d", "qqqqqqqqq", "dd", "ggggggggg", "t", "yyyy", "bbb",
//                            "yyyyyyyyyy", "tttttt", "ccccc", "aa", "eeeeee", "llllll", "kkkkkkkkkk", "sssssssss", "i",
//                            "hhhhhh", "oooooooooo", "wwwwww", "ooooooooo", "zzzz", "k", "hhhhhhhh", "aaaaa", "mmmmm"};
    vector<vector<char>> board = {{'o', 'a', 'b', 'n'},
                                  {'o', 't', 'a', 'e'},
                                  {'a', 'h', 'k', 'r'},
                                  {'a', 'f', 'l', 'v'}};
    vector<string> words = {"oa", "oaa"};
    SolutionWord s;
    vector<string> res = s.findWords(board, words);
    for (auto& str: res)
    {
        cout << str << endl;
    }
    return 0;
}