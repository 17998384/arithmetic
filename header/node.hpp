//
//  node.hpp
//  arithmetic
//
//  Created by 我叫城北徐公° on 2021/3/14.
//  Copyright © 2021 alex. All rights reserved.
//

#ifndef node_h
#define node_h

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

#endif /* node_h */
