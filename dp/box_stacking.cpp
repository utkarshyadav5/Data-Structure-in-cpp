#include <bits/stdc++.h>

using namespace std;

// Variation of LIS

class Box{
public:
    int h,w,d;
};

class myCompare{
public:
    bool operator()(Box a,Box b){
        return (a.w*a.d)<(b.w*b.d);
    }
};

int maxStackHeight(Box *arr,int n){
    Box *new_arr=new Box[3*n];

    int index=0;
    for(int i=0;i<n;i++){

        new_arr[index++]=arr[i];

        new_arr[index].h=arr[i].w;
        new_arr[index].w=min(arr[i].h,arr[i].d);
        new_arr[index++].d=max(arr[i].h,arr[i].d);

        new_arr[index].h=arr[i].d;
        new_arr[index].w=min(arr[i].w,arr[i].h);
        new_arr[index++].d=max(arr[i].w,arr[i].h);

    }
    n=3*n;

    sort(new_arr,new_arr+n,myCompare());
    // for(int i=0;i<n;i++)
    //     cout<<new_arr[i].h<<" "<<new_arr[i].w<<" "<<new_arr[i].d<<endl;


    int msh[n];
    for(int i=0;i<n;i++)
        msh[i]=new_arr[i].h;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(new_arr[i].w>new_arr[j].w && new_arr[i].d>new_arr[j].d)
                msh[i]=max(msh[i],msh[j]+new_arr[i].h);
        }
    }

    int max_val=INT_MIN;
    for(int i=0;i<n;i++)
        max_val=max(max_val,msh[i]);

    return max_val;
}

int main(){
    Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<maxStackHeight (arr, n)<<endl;

  return 0;
}







