#include <bits/stdc++.h>
#define n 5

using namespace std;

void printSumTricky(int mat[][n],int k){

    if(k>n)
        return;

    int subMat[n][n];

    for(int j=0;j<n;j++){

        int sum=0;
        for(int i=0;i<k;i++)
            sum+=mat[i][j];
        subMat[0][j]=sum;

        for(int i=1;i<n-k+1;i++){
            sum+=(mat[i+k-1][j]-mat[i-1][j]);
            subMat[i][j]=sum;
        }
    }

    for(int i=0;i<n-k+1;i++){
        int sum=0;
        for(int j=0;j<k;j++)
            sum+=subMat[i][j];
        cout<<sum<<" ";

        for(int j=1;j<n-k+1;j++){
            sum+=(subMat[i][j+k-1]-subMat[i][j-1]);
            cout<<sum<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int mat[n][n] = {{1, 1, 1, 1, 1},
                     {2, 2, 2, 2, 2},
                     {3, 3, 3, 3, 3},
                     {4, 4, 4, 4, 4},
                     {5, 5, 5, 5, 5},
                    };
    int k = 3;
    printSumTricky(mat, k);
    return 0;
}
















