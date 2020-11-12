//
//  max_area.c
//  arithmetic

//  11.盛水最多的容器

//  Created by 我叫城北徐公° on 2020/9/14.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>

int maxArea(int* height, int heightSize)
{
    int* L; int* R; int max, temp, width, product = 0;
    max = 0; temp = 0;
    L = height; R = height + heightSize - 1;
    while (L != R)
    {
        width = R - L;
        temp = *L > * R ? *(R--) : *(L++);
        product = width * temp;
        if (product > max)
            max = product;
    }
    return max;
}
