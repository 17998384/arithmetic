//
// Created by 我叫城北徐公° on 2021/5/19.
//

//  1171. 从链表中删去总和值为零的连续节点

//  给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。
//
//  删除完毕后，请你返回最终结果链表的头节点。
//
//
//
//  你可以返回任何满足题目要求的答案。
//
//  （注意，下面示例中的所有序列，都是对 ListNode 对象序列化的表示。）
//
//  示例 1：
//
//  输入：head = [1,2,-3,3,1]
//  输出：[3,1]
//  提示：答案 [1,2,1] 也是正确的。
//
//  示例 2：
//
//  输入：head = [1,2,3,-3,4]
//  输出：[1,2,4]
//
//  示例 3：
//
//  输入：head = [1,2,3,-3,-2]
//  输出：[1]
//
//
//
//  提示：
//
//  给你的链表中可能有 1 到 1000 个节点。
//  对于链表中的每个节点，节点的值：-1000 <= node.val <= 1000.


#include <iostream>
#include <vector>
#include <unordered_map>
#include "list_node.h"

using namespace std;

class Solution
{
public:

    void remove_element(int start, int end, unordered_map<int, int>& cache, vector<int>& prefixSum, vector<int>& res)
    {
        for (int i = start; i <= end; i++)
        {
            if (i != end) cache.erase(prefixSum[start]);
            prefixSum.erase(prefixSum.begin() + start);
            res.erase(res.begin() + start);
        }
    }

    ListNode* removeZeroSumSublists(ListNode* head)
    {
        unordered_map<int, int> cache;
        vector<int> res;
        vector<int> prefixSum;
        int sum;
        sum = 0;
        while (head)
        {
            sum += head->val;
            res.push_back(head->val);
            prefixSum.push_back(sum);
            if (sum == 0)
            {
                this->remove_element(0, (int) prefixSum.size() - 1, cache, prefixSum, res);
            }
            auto finder = cache.find(sum);
            if (finder != cache.end())
            {
                this->remove_element(finder->second + 1, (int) prefixSum.size() - 1, cache, prefixSum, res);
            }
            cache[sum] = prefixSum.size() - 1;
            head = head->next;
        }
        ListNode* resHead = nullptr;
        ListNode** resHeadPtr = &resHead;
        for (auto& n : res)
        {
            *resHeadPtr = new ListNode(n);
            resHeadPtr = &(*resHeadPtr)->next;
        }
        return resHead;
    }
};