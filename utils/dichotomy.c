//
//  dichotomy.c
//  arithmetic
//
//  二分法
//
//  Created by 我叫城北徐公° on 2020/10/26.
//  Copyright © 2020 alex. All rights reserved.
//

#include "dichotomy.h"

int dichotomy(int* nums,int start_idx,int end_idx,int target)
{
    int half_idx = (start_idx + end_idx) / 2;
    if (start_idx > end_idx)
        return -1;
    if (target == nums[half_idx])
        return half_idx;
    else if (target > nums[half_idx])
        return dichotomy(nums,half_idx + 1,end_idx,target);
    else
        return dichotomy(nums,start_idx,half_idx - 1,target);
}
