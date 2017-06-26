#include <bits/stdc++.h>

using namespace std;

int findNumberOfTriangles(int arr[],int n){
    sort(arr,arr+n);

    int count=0;

    for(int i=0;i<n-2;i++){
        int k=i+2;

        for(int j=i+1;j<n;j++){

            while(k<n && arr[i]+arr[j]>arr[k])
                k++;

            count+=(k-j-1);
        }
    }
    return count;
}

int main(){
    int arr[] =   {10, 21, 22, 100, 101, 200, 300};
    int size = sizeof( arr ) / sizeof( arr[0] );

    printf("Total number of triangles possible is %d \n",
           findNumberOfTriangles( arr, size ) );
    return 0;
}





















