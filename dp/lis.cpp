#include <bits/stdc++.h>

using namespace std;

int lis(int arr[],int n){
    int maxe[n];
    for(int i=0;i<n;i++)
        maxe[i]=1;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i])
                maxe[i]=max(maxe[i],1+maxe[j]);
        }
    }
    int maximum;
    for(int i=0;i<n;i++){
        cout<<maxe[i]<<" ";
        maximum=max(maxe[i],maximum);
    }
    cout<<endl;
    return maximum;
}

int main(){
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Length of lis is "<<lis(arr,n)<<endl;
    return 0;
}