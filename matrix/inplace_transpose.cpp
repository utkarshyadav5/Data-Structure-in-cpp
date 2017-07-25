#include <bits/stdc++.h>

using namespace std;

// Uses the equation new_loc = (old_loc*r)%(n-1)

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void print(int *A,int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            cout<<*(A+i*c+j)<<" ";
        cout<<endl;
    }
}

void transpose(int *A,int r,int c){
    int size=r*c-1;
    bitset<128> b;
    b.reset();
    b[0]=b[size]=1;
    int t,next,cycleBegin;

    int i=1;

    while(i<size){
        cycleBegin=i;
        t=A[i];
        do{
            next=(i*r)%size;
            swap(A[next],t);
            b[i]=1;
            i=next;
        }while(i!=cycleBegin);

        for(int i=1;i<size && b[i];i++);
    }
}



int main(){
    int r=5,c=6;
    int size=r*c;
    int *A=new int[size];

    for(int i=0;i<size;i++)
        A[i]=i+1;

    print(A,r,c);
    transpose(A,r,c);
    print(A,c,r);

    delete[] A;
    return 0;
}
















