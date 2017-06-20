#include <bits/stdc++.h>

using namespace std;

void subArraySum(int arr[],int n,int sum){
    map<int,int> myMap;

    int curr_sum=0;
    for(int i=0;i<n;i++){
        curr_sum+=arr[i];

        if(curr_sum==sum){
            cout<<0<<" to "<<i<<endl;
            return;
        }

        if(myMap.find(curr_sum-sum)!=myMap.end()){
            cout<<myMap[curr_sum-sum]+1<<" to "<<i<<endl;
            return;
        }
        myMap.insert(make_pair(curr_sum,i));
    }
}

int main(){
    int arr[] = {10, 2, -2, -20, 10};
    int sum=(-10);
    subArraySum(arr,5,sum);
    return 0;
}