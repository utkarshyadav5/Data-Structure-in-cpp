#include <bits/stdc++.h>

using namespace std;

// returns true if opening bracket
    bool check_opening(char c){
        if(c=='[' or c=='{' or c=='(')
            return true;
        else
            return false;
    }

    bool check(char a,char b){
        if((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'))
            return true;
        else
            return false;
    }

int main(){
    string s;
    getline(cin,s);
    stack<int> stack_;

    for(int i=0;i<s.length();i++){
            if(stack_.empty() && check_opening(s[i]))
                stack_.push(s[i]);

            else if(check_opening(s[i]))
                stack_.push(s[i]);

            else{
                char c=stack_.top();
                if(!check(c,s[i])){
                    cout<<"False"<<endl;
                    return 0;
                }
                else
                    stack_.pop();
            }
        }
    if(!stack_.empty())
        cout<<"False"<<endl;
    else
        cout<<"True"<<endl;
    return 0;
}
















