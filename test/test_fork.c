//
//  test_fork.c
//  arithmetic
//
//  进程炸弹

//  Created by 我叫城北徐公° on 2020/10/24.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main_process_bomb(int target)
{
    if (target)
    {
        return 0;
    }
    int process_1 = fork();
    int process_2 = fork();
    int process_3 = fork();
    int process_4 = fork();
    int process_5 = fork();
    
    if (process_1 == 0)
    {
        double a = 100;
        while (1) a /= 2;
    }

    if (process_2 == 0)
    {
        double a = 100;
        while (1) a /= 2;
    }
    if (process_3 == 0)
    {
        double a = 100;
        while (1) a /= 2;
    }
    if (process_4 == 0)
    {
        double a = 100;
        while (1) a /= 2;
    }
    if (process_5 == 0)
    {
        double a = 100;
        while (1) a /= 2;
    }
    return 0;
}


int main_main_process_bomb(void)
{
    wait(5);
    main_process_bomb(1);
    return 0;
}
