#include<bits/stdc++.h>
using namespace std;
int Partition(int A[], int s, int e)
{
    int x = A[e];
    int i = s-1;
    for(int j = s; j<=e-1; j++)
    {
        if(A[j]<=x){
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp; }
    }
    int temp = A[i+1];
    A[i+1] = A[e];
    A[e] = temp;
    return i+1;
}
void QuickSort(int A[], int s, int e)
{
    if(s<e)
    {
        int index = Partition(A, s, e);
        QuickSort(A, s, index-1);
        QuickSort(A, index+1, e);
    }
}

int main()
{
    int arr_size;
    cout<<"Enter number of elements :";
    cin>>arr_size;
    int arr[arr_size];
    cout<<"Enter the array elements :";
    for(int i=0; i<arr_size; i++)
    {
        cin>>arr[i];
    }
    int start = 0;
    int end =arr_size-1 ;

    QuickSort(arr, start, end);

    for(int i = 0; i<=end; i++)
    {
        cout<< arr[i] << " ";
    }
}
