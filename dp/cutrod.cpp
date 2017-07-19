#include <bits/stdc++.h>

using namespace std;

// Recursive solution

// int cutRod(int *arr,int n){
//     if(n<=0)
//         return 0;

//     int max_val=INT_MIN;
//     for(int i=0;i<n;i++)
//         max_val=max(max_val,arr[i]+cutRod(arr,n-i-1));

//     return max_val;
// }

// Tabular Method - Bottom to Top

// int cutRod(int *arr,int n){
//     int dp[n+1];

//     for(int i=0;i<=n;i++){
//         if(i==0)
//             dp[i]=0;
//         else{
//             int max_val=INT_MIN;
//             for(int j=0;j<i;j++)
//                 max_val=max(max_val,arr[i]+dp[i-j-1]);
//             dp[i]=max_val;
//         }
//     }

//     for(int i=0;i<=n;i++)
//         cout<<dp[i]<<" ";
//     cout<<endl;

//     return dp[n];
// }

// Memoization - Top to Bottom

int dp[100];

int cutRodUtil(int *arr,int n){
    if(dp[n]==-1){
        if(n==0)
            dp[n]=0;
        else{
            int max_val=INT_MIN;
            for(int i=0;i<n;i++)
                max_val=max(max_val,arr[i]+cutRodUtil(arr,n-i-1));
            dp[n]=max_val;
        }
    }
    return dp[n];
}

int cutRod(int *arr,int n){

    for(int i=0;i<=n;i++)
        dp[i]=-1;

    cutRodUtil(arr,n);

    for(int i=0;i<=n;i++)
        cout<<dp[i]<<" ";
    cout<<endl;

    return dp[n];
}

int main(){
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<cutRod(arr, size)<<endl;
    return 0;
}