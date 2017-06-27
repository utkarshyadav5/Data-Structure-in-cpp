#include <bits/stdc++.h>

using namespace std;

int maxRepeating(int arr[],int n,int k){
    int maxe=0;

    for(int i=0;i<n;i++)
        arr[arr[i]%k]+=k;

    for(int i=0;i<n;i++){
        if(arr[i]>arr[maxe])
            maxe=i;
    }

    //for getting back the original array
    for(int i=0;i<n;i++)
        arr[i]=arr[i]%k;

    return maxe;
}

int main(){
    int arr[] = {2, 3, 3, 5, 3, 4, 1, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 8;

    cout << "The maximum repeating number is " <<
         maxRepeating(arr, n, k) << endl;
    return 0;
}





















