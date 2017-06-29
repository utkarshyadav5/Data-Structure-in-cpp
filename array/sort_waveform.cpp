#include <bits/stdc++.h>

using namespace std;

int swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void sortInWave(int arr[],int n){

    for(int i=0;i<n;i++){
        if(i%2==0){
            if(i>0 && arr[i]<arr[i-1])
                swap(arr[i],arr[i-1]);
            if(i<n && arr[i]<arr[i+1])
                swap(arr[i],arr[i+1]);
        }
    }

}

int main(){
    int arr[] = {10, 90, 49, 2, 1, 5, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortInWave(arr, n);
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    cout<<endl;
    return 0;
}





















