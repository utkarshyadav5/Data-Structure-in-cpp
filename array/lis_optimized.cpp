#include <bits/stdc++.h>

using namespace std;

int getCeil(int arr[],vector<int> &temp,int start,int end,int key){
    while(end-start>1){
        int mid=(start+end)/2;

        if(arr[temp[mid]]>=key)
            end=mid;
        else
            start=mid;
    }
    return end;
}

int LongestIncreasingSubsequence(int arr[],int n){

    vector<int> temp(n,0);
    vector<int> result(n,-1);

    int len=1;

    for(int i=1;i<n;i++){

        if(arr[i]<arr[temp[0]])
            temp[0]=i;

        else if(arr[i]>arr[temp[len-1]]){
            result[i]=temp[len-1];
            temp[len++]=i;
        }

        else{
            int pos=getCeil(arr,temp,-1,len-1,arr[i]);

            result[i]=temp[pos-1];
            temp[pos]=i;
        }
    }

    cout<<"LIS of given input"<<endl;
    for(int i=temp[len-1];i>=0;i=result[i])
        cout<<arr[i]<<" ";
    cout<<endl;

    return len;
}

int main(){
    int arr[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("LIS size %d\n", LongestIncreasingSubsequence(arr, n));
    return 0;
}





















