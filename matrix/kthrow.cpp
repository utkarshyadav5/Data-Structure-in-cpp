#include <bits/stdc++.h>
#define n 5

using namespace std;

int find(bool mat[][n]){

    int i=0,j=n-1;
    int res=-1;

    while(i<n && j>=0){
        if(mat[i][j]==0){

            while(j>=0 && mat[i][j]==0 || i==j)
                j--;

            if(j==-1){
                res=i;
                break;
            }
            else
                i++;

        }
        else{

            while(i<n && mat[i][j]==1 || i==j)
                i++;

            if(i==n){
                res=j;
                break;
            }
            else
                j--;
        }
    }
    if(res==-1)
        return res;

    for(int i=0;i<n;i++)
        if(res!=i && mat[i][res]!=1)
            return -1;
    for(int j=0;j<n;j++)
        if(res!=j && mat[res][j]!=0)
            return -1;

    return res;
}

int main(){
    bool mat[n][n] = {{0, 0, 1, 1, 0},
                      {0, 0, 0, 1, 0},
                      {1, 1, 1, 1, 0},
                      {0, 0, 0, 0, 0},
                      {1, 1, 1, 1, 1}};
    cout << find(mat)<<endl;
}
















