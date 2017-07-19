#include <bits/stdc++.h>

using namespace std;

// Recursive solution

// int lps(char *str,int start,int end){
//     if(start==end)
//         return 1;
//     else if(start>end)
//         return 0;
//     else{
//         if(str[start]==str[end])
//             return 2+lps(str,start+1,end-1);
//         else
//             return max(lps(str,start+1,end),lps(str,start,end-1));
//     }
// }

// Tabular Method - Bottom to Top

// int lps(char *str){
//     int n=strlen(str);
//     int dp[n][n];

    // for (cl=2; cl<=n; cl++)
    // {
    //     for (i=0; i<n-cl+1; i++)
    //     {
    //         j = i+cl-1;
    //         if (str[i] == str[j] && cl == 2)
    //            L[i][j] = 2;
    //         else if (str[i] == str[j])
    //            L[i][j] = L[i+1][j-1] + 2;
    //         else
    //            L[i][j] = max(L[i][j-1], L[i+1][j]);
    //     }
    // }

//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++)
//             cout<<dp[i][j]<<" ";
//         cout<<endl;
//     }

//     return dp[0][n-1];
// }

// Memoization - Top to Bottom

int dp[100][100];

int lpsUtil(char *seq,int start,int end){
    if(dp[start][end]==-1){
        if(start==end)
            dp[start][end]=1;
        else if(end<start)
            dp[start][end]=0;
        else{
            if(seq[start]==seq[end])
                dp[start][end]=2+lpsUtil(seq,start+1,end-1);
            else
                dp[start][end]=max(lpsUtil(seq,start+1,end),lpsUtil(seq,start,end-1));
        }
    }
    return dp[start][end];
}

int lps(char *seq){
    int n=strlen(seq);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            dp[i][j]=-1;
    }

    lpsUtil(seq,0,n-1);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[0][n-1];
}

int main(){
    char seq[] = "GEEKS FOR GEEKS";
    int n = strlen(seq);
    cout<<lps(seq)<<endl;
    return 0;
}









