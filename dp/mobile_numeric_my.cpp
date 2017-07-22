#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<int>::iterator it;

unordered_map<int,vector<int> > myMap={
                            {0,{0,8}},
                            {1,{1,2,4}},
                            {2,{1,2,3,5}},
                            {3,{2,3,6}},
                            {4,{1,4,5,7}},
                            {5,{2,4,5,6,8}},
                            {6,{3,5,6,9}},
                            {7,{4,7,8}},
                            {8,{0,5,7,8,9}},
                            {9,{6,8,9}},
                            };

// for printing the combination

int cnt=0;

void possible(int n,int index,int i,int* data){
    if(n==index){
        for(int i=0;i<n;i++)
            cout<<data[i];
        cnt++;
        cout<<endl;
        return ;
    }

    if(index==0){
        for(int i=0;i<=9;i++){
            data[index]=i;
            possible(n,index+1,i,data);
        }
        return;
    }
    else{
        for(int j=0;j<myMap[i].size();j++){
            data[index]=myMap[i][j];
            possible(n,index+1,myMap[i][j],data);
        }
        return;
    }
}

int main(){
    int n = 5;
    int *data=new int[n];
    possible(n,0,-1,data);
    cout<<"Count : "<<cnt<<endl;
    return 0;
}







