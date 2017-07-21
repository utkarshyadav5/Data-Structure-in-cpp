#include <bits/stdc++.h>

using namespace std;

int cube(int n){
    return (n*n*n);
}

// Recursive solution

int word_wrap(int *arr,int index,int n,int m,int original_m){
    if(index==n)
        return 0;
    if(m<0 || arr[index]>m)
        return INT_MAX;

    int cost=cube(m-arr[index]);
    int min_val=cost+word_wrap(arr,index+1,n,original_m,original_m);
    if(index+1!=n){
        int dont=word_wrap(arr,index+1,n,(m-arr[index]-1),original_m);
        min_val=min(min_val,dont);
    }

    return min_val;
}

// Tabular Method - Bottom to Top


// Memoization - Top to Bottom

// int dp[100][100];

// int word_wrap_Util(int *arr,int index,int n,int m,int original_m){
//     if(dp[index][m]==-1){
//         if(index==n)
//             dp[index][m]=0;
//         else if(arr[index]>m)
//             dp[index][m]=INT_MAX;
//         else{
//             int cost=cube(m-arr[index]);
//             int min_val=cost+word_wrap_Util(arr,index+1,n,original_m,original_m);
//             if(index+1!=n){
//                 int dont=word_wrap_Util(arr,index+1,n,(m-arr[index]-1),original_m);
//                 min_val=min(min_val,dont);
//             }
//             dp[index][m]=min_val;
//         }
//     }
//     return dp[index][m];
// }

// int word_wrap(int *arr,int index,int n,int m,int o_m){
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=m;j++)
//             dp[i][j]=-1;
//     }

//     word_wrap_Util(arr,0,n,m,o_m);

//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=m;j++)
//             cout<<dp[i][j]<<" ";
//         cout<<endl;
//     }
//     return dp[n][m];
// }





int main(){
    //int l[] = {5,3,5,8,4,4,7};
    int l[] = {3, 2, 2, 5};
    int n = sizeof(l)/sizeof(l[0]);
    int m = 6;
    cout<<word_wrap(l,0,n,m,m)<<endl;
    return 0;
}







