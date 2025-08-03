#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int x;
    cin>>x;
    int arr[x];
    for (int i=0;i<x;i++)
    {
        cin>>arr[i];
    }
    int lower=1;
    int upper=x;
    cout<<"Please input the key : "<<endl;
    int key=0;
    cin>>key;
    while (lower<=upper)
    {
        int mid=(lower+upper)/2;
        if (arr[mid]==key)
        {
             cout<<"Index of key :"<<mid<<endl;
             break;
        }

        if (key>arr[mid])
            lower=mid+1;
        else
            upper=mid-1;
    }
    return 0;
}

