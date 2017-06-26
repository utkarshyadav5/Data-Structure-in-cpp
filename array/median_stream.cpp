#include <bits/stdc++.h>
#define MAX 10000

using namespace std;



priority_queue<int> maxHeap;
priority_queue<int,vector<int>,greater<int> > minHeap;

int signum(int a,int b){
    if(a==b)
        return 0;
    return (a<b)?(-1):1;
}

int getMedian(int key,int m){
    int sig=signum(maxHeap.size(),minHeap.size());
    switch(sig){
        case 1:
            if(key<m){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(key);
            }
            else
                minHeap.push(key);
            m=(maxHeap.top()+minHeap.top())/2;
            break;
        case 0:
            if(key<m){
                maxHeap.push(key);
                m=maxHeap.top();
            }
            else{
                minHeap.push(key);
                m=minHeap.top();
            }
            break;
        case -1:
            if(key<m)
                maxHeap.push(key);
            else{
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(key);
            }
            m=(maxHeap.top()+minHeap.top())/2;
            break;
    }
    return m;
}

void printMedian(int arr[],int n){
    int m=0;
    for(int i=0;i<n;i++){
        m=getMedian(arr[i],m);
        cout<<m<<" ";
    }
    cout<<endl;
}

int main(){
    int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};

    printMedian(A, 12);
    return 0;
}





















