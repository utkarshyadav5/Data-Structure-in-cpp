#include <bits/stdc++.h>
#define ROW 4
#define COL 5

using namespace std;

int kadane(int *arr,int *start,int *end,int n){
    int sum=0,maxSum=INT_MIN,local_start=0;
    *end=-1;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum<0){
            sum=0;
            local_start=i+1;
        }
        if(sum>maxSum){
            maxSum=sum;
            *start=local_start;
            *end=i;
        }
    }

    if(*end!=-1)
        return maxSum;

    // for all -ve values
    maxSum=arr[0];
    *start=*end=0;
    for(int i=1;i<n;i++){
        if(arr[i]>maxSum){
            maxSum=i;
            *start=*end=i;
        }
    }

    return maxSum;
}

void findMaxSum(int M[][COL]){
    int f_left,f_right,f_top,f_bottom;
    int temp[ROW],sum,start,finish;
    int maxSum=INT_MIN;

    for(int left=0;left<COL;left++){

        memset(temp,0,sizeof(temp));
        for(int right=left;right<COL;right++){

            for(int i=0;i<ROW;i++)
                temp[i]+=M[i][right];

            sum=kadane(temp,&start,&finish,ROW);

            if(sum>maxSum){
                maxSum=sum;
                f_top=start;
                f_bottom=finish;
                f_left=left;
                f_right=right;
            }
        }
    }

    cout<<f_top<<" "<<f_bottom<<endl;
    cout<<f_left<<" "<<f_right<<endl;
    cout<<maxSum<<endl;
}

int main(){
    int M[ROW][COL] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };

    findMaxSum(M);

    return 0;
}