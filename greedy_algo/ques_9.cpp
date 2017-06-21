#include <bits/stdc++.h>

using namespace std;

class Job{
public:
    char id;
    int deadline;
    int profit;
};

bool compare(Job s1,Job s2){
    return s1.profit>s2.profit;
}

void printJobScheduling(Job arr[],int n){
    sort(arr,arr+n,compare);
    int result[n];
    bool slot[n];

    for(int i=0;i<n;i++)
        slot[i]=false;

    for(int i=0;i<n;i++){
        for(int j=min(n,arr[i].deadline)-1;j>=0;j--){
            if(slot[j]==false){
                slot[j]=true;
                result[j]=i;
                break;
            }
        }
    }

    for(int i=0;i<n;i++)
        if(slot[i])
            cout<<arr[result[i]].id<<endl;
}

int main(){
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
    printJobScheduling(arr,5);
    return 0;
}