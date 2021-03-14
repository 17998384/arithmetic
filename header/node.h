//
//  node.h
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/11/23.
//  Copyright © 2020 alex. All rights reserved.
//

#ifndef node_h
#define node_h

struct Node
{
    int val;
    int numChildren;
    struct Node** children;
};

#endif /* node_h */
