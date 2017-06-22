#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

int arr[MAX][MAX];

// int lcs(string s1,string s2,int m,int n){
//     if(m==0 || n==0){
//         return arr[m][n];
//     }

//     if(arr[m][n]==(-1)){
//         if(s1[m]==s2[n])
//             arr[m][n]=1+lcs(s1,s2,m-1,n-1);
//         else
//             arr[m][n]=max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
//         return arr[m][n];
//     }
//     else
//         return arr[m+1][n+1];
// }

int lcs( string X,string Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;

   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }

   for (i=0; i<=m; i++){
        for (j=0; j<=n; j++)
            cout<<L[i][j]<<" ";
        cout<<endl;
    }
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}

int main(){
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    // for(int i=0;i<=s1.length();i++){
    //     for(int j=0;j<=s2.length();j++){
    //         if(i==0 || j==0)
    //             arr[i][j]=0;
    //         else
    //             arr[i][j]=(-1);
    //     }
    // }
    cout<<"Length of LCS is "<<lcs(s1,s2,s1.length(),s2.length())<<endl;

    // for(int i=0;i<=s1.length();i++){
    //     for(int j=0;j<=s2.length();j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}