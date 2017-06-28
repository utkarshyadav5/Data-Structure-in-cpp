#include <bits/stdc++.h>
#define n 4

using namespace std;

class MinheapNode{
public:
    int element;
    int i;
    int j;
};


class myComparator{
public:
    bool operator()(MinheapNode a,MinheapNode b){
        return a.element>b.element;
    }
};

int *mergeKArrays(int arr[][n],int k){
    int *output =new int[n*k];

    priority_queue< MinheapNode,vector<MinheapNode>, myComparator > minHeap;

    for(int i=0;i<k;i++){
        MinheapNode temp;
        temp.element=arr[i][0];
        temp.i=i;
        temp.j=1;
        minHeap.push(temp);
    }

    for(int count=0;count<n*k;count++){
        MinheapNode top=minHeap.top();
        minHeap.pop();
        output[count]=top.element;

        MinheapNode temp;
        if(top.j<n){
            temp.element=arr[top.i][top.j];
            temp.i=top.i;
            temp.j=top.j+1;
        }
        else
            temp.element=INT_MAX;
        minHeap.push(temp);
    }
    return output;
}

int main(){
    int arr[][n] =  {{2, 6, 12, 34},
                     {1, 9, 20, 1000},
                     {23, 34, 90, 2000}};
    int k = sizeof(arr)/sizeof(arr[0]);

    int *output = mergeKArrays(arr, k);

    cout << "Merged array is " << endl;
    for(int i=0;i<n*k;i++)
        cout<<output[i]<<" ";
    cout<<endl;
    return 0;
}





















