#include <bits/stdc++.h>

using namespace std;

void countDistinct(int arr[],int k,int size){
    map<int,int> myMap;

    int count=0;
    for(int i=0;i<k;i++){
        if(myMap.find(arr[i])==myMap.end()){
            myMap.insert(make_pair(arr[i],1));
            count++;
        }
        else
            myMap[arr[i]]++;
    }
    cout<<"Count for window is : "<<count<<endl;

    for(int i=k;i<size;i++){
        if(myMap[arr[i-k]]>1)
            myMap[arr[i-k]]--;
        else{
            myMap.erase(arr[i-k]);
            count--;
        }

        if(myMap.find(arr[i])==myMap.end()){
            myMap.insert(make_pair(arr[i],1));
            count++;
        }
        else
            myMap[arr[i]]++;
        cout<<"Count for window is : "<<count<<endl;
    }
}

int main(){
    int arr[] = {1, 2, 1, 3, 4, 2, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    countDistinct(arr, k, size);
    return 0;
}