#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int diff(int arr[],int n,int k){

    sort(arr,arr+n);
    int maxe=arr[n-1];
    int mine=arr[0];

    if(k>=(maxe-mine))
        return (maxe-mine);

    arr[n-1]-=k;
    arr[0]+=k;
    maxe=max(arr[n-1],arr[0]);
    mine=min(arr[n-1],arr[0]);

    for(int i=1;i<n-1;i++){
        if(arr[i]>maxe)
            arr[i]-=k;
        else if(arr[i]<mine)
            arr[i]+=k;
        else if((arr[i]-mine)<(maxe-arr[i]))
            arr[i]+=k;
        else
            arr[i]-=k;
        maxe=max(arr[i],maxe);
        mine=min(arr[i],mine);
    }

    return (maxe-mine);
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int k,n,arr[MAX];
        cin>>k>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<diff(arr,n,k)<<endl;
    }
    return 0;
}