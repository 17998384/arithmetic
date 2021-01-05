//
//  c++_hello_world.cpp
//  arithmetic
//
//  Created by 我叫城北徐公° on 2021/1/4.
//  Copyright © 2021 alex. All rights reserved.
//
#include <iostream>

using namespace std;

class Test
{
public:
    int a;
    int max(int a,int b);
};

int Test::max(int a,int b)
{
    return a > b ? a : b;
}

int main_cplus_plus(void)
{
    Test* test = new Test();
    Test* test2 = new Test();
    test2->a = 20;
    test->a = 30;
    int _max = test->max(test->a, test2->a);
    cout<<"最大值是："<<_max<<endl;
    delete test;
    delete test2;
    return 0;
}
