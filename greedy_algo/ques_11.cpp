#include <bits/stdc++.h>

using namespace std;

void printCoins(int n){
    int arr[9]={1,2,5,10,20,50,100,500,1000};
    int freq[9];

    for(int i=0;i<9;i++)
        freq[i]=0;

    int j=8;
    while(n){
        freq[j]=n/arr[j];
        n=n%arr[j];
        j--;
    }
    for(int i=0;i<9;i++){
        if(freq[i])
            cout<<arr[i]<<" : "<<freq[i]<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    printCoins(n);
    return 0;
}