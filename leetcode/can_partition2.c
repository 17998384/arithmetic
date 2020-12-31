//
//  can_partition2.c
//  arithmetic
//
//  416.分割等和子集(优化版，使用bitmap）
//
//  Created by 我叫城北徐公° on 2020/12/23.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>

//位运算解法，类似于dp
int canPartition2(int* nums, int numsSize)
{
    //计算和
    int sum = 0;
    for (int i = 0; i < numsSize; i++) sum += nums[i];
    if (sum % 2 != 0) return 0;
    int half = sum / 2;
    //32bit * 1000 = 32000位
    unsigned int bitmap[1000] = {0};
    int _unsigned_int_bit_size_ = sizeof(unsigned int) * 8;
    //当前位，当前数组索引
    int bit_sum = 0,flag = 1;
    for (int i = 0; i < numsSize; i++)
    {
        bit_sum += nums[i];
        //中位数已经满足条件了，不需要再进行了
        if (bitmap[(half - 1) / _unsigned_int_bit_size_] >> (half - 1) % _unsigned_int_bit_size_ & 1) return 1;
        //0位
        if (flag)
        {
            bitmap[(bit_sum - 1) / _unsigned_int_bit_size_] |= 1 << (bit_sum - 1) % _unsigned_int_bit_size_;
            flag = 0;
        }
        //开始拷贝
        else
        {
            int tmp_bit_sum = bit_sum - nums[i];
            for (int x = 0,j = bit_sum,k = tmp_bit_sum; x < tmp_bit_sum && j >= 0 && k >= 0; x++,j--,k--)
            {
                bitmap[(j - 1) / _unsigned_int_bit_size_] |= (bitmap[(k - 1) / _unsigned_int_bit_size_] >> (k - 1) % _unsigned_int_bit_size_ & 1) << (j - 1) % _unsigned_int_bit_size_;
            }
        }
    }
    return bitmap[(half - 1) / _unsigned_int_bit_size_] >> (half - 1) % _unsigned_int_bit_size_ & 1;
}

int main_canPartition2(void)
{
    int arr[] = {1,2,5};
    int res = canPartition2(arr, sizeof(arr) / sizeof(int));
    printf("%d ",res);
    return 0;
}
