#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

// Kadane's Algo

int maxSubArraySum(int *arr,int n){
    int max_so_far=0,max_end_here=0;

    for(int i=0;i<n;i++){
        max_end_here=max_end_here+arr[i];

        if(max_end_here<0)
            max_end_here=0;
        max_so_far=max(max_so_far,max_end_here);
    }
    return max_so_far;
}


int main(){
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum<<endl;
    return 0;
}