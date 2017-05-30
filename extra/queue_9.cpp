#include <bits/stdc++.h>

using namespace std;

int main(){
    queue<int> q0,q1,q2;
    vector<int> arr;
    vector<int>::iterator it;
    int a=0;
    cin>>a;
    while(a!=(-1)){
        arr.push_back(a);
        cin>>a;
    }
    vector<int> final;
    int sum=0;
    sort(arr.begin(),arr.end());
    for(it=arr.begin();it<arr.end();it++){
        sum+=(*it);
        if((*it)%3==0)
            q0.push((*it));
        else if((*it)%3==1)
            q1.push((*it));
        else
            q2.push((*it));
    }

    if((sum%3)==0){
        while(q0.size()!=0){
            final.push_back(q0.front());
            q0.pop();
        }
        while(q1.size()!=0){
            final.push_back(q1.front());
            q1.pop();
        }
        while(q2.size()!=0){
            final.push_back(q2.front());
            q2.pop();
        }
    }
    else if((sum%3)==1){
        if(q1.size()==0){
            q2.pop();
            q2.pop();
        }
        else
            q1.pop();

        while(q0.size()!=0){
            final.push_back(q0.front());
            q0.pop();
        }
        while(q1.size()!=0){
            final.push_back(q1.front());
            q1.pop();
        }
        while(q2.size()!=0){
            final.push_back(q2.front());
            q2.pop();
        }
    }
    else{
        if(q2.size()==0){
            q1.pop();
            q1.pop();
        }
        else
            q2.pop();

        while(q0.size()!=0){
            final.push_back(q0.front());
            q0.pop();
        }
        while(q1.size()!=0){
            final.push_back(q1.front());
            q1.pop();
        }
        while(q2.size()!=0){
            final.push_back(q2.front());
            q2.pop();
        }
    }
    sort(final.begin(),final.end(),greater<int>());
    for(it=final.begin();it<final.end();it++)
        cout<<(*it);
    cout<<endl;

    return 0;
}
















