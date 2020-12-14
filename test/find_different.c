//
//  find_different.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/12/11.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "hash_map.h"

static int equals(void* a,void* b)
{
    return !strcmp((char*)a, (char*)b);
}

static int hashCode(void* key)
{
    unsigned int max = 0xFFFFFFFF;
    long long h = 0;
    char* str = (char*)key;
    int str_len = (int)strlen(str);
    if (h == 0 && str_len > 0) {
        for (int i = 0 ; i < str_len; i++) {
            h = 31 * h + str[i];
            h &= max;
        }
    }
    return (int)h;
}

int find_different(void)
{
    FILE* sqlData = fopen("/Users/alex/Desktop/sqlData.txt", "r+");
    HashMap* map = newHashMap(hashCode, equals);
    unsigned long readCount;
    char* buffer = (char*)malloc(sizeof(char) * 6);
    int count = 0;
    while ((readCount = fread(buffer, sizeof(char), 6, sqlData)) != 0)
    {
        ++count;
        buffer[5] = '\0';
        put(map, buffer, NULL);
        buffer = (char*)malloc(sizeof(char) * 6);
    }
    printf("从sql读取id数量 -> %d\n",count);
    count = 0;
    FILE* excelData = fopen("/Users/alex/Desktop/excelData.txt", "r+");
    while ((readCount = fread(buffer, sizeof(char), 6, excelData)) != 0)
    {
        count++;
        buffer[5] = '\0';
        int boolean = contains(map, buffer);
        if (!boolean) printf("不一致数据为 -> %s\n",buffer);
        buffer = (char*)malloc(sizeof(char) * 6);
    }
    printf("从excel读取id数量 -> %d\n",count);
    free(buffer);
    free_map(map, 1);
    fclose(excelData);
    fclose(sqlData);
    return 0;
}
