#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

// int min_cost(int arr[3][3],int m,int n){
//     if(n<0 || m<0)
//         return INT_MAX;
//     else if(m==0 && n==0)
//         return arr[m][n];
//     else
//         return arr[m][n]+min(min(min_cost(arr,m-1,n-1),min_cost(arr,m,n-1)),
//                     min_cost(arr,m-1,n));
// }

int dp[3][3];

int min_cost(int arr[3][3],int m,int n){
    if(n<0 || m<0)
        return INT_MAX;

    if(dp[m][n]!=(-1))
        return dp[m][n];
    if(m==0 && n==0)
        return dp[m][n];
    else{
        dp[m][n]=arr[m][n]+min(min(min_cost(arr,m-1,n-1),min_cost(arr,m,n-1)),
                    min_cost(arr,m-1,n));
        return dp[m][n];
    }
}

int main(){
    int cost[][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            dp[i][j]=(-1);
        }
    }
    dp[0][0]=cost[0][0];
    cout<<min_cost(cost, 2, 2)<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}