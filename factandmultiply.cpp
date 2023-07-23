#include<iostream>
#include<vector>
#include<thread>
#include<future>
#include<algorithm>
using namespace std;


int fact(int n) {
    if (n == 0 || n == 1)
        return 1;

    int result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;

    return result;
}


int main(){
    int n;
    cin>>n;
    future<int> fut1 = async(fact,n);
    future<int> fut2 = async(fact,n);

   int rA=2, cA=2, rB=2, cB=2;

    vector<int> A(rA * cA);
    vector<int> B(rB * cB);

    cout << "Enter the elements of matrix A :" << endl;
    for (int i = 0; i < rA; i++)
    {
        for (int j = 0; j < cA; j++)
        {
            cout<<"Enter the element["<<i<<"]"<<"["<<j<<"] : ";
            cin >> A[ (i * cA) + j];
        }
    }
    cout << "Enter the elements of matrix B :" << endl;
    for (int i = 0; i < rB; i++)
    {
        for (int j = 0; j < cB; j++)
        {
            cout<<"Enter the element["<<i<<"]"<<"["<<j<<"] : ";
            cin >> B[i * cB + j];
        }
    }
    vector<vector<int>> c(rA, vector<int>(cB, 0));

    for (int i = 0; i < rA; i++)
    {
       for (int j = 0; j < cB; j++)
        {
            for (int k = 0; k < cA; k++)
            {
                c[i][j] += A[i * cA + k] * B[k * cB + j];
            }
        }
    }


    for (int i = 0; i < rA; i++)
    {
        for (int j = 0; j < cA; j++)
        {
            cout << A[(i * cA) + j]<<" ";
        }
        cout<<endl;
    }

    cout<<"FUT1 : "<<fut1.get()<<endl;
    cout<<"FUT2 : "<<fut2.get()<<endl;

    return 0;
}


