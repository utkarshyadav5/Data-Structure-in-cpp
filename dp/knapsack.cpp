#include <bits/stdc++.h>

using namespace std;

// Recursive solution

// int knapSack(int W,int wt[],int val[],int n){
//     if(n==0 || W==0)
//         return 0;

//     if(W<wt[n-1])
//         return knapSack(W,wt,val,n-1);
//     else
//         return max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
// }

// Tabular Method - Bottom to Top

// int knapSack(int W,int wt[],int val[],int n){
//     int dp[W+1][n+1];

//     for(int i=0;i<=W;i++){
//         for(int j=0;j<=n;j++){
//             dp[i][j]=-1;
//         }
//     }

//     for(int i=0;i<=W;i++){
//         for(int j=0;j<=n;j++){
//             if(n==0 || W==0)
//                 dp[i][j]=0;
//             else if(i<wt[j-1])
//                 dp[i][j]=dp[i][j-1];
//             else
//                 dp[i][j]=max(val[j-1]+dp[i-wt[j-1]][j-1],dp[i][j-1]);
//         }
//     }

//     for(int i=0;i<=W;i++){
//         for(int j=0;j<=n;j++)
//             cout<<dp[i][j]<<" ";
//         cout<<endl;
//     }
//     return dp[W][n];
// }

// Memoization - Top to Bottom

int dp[1000][1000];

int knapSackUtil(int W,int wt[],int val[],int n){
    if(dp[W][n]==-1){
        if(W==0 || n==0)
            dp[W][n]=0;
        else if(W<wt[n-1])
            dp[W][n]=knapSackUtil(W,wt,val,n-1);
        else
            dp[W][n]=max(val[n-1]+knapSackUtil(W-wt[n-1],wt,val,n-1),knapSackUtil(W,wt,val,n-1));
    }
    return dp[W][n];
}

int knapSack(int W,int wt[],int val[],int n){
    for(int i=0;i<=W;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }

    knapSackUtil(W,wt,val,n);

    for(int i=0;i<=W;i++){
        for(int j=0;j<=n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[W][n];
}





int main(){
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapSack(W, wt, val, n)<<endl;
    return 0;
}