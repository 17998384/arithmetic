//
// Created by 我叫城北徐公° on 2022/5/6.
//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define THREAD_COUNT 20
#define SLEEP_TIME_SECOND 5

int sumArr[THREAD_COUNT];

void* run(void* param)
{
    int idx = *(int*) param;
    char* cmd = "curl --location --request GET 'http://localhost:9200/_analyze' --header 'Content-Type: application/json' --data '{   \"analyzer\": \"phone_analyzer\",   \"text\": \"13189996606\"}'";
    while (1)
    {
        system(cmd);
        sumArr[idx]++;
    }
}

int main_test_concurrent(void)
{
    pthread_t threads[THREAD_COUNT];
    int* arr = malloc(sizeof(int) * THREAD_COUNT);
    for (int i = 0; i < THREAD_COUNT; i++)
    {
        arr[i] = 0;
        pthread_create(&threads[i], NULL, run, &arr[i]);
    }
    sleep(SLEEP_TIME_SECOND);
    for (int i = 0; i < THREAD_COUNT; i++)
    {
        pthread_kill(threads[i], 0);
    }
    free(arr);
    int sum = 0;
    for (int i = 0; i < THREAD_COUNT; i++)
    {
        sum += sumArr[i];
    }
    printf("sum : %d\n", sum);
    return 0;
}