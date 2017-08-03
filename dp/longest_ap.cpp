#include <bits/stdc++.h>

using namespace std;

int lenghtOfLongestAP(int arr[],int n){
    int L[n][n];
    int llap=2;

    for(int i=0;i<n;i++)
        L[i][n-1]=2;

    for(int j=n-2;j>0;j--){

        int i=j-1,k=j+1;

        while(i>=0 && k<n){
            if(arr[i]+arr[k] < 2*arr[j])
                k++;
            else if(arr[i]+arr[k] > 2*arr[j]){
                L[i][j]=2;
                i--;
            }
            else{
                L[i][j]=L[j][k]+1;
                llap=max(llap,L[i][j]);
                i--;
                k++;
            }
        }

        while(i>=0){
            L[i][j]=2;
            i--;
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)
    //         cout<<L[i][j]<<" ";
    //     cout<<endl;
    // }

    return llap;
}



int main()
{
    int set1[] = {1, 7, 10, 13, 14, 19};
    int n1 = sizeof(set1)/sizeof(set1[0]);
    cout <<   lenghtOfLongestAP(set1, n1) << endl;

    int set2[] = {1, 7, 10, 15, 27, 29};
    int n2 = sizeof(set2)/sizeof(set2[0]);
    cout <<   lenghtOfLongestAP(set2, n2) << endl;

    int set3[] = {2, 4, 6, 8, 10};
    int n3 = sizeof(set3)/sizeof(set3[0]);
    cout <<   lenghtOfLongestAP(set3, n3) << endl;

    return 0;
}