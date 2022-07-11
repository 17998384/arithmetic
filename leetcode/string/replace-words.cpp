//
// Created by 我叫城北徐公° on 2022/7/7.
//

//  648. 单词替换
//
//          在英语中，我们有一个叫做 词根(root) 的概念，可以词根后面添加其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。
//
//  现在，给定一个由许多词根组成的词典 dictionary 和一个用空格分隔单词形成的句子 sentence。你需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。
//
//  你需要输出替换之后的句子。
//
//
//
//  示例 1：
//
//  输入：dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
//  输出："the cat was rat by the bat"
//
//  示例 2：
//
//  输入：dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
//  输出："a a b c"
//
//
//
//  提示：
//
//  1 <= dictionary.length <= 1000
//  1 <= dictionary[i].length <= 100
//  dictionary[i] 仅由小写字母组成。
//  1 <= sentence.length <= 10^6
//  sentence 仅由小写字母和空格组成。
//  sentence 中单词的总量在范围 [1, 1000] 内。
//  sentence 中每个单词的长度在范围 [1, 1000] 内。
//  sentence 中单词之间由一个空格隔开。
//  sentence 没有前导或尾随空格。

#include <iostream>
#include <vector>
#include <prefix_tree.h>
#include <string>

using namespace std;

char* query_element_copy(PrefixTree* prefixTree, const char* str)
{
    size_t len, idx;
    idx = 0, len = strlen(str);
    Node** curNode = &prefixTree->root;
    char* tmp = (char*) calloc(len + 1, sizeof(char));
    while (idx < len)
    {
        curNode = &((*curNode)->children[str[idx] - 97]);
        if (!*curNode)
        {
            tmp[0] = '\0';
            return tmp;
        }
        tmp[idx] = str[idx];
        if ((*curNode)->end) return tmp;
        idx++;
    }
    return tmp;
}


class Solution
{
public:
    string replaceWords(vector<string>& dictionary, string sentence)
    {
        PrefixTree* pTree = create_prefix_tree(26);
        for (auto& s: dictionary) pTree->insert_element(pTree, s.c_str());
        string res;
        int findIdx;
        string tmp;
        do
        {
            findIdx = sentence.find(" ");
            char* other = nullptr;
            if (findIdx == -1)
            {
                if (!sentence.empty())
                {
                    other = query_element_copy(pTree, sentence.c_str());
                    res.append(strlen(other) == 0 ? sentence.c_str() : other);
                }
                break;
            }
            tmp = sentence.substr(0, findIdx);
            other = query_element_copy(pTree, tmp.c_str());
            res.append(strlen(other) == 0 ? tmp.c_str() : other).append(" ");
            sentence = sentence.substr(findIdx + 1);
            free(other);
        } while (!sentence.empty());
        pTree->destroy_prefix_tree(pTree);
        return res;
    }
};

//int main(void)
//{
//    string str = "oklwhcppuziixpvihihp";
//    vector<string> dictionary = {"e"};
//    Solution s;
//    string res = s.replaceWords(dictionary, str);
//    cout << res << endl;
//    return 0;
//}