#include <bits/stdc++.h>
#define r 4

using namespace std;

void search(int matrix[][r],int n,int x){
    int i=0,j=n-1;

    while(i<n && j>=0){
        if(matrix[i][j]==x){
            cout<<"Element found at "<<i<<" "<<j<<endl;
            return;
        }
        if(matrix[i][j]<x)
            i++;
        else
            j--;
    }
}

int main()
{
  int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  search(mat, 4, 29);
  return 0;
}