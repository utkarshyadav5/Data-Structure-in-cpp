#include <bits/stdc++.h>

using namespace std;

// Recursive solution

// bool findPartiionUtil(int *arr,int n,int sum){
//     if(n==0 && sum!=0)
//         return false;
//     else if(sum==0)
//         return true;
//     else
//         return findPartiionUtil(arr,n-1,sum-arr[n-1])||
//                 findPartiionUtil(arr,n-1,sum);
// }

// bool findPartiion(int *arr,int n){
//     int sum=0;
//     for(int i=0;i<n;i++)
//         sum+=arr[i];

//     if(sum & 1)
//         return false;
//     else
//         return findPartiionUtil(arr,n,sum/2);
// }

// Tabular Method - Bottom to Top

// bool findPartiion(int *arr,int n){
//     int sum=0;
//     for(int i=0;i<n;i++)
//         sum+=arr[i];

//     if(sum & 1)
//         return false;
//     else{
//         bool dp[sum/2+1][n+1];

//         for(int i=0;i<=n;i++)
//             dp[0][i]=true;

//         for(int i=1;i<=sum/2;i++)
//             dp[i][0]=false;

//         for(int i=1;i<=sum/2;i++){
//             for(int j=1;j<=n;j++){
//                 dp[i][j]=dp[i][j-1];
//                 if(i>=arr[j-1])
//                     dp[i][j]=dp[i][j]||dp[i-arr[j-1]][j-1];
//             }
//         }

//         for(int i=0;i<=sum/2;i++){
//             for(int j=0;j<n;j++)
//                 cout<<dp[i][j]<<" ";
//             cout<<endl;
//         }

//         return dp[sum/2][n];
//     }
// }

// Memoization - Top to Bottom

int dp[1000][1000];

bool findPartiionUtil(int *arr,int n,int sum){
    if(dp[sum][n]==-1){
        if(n==0 && sum!=0)
            dp[sum][n]=0;
        else if(sum==0)
            dp[sum][n]=1;
        else{
            dp[sum][n]=findPartiionUtil(arr,n-1,sum);
            if(sum-arr[n]>=0)
                dp[sum][n]=dp[sum][n]||findPartiionUtil(arr,n-1,sum-arr[n]);
        }
    }
    return dp[sum][n];
}

bool findPartiion(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];

    if(sum & 1)
        return false;
    else{
        for(int i=0;i<=sum/2;i++){
            for(int j=0;j<n;j++)
                dp[i][j]=-1;
        }

        findPartiionUtil(arr,n-1,sum/2);

        for(int i=0;i<=sum/2;i++){
            for(int j=0;j<n;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }

        return dp[sum/2][n-1];
    }
}


int main(){
    int arr[] = {3, 1, 1, 2, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    if (findPartiion(arr, n) == true)
        cout<<"Can be divided into two subsets of equal sum"<<endl;
    else
        cout<<"Can not be divided into two subsets of equal sum"<<endl;
    return 0;
}







