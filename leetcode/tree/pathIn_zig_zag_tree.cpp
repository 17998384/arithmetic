//
//  pathIn_zig_zag_tree.cpp
//  arithmetic
//
//  1104. 二叉树寻路
//
//  在一棵无限的二叉树上，每个节点都有两个子节点，树中的节点 逐行 依次按 “之” 字形进行标记。
//
//  如下图所示，在奇数行（即，第一行、第三行、第五行……）中，按从左到右的顺序进行标记；
//
//  而偶数行（即，第二行、第四行、第六行……）中，按从右到左的顺序进行标记。
//
//  给你树上某一个节点的标号 label，请你返回从根节点到该标号为 label 节点的路径，该路径是由途经的节点标号所组成的。
//
//
//
//  示例 1：
//
//  输入：label = 14
//  输出：[1,3,4,14]
//
//  Created by 我叫城北徐公° on 2021/3/13.
//  Copyright © 2021 alex. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label)
    {
        vector<int> res;
        if (!label) return res;
        
        //计算层数
        int depth = 0;
        for (int i = 1;;i <<= 1,depth++) if (label < i) break;
        
        while (depth > 0)
        {
            res.insert(res.begin(),label);
            //是偶数？
            if (depth % 2 == 0)
            {
                //求真实数据
                label = (1 << (depth - 1)) + ((1 << depth) - 1 - label);
                if (label % 2 != 0) label = (label - 1) / 2;
                else label = label / 2;
            }
            else if (depth % 2 != 0 && depth > 1)
            {
                //求真实数据
                if (label % 2 != 0) label = (label - 1) / 2;
                else label = label / 2;
                int tmpDepth = depth - 1;
                label = ((1 << tmpDepth) - 1) - (label - (1 << (tmpDepth - 1)));
            }
            depth--;
        }
        return res;
    }
};
