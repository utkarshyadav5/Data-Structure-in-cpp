#include <bits/stdc++.h>

using namespace std;

class Activity{
public:
    int start;
    int finish;
};

bool compare(Activity s1,Activity s2){
    return s1.finish<s2.finish;
}

void printMaxActivities(Activity arr[],int n){
    sort(arr,arr+n,compare);
    int i=0;
    cout<<arr[i].start<<" "<<arr[i].finish<<endl;
    for(int j=1;j<n;j++){
        if(arr[j].start >= arr[i].finish){
            cout<<arr[j].start<<" "<<arr[j].finish<<endl;
            i=j;
        }
    }
}

int main(){
    Activity arr[]={{5, 9}, {1, 2}, {3, 4}, {0, 6},{5, 7}, {8, 9}};
    printMaxActivities(arr,6);
    return 0;
}