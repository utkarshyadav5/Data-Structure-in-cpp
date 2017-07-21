#include <bits/stdc++.h>

using namespace std;

// Fibonacci in O(log n)

// Recursive Solution

int sq(int n){
    return n*n;
}

// int fib(int n){
//     if(n==0 ||n==1)
//         return n;

//     if(n & 1){
//         int k=(n+1)/2;
//         return (sq(fib(k))+sq(fib(k-1)));
//     }
//     else{
//         int k=n/2;
//         int fib_k=fib(k);
//         int fib_k_1=fib(k-1);
//         return (sq(fib_k)+2*fib_k*fib_k_1);
//     }
// }

// Memoization Method - Top to Bottom

int dp[1000];

int fib_util(int n){
    if(dp[n]==-1){
        if(n==0 || n==1)
            dp[n]=n;
        else{
            int k;
            if(n&1){
                k=(n+1)/2;
                int fib_k=fib_util(k);
                int fib_k_1=fib_util(k-1);
                dp[n]=sq(fib_k)+sq(fib_k_1);
            }
            else{
                k=n/2;
                int fib_k=fib_util(k);
                int fib_k_1=fib_util(k-1);
                dp[n]=sq(fib_k)+2*fib_k_1*fib_k;
            }
        }
    }
    return dp[n];
}

int fib(int n){
    for(int i=0;i<=n;i++)
        dp[i]=-1;

    fib_util(n);

    for(int i=0;i<=n;i++)
        cout<<dp[i]<<" ";
    cout<<endl;

    return dp[n];
}


int main(){
    int n = 9;
    cout<<fib(n)<<endl;
    return 0;
}







