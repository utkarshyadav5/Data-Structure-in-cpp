#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

// Segregate 0,1,2 (Also known as Dutch National Flag Problem)

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void sort012(int arr[],int n){
    int low=0,mid=0,high=n-1;

    while(mid<=high){
        if(arr[mid]==0)
            swap(&arr[mid++],&arr[low++]);
        else if(arr[mid]==1)
            mid++;
        else
            swap(&arr[mid],&arr[high--]);
    }
}

int main(){
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int i;

    sort012(arr, arr_size);
    printf("Array after segregation ");
    for(int i=0;i<arr_size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}





















