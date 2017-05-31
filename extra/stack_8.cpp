#include <bits/stdc++.h>

using namespace std;

stack<int> s;

void insertAtBottom(int n){
    if(s.empty())
        s.push(n);
    else{
        int top=s.top();
        s.pop();
        insertAtBottom(n);
        s.push(top);
    }
}

void reverse(){
    if(s.empty())
        return;

    int top=s.top();
    s.pop();
    reverse();
    insertAtBottom(top);
}

int main(){
    int arr[]={13,7,6,12};

    for(int i=0;i<4;i++)
        s.push(arr[i]);

    reverse();
    while(!s.empty())
        cout<<s.top()<<" ",s.pop();
    cout<<endl;
    return 0;
}
















