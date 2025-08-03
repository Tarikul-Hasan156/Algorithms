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

        for (int j=0;j<x-i-1;j++)
        {

            if (arr[j]>arr[j+1])
            {
                int temp=0;
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for (int i=0;i<x;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
