#include <bits/stdc++.h>

using namespace std;

int maxLen(int arr[],int n){
    map<int,int> myMap;
    int sum=0,max_len=0;
    int init=0,end=0;

    for(int i=0;i<n;i++)
        if(arr[i]==0)
            arr[i]=-1;

    for(int i=0;i<n;i++){
        sum=sum+arr[i];

        if (sum == 0){
            max_len=max(max_len,i+1);
            init=0;
            end=i;
        }

        if(myMap.find(sum)==myMap.end())
            myMap.insert(make_pair(sum,i));
        else{
            int len=i-myMap[sum];
            max_len=max(len,max_len);
            if(max_len==len){
                init=myMap[sum];
                end=i-1;
            }
        }
    }
    cout<<init<<" "<<end<<endl;
    return max_len;
}

int main(){
    int arr[]={1, 0, 0, 1, 0, 1, 1};
    cout<<maxLen(arr,4)<<endl;
    return 0;
}