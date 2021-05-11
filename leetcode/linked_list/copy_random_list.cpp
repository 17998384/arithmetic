//
// Created by 我叫城北徐公° on 2021/5/10.
//

#include <iostream>
#include <unordered_map>

// Definition for a Node.
class Node
{
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }

};

using namespace std;

class Solution
{
public:

    unordered_map<unsigned long, Node*> uMap;

    Node* copyRandomList(Node* head)
    {
        Node* resHead = NULL;
        Node* prev = NULL;
        Node** resHeadPtr = &resHead;
        while (head)
        {
            auto findCur = uMap.find((unsigned long) head);
            if (findCur != uMap.end()) *resHeadPtr = findCur->second;
            else
            {
                *resHeadPtr = new Node(head->val);
                uMap[(unsigned long) head] = *resHeadPtr;
            }
            if (head->random)
            {
                auto findRandom = uMap.find((unsigned long) head->random);
                if (findRandom != uMap.end()) (*resHeadPtr)->random = findRandom->second;
                else
                {
                    Node* newRandomNode = new Node(head->random->val);
                    uMap[(unsigned long) head->random] = newRandomNode;
                    (*resHeadPtr)->random = newRandomNode;
                }
            }
            if (!prev) prev = *resHeadPtr;
            else
            {
                prev->next = *resHeadPtr;
                prev = *resHeadPtr;
            }
            head = head->next;
            resHeadPtr = &(*resHeadPtr)->next;
        }
        return resHead;
    }
};

