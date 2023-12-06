#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cout<<"Enter Two intergers : ";
    cin>>a>>b;
    while(b!=0)
    {
        cout<<"a: "<<a<<" b: "<<b<<" a%b: "<<a%b<<endl;
        int temp=a;
        a=b;
        b=temp%b;
    }
    cout<<"GCD is: "<<a<<endl;
    return 0;
}