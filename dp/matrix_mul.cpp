#include <bits/stdc++.h>

using namespace std;

// Recursive solution

// int MatrixChainOrder(int *arr,int start,int end){
//     if(start==end)
//         return 0;

//     int min_val=INT_MAX;
//     for(int i=start;i<end;i++){
//         int count=MatrixChainOrder(arr,start,i)+
//                     MatrixChainOrder(arr,i+1,end)+arr[start-1]*arr[i]*arr[end];
//         min_val=min(min_val,count);
//     }
//     return min_val;
// }

// Tabular Method - Bottom to Top


// Memoization - Top to Bottom

int dp[1000][1000];

int MatrixChainOrderUtil(int *arr,int start,int end){
    if(dp[start][end]==-1){
        if(start==end)
            dp[start][end]=0;
        else{
            int min_val=INT_MAX;
            for(int i=start;i<end;i++){
                int count=MatrixChainOrderUtil(arr,start,i)+MatrixChainOrderUtil(arr,i+1,end)
                            +arr[start-1]*arr[i]*arr[end];
                min_val=min(min_val,count);
            }
            dp[start][end]=min_val;
        }
    }
    return dp[start][end];
}


int MatrixChainOrder(int *arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            dp[i][j]=-1;
    }

    MatrixChainOrderUtil(arr,1,n-1);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[1][n-1];
}




int main(){
    int arr[] = {1, 2, 3, 4,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<MatrixChainOrder(arr, n)<<endl;
    return 0;
}







