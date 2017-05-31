#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[]={13,7,6,12};
    stack<int> s;
    s.push(arr[0]);

    for(int i=1;i<4;i++){

        while(!s.empty() && s.top()<arr[i]){
            cout<<s.top()<<" -> "<<arr[i]<<endl;
            s.pop();
        }
        s.push(arr[i]);

    }

    while(!s.empty()){
        cout<<s.top()<<" -> "<<-1<<endl;
        s.pop();
    }
    return 0;
}
















