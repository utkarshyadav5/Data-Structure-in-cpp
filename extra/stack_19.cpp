#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(cin,s);

    stack<int> stk;

    if(s.length()%2!=0){
        cout<<"Not possible"<<endl;
        return 0;
    }

    for(int i=0;i<s.length();i++){
        if(s[i]=='}' && !stk.empty()){
            if(stk.top()=='{')
                stk.pop();
            else
                stk.push(s[i]);
        }
        else
            stk.push(s[i]);
    }
    int len=stk.size();

    int n=0;
    while(!stk.empty() && stk.top()!='}'){
        stk.pop();
        n++;
    }
    cout<<(len/2 +n%2)<<endl;
    return 0;
}









