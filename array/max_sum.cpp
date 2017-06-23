#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

int FindMaxSum(int arr[],int n){
    int incl=arr[0];
    int exc=0;
    int exc_new;

    for(int i=1;i<n;i++){
        exc_new=max(incl,exc);
        incl=exc+arr[i];
        exc=exc_new;
    }
    return max(incl,exc);
}

int main(){
    int arr[] = {5, 5, 10, 100, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<FindMaxSum(arr, n)<<endl;
    return 0;
}





















