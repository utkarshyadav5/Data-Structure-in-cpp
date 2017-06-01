#include <bits/stdc++.h>

using namespace std;

bool  arr[4][4] = {{0, 0, 1, 0},
                 {0, 0, 1, 0},
                 {0, 0, 0, 0},
                 {0, 0, 1, 0}};

bool knows(int a,int b){
    if(arr[a][b]==1)
        return true;
    else
        return false;
}

stack<int> stk;

int main(){
    int a,b;
    for(int i=0;i<4;i++)
        stk.push(i);

    while(stk.size()!=1){
        a=stk.top();
        stk.pop();
        b=stk.top();
        stk.pop();

        if(knows(a,b))
            stk.push(b);
        else if(knows(b,a))
            stk.push(a);
    }
    cout<<stk.top()<<endl;
    return 0;
}









