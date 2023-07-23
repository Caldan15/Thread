#include<iostream>
#include<thread>
#include<condition_variable>
using namespace std;
mutex m;
condition_variable cv;
bool ready = false;
void counts(int a,int b)
{
    unique_lock<mutex>lock(m);
    cv.wait(lock,[]{return ready;});
    if(b>a)
    {
        for(int i=b;i>=a;i--)
        {
            cout<<i<<" ";
        }
    }
    else
    {
        for(int i=b;i<=a;i++)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    thread worker2(counts,1,100);
    thread worker1(counts,100,1);
    this_thread::sleep_for(chrono::seconds(2));
    {
        lock_guard<mutex>lock(m);
        ready=true;
    }
    cv.notify_all();
    worker1.join();
    worker2.join();
}
