#include<bits/stdc++.h>
using namespace std;

void Max_heapify(int arr[],int i,int n)
{
    int largest=i;
    int l=2*i;
    int r=(2*i+1);

    if(l<=n && arr[l]>arr[i])
        largest=l;
    else
        largest=i;
    if(r<=n && arr[r]>arr[largest]  )
        largest=r;
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);

        Max_heapify(arr,largest,n);

    }

}


void Build_max_heap(int arr[],int n)
{
    for(int i=n/2;i>=1;i--)
    {
        Max_heapify(arr,i,n);
    }
}


void Heapsort(int arr[],int n)
{
    Build_max_heap(arr,n);
    int heapsize=n;
    for(int i=n;i>=2;i--)
    {
        swap(arr[1],arr[i]);
        heapsize=heapsize-1;
        Max_heapify(arr,1,heapsize);
    }
}


int main()
{
    int n;
    cout<<"array size: ";
    cin>>n;
    cout<<endl;
    int arr[n];
    cout<<"enter array elements :";
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    Heapsort(arr,n);


    cout<<endl<<"after heap sorting"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }

}
