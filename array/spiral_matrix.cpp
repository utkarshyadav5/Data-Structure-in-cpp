#include <bits/stdc++.h>
#define R 3
#define C 6

using namespace std;

void spiralPrint(int row,int col,int arr[R][C]){
    int top=0,bottom=row-1,left=0,right=col-1,i;

    while(top<=bottom && left<=right){

        for(i=left;i<=right;i++)
            cout<<arr[top][i]<<" ";
        top++;

        for(i=top;i<=bottom;i++)
            cout<<arr[i][right]<<" ";
        right--;

        if(top<bottom){
            for(i=right;i>=left;i--)
                cout<<arr[bottom][i]<<" ";
            bottom--;
        }

        if(left<right){
            for(int i=bottom;i>=top;i--)
                cout<<arr[i][left]<<" ";
            left++;
        }
    }
    cout<<endl;
}

int main(){
    int a[R][C] = { {1,  2,  3,  4,  5,  6},
                    {7,  8,  9,  10, 11, 12},
                    {13, 14, 15, 16, 17, 18}
    };
    spiralPrint(R, C, a);
    return 0;
}