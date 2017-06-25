#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

//Solved using LIS approach

int maxSumIS(int arr[],int n){
    int sum[n],maxe=0;
    for(int i=0;i<n;i++)
        sum[i]=arr[i];

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j])
                sum[i]+=arr[j];
        }
    }

    for(int i=0;i<n;i++)
        maxe=max(maxe,sum[i]);
    return maxe;
}



int main(){
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Sum of maximum sum increasing subsequence is %d\n",
           maxSumIS( arr, n ) );
    return 0;
}





















