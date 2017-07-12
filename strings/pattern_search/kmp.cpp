#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_func(string pat){
    int n=pat.length();
    vector<int> prefix(n);

    prefix[0]=0;

    for(int i=1;i<n;i++){
        int j=prefix[i-1];

        while(j>0 && pat[i]!=pat[j])
            j=prefix[j-1];

        if(pat[i]==pat[j])
            j++;
        prefix[i]=j;
    }
    return prefix;
}

void KMPSearch(string str,string pat){
    vector<int> prefix = prefix_func(str);
    int i=0,j=0;
    int n=str.length();
    int m=pat.length();

    while(i<n){
        if(str[i]==pat[j]){
            i++;
            j++;
        }
        if(j==m){
            cout<<"Found pattern at index :"<<i-j<<endl;
            j=prefix[j-1];
        }
        if(str[i]!=pat[j])
            j=prefix[j-1];
        if(str[i]!=pat[j] && j==0)
            i++;
    }
}

int main(){
    string txt = "AAAAABAAAAB";
    string pat = "AAAA";
    KMPSearch(txt,pat);
    return 0;
}











