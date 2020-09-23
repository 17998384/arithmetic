//
//  longest_common_prefix.c
//  arithmetic
//  最长公共前缀
//  Created by 我叫城北徐公° on 2020/9/14.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 0) return "";
    for (int i = 0,size = (int) strlen(*strs); i < size ; i++)
    {
        for (int j = 0; j < strsSize; j++)
        {
            if (*(*strs + i) == '\0' || *(*strs + i) != *(*(strs + j) + i))
            {
                *(*strs + i) = '\0';
                goto loop;
            }
        }
    }
loop:
    return *strs;
}
