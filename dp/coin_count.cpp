#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

// Recursive solution

// int count(int arr[],int size,int money){
//     if(money==0)
//         return 1;
//     if(money<0)
//         return 0;

//     if(size<=0 && money>=1)
//         return 0;

//     return count(arr,size-1,money)+count(arr,size,money-arr[size-1]);
// }

// Tabular method - Bottom to top

// int count(int arr[],int m,int n){
//     int dp[m+1][n+1];

//     for(int i=0;i<=m;i++)
//         dp[i][0]=1;

//     for(int i=1;i<=n;i++)
//         dp[0][i]=0;

//     for(int i=1;i<=m;i++){
//         for(int j=1;j<=n;j++){
//             dp[i][j]=dp[i-1][j];
//             if(j-arr[i-1]>=0)
//                 dp[i][j]+=dp[i][j-arr[i-1]];
//         }
//     }

//     for(int i=0;i<=m;i++){
//         for(int j=0;j<=n;j++)
//             cout<<dp[i][j]<<" ";
//         cout<<endl;
//     }

//     return dp[m][n];
// }

// Memoization Method

int dp[100][100];

int countUtil(int arr[],int m,int n){
    if(n<0)
        return 0;

    if(dp[m][n]==-1){
        if(n==0)
            dp[m][n]=1;
        else if(m==0)
            dp[m][n]=0;
        else
            dp[m][n]=countUtil(arr,m-1,n)+countUtil(arr,m,n-arr[m-1]);
    }
    return dp[m][n];
}

int count(int arr[],int m,int n){
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
            dp[i][j]=-1;
    }
    countUtil(arr,m,n);
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[m][n];
}

int main(){
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    cout<<count(arr, m, 4)<<endl;
    return 0;
}