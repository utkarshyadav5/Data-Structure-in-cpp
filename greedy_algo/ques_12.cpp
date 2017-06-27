#include <bits/stdc++.h>

using namespace std;

int findPlatform(int arr[],int dep[],int n){
    sort(arr,arr+n);
    sort(dep,dep+n);
    int max_platform=0;
    int platform=0;
    int i=0,j=0;
    while(i<n && j<n){
        if(arr[i]<dep[j]){
            platform++;
            i++;
            max_platform=max(platform,max_platform);
        }
        else{
            platform--;
            j++;
        }
    }
    return max_platform;
}

int main(){
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    cout<<findPlatform(arr,dep,6)<<endl;
    return 0;
}