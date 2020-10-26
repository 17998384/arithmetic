//
//  test_thread.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/10/25.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread(void* arg)
{
    printf("child thread!\n");
    printf("arg : %d \n",*(int*)arg);
    *(int*)arg = 200;
    return arg;
}

int main_test_thread(void)
{
    pthread_t th;
    int arg = 100;
    int* ret = NULL;
    int res = pthread_create(&th, NULL, thread, &arg);
    res = pthread_create(&th, NULL, thread, &arg);
    if (res < 0)
    {
        printf("fail start a thread!\n");
    }
    printf("main thread!\n");
    printf("current pid = %d \n",getpid());
    pthread_join(th,(void**)&ret);
    printf("%d\n",*ret);
    return 0;
}
