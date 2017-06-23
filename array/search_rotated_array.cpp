#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

int search(int arr[],int start,int end,int key){
    int mid=(start+end)/2;
    if(arr[mid]==key)
        return mid;
    else if(arr[start]<=arr[mid]){
        if(key>=arr[start] && key<=arr[mid])
            return search(arr,start,mid-1,key);
        return search(arr,mid+1,end,key);
    }
    else{
        if(key<=arr[end] && key>=arr[mid])
            return search(arr,mid+1,end,key);
        return search(arr,start,mid-1,key);
    }
}


int main(){
    int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 6;
    int i = search(arr, 0, n-1, key);
    if (i != -1)
        cout << "Index: " << i << endl;
    else
        cout << "Key not found\n";
    return 0;
}





















