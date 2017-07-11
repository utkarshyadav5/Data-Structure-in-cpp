#include <bits/stdc++.h>

using namespace std;

string minLexRotation(string str){
    int n=str.length();
    string arr[n];

    string concat=str+str;

    for(int i=0;i<n;i++)
        arr[i]=concat.substr(i,n);

    sort(arr,arr+n);
    return arr[0];
}

int main(){
    cout << minLexRotation("GEEKSFORGEEKS") << endl;
    cout << minLexRotation("GEEKSQUIZ") << endl;
    cout << minLexRotation("BCABDADAB") << endl;
    return 0;
}