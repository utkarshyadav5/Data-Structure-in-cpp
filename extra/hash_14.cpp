#include <bits/stdc++.h>

using namespace std;

int maxLen(int arr[],int n){
    map<int,int> myMap;
    int sum=0,max_len=0;

    for(int i=0;i<n;i++){
        sum=sum+arr[i];

        if (arr[i] == 0 && max_len == 0)
                max_len = 1;

        if (sum == 0)
            max_len = i+1;

        if(myMap.find(sum)==myMap.end())
            myMap.insert(make_pair(sum,i));
        else{
            int len=i-myMap[sum];
            max_len=max(len,max_len);
        }
    }
    return max_len;
}

int main(){
    int arr[]={15, -2, 2, -8, 1, 7, 10, 23};
    cout<<maxLen(arr,8)<<endl;
    return 0;
}