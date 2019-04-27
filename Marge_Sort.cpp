#include<bits/stdc++.h>
using namespace std;
void Merge(int A[], int s, int m, int e)
{
    int j = m-s+1;
    int k = e-m;
    int a1[j+1];
    int a2[k+1];
    a1[j] = a2[k] = INT_MAX;
    for(int i = s; i<=m; i++)
        a1[i-s] = A[i];

    for(int i = m+1; i<=e; i++)
        a2[i-m-1] = A[i];

    int f = 0, l = 0, p = s;
    while(f<j || l<k)
    {
        if(a1[f]< a2[l]){
            A[p] = a1[f];
            f++; }
        else{
            A[p] = a2[l];
            l++; }
        p++;
    }
}
void MergeSort(int A[], int s, int e)
{
    if(s<e){
        int index = (s+e)/2;
        MergeSort(A, s, index);
        MergeSort(A, index+1, e);
        Merge(A, s, index, e);
    }
}
int main()
{
    int arr_size;
    cout<<"Enter number of elements :";
    cin>>arr_size;
    int arr[arr_size];
    cout<<"Enter the array elements :";
    for(int i=0; i<arr_size; i++){
        cin>>arr[i]; }
    int start = 0;
    int end =arr_size-1 ;
    MergeSort(arr, start, end);
    for(int i = 0; i<=end; i++){
        cout<< arr[i] << " ";
    }
}
