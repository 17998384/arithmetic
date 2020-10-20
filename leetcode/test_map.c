//
//  test_map.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/10/19.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include "hash_map.h"
#define COUNT 100

static int hashCode(void* a)
{
    return (*(int*)a);
}

static int equals(void* a,void* b)
{
    return (*(int*)a) == (*(int*)b);
}

//static int equals(void* a,void* b)
//{
//    return !strcmp((char*)a, (char*)b);
//}
//
//static int hashCode(void* key)
//{
//    int h = 0;
//    char* str = (char*)key;
//    int str_len = (int)strlen(str);
//    if (h == 0 && str_len > 0) {
//        for (int i = 0 ; i < str_len; i++) {
//            h = 31 * h + str[i];
//        }
//    }
//    return h;
//}
//

void test()
{
    for (int i = 0; i < COUNT; i++)
    {
        HashMap* hashMap = newHashMap(hashCode, equals);
        for (int j = 0; j < 1000000; j++)
        {
            int* p = malloc(sizeof(int));
            int* p2 = malloc(sizeof(int));
            *p = j;
            *p2 = j;
            put(hashMap, p, p2);
        }
        free_map(hashMap);
    }
}

int main_test_map(void)
{
    test();
    return 0;
}
