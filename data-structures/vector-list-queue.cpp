#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

int main()
{
    vector<int> vec;
    list<int> l;
    queue<int> q;
    deque<int> d;
    auto start = system_clock::now().time_since_epoch();
    for (int i = 0; i < 1000000; i++)
    {
        vec.push_back(i);
    }
    auto end = system_clock::now().time_since_epoch();
    cout << duration<double, milli>(end - start).count() << endl;
    start = system_clock::now().time_since_epoch();
    for (int i = 0; i < 1000000; i++)
    {
        l.push_back(i);
    }
    end = system_clock::now().time_since_epoch();
    cout << duration<double, milli>(end - start).count() << endl;
    start = system_clock::now().time_since_epoch();
    for (int i = 0; i < 1000000; i++)
    {
        q.push(i);
    }
    end = system_clock::now().time_since_epoch();
    cout << duration<double, milli>(end - start).count() << endl;
    start = system_clock::now().time_since_epoch();
    for (int i = 0; i < 1000000; i++)
    {
        d.push_back(i);
    }
    end = system_clock::now().time_since_epoch();
    cout << duration<double, milli>(end - start).count() << endl;
}
