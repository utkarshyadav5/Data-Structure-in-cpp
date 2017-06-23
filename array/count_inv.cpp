#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

//Count Inversion Using Merge Sort

int merge(int arr[],int temp[],int start,int mid,int end){
    int i,j,k,inv_count=0;
    i=start;
    j=mid;
    k=start;

    while((i<=mid-1) && (j<=end)){
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else{
            temp[k++]=arr[j++];
            inv_count+=(mid-i);
        }
    }
    while(i<=mid-1)
        temp[k++]=arr[i++];
    while(j<=end)
        temp[k++]=arr[j++];

    for(int i=start;i<=end;i++)
        arr[i]=temp[i];

    return inv_count;
}

int _mergeSort(int arr[],int temp[],int start,int end){
    int inv_count=0;
    if(start<end){
        int mid=(start+end)/2;
        inv_count=_mergeSort(arr,temp,start,mid);
        inv_count+=_mergeSort(arr,temp,mid+1,end);
        inv_count+=merge(arr,temp,start,mid+1,end);
    }
    return inv_count;
}

int mergeSort(int arr[],int size){
    int *temp= new int[size];
    return _mergeSort(arr,temp,0,size-1);
}

int main(){
    int arr[] = {1, 20, 6, 4, 5};
    cout<<"Number of inversions are "<<mergeSort(arr, 5)<<endl;
    return 0;
}





















