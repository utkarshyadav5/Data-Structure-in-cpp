#include <bits/stdc++.h>
#define n 3

using namespace std;

int dp[100][100];

int findLongestOverAll_Util(int i,int j,int mat[][n]){
    if(i<0 || i>n-1 || j<0 || j>n-1)
        return 0;

    if(dp[i][j]==-1){
        if(i>0 && mat[i][j]+1==mat[i-1][j])
            dp[i][j]=1+findLongestOverAll_Util(i-1,j,mat);
        else if(i<n-1 && mat[i][j]+1==mat[i+1][j])
            dp[i][j]=1+findLongestOverAll_Util(i+1,j,mat);
        else if(j>0 && mat[i][j]+1==mat[i][j-1])
            dp[i][j]=1+findLongestOverAll_Util(i,j-1,mat);
        else if(j<n-1 && mat[i][j]+1==mat[i][j+1])
            dp[i][j]=1+findLongestOverAll_Util(i,j+1,mat);
        else
            dp[i][j]=1;
    }
    return dp[i][j];
}

int findLongestOverAll(int mat[][n]){
    int result=0;
    dp[n][n];
    memset(dp,-1,sizeof(dp));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int longest = findLongestOverAll_Util(i,j,mat);
            result=max(result,longest);
        }
    }

    return result;
}

int main(){
    int  mat[n][n] = {{1, 2, 9},
                    {5, 3, 8},
                    {4, 6, 7}};
   cout << "Length of the longest path is "
        << findLongestOverAll(mat)<<endl;
   return 0;
}
















