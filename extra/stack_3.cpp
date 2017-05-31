#include <bits/stdc++.h>

using namespace std;

int main(){
    string s,postfix;
    getline(cin,s);
    int a,b;
    stack<int> stack_;

    for(int i=0;i<s.length();i++){
        if(isdigit(s[i]))
            stack_.push(s[i]-'0');

        else{
            a=stack_.top();
            stack_.pop();
            b=stack_.top();
            stack_.pop();
            if(s[i]=='^')
                stack_.push(b^a);
            else if(s[i]=='*')
                stack_.push(a*b);
            else if(s[i]=='/')
                stack_.push(b/a);
            else if(s[i]=='+')
                stack_.push(a+b);
            else
                stack_.push(b-a);
        }

    }
    cout<<stack_.top()<<endl;
    return 0;
}
















