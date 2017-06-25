#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

void findSubArray(int arr[],int n){
    int leftsum[n];

    for(int i=0;i<n;i++)
        if(arr[i]==0)
            arr[i]=(-1);

    int maxSize=0;
    leftsum[0]=arr[0];
    for(int i=1;i<n;i++){
        leftsum[i]=leftsum[i-1]+arr[i];
        if(leftsum==0)
            maxSize=max(maxSize,i+1);
    }

    map<int,int> myMap;

    for(int i=0;i<n;i++){
        if(myMap.find(leftsum[i])==myMap.end())
            myMap.insert(make_pair(leftsum[i],i));
        else
            maxSize=max(maxSize,i-myMap[leftsum[i]]);
    }
    cout<<maxSize<<endl;
}



int main(){
    int arr[] =  {1, 0, 0, 1, 0, 1, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    findSubArray(arr, size);
    return 0;
}





















