#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

// using moore voting algo

int majority(int *arr,int n){
    int maj=0,count=1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[maj])
            count++;
        else
            count--;
        if(count==0){
            maj=i;
            count=1;
        }
    }
    return arr[maj];
}

bool printMajority(int *arr,int n){
    int maj=majority(arr,n);

    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==maj)
            count++;
    }
    if(count>n/2){
        cout<<maj<<endl;
        return true;
    }
    else
        return false;
}


int main(){
    int a[] = {2, 2, 3, 5, 2, 2, 6};
    int size = (sizeof(a))/sizeof(a[0]);
    printMajority(a, size);
    return 0;
}