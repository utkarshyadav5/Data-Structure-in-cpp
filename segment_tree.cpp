#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

int tree[MAX],lazy[MAX]={0};

void build(int arr[],int node,int start,int end){
    if(start==end)
        tree[node]=arr[start];
    else{
        int mid=(start+end)/2;
        build(arr,2*node,start,mid);
        build(arr,2*node+1,mid+1,end);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

void update(int node,int start,int end,int l,int r,int val){
    if(lazy[node]!=0){
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(start>r or end<l or start>end)
        return;

    if(start>=l and end<=r){
        tree[node]+=(end-start+1)*val;
        if(start!=end){
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return;
    }

    int mid=(start+end)/2;
    update(2*node,start,mid,l,r,val);
    update(2*node+1,mid+1,end,l,r,val);
    tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int node,int start,int end,int l,int r){
    if(start>r or end<l or start>end)
        return 0;

    if(lazy[node]!=0){
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(start>=l and end<=r)
        return tree[node];

    int mid=(start+end)/2;
    int p1=query(2*node,start,mid,l,r);
    int p2=query(2*node+1,mid+1,end,l,r);
    return (p1+p2);
}

int main(){
    int arr[] = {-1,2,4,1,7,1,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Build segment tree from given array
    build(arr,0,0,n);

    cout<<"Sum of values in given range = "<<query(0,0,n,0,n)<<endl;

    update(0,0,n,0,3,3);
    update(0,0,n,0,3,1);
    update(0,0,n,0,0,2);

    cout<<"Updated sum of values in given range = "<<query(0,0,n,0,n)<<endl;

    return 0;
}