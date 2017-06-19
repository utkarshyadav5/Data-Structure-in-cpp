#include <bits/stdc++.h>
#include <set>

using namespace std;

int LongestSub(int arr[],int n){
    //instead of using unordered_map you can use set or unordered_set
    set<int> myMap;

    int max_len=0;

    for(int i=0;i<n;i++)
        myMap.insert(arr[i]);

    for(int i=0;i<n;i++){
        if(myMap.find(arr[i]-1)==myMap.end()){
            int j=arr[i];
            while(myMap.find(j)!=myMap.end())
                j++;

            max_len=max(max_len,j-arr[i]);
        }
    }
    return max_len;
}

int main(){
    int arr[]={1,9,3,10,4,20,2};
    cout<<LongestSub(arr,8)<<endl;
    return 0;
}