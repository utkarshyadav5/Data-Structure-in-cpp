#include <bits/stdc++.h>

using namespace std;

// Recursive solution

// int binomialCoeff(int n,int k){
//     if(n==k || k==0)
//         return 1;
//     else
//         return binomialCoeff(n-1,k-1)+binomialCoeff(n-1,k);
// }

// Tabular method - Bottom to top

// int binomialCoeff(int n,int k){
//     int dp[n+1][k+1];

//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=k;j++){
//             if(i==j || j==0)
//                 dp[i][j]=1;
//             else
//                 dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
//         }
//     }

//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=k;j++)
//             cout<<dp[i][j]<<" ";
//         cout<<endl;
//     }

//     return dp[n][k];
// }

// Memoization method - Top to Bottom

int dp[100][100];

int binomialCoeffUtil(int n,int k){
    if(dp[n][k]==(-1)){
        if(n==k || k==0)
            dp[n][k]=1;
        else
            dp[n][k]=binomialCoeffUtil(n-1,k-1)+binomialCoeffUtil(n-1,k);
    }

    return dp[n][k];
}

int binomialCoeff(int n,int k){

    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++)
            dp[i][j]=-1;
    }

    binomialCoeffUtil(n,k);

    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    return dp[n][k];
}

int main(){
    int n = 5, k = 2;
    cout<<binomialCoeff(n, k)<<endl;
    return 0;
}










