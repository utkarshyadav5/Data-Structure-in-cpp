#include <bits/stdc++.h>

using namespace std;

stack<int> s;

void insertAtBottom(int n){
    if(s.empty())
        s.push(n);
    else{
        if(s.top()<n){
            int top=s.top();
            s.pop();
            insertAtBottom(n);
            s.push(top);
        }
        else
            s.push(n);
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
    int arr[]={30,-5,18,14,-3};

    for(int i=0;i<5;i++)
        s.push(arr[i]);

    reverse();
    while(!s.empty())
        cout<<s.top()<<" ",s.pop();
    cout<<endl;
    return 0;
}
















