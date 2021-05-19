//
//  list_node.h
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/10/12.
//  Copyright © 2020 alex. All rights reserved.
//

#ifndef list_node_h
#define list_node_h

#ifdef __cplusplus

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

#else

struct ListNode
{
    int val;
    struct ListNode* next;
};

#endif

#endif /* list_node_h */
