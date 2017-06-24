#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

void printNGE(int arr[],int n){
    stack<int> s;
    s.push(arr[0]);

    for(int i=1;i<n;i++){
        int next=arr[i];

        if(!s.empty()){
            int top=s.top();
            s.pop();

            while(top<next){
                cout<<top<<" "<<next<<endl;
                if(s.empty())
                    break;
                top=s.top();
                s.pop();
            }

            if(top>next)
                s.push(top);
        }
        s.push(next);
    }

    while(!s.empty()){
        int top=s.top();
        s.pop();
        cout<<top<<" "<<-1<<endl;
    }
}



int main(){
    int arr[]= {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}





















