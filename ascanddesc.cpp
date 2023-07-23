
#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<algorithm>
using namespace std;
mutex m;
vector<int> v= {13, 20, 5, 43, 21, 215, 319, 15};

void sortA()
{
m.lock();
sort(v.begin(), v.end());
cout<<"Ascending Order"<<endl;
for(auto a:v){
cout<<a<<" ";
}
cout<<endl;
m.unlock();
}
void sortD()
{
m.lock();
sort(v.begin(), v.end(), greater<int>());
cout<<"Descending Order"<<endl;
for(auto a:v){
cout<<a<<" ";
}
m.unlock();
}
int main()
{
thread th1(sortA);
thread th2(sortD);
th1.join();
th2.join();

return 0;
}
