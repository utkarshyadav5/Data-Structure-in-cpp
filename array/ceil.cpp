#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

//Ceiling

int ceilSearch(int arr[],int start,int end,int key){
    if(key <= arr[start])
        return start;

    if(key> arr[end])
        return -1;

    int mid=(start+end)/2;

    if(arr[mid]==key)
        return mid;

    else if(key<arr[mid]){
        if(mid-1>=start && arr[mid-1]<key)
            return mid-1;
        return ceilSearch(arr,start,mid-1,key);
    }
    else{
        if(mid+1<=end && arr[mid+1]>=key)
            return mid+1;
        return ceilSearch(arr,mid+1,end,key);
    }
}

int main(){
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 11;
    int index = ceilSearch(arr, 0, n-1, x);
    if(index == -1)
        printf("Ceiling of %d doesn't exist in array \n", x);
    else
        printf("Ceiling of %d is %d \n", x, arr[index]);
    return 0;
}





















