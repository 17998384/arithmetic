//
//  test_fork.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/10/24.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main_test_fork(void)
{
    int* count = (int*)malloc(sizeof(int));
    *count = 10;
    //创建子进程
    int pid = fork();
    int pid2 = fork();
    if (pid < 0)
    {
        printf("create fork fail , reason : %s\n",strerror(errno));
    }
    else if(pid == 0)
    {
        printf("%d\n",pid);
        printf("this is child2 progress , count address = %p , pid = %d\n",&count,getpid());
//        *count = 4;
    }
    else if(pid2 == 0)
    {
        printf("%d\n",pid);
        printf("this is child progress , count address = %p , pid = %d\n",&count,getpid());
//        *count = 4;
    }
    else
    {
        printf("%d\n",pid);
        *count = 20;
        printf("this is father progress , count address = %p , pid = %d\n",&count,getpid());
    }
    printf("print count content : %d \n",*count);

    return 0;
}
