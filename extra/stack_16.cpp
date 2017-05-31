#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(cin,s);
    stack<int> stack_;

    stack_.push(-1);

    int result=0;

    for(int i=0;i<s.length();i++){
        if(s[i]=='(')
            stack_.push(i);

        else{

            stack_.pop();

            if(!stack_.empty())
                result=max(result,i-stack_.top());
            else
                stack_.push(i);
        }
    }
    cout<<result<<endl;

    return 0;
}
















