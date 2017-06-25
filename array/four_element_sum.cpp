#include <bits/stdc++.h>

using namespace std;

class pairSum{
public:
    int first;
    int sec;
    int sum;
};

int compare(pairSum a,pairSum b){
    return (a.sum < b.sum);
}

bool noCommon(pairSum a,pairSum b){
    if(a.first == b.first || a.first==b.sec ||
        a.sec==b.first || a.sec==b.sec)
        return false;
    else
        return true;
}

void findFourElements(int arr[],int n,int key){
    int size=(n*(n-1))/2;
    pairSum *aux=new pairSum[size];
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            aux[k].sum=arr[i]+arr[j];
            aux[k].first=i;
            aux[k].sec=j;
            k++;
        }
    }

    sort(aux,aux+k,compare);

    int i=0,j=n-1;

    while(i<size && j>=0){
        if(aux[i].sum+aux[j].sum==key && noCommon(aux[i],aux[j])){
            cout<<arr[aux[i].first]<<" "<<arr[aux[i].sec]<<" "<<
                    arr[aux[j].first]<<" "<<arr[aux[j].sec]<<endl;
                    return;
        }
        else if(aux[i].sum+aux[j].sum < key)
            i++;
        else
            j--;
    }


}


int main(){
    int arr[] = {10, 20, 30, 40, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 91;
    findFourElements (arr, n, X);
    return 0;
}





















