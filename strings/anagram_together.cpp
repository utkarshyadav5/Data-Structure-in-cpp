#include <bits/stdc++.h>
using namespace std;

map<int,vector<string> > myMap;

void printAnagramsTogether(char* arr[],int size){
    for(int i=0;i<size;i++){
        string a=arr[i];
        int sum=0;
        for(int j=0;j<a.length();j++){
            sum+=a[j];
        }

        myMap[sum].push_back(a);
    }
    map<int,vector<string> >::iterator it;
    vector<string>::iterator it1;
    for(it=myMap.begin();it!=myMap.end();it++){
        vector<string> v=(*it).second;
        for(it1=v.begin();it1!=v.end();it1++)
            cout<<(*it1)<<" ";
    }
}

int main() {
    char* wordArr[] = {"cat", "dog", "tac", "god", "act"};
    int size = sizeof(wordArr) / sizeof(wordArr[0]);
    printAnagramsTogether(wordArr, size);
    cout<<endl;
    return 0;
}