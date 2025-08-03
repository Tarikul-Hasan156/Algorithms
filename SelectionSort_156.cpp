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
    for (int i=0;i<x-1;i++)
    {
        int min_id=i;
        for (int j=i+1;j<x;j++)
        {
            if (arr[j]<arr[i])
            {
                min_id=j;
            }

        }
        int temp=0;
        temp=arr[min_id];
        arr[min_id]=arr[i];
        arr[i]=temp;
    }
    for (int i=0;i<x;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
