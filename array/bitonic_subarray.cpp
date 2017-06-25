#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

int bitonic(int arr[],int n){
    int left[n],right[n],maxe=0;

    left[0]=1,right[n-1]=1;
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1])
            left[i]=1+left[i-1];
        else
            left[i]=1;
    }

    for(int i=n-2;i>=0;i--){
        if(arr[i]>=arr[i+1])
            right[i]=1+right[i+1];
        else
            right[i]=1;
    }

    for(int i=0;i<n;i++)
        maxe=max(maxe,left[i]+right[i]-1);

    return maxe;
}

int main(){
    int arr[] = {12, 4, 78, 90, 45, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of max length Bitnoic Subarray is %d\n",
            bitonic(arr, n));
    return 0;
}





















