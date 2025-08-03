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
    for (int i=1;i<x;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for (int i=0;i<x;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
