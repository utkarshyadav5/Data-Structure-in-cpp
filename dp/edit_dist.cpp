#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

//Recursive method

// int editDist(string s1,string s2,int m,int n){
//     if(m==0)
//         return n;
//     if(n==0)
//         return m;

//     if(s1[m-1]==s2[n-1])
//         return editDist(s1,s2,m-1,n-1);
//     else{
//         int insert=editDist(s1,s2,m,n-1);
//         int remove=editDist(s1,s2,m-1,n);
//         int replace=editDist(s1,s2,m-1,n-1);
//         return 1+min(min(insert,remove),replace);
//     }
// }

// Tabular method - Bottom to top

int editDist(string str1,string str2,int m,int n){
    int dp[m+1][n+1];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(str1[i]==str2[j])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
        }
    }

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    return dp[m][n];
}

// Memoization method - Top to bottom

// int dist[1000][1000];

// int editDistUtil(string str1,string str2,int m,int n){
//     if(dist[m][n]!=-1)
//         return dist[m][n];
//     else{
//         if(m==0 || n==0){
//             if(m==0)
//                 dist[m][n]=n;
//             else if(n==0)
//                 dist[m][n]=m;
//         }
//         else{
//             if(str1[m-1]==str2[n-1])
//                 dist[m][n]=editDistUtil(str1,str2,m-1,n-1);
//             else
//                 dist[m][n]=1+min(min(editDistUtil(str1,str2,m,n-1),editDistUtil(str1,str2,m-1,n))
//                             ,editDistUtil(str1,str2,m-1,n-1));
//         }
//         return dist[m][n];
//     }
// }

// int editDist(string str1,string str2,int m,int n){
//     for(int i=0;i<=m;i++){
//         for(int j=0;j<=n;j++)
//             dist[i][j]=-1;
//     }
//     editDistUtil(str1,str2,m,n);
//     for(int i=0;i<=m;i++){
//         for(int j=0;j<=n;j++)
//             cout<<dist[i][j]<<" ";
//         cout<<endl;
//     }

//     return dist[m][n];
// }

int main(){
    string s1 = "sunday";
    string s2 = "saturday";


    cout<<editDist(s1,s2,s1.length(),s2.length())<<endl;

    return 0;
}