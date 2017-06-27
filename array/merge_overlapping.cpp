#include <bits/stdc++.h>

using namespace std;

class Interval{
public:
    int first;
    int sec;
};

bool compare(Interval a,Interval b){
    return (a.first < b.first)?1:0;
}

void mergeIntervals(Interval arr[],int n){
    stack <Interval> s;
    sort(arr,arr+n,compare);

    s.push(arr[0]);
    for(int i=1;i<n;i++){
        Interval top=s.top();
        s.pop();

        if(top.sec >= arr[i].first){
            top.sec=max(top.sec,arr[i].sec);
            s.push(top);
        }
        else{
            s.push(top);
            s.push(arr[i]);
        }
    }

    while(!s.empty()){
        Interval top=s.top();
        s.pop();
        cout<<top.first<<" "<<top.sec<<endl;
    }
}



int main(){
    Interval arr[] =  {{1,3}, {2,4}, {5,7}, {6,8} };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}





















