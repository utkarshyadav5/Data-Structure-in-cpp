#include <bits/stdc++.h>

using namespace std;

// Recursive solution

// int eggDrop(int n,int k){
//     if(k==0 || k==1 || n==1)
//         return k;

//     int minimum=INT_MAX;
//     for(int i=1;i<=k;i++)
//         minimum=min(minimum,1+max(eggDrop(n-1,i-1),eggDrop(n,k-i)));
//     return minimum;

// }

// Tabular Method - Bottom to Top

// int eggDrop(int n,int k){
//     int dp[n+1][k+1];

//     for(int i=0;i<=n;i++){
//         dp[i][1]=1;
//         dp[i][0]=0;
//     }

//     for(int i=1;i<=k;i++)
//         dp[1][i]=i;

//     for(int i=2;i<=n;i++){
//         for(int j=2;j<=k;j++){
//             int minimum=INT_MAX;
//             for(int l=1;l<=j;l++){
//                 minimum=min(minimum,1+max(dp[i-1][l-1],dp[i][j-l]));
//             }
//             dp[i][j]=minimum;
//         }
//     }

//     for(int i=1;i<=n;i++){
//         for(int j=0;j<=k;j++)
//             cout<<dp[i][j]<<" ";
//         cout<<endl;
//     }
//     return dp[n][k];
// }

// Memoization Method - Top to Bottom

int dp[100][100];

int eggDropUtil(int n,int k){
    if(dp[n][k]==-1){
        if(k==0 || k==1 || n==1)
            dp[n][k]=k;
        else{
            int minimum=INT_MAX;
            for(int i=1;i<=k;i++){
                minimum=min(minimum,1+max(eggDropUtil(n-1,i-1),eggDropUtil(n,k-i)));
            }
            dp[n][k]=minimum;
        }
    }
    return dp[n][k];
}

int eggDrop(int n,int k){
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++)
            dp[i][j]=-1;
    }

    eggDropUtil(n,k);

    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[n][k];
}

int main(){
    int n = 2, k = 10;
    cout<<eggDrop(n, k)<<endl;
    return 0;
}