//
// Created by 我叫城北徐公° on 2021/5/10.
//

#ifndef ARITHMETIC_LIST_NODE_HPP
#define ARITHMETIC_LIST_NODE_HPP

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr)
    {}

    ListNode(int x) : val(x), next(nullptr)
    {}

    ListNode(int x, ListNode* next) : val(x), next(next)
    {}
};

#endif //ARITHMETIC_LIST_NODE_HPP
