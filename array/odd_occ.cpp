#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

void printTwoOdd(int arr[],int n){
    int xor2=arr[0];
    int set_bit;
    int x=0,y=0;

    for(int i=1;i<n;i++)
        xor2=xor2^arr[i];

    set_bit=xor2 & ~(xor2-1);

    for(int i=0;i<n;i++){
        if(set_bit & arr[i])
            x=x^arr[i];
        else
            y=y^arr[i];
    }
    cout<<x<<" "<<y<<endl;
}

int main(){
    int arr[] = {4, 2, 4, 5, 2, 3,3, 1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printTwoOdd(arr, arr_size);
    return 0;
}





















