#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

void printKMax(int arr[],int n,int k){
    deque<int> q(k);
    int i;
    for(i=0;i<k;i++){

        while(!q.empty() && arr[i]>=arr[q.back()])
            q.pop_back();

        q.push_back(i);
    }

    for(;i<n;i++){
        cout<<arr[q.front()]<<" ";

        while(!q.empty() && q.front()<=i-k)
            q.pop_front();

        while(!q.empty() && arr[i]>=arr[q.back()])
            q.pop_back();

        q.push_back(i);
    }
    cout<<arr[q.front()]<<endl;
}



int main(){
    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}





















