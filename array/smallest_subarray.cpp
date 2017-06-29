#include <bits/stdc++.h>

using namespace std;

int smallestSubWithSum(int arr[],int n,int x){
    int curr_sum=0,mini=n+1;
    int start=0,end=0;
    while(end<n){

        while(curr_sum <= x && end < n)
            curr_sum+=arr[end++];

        while(curr_sum > x && start < n){
            if(end-start < mini)
                mini=end-start;

            curr_sum-=arr[start++];
        }
    }
    return mini;
}

int main(){
    int arr1[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int res1 = smallestSubWithSum(arr1, n1, x);
    (res1 == n1+1)? cout << "Not possible\n" :
                    cout << res1 << endl;
    return 0;
}





















