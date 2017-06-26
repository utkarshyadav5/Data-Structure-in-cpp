#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

void find3Numbers(int arr[],int n){
    int *smaller=new int[n];
    int *larger=new int[n];

    smaller[0]=-1;
    larger[n-1]=-1;
    int min=0,max=n-1;
    for(int i=1;i<n;i++){
        if(arr[i]<=arr[min]){
            min=i;
            smaller[i]=-1;
        }
        else
            smaller[i]=min;
    }

    for(int i=n-2;i>=0;i--){
        if(arr[i]>arr[max])
            larger[i]=max;
        else{
            max=i;
            larger[i]=-1;
        }
    }

    for(int i=0;i<n;i++){
        if(smaller[i]!=(-1) && larger[i]!=(-1)){
            cout<<arr[smaller[i]]<<" "<<arr[i]<<" "<<arr[larger[i]]<<endl;
        }
    }
}



int main(){
    int arr[] = {12, 11, 10, 5, 6, 2, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    find3Numbers(arr, n);
    return 0;
}





















