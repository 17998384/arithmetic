//
//  rob.c
//  arithmetic
//
//  337. 打家劫舍 III
//
//  在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。
//  除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
//   如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
//
//  计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
//
//  示例 1:
//
//  输入: [3,2,3,null,3,null,1]
//
//       3
//      / \
//     2   3
//      \   \
//       3   1
//
//  输出: 7
//  解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
//
//  Created by 我叫城北徐公° on 2021/3/13.
//  Copyright © 2021 alex. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "tree_node.h"

typedef struct TreeNode Tree;

typedef struct dp
{
    int select;
    int noSelect;
}DP;

//我们规定 dp.select 为选中当前值，dp.noSelect 为不选中当前值
static DP dfs(Tree* root)
{
    DP dp;
    memset(&dp,0,sizeof(DP));
    if (!root) return dp;
    DP leftDP = dfs(root->left);
    DP rightDP = dfs(root->right);
    //如果选中当前值，那么就只能加未选中子节点的值
    dp.select = root->val + leftDP.noSelect + rightDP.noSelect;
    //如果不选中当前值，那么从（选中其子节点，或不选择其子节点中找寻最大值）
    dp.noSelect = fmax(leftDP.select,leftDP.noSelect) + fmax(rightDP.select,rightDP.noSelect);
    return dp;
}

int rob(struct TreeNode* root)
{
    DP dp = dfs(root);
    return fmax(dp.select,dp.noSelect);
}
