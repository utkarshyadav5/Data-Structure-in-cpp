#include <bits/stdc++.h>

using namespace std;

int prio(char a){
    if(a=='^')
        return 3;
    else if(a=='*' || a=='/')
        return 2;
    else if(a=='+' || a=='-')
        return 1;
    else
        return -1;
}

int main(){
    string s,postfix;
    getline(cin,s);
    //cin.ignore();
    stack<char> stck;

    for(int i=0;i<s.length();i++){

        if(s[i]>='a' && s[i]<='z')
            postfix.push_back(s[i]);

        else if(s[i]=='(')
            stck.push(s[i]);

        else if(s[i]==')'){
            while(stck.top()!='('){
                postfix.push_back(stck.top());
                stck.pop();
            }
            stck.pop();
        }

        else{

            while(!stck.empty() && prio(s[i])<=prio(stck.top())){
                postfix.push_back(stck.top());
                stck.pop();
            }
            stck.push(s[i]);

        }
    }
    while(!stck.empty()){
        postfix.push_back(stck.top());
        stck.pop();
    }

    cout<<postfix<<endl;
    return 0;
}
















