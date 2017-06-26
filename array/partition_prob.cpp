#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

// bool isSubsetSum(int arr[],int n,int sum){
//     if(sum==0)
//         return true;

//     if(n==0 && sum!=0)
//         return false;

//     if(arr[n-1]>sum)
//         return isSubsetSum(arr,n-1,sum);

//     return isSubsetSum(arr,n-1,sum) || isSubsetSum(arr,n-1,sum-arr[n-1]);
// }

// bool findPartiion(int arr[],int n){
//     int sum=0;

//     for(int i=0;i<n;i++)
//         sum+=arr[i];

//     if(sum%2)
//         return false;
//     else
//         return isSubsetSum(arr,n,sum/2);
// }


bool findPartiion (int arr[], int n){
    int sum=0;

    for(int i=0;i<n;i++)
        sum+=arr[i];

    if(sum%2)
        return false;

    bool part[sum/2+1][n+1];

    for(int i=0;i<=n;i++)
        part[0][i]=true;

    for(int i=1;i<=sum/2;i++)
        part[i][0]=false;

    for(int i=1;i<=sum/2;i++){
        for(int j=1;j<=n;j++){
            part[i][j]=part[i][j-1];
            if(i>=arr[j-1])
                part[i][j]=part[i][j] || part[i-arr[j-1]][j-1];
        }
    }

    for(int i=0;i<=sum/2;i++){
        for(int j=0;j<=n;j++)
            cout<<part[i][j]<<" ";
        cout<<endl;
    }


    return part[sum/2][n];
}

int main(){
    int arr[] = {3,1,1,2,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    if (findPartiion(arr, n) == true)
        printf("Can be divided into two subsets "
            "of equal sum\n");
    else
        printf("Can not be divided into two subsets"
            " of equal sum\n");
    return 0;
}





















