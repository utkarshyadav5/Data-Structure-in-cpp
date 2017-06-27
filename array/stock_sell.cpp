#include <bits/stdc++.h>

using namespace std;

void stockBuySell(int arr[],int n){
    int local_minima=INT_MAX,local_maxima=INT_MIN;
    int index_buy,index_sell;
    int i=0;
    while(i<n){

        while(i<n-1 && arr[i]>=arr[i+1])
            i++;

        index_buy=i;
        i++;

        while(i<n && arr[i]>=arr[i-1])
            i++;

        index_sell=i-1;

        cout<<"Buy : "<<index_buy<<" Sell : "<<index_sell<<endl;
    }
}

int main(){
    int price[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(price)/sizeof(price[0]);

    // fucntion call
    stockBuySell(price, n);
    return 0;
}





















