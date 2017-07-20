#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int arr[MAX];

void initialise(int n){
    for(int i=0;i<n;i++)
        arr[i]=i;
}

int root(int i){
    while(arr[i]!=i){
        arr[i]=arr[arr[i]];
        i=arr[i];
    }
    return i;
}

void union_(int a,int b){
    int root_a=root(a);
    int root_b=root(b);
    arr[root_a]=root_b;
}

bool find(int a,int b){
    if(root(a)==root(b))
        return true;
    else
        return false;
}

void print(int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    initialise(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        union_(a,b);
        print(n);
    }
    // queries
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<find(a,b)<<endl;
    }

}