#include <bits/stdc++.h>

using namespace std;

int findPeak(int arr[],int n,int start,int end){
    int mid=(start+end)/2;

    if(mid==0 || arr[mid]>=arr[mid-1] && mid==n-1 || arr[mid]>=arr[mid+1])
        return mid;

    else if(mid>0 && arr[mid]<arr[mid-1])
        return findPeak(arr,n,start,mid-1);

    else
        return findPeak(arr,n,mid+1,end);
}

int main(){
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Index of a peak point is %d\n", findPeak(arr, n,0,n-1));
    return 0;
}





















