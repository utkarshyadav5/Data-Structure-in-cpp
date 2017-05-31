#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s1,s2;

    queue<string> q;
    q.push("1");

    while(n--){
        s1=q.front();
        q.pop();
        cout<<s1<<endl;
        s2=s1;
        q.push(s1.append("0"));
        q.push(s2.append("1"));
    }

    return 0;
}
















