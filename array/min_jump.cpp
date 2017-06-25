#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

int minJumps(int arr[],int n){
    int *jump=new int[n];
    int min;
    jump[n-1]=0;

    for(int i=n-2;i>=0;i--){

        if(arr[i]==0)
            jump[i]=INT_MAX;

        else if(arr[i]>=(n-i-1))
            jump[i]=1;

        else{
            min=INT_MAX;
            for(int j=i+1;j<=i+arr[i];j++){
                if(min>jump[j])
                    min=jump[j];
            }
            if(min!=INT_MAX)
                jump[i]=min+1;
            else
                jump[i]=min;
        }

    }
    return jump[0];
}

int main(){
    int arr[] = {1, 3, 6, 1, 0, 9};
    int size = sizeof(arr)/sizeof(int);
    printf("Minimum number of jumps to reach end is %d \n", minJumps(arr,size));
    return 0;
}





















