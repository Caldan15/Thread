#include<iostream>
#include<vector>
#include<thread>
#include<future>
#include<chrono>

using namespace std;

int a=0;
void fun()
{
    this_thread::sleep_for(chrono::seconds(5));
}

int main()
{
    future<void> result=async(fun);
    future_status status;
    do
    {
        status=result.wait_for(chrono::milliseconds(500));
        if(status==future_status::timeout)
        {
            a=a?0:1;
            cout<<a<<endl;
        }
    }while(status!=future_status::ready);
}
