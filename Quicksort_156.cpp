#include<bits/stdc++.h>
#define sp " "
using  namespace std;
int parti_tion(int arr[],int l,int h)
{
    int pivot=arr[h];
    int i=l,j=h;
    while (i<j)
    {
        while(i<=h && arr[i]<pivot)
        {
            i++;
        }
        while (arr[j]>=pivot)
        {
            j--;
        }
        if (i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap (arr[h],arr[i]);
    return i;
}
void quicksort(int arr[],int l,int h)
{
    if (l<h)
    {
        int i=parti_tion(arr,l,h);
        quicksort(arr,l,i-1);
        quicksort(arr,i+1,h);
    }
}
int main()
{
    int x;
    cin>>x;
    int arr[x];
    for (int i=0;i<x;i++)
    {
        cin>>arr[i];
    }

    quicksort(arr,0,x-1);
    for (int i=0;i<x;i++)
    {
        cout<<arr[i]<<sp;
    }

    return 0;
}

