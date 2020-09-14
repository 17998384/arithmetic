//
//  is_palindrome.c
//  arithmetic
//  回文数
//  Created by 我叫城北徐公° on 2020/9/14.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#define true 1
#define false 0

int isPalindrome0(int x0){
    int arr[10] = {0};
    int size,temp;
    size = 0;temp = x0;
    while(temp > 0){
        int bit = temp % 10;
        arr[size] = bit;
        temp /= 10;
        size++;
    }
    for(int i = 0,j = size - 1;i < j;i++,j--){
        if(arr[i] != arr[j])
            return false;
    }
    return true;
}

int isPalindrome(int x){
    if(x < 0)
        return false;
    if(x < 10 && x >= 0)
        return true;
    return isPalindrome0(x);
}
