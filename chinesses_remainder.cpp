#include<bits/stdc++.h>
using namespace std;

int findMinX(int num[], int rem[], int k)
{
    int x = 1;  

    while (true)
    {
       
        int j;
        for (j=0; j<k; j++ )
            if (x%num[j] != rem[j])
            break;

        if (j == k)
            return x;
 
        x++;
    }

    return x;
}


int main(void)
{
    int n;
    cout<<"Enter number of Elements: ";
    cin>>n;
    int num[n],rem[n];
    cout<<"Enter elements :";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    cout<<"Enter rem elements :";
    for(int i=0;i<n;i++)
    {
        cin>>rem[i];
    }
    // int num[] = {3, 4, 5};
    // int rem[] = {2, 3, 1};
    cout << "x is " << findMinX(num, rem, n)<<endl;
    return 0;
}
