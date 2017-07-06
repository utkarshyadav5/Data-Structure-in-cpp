#include <bits/stdc++.h>

using namespace std;

void swap(char *a,char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}

void permutation(string s,int l,int r){
    if(l==r){
        cout<<s<<endl;
    }
    else{
        for(int i=l;i<=r;i++){
            swap(s[l],s[i]);
            permutation(s,l+1,r);
            swap(s[l],s[i]);
        }
    }
}

int main(){
    string s;
    getline(cin,s);
    permutation(s,0,s.length()-1);
    return 0;
}