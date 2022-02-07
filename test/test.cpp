//
// Created by 我叫城北徐公° on 2022/1/27.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template<class T>
class Cmp
{
public:

    bool operator()(T o1, T o2)
    {
        return o1->first < o2->first;
    }

};

class Test
{
public:

    void test01()
    {
        pair<int, bool> q1(1, false);
        pair<int, bool> q2(0, false);
        pair<int, bool> q3(2, false);
        pair<int, bool> q4(0, false);
        priority_queue<pair<int, bool>*, vector<pair<int, bool>*>, Cmp<pair<int, bool>*>> q;
        q.push(&q1);
        printf("%p\n", &q1);
        q.push(&q2);
        q.push(&q3);
        q.push(&q4);
        while (!q.empty())
        {
            cout << q.top()->first << endl;
            printf("%p\n", q.top());
            q.pop();
        }
    }

};

class Test3
{
public:
    int a;
    int b;

    ~Test3()
    {
        cout << "delete" << endl;
    }
};

int main_test(void)
{
    Test t;
    t.test01();
    return 0;
}