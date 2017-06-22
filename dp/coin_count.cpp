#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

// int count(int arr[],int size,int money){
//     if(money==0)
//         return 1;
//     if(money<0)
//         return 0;

//     if(size<=0 && money>=1)
//         return 0;

//     return count(arr,size-1,money)+count(arr,size,money-arr[size-1]);
// }

int count( int S[], int m, int n )
{
    int i, j, x, y;

    // We need n+1 rows as the table is consturcted in bottom up manner using
    // the base case 0 value case (n = 0)
    int table[n+1][m];

    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[0][i] = 1;

    // Fill rest of the table enteries in bottom up manner
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;

            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;

            // total count
            table[i][j] = x + y;
        }
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m;j++)
            cout<<table[i][j]<<" ";
        cout<<endl;
    }

    return table[n][m-1];
}

int main(){
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    cout<<count(arr, m, 4)<<endl;
    return 0;
}