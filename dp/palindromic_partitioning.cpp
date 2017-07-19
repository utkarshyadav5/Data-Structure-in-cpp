#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(char* arr,int start,int end){
    while(start<end){
        if(arr[start]==arr[end]){
            start++;end--;
        }
        else
            return false;
    }
    return true;
}

// Recursive solution

// int minPalPartion(char *arr,int start,int end){
//     if(start==end)
//         return 0;

//     if(isPalindrome(arr,start,end))
//         return 0;

//     int min_val=INT_MAX;
//     for(int i=start;i<end;i++){
//         int count=1+minPalPartion(arr,start,i)+minPalPartion(arr,i+1,end);
//         min_val=min(min_val,count);
//     }
//     return min_val;
// }

// Tabular Method - Bottom to Top


// Memoization - Top to Bottom

int dp[100][100];

int minPalPartionUtil(char *arr,int start,int end){
    if(dp[start][end]==-1){
        if(start==end)
            dp[start][end]=0;
        else if(isPalindrome(arr,start,end))
            dp[start][end]=0;
        else{
            int min_val=INT_MAX;
            for(int i=start;i<end;i++){
                int count=1+minPalPartionUtil(arr,start,i)+minPalPartionUtil(arr,i+1,end);
                min_val=min(min_val,count);
            }
            dp[start][end]=min_val;
        }
    }
    return dp[start][end];
}

int minPalPartion(char *arr){
    int n=strlen(arr);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            dp[i][j]=-1;
    }

    minPalPartionUtil(arr,0,n-1);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[0][n-1];
}




int main(){
    char str[] = "ababbbabbababa";
    int n=strlen(str);
    cout<<minPalPartion(str)<<endl;
}







