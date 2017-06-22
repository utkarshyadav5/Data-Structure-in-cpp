#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

int editDist(string s1,string s2,int m,int n){
    if(m==0)
        return n;
    if(n==0)
        return m;

    if(s1[m-1]==s2[n-1])
        return editDist(s1,s2,m-1,n-1);
    else{
        int insert=editDist(s1,s2,m,n-1);
        int remove=editDist(s1,s2,m-1,n);
        int replace=editDist(s1,s2,m-1,n-1);
        return 1+min(min(insert,remove),replace);
    }
}

int editDist(string s1,string s2,int m,int n){
    int dp[m+1][n+1];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else{
                dp[i][j]=1+min(min(dp[i][j-1],
                                    dp[i-1][j]),
                                    dp[i-1][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main(){
    string s1 = "sunday";
    string s2 = "saturday";


    cout<<editDist(s1,s2,s1.length(),s2.length())<<endl;

    return 0;
}